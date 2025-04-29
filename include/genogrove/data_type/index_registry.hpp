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
#include <cstdint>
#include <unordered_map>
#include <stdexcept>
#include <optional>
#include <iostream>

// Class
#include "constants.hpp"

#if __cplusplus >= 202002L
    #include <ranges>
#endif

namespace genogrove::data_type {
    /*
     * @brief Registry class that keeps track of the chromosomes that are used in the data
     */
    class index_registry {
        public:
            /*
             * Singleton to make sure that only one instance of the registry is created
             */
            static index_registry& instance();
            uint8_t register_key(const std::string& key);

            /*
             * @brief retrieves the key for a given index - throws std::runtime_error if the index is not in the registry
             */
            std::string retrieve_key(uint8_t value);

            /*
             * @brief Encodes the key into a value - return std::nullopt if the key is not in the registry
             */
            std::optional<uint8_t> encode(const std::string& key);

            /*
             * @brief Decodes the value into a key - returns std::nulopt if the value is not in the registry
             */
            std::optional<std::string> decode(uint8_t value);

        private:
            std::unordered_map<std::string, uint8_t> registry;
            uint8_t next_index;
    };
}

#endif // CHROMOSOME_REGISTRY_HPP

