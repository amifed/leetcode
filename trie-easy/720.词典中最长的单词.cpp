/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct Trie {
    bool end;
    Trie *v[26];
    Trie() {
        end = false;
        memset(v, 0, sizeof(v));
    }
    void insert(Trie *t, const string &w) {
        for (auto &c : w) {
            if (!t->v[c - 'a']) {
                t->v[c - 'a'] = new Trie();
            }
            t = t->v[c - 'a'];
        }
        t->end = true;
    }
    bool search(Trie *t, const string &w) {
        for (auto &c : w) {
            if (!t->v[c - 'a']->end) return false;
            t = t->v[c - 'a'];
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string> &ws) {
        Trie *root = new Trie();
        for (auto &w : ws) {
            root->insert(root, w);
        }
        string ans;
        for (auto &w : ws) {
            if (w.length() < ans.length() || !root->search(root, w)) continue;
            if (w.length() > ans.length() || w < ans) ans = w;
        }
        return ans;
    }
};
// @lc code=end
int main() {
    int n;
    scanf("%d", &n);
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << Solution().longestWord(v);
    return 0;
}