#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n, former[10000][10000];
double s[10000][10000];
struct point
{
	double x, y;
	int index;
}p[10000];
inline double dis(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmp(point a, point b)
{
	return a.x < b.x;
}
void min_bitonic_path()
{
	sort(p + 1, p + n + 1, cmp);
	s[1][2] = dis(p[1], p[2]);
	former[1][2] = p[1].index;
	for (int j = 3; j <= n; j++) {
		//case 1
		for (int i = 1; i <= j - 2; i++) {
			s[i][j] = s[i][j - 1] + dis(p[j - 1], p[j]);
			former[i][j] = j - 1;
		}
		//case 2
		s[j - 1][j] = 9999999999999.9;
		for (int k = 1; k <= j - 2; k++) {
			double temp = s[k][j - 1] + dis(p[k], p[j]);
			if (temp < s[j - 1][j]) {
				s[j - 1][j] = temp;
				former[j - 1][j] = k;
			}
		}
		//case 3
		s[n][n] = s[n - 1][n] + dis(p[n - 1], p[n]);
		former[n][n] = n - 1;
	}
}

void printpath(int i, int j)
{
	if (i >= j) {
		if (i == 2 && j == 1) return;
		cout << p[former[j][i]].index << ' ';
		printpath(former[j][i], j);
	}
	else {
		if (i == 1 && j == 2) return;
		printpath(i, former[i][j]);
		cout << p[former[i][j]].index << ' ';
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].index = i;
	}
	min_bitonic_path();
	cout << "最短双调欧几里得路径长为: " << s[n][n] << endl;
	cout << "路径为: " << endl;
	cout << p[n].index << ' ';
	printpath(n, n);
	return 0;
}

/*
  测试样例：
  7
  0 6
  2 3
  1 0
  6 1
  8 2
  7 5
  5 4
*/