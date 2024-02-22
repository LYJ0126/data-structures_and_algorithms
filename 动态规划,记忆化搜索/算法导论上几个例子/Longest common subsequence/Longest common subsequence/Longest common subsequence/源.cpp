#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

string x, y;
int b[1000][10000], c[1000][10000];//c[i,j]��¼x����Ϊi,y����Ϊjʱ����������г���
								   //b[i,j]��¼��c�γɵı���i,j���λ�õĹ��������д���������1��ʾ���ϣ�2
								   //��ʾ�ϣ�3��ʾ����Դ�����ϵ���˵�����ϵ�λ������Ҫ������������е�ǰһ��Ԫ��
								   //����ɵݹ�ʽ���ԺܺõĿ���������xi==yjʱ��һ����������Ǹ�Ԫ�أ����г���Ϊc[i-1,j-1]+1
void LCS_length()
{
	int m = x.length(), n = y.length();
	//��ʼ��������c��ȫ�ֱ��������Բ�Ҫ
	for (int i = 1; i <= m ; i++) c[i][0] = 0;
	for (int j = 0; j <= n ; j++) c[0][j] = 0;
	//�Ե�����
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			//case1
			if (x[i-1] == y[j-1]) {//ע��c,b����Ҫ�ճ��ᡢ������Ϊ0�����У���Ȼ��һ�������case1��c[i-1][j-1]�ᱨ��
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;//����
			}
			//��������case���ǵ�xi!=yjʱ����ȡmax(c[i][j-1],c[i-1][j])
			//case2
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;//����
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;//����
			}
		}
	}

}
void print_LCS(int i,int j)
{
	if (i == 0 || j == 0) return;
	if (b[i][j] == 1) {
		print_LCS(i - 1, j - 1);//��������Ҫ��ӡ��Ԫ�أ�ͨ���ݹ�ջ���䱣�棬����Ա�˳�����
		cout << x[i - 1] << ' ';//ע��b����string�����±��1
	}
	else if (b[i][j] == 2) print_LCS(i - 1, j);//����
	else print_LCS(i, j - 1);//����
}
int main()
{
	cin >> x >> y;
	int m = x.length(), n = y.length();
	LCS_length();
	cout << "����������г���Ϊ��" << c[m][n] << endl;
	cout << "�����������Ϊ��";
	print_LCS(m, n);
	return 0;
}

/*
abcbdab
bdcaba
*/