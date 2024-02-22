#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include "KMP.h"
using namespace std;

int main()
{
	kmp sample;
	cin >> sample.T >> sample.P;
	sample.kmp_mathcer(sample.T, sample.P);
	return 0;
}

/*
bacbababaabcbab
aba
*/