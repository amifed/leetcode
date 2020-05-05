// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int per = 0, max = nums[0];
    for (auto&& n : nums) {
      per = std::max(per + n, n);
      max = std::max(max, per);
    }
    return max;
  }
};
// @lc code=end
