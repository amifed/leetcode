/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */
#include <bits/stdc++.h>

#include "../TreeNode.cpp"
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == NULL)
            return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    TreeNode *generate(const string data, int &pos) {
        if (data[pos] == '#') {
            pos += 2;
            return NULL;
        }
        int next = pos;
        while (data[next] != ',')
            next++;
        TreeNode *root = new TreeNode(stoi(data.substr(pos, next - pos)));
        pos = next + 1;
        root->left = generate(data, pos);
        root->right = generate(data, pos);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int pos = 0;
        return generate(data, pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
