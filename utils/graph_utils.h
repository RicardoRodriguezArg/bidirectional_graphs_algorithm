#ifndef __GRAPH_UTILS_H_
#define __GRAPH_UTILS_H_
#include <vector>

namespace Graph
{

	class Graph
	{
	public:
		using DefaultAdjancecyList = std::vector<int, std::vector<int>>;
		using NodeType = int;
		explicit Graph(const DefaultAdjancecyList & adjancecy_list);
		DefaultAdjancecyList get_transpose_graph() const noexcept;
	private:
		void add_edge(const NodeType & source_node, const NodeType & target_node);
		const DefaultAdjancecyList & m_adjancecy_list;
	};
}
#endif