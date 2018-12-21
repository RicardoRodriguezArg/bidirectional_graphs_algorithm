#include "graph_utils.h"

NSGraph::Graph(const DefaultAdjancecyList & adjancecy_list):m_adjancecy_list(adjancecy_list)
{}

DefaultAdjancecyList NSGraph::Graph::get_transpose_graph() const noexcept
{
	DefaultAdjancecyList transpose_graph:
	transpose_graph.reserve(m_adjancecy_list.size());
	int current_index = 0;
	std::for_each(std::begin(m_adjancecy_list), std::end(m_adjancecy_list), [&current_index, transpose_graph](const std::vector<int> & adjancecy_vertex)
		{
			for (const auto & vertex : adjancecy_vertex)
			{
			 transpose_graph[vertex].emplace_back(current_index);	
			}
			++current_index;
		}
		);
	return transpose_graph;
}
