/*
 * @lc app=leetcode.cn id=208 lang=c
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (65.97%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    32.9K
 * Total Submissions: 49.5K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */
#include <stdbool.h>
#include <stdlib.h>
// @lc code=start
#define MAX_CHARACTER_NUM 26
typedef struct TrieNode {
  bool isWord;
  struct TrieNode* children[MAX_CHARACTER_NUM];
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {
  Trie* trie = (Trie*)calloc(1, sizeof(Trie));
  return trie;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word) {
  Trie* root = obj;
  while (*word != '\0') {
    if (root->children[*word - 'a'] == NULL) {
      root->children[*word - 'a'] = trieCreate();
    }
    root = root->children[*word - 'a'];
    word++;
  }
  root->isWord = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {
  Trie* root = obj;
  while (*word != '\0') {
    if (root->children[*word - 'a'] == NULL) return false;
    root = root->children[*word - 'a'];
    word++;
  }
  return root->isWord;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
  struct TrieNode* root = obj;
  while (*prefix != '\0') {
    if (root->children[*prefix - 'a'] == NULL) return false;
    root = root->children[*prefix - 'a'];
    prefix++;
  }
  return true;
}

void trieFree(Trie* obj) {
  if (obj)
    for (int i = 0; i < 26; i++) {
      if (obj->children[i]) {
        trieFree(obj->children[i]);
      }
    }
  free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
// @lc code=end
int main() {
  Trie* obj = trieCreate();
  trieInsert(obj, "abc");
  bool param_2 = trieSearch(obj, "abc");
  bool param_3 = trieStartsWith(obj, "ab");
  trieFree(obj);
  return 0;
}