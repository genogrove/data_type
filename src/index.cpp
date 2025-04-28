#include <genogrove/data_type/chromosome.hpp>

namespace genogrove::data_type {
    index::index(std::string key) {
        // register this type with the data type registry
        index_registry::instance().register_key(name);
    }

    std::string chromosome::get_key() const {
        chromosome_registry::instance().value_to_key(this->value);
    }

    uint8_t chromosome::get_value() const {
        return this->value;
    }
}