#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

//dinic�㷨
//ʱ�临�Ӷ�O(V^2E)
typedef long long ll;
int n, m, s, t, u, v;
ll c, ans = 0, dis[1005];
const long long inf = 0x7fffffffff;
int head[1005], now[1005], cnt = 1;//headΪͷָ�룬nowΪ��ǰ���Ż���cntΪ�ߵı��

struct node {//��ʽǰ���Ǵ�ͼ
	int to, next;//toΪ�յ㣬nextΪ��һ���ߵı��
	ll w;//wΪ�ߵ�Ȩֵ
} e[2005];

inline void add(int u, int v, ll w) {//�ӱ�
	e[++cnt].to = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;

	e[++cnt].to = u;
	e[cnt].w = 0;//�����ȨֵΪ0
	e[cnt].next = head[v];
	head[v] = cnt;
}

int bfs() {//�ڲ��������Ϲ���ֲ�ͼ
	for (int i = 1; i <= n; ++i) dis[i] = inf;
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    now[s] = head[s];
    //��ǰ���Ż�,now[i]��ʾi�㵱ǰ���ı��,����i����������һ����,�������Ա�֤ÿ�δ�i������ı߶��Ǵӵ�ǰ����ʼ��,�Ӷ������˱�������
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].next) {
            int v = e[i].to;
            if (e[i].w > 0 && dis[v] == inf) {//ֻ�в�������0��δ���ʹ��ĵ�������
                q.push(v);
                now[v] = head[v];//��ǰ���Ż�
                dis[v] = dis[x] + 1;
                if (v == t) return 1;//�ҵ�һ������·,����1
            }
        }
    }
    return 0;
}

int dfs(int x, ll sum)
{
    if (x == t) return sum;//�����㣬����sum
    ll k, res = 0;  //k�ǵ�ǰ��С��ʣ������ 
    for (register int i = now[x]; i && sum; i = e[i].next) {
        now[x] = i;  //��ǰ���Ż� 
        int v = e[i].to;
        if (e[i].w > 0 && (dis[v] == dis[x] + 1)) {  //ֻ�в�������0������ֲ�ͼ�����ĵ���ܼ�������
            k = dfs(v, min(sum, e[i].w));
            if (k == 0) dis[v] = inf;  //��֦��ȥ��������ϵĵ� 
            e[i].w -= k;//����ʣ����������
            e[i ^ 1].w += k;//��������
            res += k;  //res��ʾ�����õ������������(�൱������������)
            sum -= k;  //sum��ʾ�����õ��ʣ������ 
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