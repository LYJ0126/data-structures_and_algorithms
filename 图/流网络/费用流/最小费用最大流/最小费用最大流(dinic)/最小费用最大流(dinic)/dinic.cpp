
//dinic求解最小费用最大流
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

const int N = 5e3 + 5, M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m, tot = 1, head[N], cur[N], to[M], nxt[M], cap[M], cost[M], dis[N], ret;
//cur为当前弧优化,dis为距离标号,ret为最小费用,head为邻接表,ter为边的终点,nxt为下一条边,cap为边的容量,cost为边的费用
bool vis[N];

void add(int u, int v, int w, int c) {
    to[++tot] = v, nxt[tot] = head[u], head[u] = tot, cap[tot] = w, cost[tot] = c;
}

void addedge(int u, int v, int w, int c) { add(u, v, w, c), add(v, u, 0, -c); }

//将Dinic 算法中找增广路的过程，替换为用最短路算法寻找单位费用最小的增广路
bool spfa(int s, int t) {
    //最短路增广,返回是否存在增广路,存在则更新dis数组,不存在则返回false
    //用spfa判负环,如果存在负环,则一定不会收敛,因为每次都会更新dis数组
    memset(dis, 0x3f, sizeof(dis));
    memcpy(cur, head, sizeof(head));
    std::queue<int> q;
    q.push(s), dis[s] = 0, vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            if (cap[i] && dis[v] > dis[u] + cost[i]) {
                dis[v] = dis[u] + cost[i];
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return dis[t] != INF;
}

int dfs(int u, int t, int flow) {
    if (u == t) return flow;
    vis[u] = 1;
    int ans = 0;
    for (int& i = cur[u]; i && ans < flow; i = nxt[i]) {
        int v = to[i];
        if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i]) {
            int x = dfs(v, t, std::min(cap[i], flow - ans));
            if (x) ret += x * cost[i], cap[i] -= x, cap[i ^ 1] += x, ans += x;
        }
    }
    vis[u] = 0;
    return ans;
}

int mcmf(int s, int t) {//min cost max flow
    int ans = 0;
    while (spfa(s, t)) {
        int x;
        while ((x = dfs(s, t, INF))) ans += x;
    }
    return ans;
}

int main() {
    int s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    while (m--) {
        int u, v, w, c;
        scanf("%d%d%d%d", &u, &v, &w, &c);
        addedge(u, v, w, c);
    }
    int ans = mcmf(s, t);
    printf("%d %d\n", ans, ret);
    return 0;
}

/*
input:
4 5 4 3
4 2 30 2
4 3 20 3
2 3 20 1
2 1 30 9
1 3 40 5
output:
50 280
*/