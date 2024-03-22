#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

//����������ŷ������
//��Ϊ����
//1.����,phi(p)=p-1
//2.��С������ָ��Ϊ1,phi(i*p)=phi(i)*phi(p)
//3.��С������ָ������1,phi(i*p)=phi(i)*p
//����С������ָ��������������ɸ��
const int maxn=1000000;
int prime[maxn+1];
int phi[maxn+1];
bool is_prime[maxn+1];

void euler(int n)
{
	memset(is_prime, true, sizeof(is_prime));
	int cnt = 0;
	phi[1] = 1;
	is_prime[1] = false;
	for (int i = 2; i <= n; ++i) {
		if (is_prime[i]) {
			prime[cnt++] = i;
			phi[i] = i - 1;//������ŷ������Ϊp-1
		}
		for (int j = 0; j < cnt && i * prime[j] <= n; ++j)
		{
			is_prime[i*prime[j]]=false;
			if (i % prime[j] == 0) {//i*prime[j]����С������ָ������1
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else phi[i * prime[j]] = phi[i] * (prime[j] - 1);//i*prime[j]����С������ָ��Ϊ1,����phi(p)=p-1
		}
	}
}

int main()
{
	int n;
	cin >> n;
	euler(n);
	for (int i = 1; i <= n; ++i) cout << phi[i] << ' ';
	cout << endl;
	return 0;
}