#include <gtest/gtest.h>
#include "../utils/graph_utils.h"



struct GraphTestData : public testing::Test
{
public:
	GraphTestData()
	{
		 
		/*adj_list[0].emplace_back(1);
		adj_list[0].emplace_back(2);
		

		expected_result[1].emplace_back(0);
		expected_result[2].emplace_back(0);*/
					
	}
	virtual void SetUp()
  {
    m_adj_list[0].push_back(1);
    m_adj_list[0].push_back(2);
  }
  virtual void TearDown()
  {
  }
	bool compare_data(const std::vector<std::vector<int>> & transverse_graph)
	{
		bool result = false;
		if(transverse_graph.size() == expected_result.size())
		{
			result = (transverse_graph[0] == expected_result[0] &&
			transverse_graph[1] == expected_result[1]);
		}
		return result;
	}

	std::vector<std::vector<int>> expected_result; 
	std::vector<std::vector<int>> m_adj_list; 
};

TEST_F ( GraphTestData, test_graph_transverse_set_one )
{
	NSGraph::Graph graph(m_adj_list);
	const bool are_equal = compare_data(graph.get_transpose_graph());
	EXPECT_TRUE(are_equal);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
