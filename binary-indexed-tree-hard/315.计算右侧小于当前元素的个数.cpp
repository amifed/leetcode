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
    vector<int> tree, a;

    void init(int n) {
        tree.resize(n, 0);
    }
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int pos, int delta = 1) {
        while (pos < tree.size()) {
            tree[pos] += delta;
            pos += lowbit(pos);
        }
    }
    int query(int pos) {
        int sum = 0;
        while (pos > 0) {
            sum += tree[pos];
            pos -= lowbit(pos);
        }
        return sum;
    }

    // 排序 去重
    void Discretization(vector<int> &nums) {
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        // unique “去除”容器中相邻元素的重复出现的元素,“去除”:将重复的元素放到容器的末尾，返回值是去重之后的尾地址
        a.erase(unique(a.begin(), a.end()), a.end());
    }
    int getId(int x) {
        // 从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }

public:
    // 树状数组 + 离散化
    vector<int> countSmaller(vector<int> &nums) {
        vector<int> ret;
        Discretization(nums);
        init(nums.size() + 5);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int id = getId(nums[i]);
            ret.push_back(query(id - 1));
            update(id);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end
