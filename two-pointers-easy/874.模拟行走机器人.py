#
# @lc app=leetcode.cn id=874 lang=python3
#
# [874] 模拟行走机器人
#
from typing import List


# @lc code=start
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        dx, dy = (0, 1, 0, -1), (1, 0, -1, 0)
        obstacles_set = set(map(tuple, obstacles))
        x, y, di = 0, 0, 0
        ret = 0
        for cmd in commands:
            if cmd == -1:  # right
                di = (di + 1) % 4
            elif cmd == -2:
                di = (di - 1) % 4
            else:
                for _ in range(cmd):
                    if (x+dx[di], y+dy[di]) not in obstacles_set:
                        x, y = x+dx[di], y+dy[di]
                        ret = max(ret, x*x + y*y)
        return ret
# @lc code=end
