/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */

// Gtest
#include <gtest/gtest.h>

// genogrove
#include <genogrove/data_type/key.hpp>
#include <genogrove/data_type/interval.hpp>

namespace gdt = genogrove::data_type;

TEST(key_test, constructors) {
 gdt::interval intvl(10, 20);

 // default constructor
 gdt::key<gdt::interval> key1(intvl); // with value
 // check for type_index
 EXPECT_EQ(intvl, key1.get_value());




}


