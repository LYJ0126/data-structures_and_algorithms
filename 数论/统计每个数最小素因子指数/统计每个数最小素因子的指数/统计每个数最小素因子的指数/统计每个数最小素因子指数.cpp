#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

//ͳ��ÿ������С�����ӵ�ָ��
const int N = 1000000;
int primes[N], cnt[N], num = 0;
bool visited[N];

void get_exponent(int n)
{
	memset(visited, 0, sizeof(visited));
	for (int i = 2; i <= n; ++i) {
		if (!visited[i]) {//i������
			cnt[i] = 1;
			primes[num++] = i;
		}
		for (int j = 0; j < num && 1ll * i * primes[j] <= n; ++j) {
			visited[i * primes[j]] = true;//�������
			if (i % primes[j] == 0) {//i*primes[j]����С��������primes[j]��ָ����Ϊ1
				cnt[i * primes[j]] = cnt[i] + 1;
				break;
			}
			else cnt[i * primes[j]] = 1;//i*primes[j]����С��������primes[j]��ָ��Ϊ1
		}
	}
}

int main()
{
	int n;
	cin >> n;
	get_exponent(n);
	for (int i = 2; i <= n; ++i) {//���ÿ��������С�����ӵ�ָ��
		cout << cnt[i] << ' ';
	}
	return 0;
}