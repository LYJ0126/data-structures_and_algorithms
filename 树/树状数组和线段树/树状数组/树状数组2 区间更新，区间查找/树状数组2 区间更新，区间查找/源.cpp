#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

/*
֮ǰ����˵�Ĳ�ֵ����״���飬�õ�����ĳ�����ֵ��������Ҽ�Ҫ������£���Ҫ�����ѯ��ô�졣
�������ǻ������ò�֣��������֪
��ni = 1A[i] = ��ni = 1 ��ij = 1D[j];
��A[1]+A[2]+...+A[n]
= (D[1]) + (D[1]+D[2]) + ... + (D[1]+D[2]+...+D[n])
= n*D[1] + (n-1)*D[2] +... +D[n]
= n * (D[1]+D[2]+...+D[n]) - (0*D[1]+1*D[2]+...+(n-1)*D[n])

������ʽ���Ա�Ϊ��ni = 1A[i] = n*��ni = 1D[i] -  ��ni = 1( D[i]*(i-1) );
ά��������״���飬sum1[i] = D[i]��sum2[i] = D[i]*(i-1);
*/


int n, m;
int a[50005] = { 0 };
int sum1[50005];    //(D[1] + D[2] + ... + D[n])
int sum2[50005];    //(1*D[1] + 2*D[2] + ... + n*D[n])

int lowbit(int x) {
    return x & (-x);
}

void updata(int i, int k) {
    int x = i;    //��Ϊx���䣬���Ե��ȱ���iֵ
    while (i <= n) {
        sum1[i] += k;
        sum2[i] += k * (x - 1);
        i += lowbit(i);
    }
}

int getsum(int i) {        //��ǰ׺��
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
        updata(i, a[i] - a[i - 1]);   //�����ֵ��ʱ��Ҳ�൱�ڸ�����ֵ
    }
    cout << "��������Ҫ�޸ĵ�����˵��Լ��޸�ֵ" << endl;
    int x, y, k;
    cin >> x >> y >> k;
    //[x,y]�����ڼ���k
    updata(x, k);    //A[x] - A[x-1]����k
    updata(y + 1, -k);        //A[y+1] - A[y]����k
    //��[x,y]�����
    cout << "��������Ҫ��ѯ������˵�" << endl;
    cin >> x >> y;
    int sum = getsum(y) - getsum(x - 1);
    cout << sum << endl;
    return 0;
}