#
# @lc app=leetcode.cn id=126 lang=python3
#
# [126] 单词接龙 II
#
import collections
from typing import List


# @lc code=start
class Solution:

    def transform(self, str1: str, str2: str) -> bool:
        diff = 0
        for i in range(len(str1)):
            if str1[i] != str2[i]:
                diff += 1
            if diff > 2:
                break
        return diff == 1

    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wid, word_id, id_word = 0, dict(), list()
        for word in wordList:
            if word not in word_id:
                word_id[word] = wid
                id_word.append(word)
                wid += 1
        if endWord not in word_id:
            return []
        if beginWord not in word_id:
            word_id[beginWord] = wid
            id_word.append(beginWord)
            wid += 1
        edges = [[] for _ in range(len(word_id))]
        for i in range(len(id_word)):
            for j in range(i+1, len(id_word)):
                if self.transform(id_word[i], id_word[j]):
                    edges[i].append(j)
                    edges[j].append(i)

        ret = list()
        queue = collections.deque()
        queue.append([word_id[beginWord]])
        inf = 1 << 20
        cost = [inf for _ in range(wid)]
        cost[word_id[beginWord]] = 0
        while queue:
            now = queue.popleft()
            if now[-1] == word_id[endWord]:
                ret.append([id_word[i] for i in now])
            else:
                for index in edges[now[-1]]:
                    if cost[now[-1]] + 1 <= cost[index]:
                        cost[index] = cost[now[-1]] + 1
                        temp = now[:]
                        temp.append(index)
                        queue.append(temp)

        return ret


# @lc code=end
# "hit"\n"cog"\n["hot","dot","dog","lot","log"]
# "leet"\n"code"\n["lest","leet","lose","code","lode","robe","lost"]
print(Solution().findLadders("hit", "cog", [
    "hot", "dot", "dog", "lot", "log", "cog"]))
