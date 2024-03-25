#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

//�󵥸�����Ī����˹����ֵ
int mobius(int x)
{
	int i;
	int num = 0;
	if(x == 1) return 1;//��(1)=1
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0) {//��������i
			x /= i;
			num++;//��������������1
			if (x % i == 0) return 0;//x��ƽ������
		}
	}
	if(x > 1) num++;//���ʣ�µ�x������,��������������1
	//(-1)^num
	if(num % 2 == 0) return 1;
	else return -1;
}

int main()
{
	int n;
	cin >> n;
	cout << mobius(n) << endl;
	return 0;
}