struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
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
struct TreeNode *createBiTree() {
  char *ch = (char *)malloc(sizeof(char) * 10);
  struct TreeNode *T;
  scanf("%s", ch);
  getchar();
  if (*ch != '#') {
    T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    T->val = numStrToNum(ch);
    T->left = createBiTree();
    T->right = createBiTree();
  } else {
    T = NULL;
  }
  return T;
}