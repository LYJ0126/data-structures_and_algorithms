#include<queue>
#include<functional>
#include "TreeJudge.h"
using namespace std;

bool treejudge::bfs_judge(vector<vector<int>>& graph, int s)
{
	int n = graph.size();
	queue<int>que;
	vector<bool>visited(n, false);
	vector<int>pa(n, 0);//��¼û���ڵ�ĸ��׽ڵ㣬���ڵ㸸�ڵ�Ϊ0
	que.push(s);
	visited[s] = true;
	while (!que.empty()) {
		int size = que.size();
		while (size) {
			int u = que.front();
			que.pop();
			for (int i : graph[u]) {
				if (visited[i]) {
					if (i != pa[u]) return false;
				}//����ָ�����Ƚڵ�(ע�ⲻ�Ǹ��ڵ�)�ıߣ�����u�����ڵ�v��v�����丸�׽ڵ㡣˵������Ȧ��������
				else if (!visited[i]) {
					que.push(i);
					pa[i] = u;//i���׽ڵ����Ϊu
					visited[i] = true;
				}
			}
			size--;
		}
	}
	//�ж�ͼ�Ƿ���ͨ
	for (int i = 1; i < n; i++) {
		if (!visited[i]) return false;//ͼ����ͨ
	}
	return true;
}

/*bool treejudge::dfs(vector<vector<int>>& graph, int s, vector<bool>& visited, vector<int>& pa)
{
	visited[s] = true;
	if (graph[s].size() == 0) return true;//�ߵ���Ҷ�ڵ�
	bool flag = true;
	int len = graph[s].size();
	for (int i = 0; i < len; i++) {
		if(visited[])
	}
	return flag;
}*/

bool treejudge::dfs_judge(vector<vector<int>>& graph, int s)
{
	bool flag = true;//�ж��Ƿ���Ȧ
	int n = graph.size();
	vector<bool>visited(n, false);
	visited[s] = true;
	vector<int>pa(n, 0);//��¼���ڵ㣬����ڵ�ĸ��׽ڵ�Ϊ0
	function<void(int)>dfs = [&](int u)->void {//pa��ʾ�ýڵ�ĸ��׽ڵ�
		if (!flag) return;//��Ȧ��ֱ�ӷ��ء�������������
		if (graph[u].size() == 0) return;//����Ҷ�ڵ㣬����
		int len = graph[u].size();
		for (int i = 0; i < len; i++) {
			int v = graph[u][i];
			if (visited[v]) {
				if (pa[u] != v) {//��u���ڵ㱭���ʹ��Ҳ���x�ĸ��׽ڵ㣬˵������Ȧ
					flag = false;
					return;
				}
			}
			else {
				visited[v] = true;
				pa[v] = u;
				dfs(v);
			}
		}
	};
	dfs(s);
	if (!flag) return false;
	//�ж��Ƿ���ͨ
	for (int i = 1; i < n; i++) {
		if (!visited[i]) return false;
	}
	return true;
}

int treejudge::findpa(vector<int>& pa, int x)
{
	if (pa[x] == x) return x;
	else return pa[x] = findpa(pa, pa[x]);//·��ѹ��
}
bool treejudge::merge(vector<int>& pa, int x, int y)
{
	int px = findpa(pa, x);
	int py = findpa(pa, y);
	pa[py] = px;
	if (px == py) return true;//�����ʱ��ͬ����˵����Ȧ
	else return false;
}
bool treejudge::unionfind_judge(vector<int>& pa, bool flag)
{
	bool liantong = true;
	int n = pa.size();
	for (int i = 2; i < n; i++) {
		if (findpa(pa, i) != findpa(pa, i-1)) {
			liantong = false;
			break;
		}
	}
	if (!liantong || flag) return false;//����ͨ������Ȧ
	return true;
}