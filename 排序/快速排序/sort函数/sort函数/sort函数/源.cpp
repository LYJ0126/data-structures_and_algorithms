#include<iostream>
#include<algorithm>
using namespace std;

int a[200],n;
//����
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n+1);//ע�⣬��Ϊ�����ʱ���Ǵ�1��ʼ�ģ�sort��λ���ұ�Ϊ���һ��Ԫ�ص���һλ������Ҫn+1
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	return 0;
}

//����sort(begin,end,less<data-type>())һ��Ĭ��Ϊ��������less<data-type>()���Բ���
//����sort(begin, end, greater<data - type>())
//����һ
/*int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n+1, greater<int >());
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	return 0;
}*/
//���򷨶�
//�Զ���Ƚϴ�С�ĺ��������������ǰ��
/*bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n+1, cmp);
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	return 0;
}*/