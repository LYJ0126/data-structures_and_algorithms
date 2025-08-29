#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// KMP
string s1, s2;
vector<int>nxt;// next����
vector<int>pos;// ƥ�䵽��λ��
int main() {
	cin >> s1 >> s2;
	int m = s1.length(), n = s2.length();
	nxt.resize(n);
	// ��next����
	int len = 0, i = 1;
	nxt[0] = 0;
	while (i < n) {
		if (s2[len] == s2[i]) {
			len++;
			nxt[i] = len;
			i++;
		}
		else {
			if (len == 0) {
				nxt[i] = len;
				i++;
			}
			else {
				len = nxt[len - 1];
			}
		}
	}
	// KMPƥ��
	i = 0;
	int j = 0;
	while (i < m) {
		if (s1[i] == s2[j]) {
			i++;
			j++;
		}
		else {
			if (j == 0) {
				i++;
			}
			else {
				j = nxt[j - 1];
			}
		}
		if (j == n) {
			pos.push_back(i - j);
			j = nxt[j - 1];
		}
	}
	for (int x : pos) {
		cout << x << '\n';
	}
	for (int j = 0; j < n; ++j) {
		cout << nxt[j] << ' ';
	}
	return 0;
}

/*
����
����:
ABABABC
ABA

���:
0
2
0 0 1
*/