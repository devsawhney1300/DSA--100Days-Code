#include<stdio.h>
#include<stdlib.h>

struct Node{int data;struct Node*next;};

struct Node*insert(struct Node*head,int data){
struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=NULL;
if(head==NULL)return newNode;
struct Node*temp=head;
while(temp->next!=NULL)temp=temp->next;
temp->next=newNode;
return head;
}

int count(struct Node*head,int key){
int c=0;
while(head!=NULL){
if(head->data==key)c++;
head=head->next;
}
return c;
}

int main(){
int n,x,key;
struct Node*head=NULL;

scanf("%d",&n);

for(int i=0;i<n;i++){
scanf("%d",&x);
head=insert(head,x);
}

scanf("%d",&key);

printf("%d",count(head,key));

return 0;
}