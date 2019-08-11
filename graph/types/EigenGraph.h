//
// Created by yash on 8/6/19.
//

#pragma once

#include <vector>
#include "../pfl_graph.h"
#include "../../common/data_types.h"


namespace pfl::graph
{


template<typename Graph>
class eigen_graph
{
public:
    using graph_type = Graph;
    using data_type = typename Graph::Scalar;
    using node_type = pfl::common::NodeIndex2d;

    eigen_graph(const graph_type &graph): graph_(graph), rows_(graph.rows()), cols_(graph.cols())
    {
    }


    /// Func is applied to each adjacent node of the current node
    /// @tparam Func
    template<typename Func>
    void for_each_adjacent_node(const node_type &node, Func &&func) const;


    /// Func is applied to all the nodes in the graph
    /// @tparam Func
    template<typename Func>
    void for_each_node(Func &&func) const
    {
        for(size_t col=0; col < cols_; col++)
        {
            for(size_t row=0; row < rows_; row++)
            {
                func(pfl::common::NodeIndex2d{row, col, graph_(cols_, rows_)});
            }
        }

    }


private:
    graph_type graph_;
    size_t rows_;
    size_t cols_;
};


}

#include "EigenGraph_impl.h"