#pragma once
#ifndef _UNION_H
#define _UNION_H
class unionfind
{
public:
	int getancestor1(int id, int* p);//�ݹ��ҷ�
	int getancestor2(int id, int* p);//�����ҷ�
	void merge(int x, int y, int* p);//�ϲ�
};
#endif