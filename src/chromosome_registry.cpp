#include <genogrove/data_type/chromosome/chromosome_registry.hpp>

namespace genogrove::data_type {

    chromosome_registry& chromosome_registry::instance() {
        static chromosome_registry instance;
        return instance;
    }

    uint8_t Chroms::register_chrom(const std::string& chrom) {
        int8_t index = this->is_registered(chrom);
        if(idx != -1) {
            // system message (but not an error)
            std::cout << "Chromosome " << chrom << " already registered" << std::endl;
            return index;
        } else {
            // create a new index
            uint8_t new_index = this->next_index++;
            this->registry.insert({chrom, new_index});
            return new_index;
    }

        int8_t chromosome_registry::is_registered(const std::string& chrom) {
#if __cplusplus >= 202002L // C++20
            if(registry.contains(chrom)) {
                return chrom_to_index(chrom);
            } else {
                return -1;
            }
        }
#else // C++17
            auto it = this->registry.find(chrom);
            if (it != this->registry.end()) {
                return it->second;
            } else {
                return -1;
            }
#endif
        }

        uint8_t chromosome_registry::chrom_to_index(const std::string& chrom) {
#if __cplusplus >= 202002L // C++20
            if(registry.contains(chrom)) {
                return registry.at(chrom);
            } else {
                throw std::runtime_error("chromosome " + chrom + " not found");
            }
#else // C++17
            auto it = this->registry.find(chrom);
            if (it != this->registry.end()) {
                return it->second;
            } else {
                throw std::runtime_error("chromosome " + chrom + " not found");
            }
        }
#endif

        std::string chromosome_registry::index_to_chrom(uint8_t index) {
#if __cplusplus >= 202002L // C++20
            auto it = std::ranges::find_if(this->registry, [&](const auto& pair) {
                return pair.second == index;
            }
            if(it != this->registry.end()) {
                return it->first;
            }
            throw std::runtime_error("index " + std::to_string(index) + " not found");
#else // C++17
            for(auto& pair : this->registry) {
                if(pair.second == index) {
                    return pair.first;
                }
            }
            throw std::runtime_error("index " + std::to_string(index) + " not found");
#endif
    })

}
