#ifndef _UTILITY_ALGORITHM_BFS__
#define _UTILITY_ALGORITHM_BFS__

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <limits>
#include <algorithm>
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

namespace NSAlgorithm{
	
	namespace{
    constexpr int ZERO_DISTANCE_VALUE = 0;
    }
	
	namespace NSConstants
	{
		static  const int INFINITY_VALUE  =  std::numeric_limits<int>::max();
		static  const int NO_PREDECESSOR  = -1;
		static  const int NULL_PREDECESSOR  = 0;
	}

	using NodeType = int;
	using AdjacencyListType = std::vector<std::vector<NodeType>>;
	using DistanceVector = std::vector<NodeType>;
	using QueueType = std::queue<NodeType>;

	struct BSFAlgorithm
	{
	  enum class NodeColor{
	    White,
	    Black,
	    Grey
	  };

	  explicit BSFAlgorithm(const AdjacencyListType & input_adjancency_list):adjancency_list(input_adjancency_list)
	  ,has_cycle(false)
	  {
	    for (int index = 0; index < adjancency_list.size();++index)
	      color_map.insert(std::make_pair(index, NodeColor::White));
	  }
	  
	  
	  bool are_connected(const NodeType & source, const NodeType & target)
	  {
	    bool result {source == target};
	    if (!result)
	    {
	      auto distance_vector = create_distance_matrix();
	      QueueType queue;
	      queue.push(source);
	      while(!queue.empty())
	      {
	        const NodeType & current_node_index = queue.front();
	        queue.pop();
	        for(int child_index=0; child_index < adjancency_list[current_node_index].size(); ++child_index)
	        {
	            const int child_node_index = adjancency_list[current_node_index][child_index];
	            if ((distance_vector[child_node_index] == NSConstants::INFINITY_VALUE) ||  (color_map[child_node_index] == NodeColor::Grey))
	            {
	            queue.push(child_node_index);
	            distance_vector[child_node_index] = distance_vector[current_node_index] + 1;
	            color_map[child_node_index] = NodeColor::Grey;
	            }
	            else if ((color_map[child_node_index]==NodeColor::Black))
	            {
	              has_cycle = true;
	              //break;
	            }
	        }
	        color_map[current_node_index] = NodeColor::Black;
	      }

	      result = distance_vector[target]!= NSConstants::INFINITY_VALUE;
	      }
	    return result;
	  }

	  bool has_cycles() const
	  {
	    return has_cycle;
	  }

	  DistanceVector create_distance_matrix() const
	  {
	    DistanceVector distance(adjancency_list.size(), NSConstants::INFINITY_VALUE);
	    return distance;
	      
	  }
	  const AdjacencyListType & adjancency_list;
	  std::unordered_map<int,NodeColor > color_map;
	  bool has_cycle;

	};
}
#endif