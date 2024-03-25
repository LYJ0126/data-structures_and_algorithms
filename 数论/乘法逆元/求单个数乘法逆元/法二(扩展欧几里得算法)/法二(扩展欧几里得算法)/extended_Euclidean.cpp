#include<iostream>
#include<cmath>
using namespace std;

//��չŷ������㷨��˷���Ԫ
//ax+by=1
//ax��1(mod b)
//x%b��a�ĳ˷���Ԫ
typedef long long ll;
ll exgcd(ll a, ll b, ll& x, ll& y) {//��չŷ������㷨������a,b�����Լ����ͬʱx,y������ax+by=gcd(a,b)��һ���
	if (b == 0) {//�߽�
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
	return d == 1 ? (x % mod + mod) % mod : -1;//�޽ⷵ��-1
}

int main()
{
	int a, mod;
	cin >> a >> mod;
	cout << getinv(a, mod) << endl;
	return 0;
}