#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

//***ע�⣡��������ͼ
int findpa(int id, vector<int>& parent)
{
	if (parent[id] == id) return id;
	return parent[id] = findpa(parent[id], parent);//��ѯͬʱ·��ѹ��
}
void merge(int x, int y, vector<int>& parent)
{
	int px = findpa(x, parent);
	int py = findpa(y, parent);
	if (px != py) parent[py] = px;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);//��ӱ�
	vector<int>parent(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;//���鼯��ʼ��
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		merge(x, y, parent);
	}
	int u, v;//��ѯu,v֮���Ƿ���·��
	cin >> u >> v;
	if (findpa(u, parent) == findpa(v, parent)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

/*
sample 1:
9 9
1 2
2 3
2 4
3 5
3 6
4 5
7 8
7 9
9 8
6 1
*/
/*
output 1:
Yes
*/

/*
sample 2:
9 9
1 2
2 3
2 4
3 5
3 6
4 5
7 8
7 9
9 8
9 5
*/
/*
output 2:
No
*/