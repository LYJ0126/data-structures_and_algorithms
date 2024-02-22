#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n;
int seq[100000], dp[100000],ans=-INFINITY;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> seq[i];
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++) {
			if (seq[j] < seq[i] && dp[j]+1>dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		if (dp[i] > ans) ans = dp[i];
	}
	cout << "��������������еĳ���Ϊ " << ans << endl;
	//����Ѱ�����������������
	int len = ans, j;
	int res[100000];
	for (int i = 1; i <= n; i++) {
		if (dp[i] == len) {
			j = i;
			break;//�ҵ��������е����һ��Ԫ�ص��±�
		}
	}
	res[len] = seq[j];
	for (int i = j-1; i >= 1; i--) {
		if (seq[i] < seq[j] && dp[i] == dp[j] - 1) {
			len--;
			res[len] = seq[i];
			j = i;
		}
	}
	for (int t = 1; t <= ans; t++) cout << res[t] << ' ';
	return 0;
}