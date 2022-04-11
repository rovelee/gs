#define MAX_LEAF_NUM 50
typedef struct node
{
    char ch;
    int weight;
    int parent;
    int left, right;
} HuffmanTree[2 * MAX_LEAF_NUM];
typedef char *HuffmanCode[MAX_LEAF_NUM + 1];