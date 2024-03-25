#include<iostream>
#include<cmath>
using namespace std;

//����ʱ��������������Ԫ
const int N = 1e6 + 10;
typedef long long ll;
ll inv[N];
//���Ե��Ʒ��п����õ�inv[0]������inv[0]û�����塣��ֻ������modΪ���������
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