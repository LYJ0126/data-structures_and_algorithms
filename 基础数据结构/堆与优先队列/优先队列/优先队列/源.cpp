
//这里构建最大优先队列，最小优先队列类似
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

//寻找父结点，左右子结点用内联函数，效率更高
int heapsize = 0;
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
void max_heapify(int a[], int x, int n)//对结点x进行最大堆化
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

//优先队列操作1：查找最值
inline int heapmaximum(int a[])
{
	return a[1];
}
//优先队列操作2：取出最值（删除最值）(最大优先队列取出最大值，最小优先队列亦然)
int extractmaximum(int a[])
{
	if (heapsize < 1) {
		cout << "Error, heap underflow!" << endl;
		return NULL;
	}
	int maximum = a[1];
	a[1] = a[heapsize];
	heapsize--;
	max_heapify(a, 1, heapsize);
	return maximum;
}
//优先队列操作3：增加键值（最小优先队列是减小）
void increasekey(int a[],int x, int newkey)
{
	if (newkey < a[x]) cout << "Error, new key is smaller than the current key." << endl;
	else {//上浮
		a[x] = newkey;
		while (x > 1 && a[parent(x)] < a[x]) {
			swap(a[x], a[parent(x)]);
			x = parent(x);
		}
	}
}
//优先队列操作4：插入结点
void insert(int a[], int newkey)
{
	heapsize++;
	a[heapsize] = newkey;
	int temp = heapsize;
	while (temp > 1 && a[parent(temp)] < a[temp]) {//上浮
		swap(a[temp], a[parent(temp)]);
		temp = parent(temp);
	}
	//或者也可以调用前面的increasekey函数
	/*
	a[heapsize] = -INFINITY;
	increasekey(a, heapsize, newkey);
	*/
}
int main()
{
	int n;
	int a[10000];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	heapsize = n;
	build_max_heap(a, heapsize);//构建最大优先队列
	for (int i = 1; i <= heapsize; i++) cout << a[i] << ' ';
	cout << "\n";
	printf("最大值为%d\n", heapmaximum(a));
	printf("删除最值，其值为%d\n", extractmaximum(a));
	for (int i = 1; i <= heapsize; i++) cout << a[i] << ' ';
	cout << "\n";
	cout << "Now, choose a node and a new key that the node will increase to the new key\n";
	int pos, newkey;
	cout << "Please choose the node\n";
	cin >> pos;
	cout << "Please tell us the new key\n";
	cin >> newkey;
	increasekey(a, pos, newkey);
	for (int i = 1; i <= heapsize; i++) cout << a[i] << ' ';
	cout << "\n";
	cout << "Please tell us the key of the node which you will insert\n";
	cin >> newkey;
	insert(a, newkey);
	for (int i = 1; i <= heapsize; i++) cout << a[i] << ' ';
	cout << "\n";
	return 0;
}