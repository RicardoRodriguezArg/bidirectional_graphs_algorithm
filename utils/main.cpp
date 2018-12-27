#include "graph_utils.h"

int main()
{
	std::vector<std::vector<int>> adj_list;
	adj_list[0].push_back(1);
    adj_list[0].push_back(2);
	NSGraph::Graph graph(adj_list);
	return 0;
}
