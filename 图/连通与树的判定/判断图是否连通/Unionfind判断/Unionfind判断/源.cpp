#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int m, n, x, y;
vector<vector<int>>graph;
vector<int>pa;
int findpa(int x)
{
	if (pa[x] == x) return x;
	else return pa[x] = findpa(pa[x]);
}
void merge(int x, int y)
{
	int pax = findpa(x);
	int pay = findpa(y);
	if (pax != pay) pa[pay] = pax;
}

int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	pa.resize(n + 1);
	for (int i = 0; i <= n; i++) pa[i] = i;//并查集初始化
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);//其实可以不用建图
		merge(x, y);
	}
	bool flag = true;
	for (int i = 2; i <= n; i++) {
		if (findpa(i) != findpa(i - 1)) {
			flag = false;
			break;
		}
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

/*
sample1:
input:
5 6
1 2
1 4
4 2
2 3
4 3
2 5
output:
Yes

sample2:
input:
5 5
1 2
1 4
4 2
2 3
4 3
output:
No
*/