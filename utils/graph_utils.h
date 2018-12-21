#ifndef __GRAPH_UTILS_H_
#define __GRAPH_UTILS_H_
#include <vector>

namespace NSGraph
{

	class Graph
	{
	public:
		using DefaultAdjancecyList = std::vector<std::vector<int>>;
		using NodeType = int;
		explicit Graph(const DefaultAdjancecyList & adjancecy_list);
		DefaultAdjancecyList get_transpose_graph() const noexcept;
	private:

		const DefaultAdjancecyList & m_adjancecy_list;
	};
}
#endif