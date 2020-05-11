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
    if (root == NULL) return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
  }
  vector<string> split(string s, char ch) {
    vector<string> ret;
    int index = 0, pos = 0;
    if (s.find_first_of(ch) != string::npos || s.length() > 0) s.push_back(',');
    while (true) {
      pos = s.find(ch, index);
      if (pos == string::npos) break;
      ret.push_back(s.substr(index, pos - index));
      index = pos + 1;
    }
    return ret;
  }
  TreeNode *generate(vector<string> &data) {
    TreeNode *root;
    if (data.size() == 0) return NULL;
    if (data[0] == "#") {
      data.erase(data.begin());
      return NULL;
    }
    string sval = data.front();
    int val = 0;
    for (auto &&i : sval) {
      val = val * 10 + (i - '0');
    }
    root = new TreeNode(val);
    data.erase(data.begin());
    root->left = generate(data);
    root->right = generate(data);
    return root;
  }
  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    vector<string> nodes = split(data, ',');
    return generate(nodes);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
