#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include "MatrixSum.h"
//using namespace std;

MatrixSum::MatrixSum(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    // 注意：如果 matrix[i][j] 范围很大，需要使用 long long
    sum = std::vector<std::vector<int>>(m, std::vector<int>(n));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i][j];
        }
    }
}

// 返回左上角在 (r1+1,c1+1) 右下角在 (r2,c2) 的子矩阵元素和（类似前缀和的左开右闭）
int MatrixSum::query(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
}

// 如果你不习惯左开右闭，也可以这样写
// 返回左上角在 (r1,c1) 右下角在 (r2,c2) 的子矩阵元素和
int MatrixSum::query2(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
}

MatrixSum::~MatrixSum()
{
    std::vector<std::vector<int>>().swap(sum);
}