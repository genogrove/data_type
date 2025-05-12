/*
 * SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */

#ifndef GENOGROVE_DATA_TYPE_QUERY_RESULT_HPP
#define GENOGROVE_DATA_TYPE_QUERY_RESULT_HPP

// Standard
#include <vector>
#include <memory>

// genogrove
#include <genogrove/data_type/any_type.hpp>

namespace genogrove::data_type {
    template<typename query_type>
    class query_result {
        public:
            query_result(query_type query);
            void add_result(std::shared_ptr<any_base> result);

            query_type get_query() const;
            std::vector<std::shared_ptr<any_base>> get_results() const;

        private:
            query_type query;
            std::vector<std::shared_ptr<any_base>> results;
    };
}

#endif //GENOGROVE_DATA_TYPE_QUERY_RESULT_HPP
