#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

/*
�͸���ֻ࣬Ҫ��һ����lowv > numu �Ϳ����ˣ����Ҳ���Ҫ���Ǹ��ڵ�����⡣
����Ǻ��ǲ��Ǹ��ڵ�û��ϵ�ģ�ԭ�����������ʱ����ָ�� v �ǲ����ܲ��������ڵ� u Ϊ�ص����Ƚڵ㣨��
�����ڵ㣩�����Զ��� u �Ǹ�㡣��� lowv==numu ��ʾ�����Իص����ڵ㣬������� v ���ܻص�����Ҳû������һ
���ص����׵�·����ô u-v �����߾��Ǹ�ߡ�
*/
#define MAXN 10001
int low[MAXN], dfn[MAXN], dfs_clock;
//num����¼ÿ�����ʱ���
//low���ܲ��������׵�����С�ı��,dfs_clock��ʱ���,dfn����¼ÿ�����ʱ���
bool isbridge[MAXN];//isbridge[i]��ʾi��father[i]֮��ı��Ƿ�Ϊ��
vector<vector<int>>G;//�ڽӱ�
int cnt_bridge;//�ŵ�����
int father[MAXN];//��¼ÿ����ĸ���
void tarjan(int u, int fa) {
	father[u] = fa;//��¼����
	low[u] = dfn[u] = ++dfs_clock;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (!dfn[v]) {//���û�з��ʹ�
			tarjan(v, u);
			low[u] = min(low[u], low[v]);//����low
			if (low[v] > dfn[u]) {
				//���low[v]>dfn[u]��˵��u-v���š���Ϊv���ܾ���u�ص����ȣ�Ҳ����ͨ������·��u
				//ע�������Ǵ��ںţ���Ϊlow[v]���ܲ��������׵�����С�ı�ţ����low[v]==dfn[u]��˵��v��ͨ������·����u
				isbridge[v] = true;
				++cnt_bridge;
			}
		}
		else if (dfn[v] < dfn[u] && v != fa) {//������ʹ�����v����u�ĸ���
			low[u] = min(low[u], dfn[v]);//����low
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
			tarjan(i, i);//�ӵ�i���㿪ʼ���������Լ�
		}
	}
	cout<<"�ŵ�����Ϊ��"<<cnt_bridge<<endl;
	cout << "��Ϊ:\n";
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
�ŵ�����Ϊ��2
��Ϊ:
( 2 , 5 )
( 2 , 4 )
*/