#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n, p[10000];//n��ʾ��ʼ�������ȣ�p��Ų�ͬ���ȸ����ļ�ֵ
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	int r[10000];//r�ǹؼ�����Ӧ���������ӽṹ��r[k]��ʾ����������Ϊkʱ�����Ž⣨�и���߲��и���������棩
	int s[10000];//��ôr[n]���Ǵ𰸡�s[k]������ǵ�����Ϊkʱ��Ӧ������s[k]���ȵĸ���
	r[0] = 0;
	for (int j = 1; j <= n; j++) {
		int temp = -1;
		for (int i = 1; i <= j; i++) {
			if (temp < p[i] + r[j - i]) {
				temp = p[i] + r[j - i];//�����˴�i���и��֮ǰ�������ʱ������Ŀǰ�������temp
				s[j] = i;//��¼����
			}
		}
		r[j] = temp;
	}
	cout << "�������Ϊ: " << r[n] << endl;
	//����и��
	cout << "�и��Ϊ: " << endl;
	while (n > 0) {
		cout << s[n] << ' ';
		n -= s[n];
	}
	return 0;
}