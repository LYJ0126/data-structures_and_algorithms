#include<iostream>
#include<cmath>
using namespace std;

//扩展欧几里得算法求乘法逆元
//ax+by=1
//ax≡1(mod b)
//x%b是a的乘法逆元
typedef long long ll;
ll exgcd(ll a, ll b, ll& x, ll& y) {//扩展欧几里得算法，返回a,b的最大公约数，同时x,y是满足ax+by=gcd(a,b)的一组解
	if (b == 0) {//边界
		x=1;
		y=0;
		return a;
	}
	ll r=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
ll getinv(int a, int mod)
{
	ll x, y;
	ll d = exgcd(a, mod, x, y);
	return d == 1 ? (x % mod + mod) % mod : -1;//无解返回-1
}

int main()
{
	int a, mod;
	cin >> a >> mod;
	cout << getinv(a, mod) << endl;
	return 0;
}