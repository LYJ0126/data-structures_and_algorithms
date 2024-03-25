#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

//����������Ī����˹����
//����ɸÿ�ζ�������С������ȥɸÿһ����
//��Ϊ3�ࣺ
//1.���i����������ômu[i] = -1
//2.i�Ѿ���������С������p,��ômu[i*p] = 0
//3.i��������С������p,��ômu[i*p] = -mu[i]

const int maxn = 1000000;
int mu[maxn+1];//mu[i]��ʾi��Ī����˹������ֵ
int prime[maxn+1];//primes[i]��ʾ��i������
bool vis[maxn+1];

void Mobius(int n)
{
	memset(vis,0,sizeof(vis));
	mu[1] = 1;//1��Ī����˹����Ϊ1
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) {//i������
			prime[++cnt] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				mu[i * prime[j]] = 0;//i�Ѿ���������С������prime[j]
				break;
			}
			else mu[i * prime[j]] = -mu[i];//i��������С������prime[j]
		}
	}
}

int main()
{
	int n;
	cin >> n;
	Mobius(n);
	for (int i = 1; i <= n; ++i) cout << mu[i] << '\n';
	return 0;
}