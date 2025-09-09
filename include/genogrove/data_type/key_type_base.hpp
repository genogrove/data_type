#ifndef GENOGROVE_DATA_TYPE_KEY_TYPE_BASE_HPP
#define GENOGROVE_DATA_TYPE_KEY_TYPE_BASE_HPP

#include <cstddef>

#if __cplusplus >= 202002L
// C++20 with concepts
#include <concepts>

namespace genogrove::data_type {
    template<typename T>
    concept key_type_base = requires (T a, T b) {
        { a < b } -> std::convertible_to<bool>;
        { a <= b } -> std::convertible_to<bool>;
        { a >= b } -> std::convertible_to<bool>;
        { a > b } -> std::convertible_to<bool>;
        { a == b } -> std::convertible_to<bool>;
        { T::left_of(a, b)} -> std::convertible_to<bool>;
        { T::overlap(a,b) } -> std::convertible_to<bool>;
        { a.getStart() } -> std::convertible_to<size_t>;
        { a.getEnd() } -> std::convertible_to<size_t>;
    };

    // helper function for c++20 (with concept constraints)
    template<key_type_base key_type>
    constexpr bool is_key_type_base() {
        return true;
    }
}

#else
// C++17 implementation (uses type traits and SFINAE)
#include <type_traits>

namespace genogrove::data_type {
    template<typename T, typename = void>
    struct is_key_type_base : std::false_type {};

    template<typename T>
    struct is_key_type_base<T, std::void_t<
            decltype(std::declval<bool&>() = std::declval<T>() < std::declval<T>()),
            decltype(std::declval<bool&>() = std::declval<T>() <= std::declval<T>()),
            decltype(std::declval<bool&>() = std::declval<T>() >= std::declval<T>()),
            decltype(std::declval<bool&>() = std::declval<T>() > std::declval<T>()),
            decltype(std::declval<bool&>() = std::declval<T>() == std::declval<T>()),
            decltype(T::left_of(std::declval<T>(), std::declval<T>())),
            decltype(T::overlap(std::declval<T>(), std::declval<T>())),
            decltype(std::declval<size_t&>() = std::declval<T>().getStart()),
            decltype(std::declval<size_t&>() = std::declval<T>().getEnd())
        >> : std::true_type {};

    // helper function for c++17
    template<typename key_type,
                typename = std::enable_if_t<is_key_type_base<key_type>::value, int>>::type = 0>
    constexpr bool is_key_type_base() {
        return true;
    }
}

#endif

#endif //GENOGROVE_DATA_TYPE_KEY_TYPE_BASE_HPP
