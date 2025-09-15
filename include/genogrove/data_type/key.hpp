/*
* SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */
#ifndef GENOGROVE_DATA_TYPE_KEY_HPP
#define GENOGROVE_DATA_TYPE_KEY_HPP

// standard
#include <vector>
#include <istream>

// genogrove
#include <genogrove/data_type/any_type.hpp>
#include <genogrove/data_type/type_registry.hpp>

namespace genogrove::data_type {
    /*
     * @brief the key class
     * @details the key class is used to specify keys in any data structure
     */
    template<typename key_type>
    class key {
        public:
            /*
             * @brief default constructor
             */
            key<key_type>() :
                value(key_type()),
                data(nullptr),
                single_link(nullptr),
                multi_link(std::vector<key*>()) {}

            /*
             * @brief Constructor of a key with arbitrary key object
             */
            key(key_type value) :
                value(value),
                data(nullptr),
                single_link(nullptr),
                multi_link(std::vector<key*>()) {}

            template<typename data_type>
            key(key_type kvalue, data_type data) :
                value(kvalue),
                data(std::make_shared<ggt::any_type<std::decay_t<data_type>>>(data)),
                single_link(nullptr),
                multi_link(std::vector<key*>()) {}

            /*
            * @brief destructor
            */
            ~key() = default;

            /*
            * @brief returns the value of the key
            */
            key_type get_value() const { return value; }

            bool operator<(const key_type& other) const;
            bool operator>(const key_type& other) const;

            void serialize(std::ostream& os) const {
                value.serialize(os);
                bool has_data = (data != nullptr); // check if there is data to serialize
                os.write(reinterpret_cast<const char*>(&has_data), sizeof(has_data));

                if(has_data) {
                    std::string type_name = data->get_type_name();
                    size_t type_name_length = type_name.size();
                    os.write(reinterpret_cast<const char*>(&type_name_length), sizeof(size_t));
                    os.write(type_name.c_str(), type_name_length);

                    data->serialize(os);

                    bool has_single_link = (single_link != nullptr);
                    os.write(reinterpret_cast<const char*>(&has_single_link), sizeof(has_single_link));
                    if(has_single_link) {
                        single_link->serialize(os);
                    }

                    size_t multi_link_size = multi_link.size();
                    os.write(reinterpret_cast<const char*>(&multi_link_size), sizeof(multi_link_size));
                    for(auto& link : multi_link) {
                        link->serialize(os);
                    }
                }

            }
            key<key_type> deserialize(std::istream& is) {
                key_type obj = key_type::deserialize(is); // serialize the key object
                key<key_type> key1(obj); // create a new key object (with the key object/value)

                bool has_data;
                is.read(reinterpret_cast<char*>(&has_data), sizeof(has_data));
                if(has_data) {
                    size_t type_name_length;
                    is.read(reinterpret_cast<char*>(&type_name_length), sizeof(type_name_length));
                    std::string type_name(type_name_length, '\0');
                    is.read(&type_name[0], type_name_length);

                    // deserialize the data object
                    key1.data = ggt::type_registry::create(type_name);
                }
            }

        private:
            key_type value;
            std::shared_ptr<ggt::any_base> data;
            key* single_link;
            std::vector<key*> multi_link;



    };
}



#endif //GENOGROVE_DATA_TYPE_KEY_HPP