#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

int randomized_partition(int a[], int p, int r)
{
	int t = (rand() % (r - p + 1) + p);//��p��r�����ѡ��һ��Ԫ����Ϊ����
	swap(a[r], a[t]);//������Ԫ�طŵ��������
	int i = p - 1;//iָ���һ����������Ԫ�ص�λ��
	int x = a[r];//xָ������Ԫ��
	for (int j = p; j < r; j++) {
		if (a[j] <= x) {//�����ǰԪ��С�ڵ�������Ԫ�أ��򽻻���i+1λ��
			//������֤�˴�p��i��Ԫ�ض�С�ڵ�������Ԫ�أ���i+1��r��Ԫ�ض���������Ԫ��
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);//������Ԫ�طŵ�i+1λ��
	return i + 1;//i + 1������Ԫ�ص�����λ��
}
int randomized_select(int a[], int p, int r, int k)//����a[p..r], ��kС����
{
	if (p == r) return a[p];//����ֻ��һ��Ԫ��
	int q = randomized_partition(a, p, r);//���ѡ������Ԫ�ص�λ��, q������Ԫ�ص�����λ��,����a[p..q-1]��С�ڵ���a[q],a[q+1..r]������a[q]
	int t = q - p + 1;//��ʾa[q]�ǵ�tС����
	if (t == k) return a[q];
	else if (k < t) {
		return randomized_select(a, p, q - 1, k);//��kС������a[p..q-1]��
	}
	else return randomized_select(a, q + 1, r, k - t);//��k-tС������a[q+1..r]��
}
int main()
{
	srand((unsigned)time(NULL));
	int k, n, a[10000];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << randomized_select(a, 1, n, k);
	return 0;
}