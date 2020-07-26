#include <bits/stdc++.h>
using namespace std;
/* class Solution {
public:
    string restoreString(string s, vector<int> &indices) {
        vector<char> ret(indices.size());
        for (int i = 0; i < indices.size(); i++) {
            ret[indices[i]] = s[i];
        }
        return string(ret.begin(), ret.end());
    }
}; */
/* class Solution {
public:
    int minFlips(string target) {
        int cnt = 0;
        int i = 0;
        while (i < target.length() && target[i] == '0')
            i++;
        while (i < target.length()) {
            while (i < target.length() && target[i] == '1')
                i++;
            cnt++;
            if (i == target.length()) break;
            while (i < target.length() && target[i] == '0')
                i++;
            cnt++;
        }
        return cnt;
    }
}; */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/* class Solution {
public:
    int ret = 0;
    unordered_map<TreeNode *, TreeNode *> pm;
    unordered_set<TreeNode *> leaves;
    void dfs(TreeNode *root, TreeNode *parent) {
        if (root) {
            pm.insert({root, parent});
            if (!root->left && !root->right)
                leaves.insert(root);
            dfs(root->left, root);
            dfs(root->right, root);
        }
    }
    void bfs(TreeNode *target, int distance) {
        queue<TreeNode *> Q;
        unordered_set<TreeNode *> visited;
        Q.push(target); // target结点入队，从 target 结点开始向外延伸
        visited.insert(target);
        while (!Q.empty()) {
            int n = Q.size(); // 将当前队中所有结点向外延伸 1 个结点
            for (int i = 0; i < n; i++) {
                TreeNode *node = Q.front();
                Q.pop();
                if (leaves.count(node) > 0 && distance >= 0) {
                    ret++;
                }
                if (node->left && visited.find(node->left) == visited.end()) {
                    Q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    Q.push(node->right);
                    visited.insert(node->right);
                }
                if (pm[node] != NULL &&
                    visited.find(pm[node]) == visited.end()) {
                    Q.push(pm[node]);
                    visited.insert(pm[node]);
                }
            }
            distance--;
            if (distance < 0) break;
        }
    }
    int countPairs(TreeNode *root, int distance) {
        dfs(root, NULL);
        for (auto node : leaves) {
            bfs(node, distance);
            ret--;
        }
        return ret / 2;
    }
}; */