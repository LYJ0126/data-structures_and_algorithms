#pragma once
#ifndef _KMP_H
#define _KMP_H
#include<iostream>
#include<cstring>
#include<vector>
class kmp
{
public:
	std::string T, P;
	std::vector<int>compute_prefix_function(std::string& p);//¼ÆËãÇ°×ºº¯Êı
	void kmp_mathcer(std::string& t, std::string& p);//kmpÆ¥Åä
};
#endif