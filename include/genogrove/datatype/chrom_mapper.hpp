/*
 * SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */

#ifndef CORE_CHRMS_HPP
#define CORE_CHRMS_HPP

// Standard
#include <bitset>
#include <unordered_map>
#include <stdexcept>

// Class
#include "Constants.hpp"

namespace gcc = genogrove::core::constants;

namespace genogrove::core {
    namespace data_type {

        class chrom_mapper {
        public:
            Chrms();
            ~Chrms() = default;

            uint8_t registerChrm(const std::string& chrm);
            std::string getChrm(const uint8_t& chrm);


//            std::bitset<ggt::MAX_CHRM_BITS> registerChrm(const std::string& chrm);
//            std::bitset<ggt::MAX_CHRM_BITS> getNextBitset() const;
//            std::bitset<ggt::MAX_CHRM_BITS> getBitset(const std::String& chrm) const;

        private:
            std::unordered_map<std::string, uint8_t> chrms;
            uint8_t maxValue;
        };
    }
}



#endif //CORE_CHRMS_HPP
