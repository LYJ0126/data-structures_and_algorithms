#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
vector<vector<int>>graph;
int cx[300], cy[300];//��¼ÿ�������Ӧ��ƥ�䶥��,��û������Ϊ-1
int visited[300];//��¼ÿ��dfsap��������Щ���Ѿ������ʹ���
int n, m, x, y, nx, ny;
vector<int>setx, sety;//����ͼ���������㼯��

int dfsap(int u)//Ѱ�Ҳ���չ����·,ÿ����չ,ƥ��ĸ�������һ
{
	visited[u] = 1;
	for (int v : graph[u]) {
		if (!visited[v]) {
			visited[v] = 1;
			//���vû��ƥ�䣬��ֱ�ӽ�vƥ���u�����v�Ѿ�ƥ���ˣ����Ҵ�cy[v],Ҳ���Ǵ�v֮ǰ�Ѿ�ƥ���x������
			//�����ܹ��ҵ�һ������·����Ҳ��vƥ���u,����ԭ����ƥ��߸ĳɷ�ƥ���,��ƥ��߸ĳ�ƥ��ߡ�ƥ������һ��
			//�����һ�������������򲻻�ݹ����
			if (cy[v] == -1 || dfsap(cy[v])) {
				cx[u] = v;
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}
int Hungarian_match()
{
	int res = 0;
	memset(cx, -1, sizeof(cx));
	memset(cy, -1, sizeof(cy));
	for (int r : setx) {
		if (cx[r] == -1) {
			memset(visited, 0, sizeof(visited));
			res += dfsap(r);
		}
	}
	return res;
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	for (int i = 0; i < m; ++i) {//�ڽӱ��ͼ
		cin >> x >> y;
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
	}
	//��¼����ͼ�������㼯
	cin >> nx >> ny;
	setx.resize(nx);
	sety.resize(ny);
	int point;
	for (int i = 0; i < nx; ++i) {
		cin >> point;
		setx[i] = point;
	}
	for (int i = 0; i < ny; ++i) {
		cin >> point;
		sety[i] = point;
	}
	int ans = Hungarian_match();
	cout << "ƥ������Ϊ: " << ans << endl;
	cout << "ƥ��:\n";
	for (int i : setx) {
		if (cx[i] != -1) {
			cout << "( " << i << ',' << cx[i] << " )\n";
		}
	}
	return 0;
}

/*
input:
7 7
1 2
2 3
3 4
2 5
5 4
5 6
7 6
4 3
1 3 5 7
2 4 6
output:
ƥ������Ϊ: 3
ƥ��:
( 1,2 )
( 3,4 )
( 5,6 )
*/
/*
input:
7 7
1 2
2 3
3 4
2 5
5 4
5 6
7 6
4 3
3 5 7 1
2 4 6
output:
ƥ������Ϊ: 3
ƥ��:
( 3,4 )
( 5,2 )
( 7,6 )
*/