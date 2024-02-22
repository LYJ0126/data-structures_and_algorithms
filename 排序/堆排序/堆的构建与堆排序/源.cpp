#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

//寻找父结点，左右子结点用内联函数，效率更高
inline int parent(int x)
{
	return x / 2;
}
inline int Left(int x)
{
	return x * 2;
}
inline int Right(int x)
{
	return x * 2 + 1;
}
void max_heapify(int a[], int x,int n)//对结点x进行最大堆化
{
	int l = Left(x);
	int r = Right(x);
	int largest;
	if (l <= n && a[l] > a[x]) largest = l;
	else largest = x;
	if (r <= n && a[r] > a[largest]) largest = r;
	if (largest != x) {
		swap(a[x], a[largest]);
		return max_heapify(a, largest, n);
	}
}
void max_heapify2(int a[], int x, int n)//循环写法
{
	while (true) {
		int l = Left(x);
		int r = Right(x);
		int largest;
		if (l <= n && a[l] > a[x]) largest = l;
		else largest = x;
		if (r <= n && a[r] > a[largest]) largest = r;
		if (largest == x) break;
		swap(a[x], a[largest]);
		x = largest;
	}
}
void build_max_heap(int a[], int n)//构建最大堆
{
	for (int i = n / 2; i >= 1; i--) max_heapify(a, i, n);
}
void heapsort(int a[], int n)//堆排序
{
	build_max_heap(a, n);//先构建一个最大堆
	for (int i = n; i >= 2; i--) {
		swap(a[1], a[i]);
		max_heapify(a, 1, i - 1);
	}
}
int main()
{
	int a[10000];//形成二叉堆的数组
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);//scanf读入更快
	heapsort(a, n);
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}