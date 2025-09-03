#include <genogrove/data_type/query_result.hpp>

namespace genogrove::data_type {
    template<typename query_type, typename key_type>
    query_result<query_type, key_type>::query_result(query_type query) : query{}, keys{} {}

    template<typename query_type, typename key_type>
    query_type query_result<query_type, key_type>::get_query() const {
        return this->query;
    }

    template<typename query_type, typename key_type>
    void query_result<query_type, key_type>::add_result(key_type* key) {
        this->keys.push_back(key);
    }

    template<typename query_type, typename key_type>
    std::vector<key_type*> query_result<query_type, key_type>::get_results() const {
        return this->keys;
    }
}

