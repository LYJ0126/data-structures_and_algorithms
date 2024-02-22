#include<iostream>
#include<algorithm>
using namespace std;

int a[200];//�����С���������
void quicksort(int left, int right)
{
	int i, j, t, k;//k������Ż�׼��
	if (left > right)
		return;

	k = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] <= k && i < j)
		{
			j--;
		}
		while (a[i] >= k && i < j)
		{
			i++;
		}
		if (i < j)
		{
			swap(a[i], a[j]);
			/*t = a[i];
			a[i] = a[j];
			a[j] = t;*/
		}
	}
	//��׼����λ
	a[left] = a[i];
	a[i] = k;
	//������swap(a[left],a[i])
	//i������λ���Ѿ��ź���
	quicksort(left, i - 1);
	quicksort(i + 1, right);
	return;
}

//����
int main()
{
	int i, j, n;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	quicksort(1, n);
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}