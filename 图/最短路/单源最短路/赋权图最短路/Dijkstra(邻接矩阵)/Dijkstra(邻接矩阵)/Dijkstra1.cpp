#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int s, n, m, x, y, w;
vector<vector<int>>graph;
vector<bool>vis;//vis��Ϊtrue�ĵ����Ѿ�ȷ���˵�Դ��ľ���ĵ�
vector<int>d;//Ԥ�������Ͻ�
void dijkstra()
{
    d[s] = 0;
    int iter = n;
    while (iter--)//n���㣬ѭ��n��
    {
        int t = -1;
        //�ӵ�ǰ����ѡ��һ����Ϊu���������ڱ߽���·���ɳ�
        for (int i = 1; i <= n; i++)
            if (!vis[i] && (t == -1 || d[t] > d[i]))
                t = i;

       vis[t] = true;
        //·���ɳ�
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
	d.resize(n + 1, 0x7f7f7f7f);//��ʼ������
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		graph[x][y] = w;
	}
    dijkstra();
    cout << "�����㵽" << s << "�ľ���Ϊ:\n";
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
�����㵽1�ľ���Ϊ:
1 : 0
2 : 3
3 : 9
4 : 11
5 : 5
*/