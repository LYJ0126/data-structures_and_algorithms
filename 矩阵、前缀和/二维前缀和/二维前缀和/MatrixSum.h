#pragma once
#ifndef _MATRIXSUM_H_
#define _MATRIXSUM_H_
#include<vector>
class MatrixSum {
private:
    std::vector<std::vector<int>> sum;

public:
    //���ù��캯����ʼ��
    MatrixSum(std::vector<std::vector<int>>& matrix);

    // �������Ͻ��� (r1,c1) ���½��� (r2-1,c2-1) ���Ӿ���Ԫ�غͣ�����ǰ׺�͵�����ҿ���
    int query(int r1, int c1, int r2, int c2);

    // ����㲻ϰ������ҿ���Ҳ��������д
    // �������Ͻ��� (r1,c1) ���½��� (r2,c2) ���Ӿ���Ԫ�غ�
    int query2(int r1, int c1, int r2, int c2);
    ~MatrixSum();
};

#endif