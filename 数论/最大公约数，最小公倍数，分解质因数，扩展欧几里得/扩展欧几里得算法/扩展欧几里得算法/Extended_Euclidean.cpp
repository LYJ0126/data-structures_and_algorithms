#include<iostream>
#include<cmath>
using namespace std;

// ��չŷ������㷨
// ��� ax + by = gcd(a, b) ��������
// ���� gcd(a, b), x, y
int extgcd(int a, int b, int& x, int& y) {
	int d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1;
		y = 0;
	}
	return d;
}

int main() {
	int a, b;
	cin >> a >> b;
	int x, y;
	int d = extgcd(a, b, x, y);
	cout << a << " * " << x << " + " << b << " * " << y << " = " << d << endl;
	return 0;
}