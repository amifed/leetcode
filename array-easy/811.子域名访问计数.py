#
# @lc app=leetcode.cn id=811 lang=python3
#
# [811] 子域名访问计数
#
import collections
from typing import List


# @lc code=start
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        counter = collections.defaultdict(int)
        for s in cpdomains:
            time, domains = s.split(' ')
            time = int(time)
            ds = domains.split('.')
            for i in range(len(ds)):
                counter['.'.join(ds[i:])] += time
        return [f'{v} {k}' for k, v in counter.items()]


# @lc code=end