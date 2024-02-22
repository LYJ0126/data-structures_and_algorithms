#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

//dinic算法
//时间复杂度O(V^2E)
typedef long long ll;
int n, m, s, t, u, v;
ll c, ans = 0, dis[1005];
const long long inf = 0x7fffffffff;
int head[1005], now[1005], cnt = 1;//head为头指针，now为当前弧优化，cnt为边的编号

struct node {//链式前向星存图
	int to, next;//to为终点，next为下一条边的编号
	ll w;//w为边的权值
} e[2005];

inline void add(int u, int v, ll w) {//加边
	e[++cnt].to = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;

	e[++cnt].to = u;
	e[cnt].w = 0;//反向边权值为0
	e[cnt].next = head[v];
	head[v] = cnt;
}

int bfs() {//在残量网络上构造分层图
	for (int i = 1; i <= n; ++i) dis[i] = inf;
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    now[s] = head[s];
    //当前弧优化,now[i]表示i点当前弧的编号,即从i点出发的最后一条边,这样可以保证每次从i点出发的边都是从当前弧开始的,从而减少了遍历次数
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].next) {
            int v = e[i].to;
            if (e[i].w > 0 && dis[v] == inf) {//只有残量大于0且未访问过的点才能入队
                q.push(v);
                now[v] = head[v];//当前弧优化
                dis[v] = dis[x] + 1;
                if (v == t) return 1;//找到一条增广路,返回1
            }
        }
    }
    return 0;
}

int dfs(int x, ll sum)
{
    if (x == t) return sum;//到达汇点，返回sum
    ll k, res = 0;  //k是当前最小的剩余容量 
    for (register int i = now[x]; i && sum; i = e[i].next) {
        now[x] = i;  //当前弧优化 
        int v = e[i].to;
        if (e[i].w > 0 && (dis[v] == dis[x] + 1)) {  //只有残量大于0且满足分层图条件的点才能继续增广
            k = dfs(v, min(sum, e[i].w));
            if (k == 0) dis[v] = inf;  //剪枝，去掉增广完毕的点 
            e[i].w -= k;//正向剩余容量减少
            e[i ^ 1].w += k;//反向增加
            res += k;  //res表示经过该点的所有流量和(相当于流出的总量)
            sum -= k;  //sum表示经过该点的剩余流量 
        }
    }
    return res;
}

int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> c;
        add(u, v, c);
    }
    while (bfs()) {
        ans += dfs(s, inf);
    }
    cout << ans;
    return 0;
}

/*
input:
4 5 4 3
4 2 30
4 3 20
2 3 20
2 1 30
1 3 30
output:
50
*/