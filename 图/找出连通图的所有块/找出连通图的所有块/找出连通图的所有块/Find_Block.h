#pragma once
#include<vector>
#include<stack>
class find_block
{
public:
	void dfsblk(std::vector<std::vector<int>>&, int, int&, std::vector<int>&, std::vector<int>&, std::vector<bool>&,
		std::stack<std::pair<int, int>>&, std::vector<int>&, std::vector<int>&,int&);
};