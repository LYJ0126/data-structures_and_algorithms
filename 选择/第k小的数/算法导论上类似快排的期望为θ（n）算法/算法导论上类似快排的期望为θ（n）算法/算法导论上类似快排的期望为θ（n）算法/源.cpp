#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

int randomized_partition(int a[], int p, int r)
{
	int t = (rand() % (r - p + 1) + p);//从p到r中随机选择一个元素作为枢轴
	swap(a[r], a[t]);//将枢轴元素放到数组最后
	int i = p - 1;//i指向第一个大于枢轴元素的位置
	int x = a[r];//x指向枢轴元素
	for (int j = p; j < r; j++) {
		if (a[j] <= x) {//如果当前元素小于等于枢轴元素，则交换到i+1位置
			//这样保证了从p到i的元素都小于等于枢轴元素，从i+1到r的元素都大于枢轴元素
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);//将枢轴元素放到i+1位置
	return i + 1;//i + 1是枢轴元素的最终位置
}
int randomized_select(int a[], int p, int r, int k)//数组a[p..r], 第k小的数
{
	if (p == r) return a[p];//数组只有一个元素
	int q = randomized_partition(a, p, r);//随机选择枢轴元素的位置, q是枢轴元素的最终位置,并且a[p..q-1]都小于等于a[q],a[q+1..r]都大于a[q]
	int t = q - p + 1;//表示a[q]是第t小的数
	if (t == k) return a[q];
	else if (k < t) {
		return randomized_select(a, p, q - 1, k);//第k小的数在a[p..q-1]中
	}
	else return randomized_select(a, q + 1, r, k - t);//第k-t小的数在a[q+1..r]中
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