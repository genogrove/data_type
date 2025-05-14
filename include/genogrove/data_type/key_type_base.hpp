#ifndef GENOGROVE_DATA_TYPE_KEY_TYPE_BASE_HPP
#define GENOGROVE_DATA_TYPE_KEY_TYPE_BASE_HPP

#include <cstddef>

#if __cplusplus >= 202002L
#include <concepts>

namespace genogrove::data_type {
    template<typename T>
    concept key_type_base = requires (T a, T b) {
        { a < b } -> std::convertible_to<bool>;
        { a > b } -> std::convertible_to<bool>;
        { a == b } -> std::convertible_to<bool>;
        { T::left_of(a, b)} -> std::convertible_to<bool>;
        { T::overlap(a,b) } -> std::convertible_to<bool>;
        { a.getStart() } -> std::convertible_to<size_t>;
        { a.getEnd() } -> std::convertible_to<size_t>;
    };
}

#else
#include <type_traits>





#endif










#endif //GENOGROVE_DATA_TYPE_KEY_TYPE_BASE_HPP
