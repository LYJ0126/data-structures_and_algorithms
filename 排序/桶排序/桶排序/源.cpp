#include<iostream>
using namespace std;

int bucket[1000];//1000这个数可以改，只要保证所有数不超过这个数即可
int main()
{
	int n;//给n个数排序
	cin >> n;
	int a;
	for (int i=1; i <= n; i++)
	{
		cin >> a;
		bucket[a]++;//如果要求把重复的数删掉，可以写bucket[a]=1;
	}
	for (int i = 1; i <= 200; i++)
	{
		while (bucket[i] > 0)
		{
			cout << i << ' ';
			bucket[i]--;
		}
	}
	return 0;
}