#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Queue for level order construction */
Node* queue[1000];
int front = 0, rear = -1;

void enqueue(Node* node){
    queue[++rear] = node;
}

Node* dequeue(){
    return queue[front++];
}

int isEmpty(){
    return front > rear;
}

/* Traversals */

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){

    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(arr[0] == -1) return 0;

    Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while(!isEmpty() && i < n){

        Node* curr = dequeue();

        if(i < n && arr[i] != -1){
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if(i < n && arr[i] != -1){
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}