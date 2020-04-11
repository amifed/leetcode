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
void perOrder(struct TreeNode *T) {
  if (T != NULL) {
    printf("%d -> ", T->val);
    perOrder(T->left);
    perOrder(T->right);
  }
}

void inOrder(struct TreeNode *T) {
  if (T != NULL) {
    inOrder(T->left);
    printf("%d -> ", T->val);
    inOrder(T->right);
  }
}

void postOrder(struct TreeNode *T) {
  if (T != NULL) {
    postOrder(T->left);
    postOrder(T->right);
    printf("%d ", T->val);
  }
}