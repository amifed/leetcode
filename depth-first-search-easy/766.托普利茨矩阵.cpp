/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  // bool isToeplitzMatrix(vector<vector<int>> &matrix) {
  //   int row = matrix.size(), col = matrix[0].size();
  //   unordered_map<int, int> um;
  //   for (int i = 0; i < row; i++) {
  //     for (int j = 0; j < col; j++) {
  //       if (um.find(i - j) == um.end())
  //         um.insert({i - j, matrix[i][j]});
  //       else if (um[i - j] != matrix[i][j])
  //         return false;
  //     }
  //   }
  //   return true;
  // }
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (i > 0 && j > 0 && matrix[i - 1][j - 1] != matrix[i][j])
          return false;
      }
    }
    return true;
  }
};
// @lc code=end
int main() {
  vector<vector<int>> m = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
  Solution().isToeplitzMatrix(m);
  return 0;
}