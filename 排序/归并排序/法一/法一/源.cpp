#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 0x7fffffff;
int a[100];
void merge(int l, int mid, int r)//�ϲ�
{
	int b[100];
	int i = l, j = mid + 1, k = l;//i��¼����������λ�ã�j��¼�Ұ���������λ��
	while (i <= mid && j <= r) {//���ұȽϺϲ�
		if (a[i] <= a[j]) {
			b[k] = a[i];
			i++;
			k++;
		}
		else {
			b[k] = a[j];
			j++;
			k++;
		}
	}
	//��ʣ�µ����ϲ�����һ����Ѿ�����
	while (i <= mid) {
		b[k] = a[i];
		k++;
		i++;
	}
	while (j <= r) {
		b[k] = a[j];
		k++;
		j++;
	}
	//b���鸳ֵ��a
	for (int t = l; t <= r; t++) {
		a[t] = b[t];
	}
}
void mergesort(int l, int r)//�鲢����
{
	if (l < r) {
		int mid = (l + r) >> 1;//�м���
		mergesort(l, mid);
		mergesort(mid + 1, r);
		merge(l, mid, r);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	mergesort(1, n);
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}