#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, k;
vector<int>arr;//存储数据
int partition(vector<int>& a, int s, int e, int pivot) {//划分函数，类似快排的划分
	int i = s, j = e;
	while (i <= e && j >= s) {
		while (a[i] < pivot)i++;
		while (a[j] > pivot)j--;
		if (i >= j)break;
		else {
			swap(a[i], a[j]);
		}
	}
	return j;
}
void select_lsort(vector<int>& a, int s, int e)//选择排序
{
	for (int i = s; i < e; i++) {
		int min = i;
		for (int j = i + 1; j < e; j++)
			if (a[j] < a[min])
				min = j;
		swap(arr[i], arr[min]);
	}
}
int liner_select(vector<int>& a, int s, int e, int k) {//算法主体
	if (e - s < 5) {
		select_lsort(a, s, e);
		return a[s + k - 1];
	}
	int base;
	for (int i = 0; i <= (e - s - 4) / 5; i++) {//通过不超过6次比较找出每组的中位数
		base = s + i * 5;
		if (a[base] > a[base + 1])//CEX 1,2
			swap(a[base], a[base + 1]);

		if (a[base + 2] > a[base + 3])//CEX 3,4
			swap(a[base + 2], a[base + 3]);

		if (a[base] > a[base + 2])//CEX 1,3
		{
			swap(a[base], a[base + 2]);
			swap(a[base + 1], a[base + 3]);
		}

		if (a[base + 1] > a[base + 4])//CEX 2,5
		{
			swap(a[base + 1], a[base + 4]);
		}

		if (a[base + 1] > a[base + 2])//CEX 2, 3
		{
			swap(a[base + 1], a[base + 2]);
			swap(a[base + 3], a[base + 4]);
		}

		if (a[base + 2] > a[base + 4])//CEX 3, 5
		{
			swap(a[base + 2], a[base + 4]);
		}

		swap(a[base + 2], a[s + i]);//找出的每组的中位数全部放到最前面。
	}
	int mid = liner_select(a, s, s + (e - s - 4) / 5, ((e - s - 4) / 5 + 1) / 2 + 1);//递归调用，在中位数中找中位数。
	int mid_index = partition(a, s, e - 1, mid);//按照中位数的中位数（即整体的中位数）对要进行操作的子数组进行划分，
	//确定中位数是第子数组(s,e-1)中第mid_index小的数。
	int mid_rank = mid_index - s + 1;//确定之前找出的子数组的中位数是原数组a中第mid_rank小的数
	if (k == mid_rank) {
		return a[mid_index];
	}
	else if (k < mid_rank) {
		return liner_select(a, s, mid_index, k);
	}
	else {
		return liner_select(a, mid_index + 1, e, k - mid_rank);
	}
}
int main()
{
	int temp;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	cout << liner_select(arr, 0, n, k) << endl;
}
