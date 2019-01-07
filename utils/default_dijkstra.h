#ifndef __DEFAULT_DIJKSTRA_ALGORITHM_H_
#define __DEFAULT_DIJKSTRA_ALGORITHM_H_
#include <unordered_map>
#include <limits>
#include <vector>
#include <tuple>
#include <functional>
#include <queue>

namespace NSAlgorithm{
	namespace 
	{
		constexpr int ZERO_NODE_COST = 0;
		constexpr int INFINITY_VALUE = std::numeric_limits<unsigned>::max();
	}
	using NodeType = int ;
	using CostType = int;
	using MatrixCostType = std::vector<std::vector<CostType> >;
	using DefaultGraphType = std::vector<std::vector<NodeType> >;
	using DistanceMatrixType = std::vector< CostType >;
	using CostNodeTuple = std::tuple<NodeType, NodeType>;
	



	template<class Graph = DefaultGraphType>
	struct Dijkstra
	{
		using shortestPathContainnerType = std::unordered_map<NodeType, NodeType>;
		using CostMatrixType = std::unordered_map<NodeType, NodeType>;
		template<typename Comparator>
    	using GraphPriorityQueueType = std::priority_queue<CostNodeTuple, std::vector<CostNodeTuple>, Comparator>;
		struct QueueComparator{
			bool operator()(const CostNodeTuple & left, const CostNodeTuple & right)
			{
				return std::get<1>(left) < std::get<1>(right);
			}
		};

		explicit Dijkstra(const Graph & input_graph, const MatrixCostType & input_cost_matrix):graph(input_graph),
		cost_matrix(input_cost_matrix)
		{
		}
		
		
		CostType get_cost_between_nodes(const NodeType & source_node, const NodeType & target_node)
		{
			init();
			DistanceMatrixType distance_cost_matrix (cost_matrix.size(), INFINITY_VALUE);
			distance_cost_matrix[source_node] = ZERO_NODE_COST;
			fill_queue( source_node, ZERO_NODE_COST);
			//set initial node cost node to zero
			
			while(!queue.empty())
			{
				const auto & current_node = queue.top();
				queue.pop();
				const NodeType current_node_index = std::get<0>(current_node);
				for (int child_index = 0; child_index < graph[current_node_index].size(); ++child_index)
				{
					const NodeType & child_node = graph[current_node_index][child_index];
					//Relaxation of the nodes
					const int & relaxation_cost = cost_matrix[current_node_index][child_index] + distance_cost_matrix[current_node_index];
					if(cost_matrix[child_node][child_index] < relaxation_cost )
					{
						distance_cost_matrix[child_node] = 	relaxation_cost;
						fill_queue( child_node, relaxation_cost);
					}
				}
			}
			const int & result_value = distance_cost_matrix[target_node];
			return (result_value == INFINITY_VALUE )? -1 : result_value;
		}


		void calculate_shortest_path(const NodeType & SourceNode, const NodeType & TargetNode)
		{

		}

	private:
		
		void fill_queue(const NodeType & node, const CostType & cost)
		{
			queue.emplace(std::make_tuple(node, cost));
		}

		
		void init() noexcept
		{
			queue = GraphPriorityQueueType<QueueComparator>{};
			
		}

		const Graph & graph;
		const MatrixCostType & cost_matrix;
		GraphPriorityQueueType<QueueComparator> queue;
		//RelaxationFunctor relaxator;
		shortestPathContainnerType shortest_path;
	};
	using DefaultDijkstra = Dijkstra<DefaultGraphType>;
	
}
#endif