/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class WordDictionary {
private:
  bool isEnd;
  unordered_map<char, WordDictionary *> children;

  bool backtracking(string word, WordDictionary *dict, int pos) {
    if (pos == word.length())
      return dict->isEnd;
    if (word[pos] == '.') {
      for (auto &&i : dict->children) {
        if (backtracking(word, i.second, pos + 1))
          return true;
      }
    } else if (dict->children.find(word[pos]) != dict->children.end())
      return backtracking(word, dict->children[word[pos]], pos + 1);
    return false;
  }

public:
  /** Initialize your data structure here. */
  WordDictionary() { isEnd = false; }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    WordDictionary *dict = this;
    for (auto &&c : word) {
      if (dict->children.find(c) == dict->children.end())
        dict->children.insert({c, new WordDictionary()});
      dict = dict->children[c];
    }
    dict->isEnd = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) { return backtracking(word, this, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
