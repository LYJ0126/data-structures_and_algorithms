#include<iostream>
#include<cmath>
using namespace std;

//���㵥������ŷ������
//���㹫ʽ:��(n)=n(1-1/p1)(1-1/p2)(1-1/p3)����(1-1/pn)
int euler_function(int n)
{
	int res = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)//n��������i
		{
			res = res / i * (i - 1);
			while(n % i == 0) n /= i;//��ȥ����������i
		}
	}
	if(n > 1) res = res / n * (n - 1);//���ʣ�µ�n������
	return res;
}

int main()
{
	int n;
	cin >> n;
	cout << euler_function(n) << endl;
	return 0;
}