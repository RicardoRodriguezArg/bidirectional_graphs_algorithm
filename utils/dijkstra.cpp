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
            const int child_node_index = adjancency_list.at(current_node_index).at(child_index);
            if ((distance_vector.at(child_node_index) == NSConstants::INFINITY_VALUE) ||  (color_map[child_node_index] == NodeColor::Grey))
            {
            queue.push(child_node_index);
            distance_vector[child_node_index] = distance_vector[current_node_index] + 1;
            color_map[child_node_index] = NodeColor::Grey;
            }
            else if ((color_map.at(child_node_index)==NodeColor::Black))
            {
              has_cycle = true;
              //break;
            }
        }
        color_map[current_node_index] = NodeColor::Black;
      }

      result = distance_vector.at(target)!= NSConstants::INFINITY_VALUE;
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

//===================================================================
class Graph{
  public:
    using CostType = int;
    using PrecessorType = int;
    using NodeType = int;
    using CostNodeTuple = std::tuple<NodeType, CostType>;
    using DistanceMatrixType = std::vector< CostType >;
    explicit Graph(const AdjacencyListType & input_list, const std::vector<std::vector<int> > & input_cost_list):adjancecy_list(input_list),
                                                          cost_list(input_cost_list)
    {
      
    }
    
    struct QueueComparator{
      bool operator()(const CostNodeTuple & left, const CostNodeTuple & right)
      {
        return std::get<1>(left) < std::get<1>(right);
      }
    };

bool has_negative_cycle()
    {
      DistanceMatrixType distance_cost_matrix (cost_list.size(), static_cast<int>(NSConstants::INFINITY_VALUE));
      distance_cost_matrix[0] = ZERO_DISTANCE_VALUE;
      bool has_negative_cycle = false;
      for (int iteration = 0; iteration < adjancecy_list.size(); ++iteration)
      {
        for(int u = 0; u < adjancecy_list.size(); ++u)
        {
          for (int k = 0; k < adjancecy_list[u].size(); ++k)
          {
            const int & v = adjancecy_list[u][k];
            const int & relaxation_value = distance_cost_matrix[u] + cost_list[u][k];
            if(distance_cost_matrix[v] > relaxation_value ) 
            {
                distance_cost_matrix[v] = relaxation_value;
                if(iteration == adjancecy_list.size() - 1)
                {
                  has_negative_cycle = true;
                  break;
                }
                
              }
            }
          }
        
      }
      return has_negative_cycle;
}


int shortest_path(const int & source, const int & target)
{
  int result = 0;
  if (source == target) 
    return result;
  if (!is_valid_node(source))
    return -1;
  std::vector<int> distance_node(adjancecy_list.size(), static_cast<int>(NSConstants::INFINITY_VALUE) );
  distance_node[source] = 0 ;
  queue.emplace(std::make_tuple(source, 0));
  while(!queue.empty())
  {
    const auto & current_node = queue.top();
    queue.pop();
    const NodeType & current_node_index = std::get<0>(current_node);
    const auto & sub_node_vector = adjancecy_list.at(current_node_index);
    const auto & sub_node_cost = cost_list.at(current_node_index);
    const int & current_distance_cost = distance_node.at(current_node_index);
    for(NodeType index = 0; index < sub_node_vector.size(); ++index)
    {
      const auto & child_index = sub_node_vector.at(index);
      const int relaxation_value =  current_distance_cost + sub_node_cost.at(index);

      if ((distance_node.at(child_index) > relaxation_value) )
      {
        distance_node[child_index]= relaxation_value;
        queue.emplace(std::make_tuple(child_index, relaxation_value));
        //visited[child_index] = true;
      }
    
    }
    
  }
  try{
      const auto & target_distance = distance_node.at(target);
      result = target_distance == static_cast<int>(NSConstants::INFINITY_VALUE) ? -1 : target_distance ;  
      }
      catch(...)
      {
        result = -1 ;
      }
  
  return result;
}


private:

  bool is_valid_node(const NodeType & node)
  {
    return node < adjancecy_list.size();
  }

std::priority_queue<std::tuple<NodeType, int>,std::vector<std::tuple<NodeType, int>>, QueueComparator> queue;

const vector<vector<int> > & cost_list;
const AdjacencyListType & adjancecy_list;
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  BSFAlgorithm bsf(adj);
  int result = -1;
  if(bsf.are_connected(s,t))
  {
      Graph graph(adj, cost);
      if(!graph.has_negative_cycle())
      {
        result = graph.shortest_path(s,t);
        
      }
        
      
  }
  
  return result;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
