#include<vector>
#include<cmath>
#include "DFSCV.h"
using namespace std;

void find_cut_point::dfscv(vector<vector<int>>& graph, int u,int& times, vector<int>&d, 
	vector<int>& low, vector<bool>& visited, vector<int>& parent, vector<int>& children, vector<bool>& iscut)
{
	//d��¼����ÿ�������ʵ�ʱ���
	//low��¼���Ǽ�¼�ö��㼰��������ͨ������߹������ڵ����Сd(ʱ���)ֵ
	//parent��¼ÿ������ǰһ�����ʵĶ���(�����),���ڵ��parent��Ϊ-1
	//children��¼ÿ��������Ӷ������
	times++;//���ʴ���(����)��һ
	d[u] = times;//��ǰ��ķ���ʱ���Ϊ��ǰtimes
	low[u] = d[u];//Ŀǰ��low��Ϊd[u]������ǰ�������ֻ�ܵ��Լ�
	visited[u] = true;//u�Ѿ������ʹ�
	for (int v : graph[u]) {//dfs����
		if (!visited[v]) {//vû�б����ʹ���(u,v)������
			parent[v] = u;//u��v�ĸ��ڵ�
			children[u]++;//u�Ӷ��������һ
			dfscv(graph, v, times, d, low, visited, parent, children, iscut);//dfs�ݹ�ִ��
			low[u] = min(low[u], low[v]);//���˵�ʱ��low[u]Ҫ��low[v]�Ƚϣ���˭�ĺ������ָ����������
			if (parent[u] == -1 && children[u] >= 2) {//��u�Ǹ��ڵ���dfs����������������ʱ��˵��u�Ǹ��
				iscut[u] = true;
			}
			else if (parent[u] >= 0 && low[v] >= d[u]) {//u���Ǹ��ڵ㣬��v��v�ĺ��û���ܷ��ʵ�u�����ȵģ�
				//�������ڴ�u���ָ��u���ȵĺ���ߣ���ôu�Ǹ��
				iscut[u] = true;
			}
		}
		//v�����ʹ���(u,v)�Ǻ���ߡ���v��u���ڵ㣬�ڵݹ����ʱ���v.low���и��¡�
		//��v����u���ڵ㣬����v.low����u��v˭��ָ�����Ľڵ㡣���ﲻдlow[v]������Ϊ��û���˵�v��low[v]==d[v]��
		else if (v != parent[u]) low[u] = min(low[u], d[v]);
	}
}