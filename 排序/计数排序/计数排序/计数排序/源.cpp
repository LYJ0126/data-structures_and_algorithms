#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[200], b[200],n;//a���룬b�����������
vector<int>c;//c�ṩ��ʱ�洢�ռ䣨cһ��Ҫ�Ƕ�̬���飩
void countingsort(int a[], int b[], int k)//k��0��ʼ
{
	for (int j = 1; j <= n; j++) 
	for (int j = n; j >= 1; j--) {
		b[c[a[j]]] = a[j];
		c[a[j]]--;
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	countingsort(a, b, n);
	for (int i = 0; i < n; i++) cout << b[i] << ' ';
	return 0;
}

/*
5
6 7 3 9 1
*/