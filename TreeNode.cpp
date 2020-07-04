#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
int numStrToNum(char *str) {
  int num = 0, negative = 0;
  if (*str == '-') {
    negative = 1;
    str++;
  }
  while (*str != '\0') {
    num = num * 10 + (*str - '0');
    str++;
  }
  return negative == 0 ? num : -num;
}
TreeNode *createBiTree() {
  string val;
  cin >> val;
  if (val != "#") {
    TreeNode *T = new TreeNode(stoi(val));
    T->left = createBiTree();
    T->right = createBiTree();
    return T;
  } else
    return NULL;
}
void pre_order(TreeNode *T) {
  if (T != NULL) {
    cout << T->val << " -> ";
    pre_order(T->left);
    pre_order(T->right);
  }
}
// perorder serialize
string serialize(TreeNode *root) {
  if (root == NULL) return "#";
  return to_string(root->val) + "," + serialize(root->left) + "," +
         serialize(root->right);
}
vector<string> split(string s, char ch) {
  vector<string> ret;
  int index = 0, pos = 0;
  if (s.find_first_of(ch) != string::npos || s.length() > 0)
    s.push_back(',');
  while (true) {
    pos = s.find(ch, index);
    if (pos == string::npos)
      break;
    ret.push_back(s.substr(index, pos - index));
    index = pos + 1;
  }
  return ret;
}
TreeNode *generate(vector<string> &data) {
  if (data.size() == 0)
    return NULL;
  if (data[0] == "#") {
    data.erase(data.begin());
    return NULL;
  }
  TreeNode *root = new TreeNode(stoi(data[0]));
  data.erase(data.begin());
  root->left = generate(data);
  root->right = generate(data);
  return root;
}
TreeNode *deserialize(string data) {
  vector<string> nodes = split(data, ',');
  return generate(nodes);
}
// int main() {
//   // -1 2 # # 33 4 # # 5 # #
//   TreeNode *T = createBiTree();
//   string tree = serialize(T);
//   cout << tree << endl;
//   TreeNode *t = deserialize(tree);
//   pre_order(t);
//   cout << endl;
//   return 0;
// }