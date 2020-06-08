#
# @lc app=leetcode.cn id=1399 lang=python3
#
# [1399] 统计最大组的数目
#

# @lc code=start
class Solution:
    # def countLargestGroup(self, n: int) -> int:
    #     cnt = dict()
    #     for i in range(1, n+1):
    #         nums_sum = sum([int(i) for i in str(i)])
    #         cnt[nums_sum] = cnt.get(nums_sum, 0) + 1
    #     max_cnt = max(cnt.values())
    #     return sum([value == max_cnt for value in cnt.values()])
    def countLargestGroup(self, n: int) -> int:
        sum_list = [0] * (n + 1)
        cnt = [0] * 37
        for i in range(1, n+1):
            sum_list[i] = sum_list[i // 10] + i % 10
            cnt[sum_list[i]] += 1

        max_cnt = max(cnt)
        return sum([i == max_cnt for i in cnt])

# @lc code=end
