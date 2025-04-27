/*
 * SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */

#ifndef DATATYPE_INTERVAL_HPP
#define DATATYPE_INTERVAL_HPP

// Standard
#include <cstddef>
#include <iostream>
#include <string>
#include <compare>

namespace genogrove::datatype {
    class Interval {
        public:
            Interval();
            Interval(size_t start, size_t end):
            ~Interval();

            /*
             * @brief operator overload for intervals to check if they are non-overlapping (e.g., left-most end < right-most start)
             */
            std::strong_ordering operator<=>(const Interval& other) const;
            /*
             * replaces:
             * bool operator<(const Interval& other) const;
             * bool operator>(const Interval& other) const;
             * bool operator<=(const Interval& other) const;
             * bool operator>=(const Interval& other) const
             */

            /*
             * @brief converts the interval to a string
             */
            std::string toString() const;

            /*
             * @brief Check if the subjected interval is left of the class interval
             */
            bool leftOf(const Interval& other) const;

            static bool overlap(const Interval& a, const Interval& b);

            // getter & setter
            /*
             * @brief Get the start of the interval
             */
            size_t getStart() const;
            /*
             * @brief Get the end of the interval
             */
            void setStart(size_t start);

            /*
             * @brief Get the end of the interval
             */
            size_t getEnd() const;

            /*
             * @brief Get the end of the interval
             */
            void setEnd(size_t end);

            /*
             * @brief Serialize the interval to a stream
             */
            void serialize(std::ostream& os) const;

            /*
             * @brief Deserialize the interval from a stream
             */
            static Interval deserialize(std::istream& is);

        private:
            size_t start;
            size_t end;
    };
}

#endif //DATATYPE_INTERVAL_HPP
