#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, k;
vector<int>arr;//�洢����
int partition(vector<int>& a, int s, int e, int pivot) {//���ֺ��������ƿ��ŵĻ���
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
void select_lsort(vector<int>& a, int s, int e)//ѡ������
{
	for (int i = s; i < e; i++) {
		int min = i;
		for (int j = i + 1; j < e; j++)
			if (a[j] < a[min])
				min = j;
		swap(arr[i], arr[min]);
	}
}
int liner_select(vector<int>& a, int s, int e, int k) {//�㷨����
	if (e - s < 5) {
		select_lsort(a, s, e);
		return a[s + k - 1];
	}
	int base;
	for (int i = 0; i <= (e - s - 4) / 5; i++) {//ͨ��������6�αȽ��ҳ�ÿ�����λ��
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

		swap(a[base + 2], a[s + i]);//�ҳ���ÿ�����λ��ȫ���ŵ���ǰ�档
	}
	int mid = liner_select(a, s, s + (e - s - 4) / 5, ((e - s - 4) / 5 + 1) / 2 + 1);//�ݹ���ã�����λ��������λ����
	int mid_index = partition(a, s, e - 1, mid);//������λ������λ�������������λ������Ҫ���в�������������л��֣�
	//ȷ����λ���ǵ�������(s,e-1)�е�mid_indexС������
	int mid_rank = mid_index - s + 1;//ȷ��֮ǰ�ҳ������������λ����ԭ����a�е�mid_rankС����
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
