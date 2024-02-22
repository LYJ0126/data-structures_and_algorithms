#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long long fastPower(long long base, long long power, long long mod) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//�˴��ȼ���if(power%2==1)
            result = result * base % mod;
        }
        power >>= 1;//�˴��ȼ���power=power/2
        base = (base * base) % mod;
    }
    return result;
}
int main()
{
    long long x, y;
    cin >> x >> y;
    cout << fastPower(x, y,998244353) << endl;
    return 0;
}