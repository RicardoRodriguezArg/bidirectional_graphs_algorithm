#ifndef __GRAPH_UTILS_H_
#define __GRAPH_UTILS_H_
#include <vector>
#include <algorithm>

namespace NSGraph
{
	using DefaultAdjancecyList = std::vector<std::vector<int>>;
	using NodeType = int;

	class Graph
	{
	public:
		explicit Graph(const DefaultAdjancecyList & adjancecy_list);
		DefaultAdjancecyList get_transpose_graph() const;
	private:

		const DefaultAdjancecyList & m_adjancecy_list;
	};
}
#endif