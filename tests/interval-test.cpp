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

// Genogrove
#include <genogrove/data_type/interval.hpp>

namespace gdt = genogrove::data_type;

TEST(interval_test, interval_operators) {
    gdt::interval intvl1(20, 30);
    gdt::interval intvl2(20, 30);

    // test operator==
    EXPECT_TRUE(intvl1 == intvl2);
    EXPECT_FALSE(intvl1 != intvl2);

    // test operator< and operator>
    gdt::interval intvl3(10, 20);
    gdt::interval intvl4(10, 25);
    gdt::interval intvl5(15, 30);

    EXPECT_TRUE(intvl3 < intvl4);
    EXPECT_FALSE(intvl3 > intvl4);
    EXPECT_TRUE(intvl3 < intvl5);
    EXPECT_FALSE(intvl3 > intvl5);

}
