/*
 * SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */

// Google Test
#include <gtest/gtest.h>

// Standard
#include <string>

// genogrove
#include <genogrove/data_type/query_result.hpp>
#include <genogrove/data_type/interval.hpp>

namespace gdt = genogrove::data_type;

TEST(query_result_test, constructor) {
    // Create a query result object, lets assume the query in an interval
    gdt::interval intvl(10, 20);
    gdt::query_result<gdt::interval> qres(intvl); // initialize with query (aka interval)

    // constructor
    EXPECT_EQ(qres.get_query(), intvl); // check if query is set correctly
    EXPECT_TRUE(qres.get_keys().empty()); // check if keys are empty

    // Add some element (ideally that would be keys - but lets use intervals here)
    gdt::interval key1(15, 25);
    gdt::interval key2(5, 12);
    gdt::interval key3(30, 40);
    qres.add_key(&key1);
    qres.add_key(&key2);
    qres.add_key(&key3);

    // check if keys are added correctly
    auto keys = qres.get_keys();
    ASSERT_EQ(keys.size(), 3);
    EXPECT_EQ(*keys[0], key1);
    EXPECT_EQ(*keys[1], key2);
    EXPECT_EQ(*keys[2], key3);

}