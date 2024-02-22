#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int r[10000];//r[k]��ʾ����Ϊk�ĸ���ͨ���и���и��������棬�������ӽṹ
int s[10000]; //s[k]��ʾ��������Ϊkʱ����Ҫ���³���Ϊs[k]�Ĳ���
int memorized_cut_rod_aux(int p[], int n)
{
	if (r[n] >= 0) return r[n];//r[n]���ڵ���0��˵���Ѿ����޸Ĺ������治��Ҫ���ظ������ˡ���������������ʡ��
	//����ʱ��
	int q;
	if (n == 0) q = 0;//˵���ϴ�û���и�������������ˣ�����û�и���ʣ���ˣ���ֵΪ0
	else {
		q = -INFINITY;//��ʼ��
		for (int i = 1; i <= n; i++) {
			int val = memorized_cut_rod_aux(p, n - i);//�и��³���Ϊi�Ĳ���
			if (q < p[i] + val) {//���ִ�ʱ�����֮ǰ����
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
	cout << "�������Ϊ�� " << ans << endl;
	cout << "�����и��Ϊ�� " << endl;
	int temp = n;
	while (temp > 0) {
		cout << s[temp] << ' ';
		temp -= s[temp];
	}
}
int main()
{
	int n, p[10000];//nΪ��ʼ�������ȣ�p���治ͬ���ȸ����ļ�ֵ
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	memorized_cut_rod(p, n);
	return 0;
}