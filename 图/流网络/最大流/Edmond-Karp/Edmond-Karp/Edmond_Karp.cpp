#include <iostream>
#include <queue>
#include<string.h>


//Edmond-Karp算法求最大流
//时间复杂度O(VE^2)
using namespace std;
#define arraysize 201
int maxData = 0x7fffffff;
int capacity[arraysize][arraysize]; //记录残留网络的容量
int flow[arraysize];                //标记从源点到当前节点实际还剩多少流量可用
int pre[arraysize];                 //标记在这条路径上当前节点的前驱,同时标记该节点是否在队列中
int n, m, s, t;//n个点，m条边，s为源点，t为汇点
queue<int> myqueue;

int BFS(int src, int des)
{
	int i, j;
	while (!myqueue.empty())       //队列清空
	         myqueue.pop();
	 for (i = 1; i <= n; ++i)
	 {
	         pre[i] = -1;		   //初始化前驱为-1
	 }
	 pre[src] = 0;
	 flow[src] = maxData;//源点的前驱为0，源点的流量为无穷大
	 myqueue.push(src);
	 while (!myqueue.empty())
	 {
		int index = myqueue.front();
	    myqueue.pop();
	    if (index == des)            //找到了增广路径
	    break;
		for (i = 1; i <= n; ++i)
		{
			if (i != src && capacity[index][i] > 0 && pre[i] == -1)
	        {
				pre[i] = index; //记录前驱
	            flow[i] = min(capacity[index][i], flow[index]);   //关键：迭代的找到增量
	            myqueue.push(i);
	        }
	    }
	 }
	 if (pre[des] == -1)      //残留图中不再存在增广路径
	         return -1;
	 else
	         return flow[des];
}
int maxFlow(int src, int des)
{
	int increasement = 0;
	int sumflow = 0;
	while ((increasement = BFS(src, des)) != -1) //当存在增广路径时
	{
		int k = des;          //利用前驱寻找路径
	    while (k != src)
	    {
			int last = pre[k];
	        capacity[last][k] -= increasement; //改变正向边的容量
	        capacity[k][last] += increasement; //改变反向边的容量
	        k = last;
	    }
	    sumflow += increasement;
	}
	return sumflow;
}

int main()
{
	/*int i, j;
	int start, end, ci;
	while (cin >> n >> m)
	{
		memset(capacity, 0, sizeof(capacity));
	    memset(flow, 0, sizeof(flow));
	    for (i = 0; i < n; ++i)
	    {
			cin >> start >> end >> ci;
	        if (start == end)               //考虑起点终点相同的情况
	            continue;
	        capacity[start][end] += ci;     //此处注意可能出现多条同一起点终点的情况
	    }
	    cout << maxFlow(1, m) << endl;
	}*/
	cin>>n>>m>>s>>t;
	memset(capacity, 0, sizeof(capacity));
	memset(flow, 0, sizeof(flow));
	int u, v, ci;
	for (int i = 0; i < m; i++)
	{
		cin>>u>>v>>ci;
		capacity[u][v]+=ci;
	}
	cout<<maxFlow(s,t)<<endl;
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout<<capacity[i][j]<<" ";
		}
		cout<<endl;
	}*/
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