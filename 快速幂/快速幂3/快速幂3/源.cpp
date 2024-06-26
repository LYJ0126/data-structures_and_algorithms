#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long long fastPower(long long base, long long power, long long mod) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base % mod;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % mod;
    }
    return result;
}
int main()
{
    long long x, y, mod;
    cin >> x >> y >> mod;
    cout << fastPower(x, y, mod) << endl;
    return 0;
}