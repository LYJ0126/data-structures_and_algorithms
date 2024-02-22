#include<iostream>
#include<algorithm>
using namespace std;

void insertion_sort(int arr[], int len) {
    //�ӵڶ���λ�ÿ�ʼ������Ѱ�ң�����ҵ�С�ڵ����������������������ĺ���
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        while ((j >= 0) && (key < arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int n,a[200];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    insertion_sort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}