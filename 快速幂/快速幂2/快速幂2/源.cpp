#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = result * base % 1000;
        }
        //powerΪż��ֱ�ӳ���2��Ϊ������ԭ���Ǽ�ȥ1�ٳ���2��������������������ֱ��
        //����2�������ͬ�ģ�����ʡȥ��-1�Ĳ���
        power = power / 2;
        base = (base * base) % 1000;
    }
    return result;
}

int main()
{
    long long x, y;
    cin >> x >> y;
    cout << fastPower(x, y) << endl;
    return 0;
}