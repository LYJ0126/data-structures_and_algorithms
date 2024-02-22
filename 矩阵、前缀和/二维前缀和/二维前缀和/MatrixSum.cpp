#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include "MatrixSum.h"
//using namespace std;

MatrixSum::MatrixSum(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    // ע�⣺��� matrix[i][j] ��Χ�ܴ���Ҫʹ�� long long
    sum = std::vector<std::vector<int>>(m, std::vector<int>(n));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i][j];
        }
    }
}

// �������Ͻ��� (r1+1,c1+1) ���½��� (r2,c2) ���Ӿ���Ԫ�غͣ�����ǰ׺�͵����ұգ�
int MatrixSum::query(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
}

// ����㲻ϰ�����ұգ�Ҳ��������д
// �������Ͻ��� (r1,c1) ���½��� (r2,c2) ���Ӿ���Ԫ�غ�
int MatrixSum::query2(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
}

MatrixSum::~MatrixSum()
{
    std::vector<std::vector<int>>().swap(sum);
}