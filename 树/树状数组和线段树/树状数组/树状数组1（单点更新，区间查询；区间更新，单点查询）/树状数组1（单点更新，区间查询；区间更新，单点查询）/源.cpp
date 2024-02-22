#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int a[1005], c[1005]; //对应原数组和树状数组
int lowbit(int x) {
    return x & (-x);//lowbit求的是数x中2的最大次方因子
}
/*
这里利用的负数的存储特性，负数是以补码存储的，对于整数运算 x&(-x)有
       ● 当x为0时，即 0 & 0，结果为0；
       ●当x为奇数时，最后一个比特位为1，取反加1没有进位，故x和-x除最后一位外前面的位正好相反，按位与结果为0。结果为1。
       ●当x为偶数，且为2的m次方时，x的二进制表示中只有一位是1（从右往左的第m+1位），其右边有m位0，故x取反加1后，从右
         到左第有m个0，第m+1位及其左边全是1。这样，x& (-x) 得到的就是x。
       ●当x为偶数，却不为2的m次方的形式时，可以写作x= y * (2^k)。其中，y的最低位为1。实际上就是把x用一个奇数左移k位
         来表示。这时，x的二进制表示最右边有k个0，从右往左第k+1位为1。当对x取反时，最右边的k位0变成1，第k+1位变为0；
         再加1，最右边的k位就又变成了0，第k+1位因为进位的关系变成了1。左边的位因为没有进位，正好和x原来对应的位上的值
         相反。二者按位与，得到：第k+1位上为1，左边右边都为0。结果为2^k。
        总结一下：x&(-x)，当x为0时结果为0；x为奇数时，结果为1；x为偶数时，结果为x中2的最大次方的因子。
*/

void update(int i, int k) {    //在i位置加上k(点更新)
    while (i <= n) {
        c[i] += k;
        i += lowbit(i);
    }
}

//SUMi = C[i] + C[i-2k1] + C[(i - 2k1) - 2k2] + .....；
int getsum(int i) {        //求A[1 - i]的和
    int res = 0;
    while (i > 0) {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);//输入初值，相当于更新
    }
    cout << "请输入需要查询的区间和的左右端点" << endl;
    int left, right;
    cin >> left >> right;
    int sum = getsum(right) - getsum(left - 1);
    cout << sum << endl;//[left,right]区间即[1,right]区间减去[1,left-1]区间
    cout << "请输入需要修改的点的位置以及值" << endl;
    int x, y;
    cin >> x >> y;
    update(x, y - a[x]);
    a[x] = y;//记得修改原来数组里的值，可能下次还会修改这个位置的值

    //上面实现的是单点更新，区间查询
    // 
    //下面是区间更新，单点查询（利用差分思想）
    /*假设我们规定A[0] = 0;

则有 A[i] = Σij = 1D[j];(D[j] = A[j] - A[j-1])，即前面i项的差值和，这个有什么用呢？例如对于下面这个数组

A[] = 1 2 3 5 6 9
D[] = 1 1 1 2 1 3
如果我们把[2,5]区间内值加上2，则变成了

A[] = 1 4 5 7 8 9
D[] = 1 3 1 2 1 1
当某个区间[x,y]值改变了，区间内的差值是不变的，只有D[x]和D[y+1]的值发生改变
    */
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i] - a[i - 1]);//输入初值，相当于更新
    }
    cout << "请输入需要修改的区间的端点位置以及修改值，默认修改为加" << endl;
    int k;
    cin >> left >> right >> k;
    update(left, k);//a[left]-a[left-1]增加k
    update(right + 1, -k);//a[right+1]-a[right]减少k
    cout << "请输入需要查询的点的位置" << endl;
    int pos;
    cin >> pos;
    cout << getsum(pos);//等于从1到pos的所有差分加在一起
    return 0;
}
