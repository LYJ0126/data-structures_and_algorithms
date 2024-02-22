#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

string x, y;
int b[1000][10000], c[1000][10000];//c[i,j]记录x长度为i,y长度为j时最长公共子序列长度
								   //b[i,j]记录在c形成的表格里，i,j这个位置的公共子序列从哪里来，1表示左上，2
								   //表示上，3表示左。来源于左上的则说明左上的位置是所要的最长公共子序列的前一个元素
								   //这点由递归式可以很好的看出，即当xi==yj时，一定包含最后那个元素，序列长度为c[i-1,j-1]+1
void LCS_length()
{
	int m = x.length(), n = y.length();
	//初始化，由于c是全局变量，可以不要
	for (int i = 1; i <= m ; i++) c[i][0] = 0;
	for (int j = 0; j <= n ; j++) c[0][j] = 0;
	//自底向上
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			//case1
			if (x[i-1] == y[j-1]) {//注意c,b都是要空出横、纵坐标为0的行列，不然第一步如果是case1，c[i-1][j-1]会报错
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;//左上
			}
			//下面两个case都是当xi!=yj时，则取max(c[i][j-1],c[i-1][j])
			//case2
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;//向上
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;//向左
			}
		}
	}

}
void print_LCS(int i,int j)
{
	if (i == 0 || j == 0) return;
	if (b[i][j] == 1) {
		print_LCS(i - 1, j - 1);//发现了需要打印的元素，通过递归栈将其保存，最后以便顺序输出
		cout << x[i - 1] << ' ';//注意b表格和string类型下标差1
	}
	else if (b[i][j] == 2) print_LCS(i - 1, j);//向上
	else print_LCS(i, j - 1);//向左
}
int main()
{
	cin >> x >> y;
	int m = x.length(), n = y.length();
	LCS_length();
	cout << "最长公共子序列长度为：" << c[m][n] << endl;
	cout << "最长公共子序列为：";
	print_LCS(m, n);
	return 0;
}

/*
abcbdab
bdcaba
*/