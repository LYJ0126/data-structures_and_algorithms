#include<iostream>
#include<algorithm>
using namespace std;
//��ӡȫ����
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
		return;//ֻ��һ��Ԫ�أ�������Ԫ��
	}
	for (int i = begin; i <= end; i++)
	{
		swap(a[begin], a[i]);
		perm(a, begin + 1, end);
		swap(a[begin], a[i]);
	}
}
//���ԣ�������ǰ���Ϊchara[]�������������ԶԷ��Ž���ȫ���У�
int main()
{
	int a[4] = { 1,3,5,7 };
	perm(a, 0, 3);
	return 0;
}

//��������1��n����������ȫ����
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