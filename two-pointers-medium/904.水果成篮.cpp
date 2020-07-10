/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int totalFruit(vector<int> &tree) {
        int ret = 0;
        unordered_map<int, int> fruits;
        for (int left = 0, right = 0; right < tree.size(); right++) {
            fruits[tree[right]]++;
            while (fruits.size() > 2) {
                fruits[tree[left]]--;
                if (fruits[tree[left]] == 0)
                    fruits.erase(tree[left]);
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};
// @lc code=end
