#ifndef __GRAPH_UTILS_H_
#define __GRAPH_UTILS_H_
#include <vector>
#include <algorithm>

namespace NSGraph
{
	using DefaultAdjancecyList = std::vector<std::vector<int>>;
	using NodeType = int;
	using adjancecyListIterator = DefaultAdjancecyList::iterator;
	using adjancecyListConstIterator = DefaultAdjancecyList::const_iterator;

	class Graph
	{
	public:
		explicit Graph(const DefaultAdjancecyList & adjancecy_list);
		
		DefaultAdjancecyList get_transpose_graph() const;
		
		size_t node_count() const noexcept ;
		
		adjancecyListIterator begin() const;
		adjancecyListIterator end() const;
		
		adjancecyListConstIterator cBegin() const;
		adjancecyListConstIterator cEnd() const;
	private:

		const DefaultAdjancecyList & m_adjancecy_list;
	};
}
#endif