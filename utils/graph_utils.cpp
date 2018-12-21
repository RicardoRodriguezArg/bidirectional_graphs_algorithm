#include "graph_utils.h"

Graph::Graph(const DefaultAdjancecyList & adjancecy_list):m_adjancecy_list(adjancecy_list)
{}

DefaultAdjancecyList Graph::Graph::get_transpose_graph() const noexcept
{
	return {};
}

void Graph::Graph::add_edge(const NodeType & source_node, const NodeType & target_node)
{}