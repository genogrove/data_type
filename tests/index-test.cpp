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
#include <genogrove/data_type/index.hpp>
#include <genogrove/data_type/index_registry.hpp>

namespace gdt = genogrove::data_type;

TEST(chromosome_test, chromsome) {
    gdt::index chr1("chr1");
    gdt::index chr2("chr2");
    gdt::index chr3("chr3");

    // test that the chromosomes are created
    EXPECT_EQ(chr1.get_value(), 0);
    EXPECT_EQ(chr2.get_value(), 1);
    EXPECT_EQ(chr3.get_value(), 2);
}
