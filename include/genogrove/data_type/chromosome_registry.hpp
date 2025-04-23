/*
 * SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */

#ifndef CHROMOSOME_REGISTRY_HPP
#define CHROMOSOME_REGISTRY_HPP

// Standard
#include <bitset>
#include <unordered_map>
#include <stdexcept>

// Class
#include "../Constants.hpp"

#if __cplusplus >= 202002L
    #include <ranges>
#endif

namespace gcc = genogrove::core::constants;

namespace genogrove::data_type {
    /*
     * @brief Registry class that keeps track of the chromosomes that are used in the data
     */
    class chromosome_registry {
        public:
            /*
             * Singleton to make sure that only one instance of the registry is created
             */
            static chromosome_registry& instance();

            uint8_t register_chrom(const std::string& chrom);
            int8_t is_registered(const std::string& chrom);

            uint8_t chrom_to_index(const std::string& chrom);
            std::string index_to_chrom(uint8_t index);

        private:
            std::unordered_map<std::string, uint8_t> registry;
            uint8_t next_index;
    };
}

#endif // CHROMOSOME_REGISTRY_HPP

