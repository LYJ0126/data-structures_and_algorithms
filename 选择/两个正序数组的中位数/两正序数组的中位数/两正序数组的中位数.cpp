#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
private:
    int findkthnumber(vector<int>& nums1, vector<int>& nums2, int nums1start, int nums2start, int k)
    {
        //����һ�������Ԫ�ض�����̭ʱ��ֱ�ӷ�����һ�����������Ӧ��λ�õ�Ԫ��
        if (nums1start >= nums1.size()) return nums2[nums2start + k - 1];
        if (nums2start >= nums2.size()) return nums1[nums1start + k - 1];
        //base case
        if (k == 1) { return min(nums1[nums1start], nums2[nums2start]); };
        //mid1��mid2�н�С����һ�������������߲��ֶ��϶�����λ��С����̭
        //����һ������Ԫ���Ѳ���k/2ʱ��������������̭����һ�������k/2��Ԫ��
        int mid1 = (nums1start + (k >> 1) - 1 < nums1.size()) ? nums1[nums1start + (k >> 1) - 1] : 0x7fffffff;
        int mid2 = (nums2start + (k >> 1) - 1 < nums2.size()) ? nums2[nums2start + (k >> 1) - 1] : 0x7fffffff;
        return mid1 < mid2 ? findkthnumber(nums1, nums2, nums1start + (k >> 1), nums2start, k - (k >> 1)) : findkthnumber(nums1, nums2, nums1start, nums2start + (k >> 1), k - (k >> 1));
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) & 1) {
            return findkthnumber(nums1, nums2, 0, 0, ((m + n + 1) >> 1));
        }
        else {
            return (findkthnumber(nums1, nums2, 0, 0, ((m + n + 1) >> 1)) + findkthnumber(nums1, nums2, 0, 0, ((m + n + 2) >> 1))) / 2.0;
        }
    }
};
int main()
{
    vector<int>nums1{0, 3, 4, 5, 9}, nums2{ 1,2,6,7,8 };
    Solution ss;
    cout << ss.findMedianSortedArrays(nums1, nums2);
    return 0;
}