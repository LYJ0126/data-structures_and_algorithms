/*for(ll i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        for(ll j=1;j<=c;j++)
        {
            v[cnt]=a;
            w[cnt]=b;
            cnt++;
        }//�����ر���һ��һ�������
    }
*/

#include<iostream>
#include<cmath>
using namespace std;
const int N = 1010;

int n, m;
int dp[N][N], v[N], w[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k * v[i] <= j; k++)//��Ϊÿһ����Ʒ�������޼����ã�����ֻ��Ҫ�ҳ�������ֵ��ߵ���Ʒ�Ϳ�����
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
    cout << dp[n][m] << endl;
}
