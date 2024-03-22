#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

//求所有数的约数个数
//分三类
//1.质数，约数个数为2
//2.最小质因子指数为1，num[i*p]=num[i]*num[p](积性函数)
//3.最小质因子指数大于1，num[i*p]=num[i]/exp[i*p]*(exp[i*p]+1)=num[i]/(exp[i]+1)*(exp[i]+2)
//其中exp[i]为i的最小质因子指数(因为此时exp[i*p]=exp[i]+1)
const int maxn=1000000;
int num[maxn+1];//约数个数
int exponent[maxn+1];//最小质因子指数
int prime[maxn+1];//质数表
bool visited[maxn + 1];

void factor_num(int n)//求1~n的约数个数
{
	memset(visited,0,sizeof(visited));
	num[1]=1;//1的约数个数为1
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		if (!visited[i]) {//i为质数
			prime[++cnt] = i;
			num[i] = 2;
			exponent[i] = 1;
		}
		for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
			visited[i * prime[j]] = true;
			if (i % prime[j] == 0) {//i*prime[j]的最小质因子指数大于1
				exponent[i * prime[j]] = exponent[i] + 1;//exp[i*p]=exp[i]+1
				num[i * prime[j]] = num[i] / (exponent[i] + 1) * (exponent[i] + 2);//num[i*p]=num[i]/(exp[i]+1)*(exp[i]+2)
				break;
			}
			else {//i*prime[j]的最小质因子指数为1
				exponent[i * prime[j]] = 1;//exp[i*p]=1
				num[i * prime[j]] = num[i] * num[prime[j]];//num[i*p]=num[i]*num[p]
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	factor_num(n);
	for (int i = 1; i <= n; i++) cout << num[i] << ' ';
	cout << endl;
	return 0;
}