#
# @lc app=leetcode.cn id=212 lang=python3
#
# [212] 单词搜索 II
#
from typing import List


# @lc code=start
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        WORD_KEY = '$'
        trie = dict()
        for word in words:
            node = trie
            for letter in word:
                node = node.setdefault(letter, dict())
            node[WORD_KEY] = word
        row, col, ret = len(board), len(board[0]), list()

        def backtracking(r, c, parent):
            letter = board[r][c]
            curr_node = parent[letter]

            match_word = curr_node.pop(WORD_KEY, False)
            if match_word:
                ret.append(match_word)

            board[r][c] = '#'

            for x, y in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
                nr, nc = r + x, c + y
                if -1 < nr < row and -1 < nc < col and board[nr][nc] in curr_node:
                    backtracking(nr, nc, curr_node)

            board[r][c] = letter

            if not curr_node:
                parent.pop(letter)

        for i in range(row):
            for j in range(col):
                if board[i][j] in trie:
                    backtracking(i, j, trie)
        return ret
# @lc code=end
