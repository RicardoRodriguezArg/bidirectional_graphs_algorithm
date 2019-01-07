#include "graph_utils.h"

namespace NSGraph{
Graph::Graph(const DefaultAdjancecyList & adjancecy_list):m_adjancecy_list(adjancecy_list)
{}

DefaultAdjancecyList Graph::get_transpose_graph() const
{
	DefaultAdjancecyList transpose_graph;
	transpose_graph.reserve(m_adjancecy_list.size());
	int current_index = 0;
	std::for_each(std::begin(m_adjancecy_list), std::end(m_adjancecy_list), [&current_index, &transpose_graph](const std::vector<int> & adjancecy_vertex)
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

size_t Graph::node_count() const noexcept
{
	return m_adjancecy_list.size();
}

adjancecyListIterator Graph::begin() const
{
	return m_adjancecy_list.begin();
}

adjancecyListIterator Graph::end() const
{
	return m_adjancecy_list.end();	
}

adjancecyListConstIterator Graph::cBegin() const
{
	return m_adjancecy_list.cbegin();
}

adjancecyListConstIterator Graph::cEnd() const;
{
	return m_adjancecy_list.cend();
}

}