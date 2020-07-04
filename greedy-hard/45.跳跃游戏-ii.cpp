/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  // TLE
  // int jump(vector<int>& nums) {
  //   int step = 0, pos = nums.size() - 1;
  //   while (pos > 0) {
  //     for (int i = 0; i < pos; i++) {
  //       if (i + nums[i] >= pos) {
  //         pos = i;
  //         break;
  //       }
  //     }
  //     step++;
  //   }
  //   return step;
  // }
  int jump(vector<int>& nums) {
    int max_pos = 0, end_pos = 0, step = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (max_pos >= i) {
        max_pos = max(max_pos, i + nums[i]);
        if (i == end_pos) {
          end_pos = max_pos;
          step++;
        }
      }
    }
    return step;
  }
};
// @lc code=end
