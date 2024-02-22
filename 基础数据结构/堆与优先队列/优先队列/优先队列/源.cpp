
//���ﹹ��������ȶ��У���С���ȶ�������
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

//Ѱ�Ҹ���㣬�����ӽ��������������Ч�ʸ���
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
void max_heapify(int a[], int x, int n)//�Խ��x�������ѻ�
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
void max_heapify2(int a[], int x, int n)//ѭ��д��
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
void build_max_heap(int a[], int n)//��������
{
	for (int i = n / 2; i >= 1; i--) max_heapify(a, i, n);
}

//���ȶ��в���1��������ֵ
inline int heapmaximum(int a[])
{
	return a[1];
}
//���ȶ��в���2��ȡ����ֵ��ɾ����ֵ��(������ȶ���ȡ�����ֵ����С���ȶ�����Ȼ)
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
//���ȶ��в���3�����Ӽ�ֵ����С���ȶ����Ǽ�С��
void increasekey(int a[],int x, int newkey)
{
	if (newkey < a[x]) cout << "Error, new key is smaller than the current key." << endl;
	else {//�ϸ�
		a[x] = newkey;
		while (x > 1 && a[parent(x)] < a[x]) {
			swap(a[x], a[parent(x)]);
			x = parent(x);
		}
	}
}
//���ȶ��в���4��������
void insert(int a[], int newkey)
{
	heapsize++;
	a[heapsize] = newkey;
	int temp = heapsize;
	while (temp > 1 && a[parent(temp)] < a[temp]) {//�ϸ�
		swap(a[temp], a[parent(temp)]);
		temp = parent(temp);
	}
	//����Ҳ���Ե���ǰ���increasekey����
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
	build_max_heap(a, heapsize);//����������ȶ���
	for (int i = 1; i <= heapsize; i++) cout << a[i] << ' ';
	cout << "\n";
	printf("���ֵΪ%d\n", heapmaximum(a));
	printf("ɾ����ֵ����ֵΪ%d\n", extractmaximum(a));
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