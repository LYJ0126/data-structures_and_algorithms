#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//求数组中数字的最大位数
int maxDigit(int* arr, int num)
{
    int n = 0;
    int* temp = new int[num];
    for (int i = 0; i < num; i++)
        temp[i] = arr[i];
    for (int i = 0; i < num; i++)
    {
        int counter = 1;
        while (temp[i] / 10 > 0)
        {
            counter++;
            temp[i] /= 10;
        }
        if (n < counter)
            n = counter;
    }
    delete[] temp;
    return n;
}

//基数排序
void radixSort(int* arr, int num)
{
    int n = maxDigit(arr, num);
    int* temp = new int[num];//num*sizeof(int)
    int* count = new int[10];
    int i, j, k;
    int radix = 1;//从个位开始
    for (i = 1; i <= n; i++)//从最低位到最高位
    {
        for (j = 0; j < 10; j++)
            count[j] = 0;
        //下面是计数排序
        for (j = 0; j < num; j++)
        {
            k = (arr[j] / radix) % 10;
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j];//计算前缀和
        for (j = num - 1; j >= 0; j--)
        {
            k = (arr[j] / radix) % 10;
            count[k]--;
            temp[count[k]] = arr[j];
        }
        for (j = 0; j < num; j++)
            arr[j] = temp[j];
        radix *= 10;
    }
    delete[] temp;
    delete[] count;
}

int main()
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i <n ; i++) {
        cin >> a[i];
    }
    radixSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}