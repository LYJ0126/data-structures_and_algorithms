#pragma once
#include<vector>
class find_cut_point
{
public:
	void dfscv(std::vector<std::vector<int>>&, int, int&,std::vector<int>&, std::vector<int>&, 
		std::vector<bool>&, std::vector<int>&, std::vector<int>&,std::vector<bool>& iscut);
};