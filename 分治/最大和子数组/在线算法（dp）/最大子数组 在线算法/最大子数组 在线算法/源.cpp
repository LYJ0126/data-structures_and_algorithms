#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int a[10000], n, thissum = 0, maxsum = 0;
int anslow = 1, anshigh = 1, temp = 1;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		thissum += a[i];
		if (thissum > maxsum) {
			maxsum = thissum;
			anshigh = i;
			anslow = temp;
		}
		else if (thissum < 0) {
			thissum = 0;
			temp = i + 1;
		}
	}
	cout << "����������Ϊ�� " << maxsum << endl;
	cout << "���������Ϊ�� " << endl;
	for (int i = anslow; i <= anshigh; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}

/*����������
16
13 -3 -25 20 -3 -16 -23 18 20 -7 12 -5 -22 15 -4 7
��� 43
	 18 20 -7 12
*/