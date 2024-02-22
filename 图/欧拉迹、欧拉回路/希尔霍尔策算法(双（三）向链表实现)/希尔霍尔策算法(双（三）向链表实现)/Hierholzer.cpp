#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int n, m, x, y, t = 0;
int deg[100009], odd = 0, start = -1;
int path[2000010];
typedef struct point//�����ṹ��point
{
	int id;
	point* former;//�ڽӱ���ǰһ����
	point* next;//�ڽӱ��к�һ����
	point* opp;//�ڽӱ�u���е�v��v->oppָ���ڽӱ�v�е�u
	point() :id(0), former(nullptr), next(nullptr), opp(nullptr) {};
	point(int _id) :id(_id), former(nullptr), next(nullptr), opp(nullptr) {};
	point(int _id, point* _former, point* _next, point* _opp) :id(_id), former(_former), next(_next), opp(_opp) {};
};

point** graph = new point * [n + 1];//����ָ������
point* cur[100009];

void findpath(int u)
{
	while (cur[u] != graph[u]) {//ɾ��(u,v)
		int v = cur[u]->id;
		point* todelete1 = cur[u];
		point* todelete2 = cur[u]->opp;
		cur[u] = cur[u]->former;
		if (todelete2 == cur[v]) cur[v] = cur[v]->former;//���ܺ����ɾ��cur[v]
		todelete1->former->next = todelete1->next;
		if (todelete1->next) {
			todelete1->next->former = todelete1->former;
		}
		todelete2->former->next = todelete2->next;
		if (todelete2->next) {
			todelete2->next->former = todelete2->former;
		}
		delete todelete1;
		delete todelete2;
		findpath(v);
	}
	path[++t] = u;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; ++i) graph[i] = new point(0);//�ƽ��
	for (int i = 0; i <= n; ++i) cur[i] = graph[i];
	for (int i = 0; i < m; ++i) {//�����ͼΪ����ͼ
		scanf("%d%d", &x, &y);
		deg[x]++, deg[y]++;
		point* temp1 = new point(y);
		point* temp2 = new point(x);
		temp1->former = cur[x], temp2->former = cur[y];
		temp1->former->next = temp1, temp2->former->next = temp2;
		temp1->opp = temp2, temp2->opp = temp1;
		cur[x] = temp1, cur[y] = temp2;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] & 1) {
			if (start == -1) start = i;
			odd++;
		}
	}
	if (odd > 2) {
		printf("NO");
	}
	else {
		if (odd == 0) start = 1;
		printf("YES\n");
		findpath(start);
		for (int i = t; i > 0; i--) printf("%d ", path[i]);
	}
	//�ǵ��ͷſռ�
	for (int i = 0; i <= n; ++i) {
		point* deletepos;
		while (cur[i]) {
			deletepos = cur[i];
			cur[i] = cur[i]->former;
			delete deletepos;
		}
	}
	return 0;
}
/*
input:
6 7
1 2
2 3
3 4
4 2
5 2
6 5
6 1
output:
YES
1 2 3 4 2 5 6 1
*/
/*
input:
6 8
1 2
2 3
3 4
4 2
5 2
6 5
6 1
5 1
output:
YES
1 2 3 4 2 5 6 1 5
*/
/*
5 5
1 2
2 4
3 2
3 4
5 3
output:
NO
*/