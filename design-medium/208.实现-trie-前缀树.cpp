/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Trie {
private:
  bool isEnd;
  Trie *children[26];

public:
  /** Initialize your data structure here. */
  Trie() {
    isEnd = false;
    memset(children, 0, sizeof(children));
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trie *trie = this;
    for (auto &&c : word) {
      if (trie->children[c - 'a'] == NULL)
        trie->children[c - 'a'] = new Trie();
      trie = trie->children[c - 'a'];
    }
    trie->isEnd = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trie *trie = this;
    for (auto &&c : word) {
      if (trie->children[c - 'a'] == NULL)
        return false;
      trie = trie->children[c - 'a'];
    }
    return trie->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Trie *trie = this;
    for (auto &&c : prefix) {
      if (trie->children[c - 'a'] == NULL)
        return false;
      trie = trie->children[c - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
