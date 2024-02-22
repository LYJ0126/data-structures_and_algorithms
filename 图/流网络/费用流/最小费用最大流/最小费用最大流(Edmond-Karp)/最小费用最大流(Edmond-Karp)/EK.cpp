
//��Edmond-Karp�㷨����С���������
//���Ӷ�O(n*m*m)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
#define N 5005
#define M 100005
int n, m, s, t;
int maxflow = 0, mincost = 0;
int dis[N], pre[N], incf[N];
bool vis[N];
struct qxx {//��ʽǰ����
    int nex, t, v, c;//nexΪ��һ���ߵı��,tΪ�յ�,vΪ����,cΪ����
    qxx(int _nex = 0, int _t = 0, int _v = 0, int _c = 0) : nex(_nex), t(_t), v(_v), c(_c) {};
};

qxx e[M];
int head[N], cnt = 1;

void add_path(int f, int t, int v, int c) {//�ӱ�
    e[++cnt] = qxx{ head[f], t, v, c }, head[f] = cnt;
}

void add_flow(int f, int t, int v, int c) {
    add_path(f, t, v, c);
    add_path(t, f, 0, -c);//����߷���Ϊ��,����Ϊ0
}

//�� EK �㷨��������·�Ĺ��̣��滻Ϊ�����·�㷨Ѱ�ҵ�λ������С������·
bool spfa() {//spfa�����·
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(s), dis[s] = 0, incf[s] = INF, incf[t] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].nex) {
            const int& v = e[i].t, & w = e[i].v, & c = e[i].c;
            if (!w || dis[v] <= dis[u] + c) continue;
            dis[v] = dis[u] + c, incf[v] = min(w, incf[u]), pre[v] = i;
            if (!vis[v]) q.push(v), vis[v] = 1;
        }
    }
    return incf[t];
}

void update() {
    maxflow += incf[t];
    for (int u = t; u != s; u = e[pre[u] ^ 1].t) {
        e[pre[u]].v -= incf[t], e[pre[u] ^ 1].v += incf[t];
        mincost += incf[t] * e[pre[u]].c;
    }
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1, f, t, v, c; i <= m; ++i) {
		scanf("%d%d%d%d", &f, &t, &v, &c);
		add_flow(f, t, v, c);
	}
	while (spfa()) update();
	printf("%d %d\n", maxflow, mincost);
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