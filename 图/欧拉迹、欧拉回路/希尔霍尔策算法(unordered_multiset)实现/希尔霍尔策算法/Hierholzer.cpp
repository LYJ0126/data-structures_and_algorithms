#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//此处利用STL工具unordered_multiset
unordered_multiset<int>vertex[100009];
int n, m, x, y, t = 0;
int path[2000010];
int deg[100009], odd = 0, start = -1;
void findpath(int u)
{
	while (vertex[u].begin() != vertex[u].end()) {
		unordered_multiset<int>::iterator it = vertex[u].begin();
		int v = *it;
		vertex[u].erase(it);
		vertex[v].erase(vertex[v].find(u));
		findpath(v);
	}
	path[++t] = u;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		vertex[x].insert(y);
		vertex[y].insert(x);
		deg[x]++;
		deg[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] & 1) {
			if (start == -1) start = i;
			odd++;
		}
	}
	if (odd > 2) {
		printf("NO");
		return 0;
	}
	if (odd == 0) start = 1;
	printf("YES\n");
	findpath(start);
	for (int i = t; i > 0; i--) printf("%d ", path[i]);
	return 0;
}

/*
input:
6 7
1 2
2 3
3 4
4 2
5 2
6 5
6 1
output:
YES
1 2 3 4 2 5 6 1
*/
/*
input:
6 8
1 2
2 3
3 4
4 2
5 2
6 5
6 1
5 1
output:
YES
1 2 3 4 2 5 6 1 5
*/
/*
5 5
1 2
2 4
3 2
3 4
5 3
output:
NO
*/