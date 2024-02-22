#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

/*
之前我们说的差值建树状数组，得到的是某个点的值，那如果我既要区间更新，又要区间查询怎么办。
这里我们还是利用差分，由上面可知
∑ni = 1A[i] = ∑ni = 1 ∑ij = 1D[j];
则A[1]+A[2]+...+A[n]
= (D[1]) + (D[1]+D[2]) + ... + (D[1]+D[2]+...+D[n])
= n*D[1] + (n-1)*D[2] +... +D[n]
= n * (D[1]+D[2]+...+D[n]) - (0*D[1]+1*D[2]+...+(n-1)*D[n])

所以上式可以变为∑ni = 1A[i] = n*∑ni = 1D[i] -  ∑ni = 1( D[i]*(i-1) );
维护两个数状数组，sum1[i] = D[i]，sum2[i] = D[i]*(i-1);
*/


int n, m;
int a[50005] = { 0 };
int sum1[50005];    //(D[1] + D[2] + ... + D[n])
int sum2[50005];    //(1*D[1] + 2*D[2] + ... + n*D[n])

int lowbit(int x) {
    return x & (-x);
}

void updata(int i, int k) {
    int x = i;    //因为x不变，所以得先保存i值
    while (i <= n) {
        sum1[i] += k;
        sum2[i] += k * (x - 1);
        i += lowbit(i);
    }
}

int getsum(int i) {        //求前缀和
    int res = 0, x = i;
    while (i > 0) {
        res += x * sum1[i] - sum2[i];
        i -= lowbit(i);
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        updata(i, a[i] - a[i - 1]);   //输入初值的时候，也相当于更新了值
    }
    cout << "请输入需要修改的区间端点以及修改值" << endl;
    int x, y, k;
    cin >> x >> y >> k;
    //[x,y]区间内加上k
    updata(x, k);    //A[x] - A[x-1]增加k
    updata(y + 1, -k);        //A[y+1] - A[y]减少k
    //求[x,y]区间和
    cout << "请输入需要查询的区间端点" << endl;
    cin >> x >> y;
    int sum = getsum(y) - getsum(x - 1);
    cout << sum << endl;
    return 0;
}