#include <genogrove/data_type/index.hpp>

namespace genogrove::data_type {
    index::index(std::string key) {
        // register this type with the data type registry
        index_registry::instance().register_key(key);
    }

    std::string index::get_key() const {
        return index_registry::instance().retrieve_key(this->value);
    }

    uint8_t index::get_value() const {
        return this->value;
    }
}