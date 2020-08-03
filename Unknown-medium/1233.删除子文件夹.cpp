/*
 * @lc app=leetcode.cn id=1233 lang=cpp
 *
 * [1233] 删除子文件夹
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> removeSubfolders(vector<string> &folder) {
        sort(folder.begin(), folder.end());
        vector<string> ret = {folder.front()};
        for (int i = 1; i < folder.size(); i++) {
            if (includes(folder[i].begin(), folder[i].end(), ret.back().begin(), ret.back().end()) && folder[i][ret.back().length() - 1] == '/')
                continue;
            ret.push_back(folder[i]);
        }
        return ret;
    }
};
// @lc code=end
