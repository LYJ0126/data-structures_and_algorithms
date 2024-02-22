#pragma once
#ifndef _UNION_H
#define _UNION_H
class unionfind
{
public:
	int getancestor1(int id, int* p);//递归找法
	int getancestor2(int id, int* p);//迭代找法
	void merge(int x, int y, int* p);//合并
};
#endif