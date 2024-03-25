#include<iostream>
#include<cmath>
using namespace std;

void Decomposition_prime_factor(int n)
{
	bool first = true;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)//i��n��������
		{
			int s=0;//s��i��ָ��
			while (n % i == 0)
			{
				n /= i;
				s++;
			}
			if(first) first = false;//����ǵ�һ�������ӣ�������˺�
			else cout<<"*";//����˺�
			if(s==1) cout<<i;//���i^1
			else cout<<i<<"^"<<s;//���i^s
		}
	}
	if (n > 1)//���n���ʣ��������
	{
		if(first) first = false;//����ǵ�һ�������ӣ�������˺�
		else cout<<"*";//����˺�
		cout<<n;//���n^1
	}
}
int main()
{
	int n;
	cin>>n;
	Decomposition_prime_factor(n);
	return 0;
}