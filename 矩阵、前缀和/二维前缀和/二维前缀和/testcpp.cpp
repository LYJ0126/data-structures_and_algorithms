#include<iostream>
#include "MatrixSum.h"
using namespace std;

int main()
{
	int row, col;
	cin >> row >> col;
	vector<vector<int>>sample(row + 1, vector<int>(col + 1));
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> sample[i][j];
		}
	}
	MatrixSum ss(sample);
	int qr1, qc1, qr2, qc2;
	cin >> qr1 >> qc1 >> qr2 >> qc2;
	int ans1 = ss.query(qr1, qc1, qr2, qc2);//×ó¿ªÓÒ±Õ
	cout << ans1 << endl;
	cin >> qr1>> qc1>> qr2>> qc2;
	int ans2 = ss.query2(qr1, qc1, qr2, qc2);//×ó±ÕÓÒ±Õ
	cout << ans2 << endl;
	vector<vector<int>>().swap(sample);
	return 0;
}

/*
3 4
1 2 3 4
5 6 7  8
9 10 11 12
*/