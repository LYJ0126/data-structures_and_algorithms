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
        //power为偶数直接除以2，为奇数，原本是减去1再除以2，但由是整数除法，和直接
        //除以2结果是相同的，所以省去了-1的步骤
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