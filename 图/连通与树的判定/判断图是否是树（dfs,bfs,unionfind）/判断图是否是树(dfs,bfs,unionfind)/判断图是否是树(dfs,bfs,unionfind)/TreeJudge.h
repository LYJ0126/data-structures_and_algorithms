#pragma once
#ifndef _TREEJUDGE_H
#define _TREEJUDGE_H
#include<vector>
class treejudge
{
public:
	bool bfs_judge(std::vector<std::vector<int>>&, int);
	bool dfs_judge(std::vector<std::vector<int>>&, int);
	int findpa(std::vector<int>&, int);
	bool merge(std::vector<int>&, int, int);
	bool unionfind_judge(std::vector<int>&, bool);
};
#endif