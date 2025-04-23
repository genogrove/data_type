#include <genogrove/data_type/chromosome.hpp>

namespace genogrove::data_type {
    chromosome::chromosome(std::string name) {
        // register this type with the data type registry
        chromosome_registry::instance().register_type(name);
    }

    std::string chromosome::get_name() const {
        chromosome_registry::instance().index_to_chrom(this->chromosome_index);
    }
}