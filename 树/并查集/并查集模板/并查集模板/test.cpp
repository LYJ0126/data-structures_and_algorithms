#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include "Union.h"
using namespace std;

int main()
{
	//n个元素，m条关系，求有多少个不相交集合
	int n, m;
	cin >> n >> m;
	int* p = new int[n+1];
	for (int i = 1; i <= n; i++) p[i] = i;
	unionfind uf;
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;//x,y有关系
		uf.merge(x, y, p);//合并
	}
	//下面求不想交集合个数
	unordered_map<int, int>mp;
	for (int i = 1; i <= n; i++) {
		mp[uf.getancestor2(i, p)]++;//注意利用getancestor函数路径压缩
	}
	cout << mp.size();
	return 0;
}