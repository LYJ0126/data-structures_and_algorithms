#include<iostream>
#include<algorithm>
using namespace std;

int a[200];
//升序
int main()
{
	int j, t, n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i)
	{
		for (j = 1; j <= n - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				//或者用swpa(a[j],a[j+1])
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}

//降序
/*int main()
{
	int j, t, n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i)
	{
		for (j = 1; j <= n - i; ++j)
		{
			if (a[j] < a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				//或者用swpa(a[j],a[j+1])
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}*/