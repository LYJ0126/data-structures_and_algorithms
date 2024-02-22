#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n, p[10000];//n表示初始钢条长度，p存放不同长度钢条的价值
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	int r[10000];//r是关键，对应的是最优子结构。r[k]表示当钢条长度为k时的最优解（切割或者不切割后的最大收益）
	int s[10000];//那么r[n]就是答案。s[k]储存的是当长度为k时，应当切下s[k]长度的钢条
	r[0] = 0;
	for (int j = 1; j <= n; j++) {
		int temp = -1;
		for (int i = 1; i <= j; i++) {
			if (temp < p[i] + r[j - i]) {
				temp = p[i] + r[j - i];//遇到了从i处切割比之前收益更大时，更新目前最大收益temp
				s[j] = i;//记录更新
			}
		}
		r[j] = temp;
	}
	cout << "最大收益为: " << r[n] << endl;
	//输出切割方案
	cout << "切割方案为: " << endl;
	while (n > 0) {
		cout << s[n] << ' ';
		n -= s[n];
	}
	return 0;
}