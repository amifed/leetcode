#define MAX_TREE_SIZE 100
#define ElemType char
struct PTNode {
  ElemType val;
  int parent;
};
struct PTree {
  struct PTNode nodes[MAX_TREE_SIZE];
  int n;
};
/**
R -1
A 0
B 0
C 0
D 1
E 1
F 3
G 6
H 6
K 6
**/
struct PTree* createPTree() {
  struct PTree* P = (struct PTree*)malloc(sizeof(struct PTree));
  printf("number of PTnode:");
  scanf("%d", &P->n);
  getchar();
  for (int i = 0; i < P->n; i++) {
    scanf("%c %d", &P->nodes[i].val, &P->nodes[i].parent);
    getchar();
  }
  return P;
};
void outputPTree(struct PTree* P) {
  for (int i = 0; i < P->n; i++) {
    printf("%d (%c %d)\n", i, P->nodes[i].val, P->nodes[i].parent);
  }
}
/**
 * 叶子结点数量
 **/
int numsOfLeaves(struct PTree* P) {
  if (P->n == 0) return 0;
  int cnt = 0, data = P->nodes[0].parent;
  for (int i = 1; i < P->n; i++) {
    if (data != P->nodes[i].parent) {
      data = P->nodes[i].parent;
      cnt++;
    }
  }
  return P->n - cnt;
}
int Max(int a, int b) { return a > b ? a : b; }
// 度
int degreeOfPTree(struct PTree* P) {
  if (P->n == 0) return 0;
  int degree = 0, *parent = (int*)calloc(P->n, sizeof(int));
  for (int i = 1; i < P->n; i++) {
    parent[P->nodes[i].parent]++;
    degree = Max(degree, parent[P->nodes[i].parent]);
  }
  return degree;
}
int sameDegeeeNodes(struct PTree* P, char* result, int* resultSize) {
  if (P->n == 0) return 0;
  int i, degree = 0, *parent = (int*)calloc(P->n, sizeof(int));
  result = (char*)malloc(sizeof(char) * P->n);
  *resultSize = 0;
  for (i = 1; i < P->n; i++) {
    parent[P->nodes[i].parent]++;
    degree = Max(degree, parent[P->nodes[i].parent]);
  }
  for (i = 0; i < P->n; i++) {
    if (parent[i] == degree) result[(*resultSize)++] = P->nodes[i].val;
  }
  return degree;
}