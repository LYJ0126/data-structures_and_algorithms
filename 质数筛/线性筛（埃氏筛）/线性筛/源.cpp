#include<iostream>
using namespace std;

const int m = 6000000;
int prime[m + 10];
int check[m];
int main()
{
	int t = 0;
	memset(check, 0, sizeof(check));
	for (int i = 2; i <= m - 1; ++i)
	{
		if (!check[i])
		{
			prime[t++] = i;
			for (int j = 2; j * i <= m - 1; ++j)
			{
				check[j * i] = 1;
			}
		}
	}
	cout << t << endl;
	for (int i = 0; i <= t - 1; ++i)
	{
		cout << prime[i] << endl;
	}
	return 0;
}