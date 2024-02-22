#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

/*
和割点差不多，只要改一处：lowv > numu 就可以了，而且不需要考虑根节点的问题。
割边是和是不是根节点没关系的，原来我们求割点的时候是指点 v 是不可能不经过父节点 u 为回到祖先节点（包
括父节点），所以顶点 u 是割点。如果 lowv==numu 表示还可以回到父节点，如果顶点 v 不能回到祖先也没有另外一
条回到父亲的路，那么 u-v 这条边就是割边。
*/
#define MAXN 10001
int low[MAXN], dfn[MAXN], dfs_clock;
//num：记录每个点的时间戳
//low：能不经过父亲到达最小的编号,dfs_clock：时间戳,dfn：记录每个点的时间戳
bool isbridge[MAXN];//isbridge[i]表示i和father[i]之间的边是否为桥
vector<vector<int>>G;//邻接表
int cnt_bridge;//桥的数量
int father[MAXN];//记录每个点的父亲
void tarjan(int u, int fa) {
	father[u] = fa;//记录父亲
	low[u] = dfn[u] = ++dfs_clock;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (!dfn[v]) {//如果没有访问过
			tarjan(v, u);
			low[u] = min(low[u], low[v]);//更新low
			if (low[v] > dfn[u]) {
				//如果low[v]>dfn[u]，说明u-v是桥。因为v不能经过u回到祖先，也不能通过其他路到u
				//注意这里是大于号，因为low[v]是能不经过父亲到达最小的编号，如果low[v]==dfn[u]，说明v能通过其他路到达u
				isbridge[v] = true;
				++cnt_bridge;
			}
		}
		else if (dfn[v] < dfn[u] && v != fa) {//如果访问过，且v不是u的父亲
			low[u] = min(low[u], dfn[v]);//更新low
		}
	}
}

int main() {
	int n, m, x, y;
	cin>> n >> m;
	G.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i]) {
			tarjan(i, i);//从第i个点开始，父亲是自己
		}
	}
	cout<<"桥的数量为："<<cnt_bridge<<endl;
	cout << "桥为:\n";
	for (int i = 1; i <= n; ++i) {
		if (isbridge[i]) cout << "( " << father[i] << " , " << i << " )\n";
	}
	return 0;
}
/*
input:
6 6
1 2
2 3
2 4
2 5
4 6
3 6
output:
桥的数量为：2
桥为:
( 2 , 5 )
( 2 , 4 )
*/