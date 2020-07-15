/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    /**
     * 单调栈找出每个数组中的k个最大子序列
     */
    vector<int> findMaxKNumber(vector<int> &nums, int k) {
        if (k == 0)
            return vector<int>();
        stack<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.size() + n - i > k && nums[i] > st.top())
                st.pop();
            st.push(nums[i]);
        }
        vector<int> ret;
        while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return vector<int>(ret.begin(), ret.begin() + k);
    }
    // 按字典序归并两个子序列
    vector<int> mergeNumber(vector<int> nums1, vector<int> nums2, int k) {
        int i = 0, j = 0;
        vector<int> ret;
        while (i < nums1.size() && j < nums2.size() && i + j < k) {
            if (nums1[i] > nums2[j])
                ret.push_back(nums1[i++]);
            else if (nums1[i] < nums2[j])
                ret.push_back(nums2[j++]);
            else {
                int l = i, r = j;
                while (l < nums1.size() && r < nums2.size() && nums1[l] == nums2[r])
                    l++, r++;
                if (l == nums1.size())
                    ret.push_back(nums2[j++]);
                else if (r == nums2.size())
                    ret.push_back(nums1[i++]);
                else if (nums1[l] > nums2[r])
                    ret.push_back(nums1[i++]);
                else
                    ret.push_back(nums2[j++]);
            }
        }
        while (i < nums1.size() && i + j < k)
            ret.push_back(nums1[i++]);
        while (j < nums2.size() && i + j < k)
            ret.push_back(nums2[j++]);
        return ret;
    }
    vector<int> maxx(vector<int> &v1, vector<int> &v2) {
        int n = v1.size();
        for (int i = 0; i < n; i++) {
            if (v1[i] > v2[i])
                return v1;
            else if (v1[i] < v2[i])
                return v2;
        }
        return v1;
    }
    /**
     * 分别在两个数组中找 [0,k] [1,k-1] ... [k,0]个最大组合，求最大
     */
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ret(k, 0);
        for (int i = 0; i <= k; i++) {
            if (i > nums1.size() || k - i > nums2.size())
                continue;
            vector<int> nums = mergeNumber(findMaxKNumber(nums1, i), findMaxKNumber(nums2, k - i), k);
            ret = maxx(ret, nums);
        }
        return ret;
    }
};
// @lc code=end
