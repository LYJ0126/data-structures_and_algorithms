#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long long fastPower(long long base, long long power) 
{
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 0) {
            //���ָ��Ϊż��
            power = power / 2;//��ָ����СΪһ��
            base = base * base % 1000;//��������ԭ����ƽ��
        }
        else {
            //���ָ��Ϊ����
            power = power - 1;//��ָ����ȥ1��ʹ����һ��ż��
            result = result * base % 1000;//��ʱ�ǵ�Ҫ��ָ��Ϊ����ʱ��������ĵ�����һ�η��ռ���
            power = power / 2;//��ʱָ��Ϊż�������Լ���ִ�в���
            base = base * base % 1000;
        }
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