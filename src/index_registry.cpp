#include <genogrove/data_type/index_registry.hpp>

namespace genogrove::data_type {
    index_registry& index_registry::instance() {
        static index_registry instance;
        return instance;
    }

    uint8_t index_registry::register_key(const std::string& key) {
        std::optional<uint8_t> idx = this->encode(key);
        if(idx.has_value()) {
            std::cout << "key " << key << " already registered" << std::endl;
            return idx.value();
        } else {
            uint8_t new_index = this->next_index++;
            this->registry.insert({key, new_index});
            return new_index;
        }
    }

    std::string index_registry::retrieve_key(uint8_t value) {
        std::optional<std::string> key = this->decode(value);
        if(key.has_value()) {
            return key.value();
        } else {
            throw std::runtime_error("key not found");
        }
    }

    std::optional<uint8_t> index_registry::encode(const std::string& key) {
#if __cplusplus >= 202002L // C++20
        if(registry.contains(key)) ? return registry.at(key) : std::nullopt;
#else // C++17
        auto it = this->registry.find(key);
        if(it != this->registry.end()) ? return it->second : std::nullopt;
#endif
    }

    std::optional<std::string> index_registry::decode(uint8_t value) {
#if __cplusplus >= 202002L // C++20
        auto it = std::ranges::find_if(this->registry, [&](const auto& pair) {
            return pair.second == value;
        });
        if(it != this->registry.end()) ? return it->first : std::nullopt;
#else // C++17
        for(auto& pair : this->registry) {
            if(pair.second == value) {
                return pair.first;
            }
        }
        return std::nullopt;
#endif

    }
