#include<iostream>
#include<cmath>
#include<vector>
#include "Solution.h"

int Solution::findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k)
{
    //��nums1Ϊ�գ�����˵��������ȫ����̭�ˣ�
        //��nums2���ҵ�k��Ԫ�أ���ʱnums2��ʼλ����j��������j+k-1
    if (i >= nums1.size())    return nums2[j + k - 1];
    //nums2ͬ��
    if (j >= nums2.size())    return nums1[i + k - 1];

    //�ݹ����
    if (k == 1)  return std::min(nums1[i], nums2[j]);

    //����������ĵ�K/2С�����֣�������k/2��������ֵ�������ֵ���Ա���̭��һ�����ǰk/2������
    int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
    int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
    //���ַ����Ĳ���
    if (midVal1 < midVal2)
        return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
    else
        return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
}
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    //��λ�� = ��left + right��/2
    int left = (m + n + 1) / 2;
    int right = (m + n + 2) / 2;
    return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
}