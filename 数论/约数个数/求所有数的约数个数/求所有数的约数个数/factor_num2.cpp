#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

//����������Լ������
//������
//1.������Լ������Ϊ2
//2.��С������ָ��Ϊ1��num[i*p]=num[i]*num[p](���Ժ���)
//3.��С������ָ������1��num[i*p]=num[i]/exp[i*p]*(exp[i*p]+1)=num[i]/(exp[i]+1)*(exp[i]+2)
//����exp[i]Ϊi����С������ָ��(��Ϊ��ʱexp[i*p]=exp[i]+1)
const int maxn=1000000;
int num[maxn+1];//Լ������
int exponent[maxn+1];//��С������ָ��
int prime[maxn+1];//������
bool visited[maxn + 1];

void factor_num(int n)//��1~n��Լ������
{
	memset(visited,0,sizeof(visited));
	num[1]=1;//1��Լ������Ϊ1
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		if (!visited[i]) {//iΪ����
			prime[++cnt] = i;
			num[i] = 2;
			exponent[i] = 1;
		}
		for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
			visited[i * prime[j]] = true;
			if (i % prime[j] == 0) {//i*prime[j]����С������ָ������1
				exponent[i * prime[j]] = exponent[i] + 1;//exp[i*p]=exp[i]+1
				num[i * prime[j]] = num[i] / (exponent[i] + 1) * (exponent[i] + 2);//num[i*p]=num[i]/(exp[i]+1)*(exp[i]+2)
				break;
			}
			else {//i*prime[j]����С������ָ��Ϊ1
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