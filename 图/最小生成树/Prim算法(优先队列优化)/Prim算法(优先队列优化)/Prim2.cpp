#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

//����������Ϊͼ����ͨ��,��һ����������
int n, m, x, y, w;
vector<vector < pair<int, int>>>graph;
vector<bool>vis;
bool cmp(pair<int, int>& a, pair<int, int>& b)//��С�ѱȽϺ���
{
	return a.second > b.second;
}
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)>pq(cmp);
//pair�е�һ��������λ��parent,��λ��õ�;�ڶ����������Ȩ
//prim�㷨(���ȶ����Ż�)
void prim()
{
	//ȡ����һ���㿪ʼ��չ������ѡ1
	pq.push(make_pair(1, 0));
	int pointleft = n;//ʣ��ĵ���
	int ans = 0;
	vector<pair<int, int>>::iterator it;
	cout << "��С������:\n";
	while (pointleft) {
		while (vis[pq.top().first & 0x00003fff]) pq.pop();//�����еĵ��Ѿ���������,���߻����������ȶ����У���Ҫ����
		int parent = (pq.top().first>>14), u=(pq.top().first&0x00003fff), v, weight;
		ans += pq.top().second;
		pq.pop();
		vis[u] = true;
		--pointleft;
		if (u != 1) {
			cout << "( " << parent << " , " << u << " )\n";
		}
		for (it = graph[u].begin(); it != graph[u].end(); it++) {
			v = it->first;
			weight = it->second;
			if (!vis[v]) {
				pq.push(make_pair((u << 14) + v, weight));
			}
		}
	}
	cout << "��С������Ȩ��:" << ans << endl;
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	vis.resize(n + 1, false);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> w;
		graph[x].push_back(make_pair(y, w));
		graph[y].push_back(make_pair(x, w));
	}
	prim();
	return 0;
}

/*
input:
7 11
1 2 7
1 4 5
2 4 9
2 3 8
2 5 7
3 5 5
4 5 15
4 6 6
5 6 8
5 7 9
6 7 11
output:
��С������:
( 1 , 4 )
( 4 , 6 )
( 1 , 2 )
( 2 , 5 )
( 5 , 3 )
( 5 , 7 )
��С������Ȩ��:39
*/