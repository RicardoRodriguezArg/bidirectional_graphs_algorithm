#include <gtest/gtest.h>
#include <algorithm>
#include "../utils/graph_utils.h"



struct GraphTestData : public testing::Test
{
public:
	GraphTestData()
	{
	}

	virtual void SetUp()
  {
    m_adj_list[0].push_back(1);
    m_adj_list[0].push_back(2);
    //expected result
    expected_result[1].emplace_back(0);
	expected_result[2].emplace_back(0);
  }

  std::vector<std::vector<int>>&& setup_for_test_two()
  {
  	std::vector<std::vector<int>> test_set_two;
  	test_set_two[0].emplace_back(1);
  	test_set_two[0].emplace_back(4);
  	test_set_two[0].emplace_back(3);
  	test_set_two[2].emplace_back(0);
    test_set_two[3].emplace_back(2);
    test_set_two[4].emplace_back(1);
    test_set_two[4].emplace_back(3);
    return std::move(test_set_two);
  }

  std::vector<std::vector<int>>&& setup_for_expected_set_two()
  {
  	
  	std::vector<std::vector<int>> test_set_two;
  	test_set_two[0].emplace_back(2);
  	test_set_two[1].emplace_back(0);
  	test_set_two[2].emplace_back(3);
  	test_set_two[3].emplace_back(0);
    test_set_two[3].emplace_back(4);
    test_set_two[4].emplace_back(0);
    test_set_two[1].emplace_back(4);
    return std::move(test_set_two);
  }

	void setup_for_expected_set_three()
	{
		expected_result.clear();
		expected_result[0].emplace_back(1);
		expected_result[0].emplace_back(2);
		expected_result[3].emplace_back(4);
		expected_result[5].emplace_back(6);
	}

	std::vector<std::vector<int>>&& setup_for_test_three()
	{
		std::vector<std::vector<int>> test_set;
		test_set[1].emplace_back(0);
		test_set[2].emplace_back(0);
		test_set[4].emplace_back(3);
		test_set[6].emplace_back(5);
		return std::move(test_set);
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
	const auto transposed_set = graph.get_transpose_graph();
	const bool are_equal = std::equal(expected_result.begin(), expected_result.end(), transposed_set.begin());
	EXPECT_TRUE(are_equal);
}

TEST_F ( GraphTestData, test_graph_transverse_set_two )
{
	NSGraph::Graph graph(setup_for_test_two());
	const auto expected_set = setup_for_expected_set_two();
	const auto transposed_set = graph.get_transpose_graph();
	const bool are_equal = std::equal(expected_set.begin(), expected_set.end(), transposed_set.begin());
	EXPECT_TRUE(are_equal);
}

TEST_F ( GraphTestData, test_graph_transverse_set_three )
{
	NSGraph::Graph graph(setup_for_test_two());
	setup_for_expected_set_three();
	const auto transposed_set = graph.get_transpose_graph();
	const bool are_equal = std::equal(expected_result.begin(), expected_result.end(), transposed_set.begin());
	EXPECT_TRUE(are_equal);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
