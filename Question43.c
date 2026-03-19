#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Queue implementation */
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

/* Inorder Traversal */
void inorder(Node* root){
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){

    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(arr[0] == -1)
        return 0;

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

    return 0;
}