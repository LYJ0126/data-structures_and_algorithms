#pragma once
#include<vector>
class bipartite_graph_judge
{
public:
	bool dfsbpt(std::vector<std::vector<int>>&, std::vector<int>&, std::vector<bool>&, int);
	bool bfsbpt(std::vector<std::vector<int>>&, std::vector<int>&);
};