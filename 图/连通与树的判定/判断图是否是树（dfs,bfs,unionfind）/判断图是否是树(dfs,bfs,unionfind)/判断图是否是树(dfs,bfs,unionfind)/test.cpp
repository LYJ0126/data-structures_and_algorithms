#include<iostream>
#include<cstring>
#include "TreeJudge.h"
using namespace std;

int n, m, x, y;
vector<vector<int>>graph;
vector<int>pa;//���ڲ��鼯������
bool flag = false;//�ж��Ƿ���Ȧ
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	pa.resize(n + 1);
	treejudge ss;
	for (int i = 0; i <= n; i++) pa[i] = i;//��ʼ��
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		//����ѡ������ͼ
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
		if (ss.merge(pa, x, y)) flag = true;
	}
	//�ж�ͼ�Ƿ�����
	cout << boolalpha << ss.bfs_judge(graph, 1) << endl;
	cout << boolalpha << ss.dfs_judge(graph, 1) << endl;
	cout << boolalpha << ss.unionfind_judge(pa, flag) << endl;
	return 0;
}
/*
sample1:
input:
5 4
1 2
2 3
4 3
5 2
output:
true
*/

/*
* sample2:
intput:
5 5
1 2
2 3
4 3
3 1
2 5
output:
false
*/