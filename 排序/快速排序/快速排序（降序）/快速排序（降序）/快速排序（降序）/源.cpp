#include<iostream>
#include<algorithm>
using namespace std;

int a[200];//数组大小视情况而定
void quicksort(int left, int right)
{
	int i, j, t, k;//k用来存放基准数
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
	//基准数归位
	a[left] = a[i];
	a[i] = k;
	//或者用swap(a[left],a[i])
	//i处数的位置已经排好了
	quicksort(left, i - 1);
	quicksort(i + 1, right);
	return;
}

//举例
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