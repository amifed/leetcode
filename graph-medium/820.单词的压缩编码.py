#
# @lc app=leetcode.cn id=820 lang=python3
#
# [820] 单词的压缩编码
#
import collections
from typing import List
from functools import reduce


# @lc code=start
class Trie:
    def __init__(self):
        self.children = {}

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self
        for letter in word:
            node = node.children.setdefault(letter, Trie())
        node.children['#'] = 1

    def isTail(self, word: str) -> bool:
        node = self
        for letter in word:
            node = node.children[letter]
        return len(node.children) == 1


class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        trie, ret = Trie(), 0
        words_set = set(words)
        for word in words_set:
            trie.insert(word[::-1])
        for word in words_set:
            if trie.isTail(word[::-1]):
                ret += len(word)+1
        return ret
# @lc code=end
