#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int r[10000];//r[k]表示长度为k的钢条通过切割或不切割后最大收益，即最优子结构
int s[10000]; //s[k]表示钢条长度为k时，需要切下长度为s[k]的部分
int memorized_cut_rod_aux(int p[], int n)
{
	if (r[n] >= 0) return r[n];//r[n]大于等于0，说明已经被修改过，后面不需要再重复计算了。动规就是在这里节省了
	//大量时间
	int q;
	if (n == 0) q = 0;//说明上次没有切割，整个钢条拿走了，现在没有钢条剩余了，价值为0
	else {
		q = -INFINITY;//初始化
		for (int i = 1; i <= n; i++) {
			int val = memorized_cut_rod_aux(p, n - i);//切割下长度为i的部分
			if (q < p[i] + val) {//发现此时收益比之前更大
				q = p[i] + val;
				s[n] = i;
			}
		}
		r[n] = q;
	}
	return q;
}
void memorized_cut_rod(int p[], int n)
{
	for (int i = 0; i <= n; i++) r[i] = -1;
	int ans = memorized_cut_rod_aux(p, n);
	cout << "最大收益为： " << ans << endl;
	cout << "最优切割方案为： " << endl;
	int temp = n;
	while (temp > 0) {
		cout << s[temp] << ' ';
		temp -= s[temp];
	}
}
int main()
{
	int n, p[10000];//n为初始钢条长度，p保存不同长度钢条的价值
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	memorized_cut_rod(p, n);
	return 0;
}