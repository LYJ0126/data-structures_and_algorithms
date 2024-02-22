#pragma once
#ifndef _MATRIXSUM_H_
#define _MATRIXSUM_H_
#include<vector>
class MatrixSum {
private:
    std::vector<std::vector<int>> sum;

public:
    //利用构造函数初始化
    MatrixSum(std::vector<std::vector<int>>& matrix);

    // 返回左上角在 (r1,c1) 右下角在 (r2-1,c2-1) 的子矩阵元素和（类似前缀和的左闭右开）
    int query(int r1, int c1, int r2, int c2);

    // 如果你不习惯左闭右开，也可以这样写
    // 返回左上角在 (r1,c1) 右下角在 (r2,c2) 的子矩阵元素和
    int query2(int r1, int c1, int r2, int c2);
    ~MatrixSum();
};

#endif