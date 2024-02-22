#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
    /**
     * 普通的求幂函数
     * @param base 底数
     * @param power  指数
     * @return  求幂结果的最后3位数表示的整数
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