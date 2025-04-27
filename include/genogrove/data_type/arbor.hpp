/*
 * SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */
#ifndef DATATYPE_CHROMOSOME_HPP
#define DATATYPE_CHROMOSOME_HPP

// Standard

// Class
#include <genogrove/data_type/chromosome_registry.hpp>

namespace genogrove::data_type {
    class chromosome {
        public:
            chromosome(std::string name);
            ~chromosome();

            /*
             * @ brief returns the name string of the chromosome
             */
            std::string get_name() const;
            uit8_t get_index() const;

        private:
            uint8_t chromosome_index;
    };
}

#endif //DATATYPE_CHROMOSOME_HPP
