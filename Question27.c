#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* create(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insert(struct Node** head, int data) {
    struct Node* temp = create(data);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* t = *head;
    while (t->next)
        t = t->next;
    t->next = temp;
}
int length(struct Node* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}
struct Node* intersection(struct Node* h1, struct Node* h2) {
    int l1 = length(h1);
    int l2 = length(h2);
    int d = abs(l1 - l2);
    if (l1 > l2)
        while (d--) h1 = h1->next;
    else
        while (d--) h2 = h2->next;

    while (h1 && h2) {
        if (h1 == h2)
            return h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;
}
int main() {
    int n, m, i;
    struct Node *head1 = NULL, *head2 = NULL;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        insert(&head1, a[i]);
    }
    scanf("%d", &m);
    int b[m];
    for (i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        insert(&head2, b[i]);
    }
    struct Node *t1 = head1;
    while (t1) {
        struct Node *t2 = head2;
        while (t2) {
            if (t1->data == t2->data) {
                t2->next = t1->next;
                break;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    struct Node* ans = intersection(head1, head2);
    if (ans)
        printf("%d", ans->data);
    else
        printf("No Intersection");
    return 0;
}