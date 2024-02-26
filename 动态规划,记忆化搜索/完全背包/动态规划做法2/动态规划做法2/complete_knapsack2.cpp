#include<iostream>
using namespace std;

const int N = 1010;
const int M = 10010;
int n, m;
int v[N], w[N];
int dp[N][M];
int main()
{
	//��ȫ��������
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> w[i];//v[i]��ʾ��i����Ʒ�������w[i]��ʾ��i����Ʒ�ļ�ֵ
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j < v[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				//ע����dp[i][j - v[i]] + w[i]������dp[i - 1][j - v[i]] + w[i],��Ϊ����ȫ�������⣬�����ظ�ѡȡ
				//��ôд����Ϊdp[i][j-v[i]]+w[i]������ԭ������ѭ���е�dp[i-1][j-v[i]]+w[i]��dp[i-1][j-2*v[i]]+2*w[i]...dp[i-1][j-k*v[i]]+k*w[i]...�����
				dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}