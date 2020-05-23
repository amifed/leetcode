#define MAX_SIZE 100
typedef char ElemType;

typedef struct {
  ElemType val;
  int parent;
} PTNode;

typedef struct {
  PTNode nodes[MAX_SIZE];
  int n;
} PTree;

void mock(PTree *T) {
  T->nodes[0].val = 'R';
  T->nodes[0].val = 'R';
  T->nodes[0].parent = -1;
  T->nodes[1].val = 'A';
  T->nodes[1].parent = 0;
  T->nodes[2].val = 'B';
  T->nodes[2].parent = 0;
  T->nodes[3].val = 'C';
  T->nodes[3].parent = 0;
  T->nodes[4].val = 'D';
  T->nodes[4].parent = 1;
  T->nodes[5].val = 'E';
  T->nodes[5].parent = 1;
  T->nodes[6].val = 'F';
  T->nodes[6].parent = 3;
  T->nodes[7].val = 'G';
  T->nodes[7].parent = 6;
  T->nodes[8].val = 'H';
  T->nodes[8].parent = 6;
  T->nodes[9].val = 'K';
  T->nodes[9].parent = 6;
  T->n = 10;
}

void putPTree(PTree T) {
  int i;
  for (i = 0; i < T.n; i++) {
    printf("val: %c parent: %d\n", T.nodes[i].val, T.nodes[i].parent);
  }
}

PTree createPTree() {
  PTree T;
  int i, n;
  //    printf("PTree nodes: ");
  //    scanf("%d", &n);
  mock(&T);
  //    for (i = 0; i < n; i++) {
  //        getchar();
  //        scanf("%c %d", &T.nodes[i].val, &T.nodes[i].parent);
  //    }
  return T;
}

int nodeLevel(PTree T, PTNode p) {
  int l = 1;
  while (p.parent != -1) {
    p = T.nodes[p.parent];
    l++;
  }
  return l;
}

int lastLevelCount(PTree T) {
  int i, l, ln[10] = {0}, ml = 0;
  PTNode p;
  for (i = 0; i < T.n; i++) {
    l = 1;
    p = T.nodes[i];
    while (p.parent != -1) {
      p = T.nodes[p.parent];
      l++;
    }
    ln[l]++;
    if (l > ml) ml = l;
  }
  return ln[ml];
}

int degree(PTree T) {
  int d, i, de[T.n];
  memset(de, 0, sizeof(de) * T.n);
  for (i = 0; i < T.n; i++) {
    if (T.nodes[i].parent != -1) de[T.nodes[i].parent]++;
  }
  d = de[0];
  for (i = 0; i < T.n; i++) {
    if (de[i] > d) d = de[i];
  }
  return d;
}