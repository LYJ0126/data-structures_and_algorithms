#include<iostream>
#include<cmath>
using namespace std;

const int N = 110;
int f[N][N];  //ֻ��ǰi����Ʒ��ѡ����ǰ���С�ڵ���j�����ֵ
int v[N][N], w[N][N], s[N];   //vΪ�����wΪ��ֵ��s�����i����Ʒ�ĸ���
int n, m, k;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i]; j++) {
            cin >> v[i][j] >> w[i][j];  //����
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];  //��ѡ ��ѡ��ʾ��ѡ�� i ����Ʒ��������Ʒ��ֻ��ǰ i?1 ����Ʒ����ѡ
            for (int k = 0; k < s[i]; k++) {
                if (j >= v[i][k])     f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << f[n][m] << endl;
}
