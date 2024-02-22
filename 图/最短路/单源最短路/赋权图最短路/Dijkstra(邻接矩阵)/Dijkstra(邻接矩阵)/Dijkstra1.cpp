#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int s, n, m, x, y, w;
vector<vector<int>>graph;
vector<bool>vis;//vis中为true的点是已经确定了到源点的距离的点
vector<int>d;//预估距离上界
void dijkstra()
{
    d[s] = 0;
    int iter = n;
    while (iter--)//n个点，循环n次
    {
        int t = -1;
        //从当前点中选择一个作为u，并对其邻边进行路径松弛
        for (int i = 1; i <= n; i++)
            if (!vis[i] && (t == -1 || d[t] > d[i]))
                t = i;

       vis[t] = true;
        //路径松弛
        for (int i = 1; i <= n; i++)
            if (vis[i] == 0)
                d[i] = min(d[i], d[t] + graph[t][i]);
    }

}
int main()
{
	cin >> n >> m >> s;
	graph.resize(n + 1, vector<int>(n + 1, 0x7f7f7f7f));
	vis.resize(n + 1, false);
	d.resize(n + 1, 0x7f7f7f7f);//初始化距离
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		graph[x][y] = w;
	}
    dijkstra();
    cout << "各个点到" << s << "的距离为:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " : " << d[i] << '\n';
    }
    return 0;
}
/*
input:
5 10 1
1 2 3
1 5 5
2 3 6
2 5 2
3 4 2
4 3 7
4 1 3
5 2 1
5 3 4
5 4 6
output:
各个点到1的距离为:
1 : 0
2 : 3
3 : 9
4 : 11
5 : 5
*/