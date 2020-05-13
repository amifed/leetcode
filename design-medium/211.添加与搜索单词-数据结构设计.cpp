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
  WordDictionary *children[26];

  bool backtracking(string word, WordDictionary *dict, int pos) {
    if (pos == word.length())
      return dict->isEnd;
    if (word[pos] == '.') {
      for (int i = 0; i < 26; i++) {
        if (dict->children[i] && backtracking(word, dict->children[i], pos + 1))
          return true;
      }
    } else if (dict->children[word[pos] - 'a'])
      return backtracking(word, dict->children[word[pos] - 'a'], pos + 1);
    return false;
  }

public:
  /** Initialize your data structure here. */
  WordDictionary() {
    isEnd = false;
    memset(children, 0, sizeof(children));
  }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    WordDictionary *dict = this;
    for (auto &&c : word) {
      if (dict->children[c - 'a'] == NULL)
        dict->children[c - 'a'] = new WordDictionary();
      dict = dict->children[c - 'a'];
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
// ["WordDictionary","addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]\n[[],["at"],["and"],["an"],["add"],["a"],[".at"],["bat"],[".at"],["an."],["a.d."],["b."],["a.d"],["."]]