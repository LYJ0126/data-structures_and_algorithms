#include<iostream>
#include<algorithm>
using namespace std;
//打印全排列
void print(int a[], int end)
{
	for (int i = 0; i <= end; i++)
	{
		cout << a[i] << ' ';
	}
}

void perm(int a[], int begin, int end)
{
	if (begin == end)
	{
		print(a, end);
		cout << endl;
		return;//只有一个元素，输出这个元素
	}
	for (int i = begin; i <= end; i++)
	{
		swap(a[begin], a[i]);
		perm(a, begin + 1, end);
		swap(a[begin], a[i]);
	}
}
//测试（可以在前面改为chara[]，这样，还可以对符号进行全排列）
int main()
{
	int a[4] = { 1,3,5,7 };
	perm(a, 0, 3);
	return 0;
}

//这个是输出1到n的所有数的全排列
/*int main()
{
	int a[200];
	int n;
	cin >> n;
	for (int i = 0; i <= n - 1; ++i)
	{
		a[i] = i + 1;
	}
	perm(a, 0, n - 1);
	return 0;
}*/