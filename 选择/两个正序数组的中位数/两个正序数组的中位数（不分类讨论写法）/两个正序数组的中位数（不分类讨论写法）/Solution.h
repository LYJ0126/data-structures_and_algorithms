#pragma once
#ifndef _Solution_H_
#define _Solution_H_
#include<vector>
using namespace std;
class Solution
{
private:
	int findKth(vector<int>&, int i, vector<int>&, int j, int k);
public:
	double findMedianSortedArrays(vector<int>&, vector<int>&);
};
#endif