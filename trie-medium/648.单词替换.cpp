/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Trie {
public:
    bool end;
    Trie *next[26];
    Trie() {
        end = false;
        memset(next, 0, sizeof(next));
    }
    void insert(string s) {
        Trie *t = this;
        for (auto &c : s) {
            if (!t->next[c - 'a']) t->next[c - 'a'] = new Trie();
            t = t->next[c - 'a'];
        }
        t->end = true;
    }
    string translate(string s) {
        int pos = 0;
        string ans;
        Trie *t = this;
        for (auto &c : s) {
            if (!t->next[c - 'a'] || t->end) break;
            ans.push_back(c);
            t = t->next[c - 'a'];
        }
        return ans != "" && t->end ? ans : s;
    }
};
class Solution {
public:
    string replaceWords(vector<string> &d, string s) {
        Trie *root = new Trie();
        for (auto &x : d) {
            root->insert(x);
        }
        s.push_back(' ');
        int i, j;
        string ans;
        for (i = 0, j = 0; j < s.length(); j++) {
            if (s[j] == ' ') {
                ans.append(root->translate(s.substr(i, j - i)));
                if (j < s.length() - 1) ans.push_back(' ');
                i = j + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
