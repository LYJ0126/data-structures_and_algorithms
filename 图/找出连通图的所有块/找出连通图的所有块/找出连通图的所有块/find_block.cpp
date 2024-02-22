#include<iostream>
#include<cmath>
#include "Find_Block.h"
using namespace std;
pair<int, int>pa;
//dfsblk算法和dfscv很像，也是遍历，找到割点的时候说明已经找完一个块了，输出该块
void find_block::dfsblk(vector<vector<int>>& graph, int u, int& times, vector<int>& d, vector<int>& low, 
	vector<bool>& visited,stack<pair<int, int>>& st, vector<int>& parent, vector<int>& children,int& num)
{
	//parent记录每个顶点的父节点，根没有父节点，记作-1
	times++;//访问点数加一
	d[u] = times;//d储存访问点u时的时间戳
	low[u] = d[u];//low表示该点及其后代结点通过后向边能找到的最早的祖先节点。初始在树边上，认为u及其后代节点最早能找到的就是u
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {//v未被访问过，形成树边，块内加上这一条边(入栈)
			st.push(make_pair(u, v));
			parent[v] = u;//u是v的父节点
			children[u]++;//u子结点数量加一
			dfsblk(graph, v, times, d, low, visited, st, parent, children,num);
			low[u] = min(low[u], low[v]);//回退时，更新low[u],取u和v能找到的最早祖先
			if ((parent[u] == -1 && children[u] >= 2) || (parent[u] >= 0 && low[v] >= d[u])) {
				num++;
				cout << "以下边组成块" << num << ':' << endl;
				do {
					pa = st.top();
					st.pop();
					cout << "( " << pa.first << " , " << pa.second << " ) ";
				} while (!st.empty() && pa != make_pair(u, v));
				cout << endl;
			}
		}
		else if (v != parent[u]) {//v不是u的父节点，v又被访问过,那么(u,v)是后向边，
			if (d[u] > d[v]) st.push(make_pair(u, v));//d[u]>d[v]保证(u,v)不会被加两次
			low[u] = min(low[u], d[v]);//更新low[u]，比较low[u]和v的时间戳，看u(及其后代顶点)能找到的最早的祖先
		}
	}
}