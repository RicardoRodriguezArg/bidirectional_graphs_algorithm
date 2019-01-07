#ifndef _UTILITY_ALGORITHM_BFS__
#define _UTILITY_ALGORITHM_BFS__

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <queue>

using std::vector;
using std::queue;
using std::numeric_limits;
using std::queue;

namespace NSAlgorithm{
	
	using DefaultAdjancecyList = std::vector<std::vector<int>>;
	using NodeType = int;
	using DistanceVector = std::vector<NodeType>;
	using QueueType = std::queue<NodeType>;
	namespace{
		constexpr int ZERO_DISTANCE_VALUE = 0;
	}

struct BSFAlgorithm
{
	explicit BSFAlgorithm(const DefaultAdjancecyList & input_adjancency_list):adjancency_list(input_adjancency_list)
	{}
	
	
	bool are_connected(const NodeType & source, const NodeType & target)
	{
		bool result {source == target};
		if (!result)
		{
			auto distance_vector = create_distance_matrix();
			distance_vector[0] = ZERO_DISTANCE_VALUE;
			QueueType queue;
			queue.emplace(source);
			while(!queue.empty())
			{
				const NodeType & current_node_index = queue.front();
				queue.pop();
				for(int child_index=0; child_index < adjancency_list[current_node_index].size(); ++child_index)
				{
					int child_node_index = adj[current_node_index][child_index];
				    if(distance_vector[child_node_index] == numeric_limits<int>::max())
				    {
						queue.emplace(child_node_index);
						distance_vector[child_node_index] = distance_vector[current_node_index] + 1;
				  	}	
				}
  			}
  		result = distance_vector[target]!= numeric_limits<int>::max();
  		}
		return result;
	}

	DistanceVector create_distance_matrix() const
	{
		DistanceVector distance(adjancency_list.size(), numeric_limits<int>::max());
		return distance;
  		
	}
	const DefaultAdjancecyList & adjancency_list;

};
}
#endif