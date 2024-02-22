#include<iostream>
#include<algorithm>
using namespace std;

void insertion_sort(int arr[], int len) {
    //从第二个位置开始，倒着寻找，如果找到小于等于它的数，则插在这个数的后面
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