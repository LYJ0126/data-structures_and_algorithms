#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1000];
int main()
{
	int n,sum=-INT_MAX;
	int left = 0, right = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {//����ѭ����������
		int cur_sum = 0;
		for (int j = i; j < n; j++) {
			cur_sum += a[j];
			if (cur_sum > sum) {//����sum,left,right
				sum = cur_sum;
				right = j;
				left = i;
			}
		}
	}
	cout << "����������Ϊ��" << sum << "\n";
	cout << "��������飺";
	for (int i = left; i <= right; i++) cout << a[i] << ' ';
	return 0;
}