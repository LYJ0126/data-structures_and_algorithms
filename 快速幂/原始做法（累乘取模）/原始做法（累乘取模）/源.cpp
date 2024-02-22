#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
    /**
     * ��ͨ�����ݺ���
     * @param base ����
     * @param power  ָ��
     * @return  ���ݽ�������3λ����ʾ������
     */
long long power(long long base, long long n)
{
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= base;
        result = result % 1000;
    }
    return result % 1000;
}

int main()
{
    long long x, y;
    cin >> x >> y;
    cout << power(x, y) << endl;
    return 0;
}