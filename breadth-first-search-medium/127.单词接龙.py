#
# @lc app=leetcode.cn id=127 lang=python3
#
# [127] 单词接龙
#
import collections
from typing import List


# @lc code=start
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if not beginWord or not endWord or not wordList or endWord not in wordList:
            return 0
        L = len(beginWord)
        all_combo_dict = collections.defaultdict(list)
        for word in wordList:
            for i in range(L):
                all_combo_dict[word[:i] + '*' + word[i+1:]].append(word)
        visited = {beginWord}
        queue = collections.deque([(beginWord, 1)])
        while queue:
            current_word, level = queue.popleft()
            for i in range(L):
                joined_word = current_word[:i] + '*' + current_word[i+1:]
                for word in all_combo_dict[joined_word]:
                    if word == endWord:
                        return level + 1
                    if word in visited:
                        continue
                    visited.add(word)
                    queue.append((word, level + 1))
        return 0
# @lc code=end
