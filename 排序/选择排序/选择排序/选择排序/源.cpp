
//注意：选择排序不稳定
//	稳定算法是指：如果待排序的序列中存在值相等的元素，经过排序之后，相等元素之间原有的先后顺序不变。
//	比如说：5，8，5，2，9 这样一组数据，使用选择排序算法来排序的话，第一次找到最小元素 2，与第一个 5 交换位置，
//那第一个 5 和中间的 5 顺序就变了，所以就不稳定了。正是因此，相对于冒泡排序和插入排序，选择排序就稍微逊色了。
#include<iostream>
#include<algorithm>
using namespace std;

void selectsort(int a[], int len)//len为长度
{
	//从数组a的第一位(i==0)开始，一直到倒数第二位，逐个排序确定该位置上的数
	int minidex;
	for (int i = 0; i < len - 1; i++)
	{
		minidex = i;//先以开始的i这个位置为最小数位置，minidex指向从第i位开始后面所有数中最小数的位置
		for (int j = i + 1; j < len; j++)
		{
			//如果有某个第j位上的数比a[minidex]小，更新minidex
			if (a[j] < a[minidex])
				minidex = j;
		}
		swap(a[i], a[minidex]);
	}
}
int n,a[200];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	selectsort(a, n);
	for (int i = 0; i < n; i++) cout << a[i]<<" ";
	return 0;
}