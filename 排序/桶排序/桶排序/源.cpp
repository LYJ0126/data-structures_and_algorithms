#include<iostream>
using namespace std;

int bucket[1000];//1000��������Ըģ�ֻҪ��֤���������������������
int main()
{
	int n;//��n��������
	cin >> n;
	int a;
	for (int i=1; i <= n; i++)
	{
		cin >> a;
		bucket[a]++;//���Ҫ����ظ�����ɾ��������дbucket[a]=1;
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