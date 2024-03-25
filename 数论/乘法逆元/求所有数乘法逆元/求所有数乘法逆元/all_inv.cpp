#include<iostream>
#include<cmath>
using namespace std;

//线性时间求所有数的逆元
const int N = 1e6 + 10;
typedef long long ll;
ll inv[N];
//线性递推法中可能用到inv[0]，但是inv[0]没有意义。故只适用于mod为素数的情况
void get_inv(ll mod)
{
	inv[1] = 1;
	for (int i = 2; i < mod; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
int main()
{
	ll mod;
	cin >> mod;
	get_inv(mod);
	for (int i = 1; i < mod; i++) cout << inv[i] << ' ';
	return 0;
}