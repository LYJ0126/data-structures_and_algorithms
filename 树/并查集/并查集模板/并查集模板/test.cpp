#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include "Union.h"
using namespace std;

int main()
{
	//n��Ԫ�أ�m����ϵ�����ж��ٸ����ཻ����
	int n, m;
	cin >> n >> m;
	int* p = new int[n+1];
	for (int i = 1; i <= n; i++) p[i] = i;
	unionfind uf;
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;//x,y�й�ϵ
		uf.merge(x, y, p);//�ϲ�
	}
	//�������뽻���ϸ���
	unordered_map<int, int>mp;
	for (int i = 1; i <= n; i++) {
		mp[uf.getancestor2(i, p)]++;//ע������getancestor����·��ѹ��
	}
	cout << mp.size();
	return 0;
}