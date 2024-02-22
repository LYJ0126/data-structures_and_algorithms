#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int partition(int a[], int p, int r)//����ʱѡȡ���ұߵ���Ϊ��׼��������i,j˫ָ�룬��֤��С�ڵ��ڻ�׼��x��Ԫ�طŵ�x��ߡ�Ҳ����ÿ��
//ȷ��һ����׼����λ��
{
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}
void quicksort(int a[], int p, int r)
{
	if (p < r) {
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}
int main()
{
	int n, A[100];
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	quicksort(A, 1, n);
	for (int i = 1; i <= n; i++) cout << A[i] << ' ';
	return 0;
}