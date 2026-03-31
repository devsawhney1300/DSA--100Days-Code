#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}
struct Node* buildTree(int inorder[], int postorder[],
                       int inStart, int inEnd, int *postIndex) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = createNode(rootVal);

    if (inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}
void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int n;
    scanf("%d", &n);
    int inorder[n], postorder[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);
    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);
    preorder(root);
    return 0;
}