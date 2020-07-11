/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> ret;

public:
    // 归并排序 + 索引数组
    vector<int> countSmaller(vector<int> &nums) {
        ret.resize(nums.size(), 0);
        vector<int> indexes, tmp(nums.size());
        for (int i = 0; i < nums.size(); i++)
            indexes.push_back(i);
        mergeSort(nums, tmp, indexes, 0, nums.size() - 1);
        return ret;
    }
    void mergeSort(vector<int> &nums, vector<int> &tmp, vector<int> &indexes, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, tmp, indexes, left, mid);
        mergeSort(nums, tmp, indexes, mid + 1, right);
        int i = left, j = mid + 1, pos = left;
        while (i <= mid && j <= right) {
            if (nums[indexes[i]] <= nums[indexes[j]]) {
                tmp[pos++] = indexes[i];
                ret[indexes[i++]] += j - mid - 1;
            } else
                tmp[pos++] = indexes[j++];
        }
        while (i <= mid) {
            tmp[pos++] = indexes[i];
            ret[indexes[i++]] += j - mid - 1;
        }
        while (j <= right)
            tmp[pos++] = indexes[j++];
        copy(tmp.begin() + left, tmp.begin() + right + 1, indexes.begin() + left);
    }
};
// @lc code=end
