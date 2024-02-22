#include<iostream>
#include<cmath>
#include "Find_Block.h"
using namespace std;
pair<int, int>pa;
//dfsblk�㷨��dfscv����Ҳ�Ǳ������ҵ�����ʱ��˵���Ѿ�����һ�����ˣ�����ÿ�
void find_block::dfsblk(vector<vector<int>>& graph, int u, int& times, vector<int>& d, vector<int>& low, 
	vector<bool>& visited,stack<pair<int, int>>& st, vector<int>& parent, vector<int>& children,int& num)
{
	//parent��¼ÿ������ĸ��ڵ㣬��û�и��ڵ㣬����-1
	times++;//���ʵ�����һ
	d[u] = times;//d������ʵ�uʱ��ʱ���
	low[u] = d[u];//low��ʾ�õ㼰�������ͨ����������ҵ�����������Ƚڵ㡣��ʼ�������ϣ���Ϊu�������ڵ��������ҵ��ľ���u
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {//vδ�����ʹ����γ����ߣ����ڼ�����һ����(��ջ)
			st.push(make_pair(u, v));
			parent[v] = u;//u��v�ĸ��ڵ�
			children[u]++;//u�ӽ��������һ
			dfsblk(graph, v, times, d, low, visited, st, parent, children,num);
			low[u] = min(low[u], low[v]);//����ʱ������low[u],ȡu��v���ҵ�����������
			if ((parent[u] == -1 && children[u] >= 2) || (parent[u] >= 0 && low[v] >= d[u])) {
				num++;
				cout << "���±���ɿ�" << num << ':' << endl;
				do {
					pa = st.top();
					st.pop();
					cout << "( " << pa.first << " , " << pa.second << " ) ";
				} while (!st.empty() && pa != make_pair(u, v));
				cout << endl;
			}
		}
		else if (v != parent[u]) {//v����u�ĸ��ڵ㣬v�ֱ����ʹ�,��ô(u,v)�Ǻ���ߣ�
			if (d[u] > d[v]) st.push(make_pair(u, v));//d[u]>d[v]��֤(u,v)���ᱻ������
			low[u] = min(low[u], d[v]);//����low[u]���Ƚ�low[u]��v��ʱ�������u(����������)���ҵ������������
		}
	}
}