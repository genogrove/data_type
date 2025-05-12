#include <genogrove/data_type/query_result.hpp>

namespace genogrove::data_type {
    template<typename query_type>
    query_result<query_type>::query_result(query_type query) : query{},
        results(std::vector<std::shared_ptr<any_base>>{}) {}

    template<typename query_type>
    query_type query_result<query_type>::get_query() const {
        return this->query;
    }

    template<typename query_type>
    std::vector<std::shared_ptr<any_base>> query_result<query_type>::get_results() const {
        return this->results;
    }
}

