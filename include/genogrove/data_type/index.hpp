/*
 * SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */
#ifndef DATATYPE_INDEX_HPP
#define DATATYPE_INDEX_HPP

// Standard
#include <cstdint>

// Class
#include <genogrove/data_type/index_registry.hpp>

namespace genogrove::data_type {
    class index {
        public:
            index(std::string key);
            ~index();

            /*
             * @ brief returns the name string of the chromosome
             */
            std::string get_key() const;
            uint8_t get_value() const;

        private:
            uint8_t value;
    };
}

#endif //DATATYPE_INDEX_HPP
