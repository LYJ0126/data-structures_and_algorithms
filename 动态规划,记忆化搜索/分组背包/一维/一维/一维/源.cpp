#include<iostream>
#include<cmath>
using namespace std;

const int N = 110;
int f[N];
int v[N][N], w[N][N], s[N];
int n, m, k;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i]; j++) {
            cin >> v[i][j] >> w[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k < s[i]; k++) {    //for(int k=s[i];k>=1;k--)р╡©ирт
                if (j >= v[i][k])     f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << f[m] << endl;
}
