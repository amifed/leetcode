#
# @lc app=leetcode.cn id=690 lang=python3
#
# [690] 员工的重要性
#
from typing import List


class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates


# @lc code=start
"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""


class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        emp = {e.id: e for e in employees}

        def dfs(emp_id: int):
            return emp[emp_id].importance + sum(dfs() for eid in emp[emp_id].subordinates)

        return dfs(id)
# @lc code=end
