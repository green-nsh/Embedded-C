#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// 1 create Node struct
typedef struct node
{
    ElemType     data;
    struct node* next;
} Node;

// 2 initialize linkedList
Node* initList()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;

    return head;
}

// 3 insert element in the head
bool insertHead(Node* L, ElemType element)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->data = element;
    node->next = L->next;

    L->next = node;

    return true;
}

// 4 insert element in the tail
bool insertTail(Node* L, ElemType element)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;

    Node* p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = node;

    return true;
}

// 5 insert element anywhere
bool insertNode(Node* L, int pos, ElemType element)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = element;

    int   ind = 0;
    Node* p   = L;

    while (p->next != NULL) {
        ind++;
        if (ind == pos) {
            node->next = p->next;
            p->next    = node;
            return true;
        }
        p = p->next;   // indth node
    }

    // if out of range
    printf("position %d out of range", pos);
    return false;
}

// 6 delete element
bool deleteNode(Node* L, int pos)
{
    int   ind = 0;
    Node* p   = L;
    Node* q   = NULL;

    while (ind < pos) {
        if (ind == pos - 1) {
            q = p;   // q -> last
        }

        if (p->next == NULL) {
            return 0;
        }
        ind++;
        p = p->next;

    }   // p -> current

    q->next = p->next;
    free(p);
    return true;
}

// 7 list linkedList
void listNode(Node* L)
{
    Node* p = L->next;
    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

// 8 get LinkedList length
int getLength(Node* L)
{
    Node* p   = L;
    int   len = 0;

    while (p->next != NULL) {
        p = p->next;
        len++;
    }

    return len;
}

// 9 free LinkedList
void freeNode(Node* L)
{

    Node* p = L;
    Node* q;

    while (p != NULL) {
        p = p->next;
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

// 10 find the kth element from the end
bool findEndK(Node* L, int k, ElemType* result)
{
    Node* slowP = L;
    Node* fastP = L;

    for (int i = 0; i < k; i++) {
        if (fastP->next == NULL) return false;
        fastP = fastP->next;
    }

    while (fastP != NULL) {
        fastP = fastP->next;
        slowP = slowP->next;
    }

    *result = slowP->data;
    return true;
}

int main()
{
    // head node
    Node* head = initList();

    // append node (head)
    insertHead(head, (ElemType)10);
    insertHead(head, (ElemType)20);
    insertHead(head, (ElemType)30);
    insertHead(head, (ElemType)40);
    insertHead(head, (ElemType)50);
    listNode(head);

    // append node (tail)
    insertTail(head, (ElemType)0);

    // append node (anywhere)
    insertNode(head, 3, (ElemType)0);

    // list linkedlist
    listNode(head);

    // delete element
    deleteNode(head, 3);
    deleteNode(head, 1);
    listNode(head);

    // get length
    printf("The length of LinkedList: %d\n", getLength(head));

    // free LinkedList
    // freeNode(head);
    listNode(head);

    // find kth element from the end
    ElemType result;
    findEndK(head, 2, &result);
    printf("the kth element from the end : %d\n", result);

    findEndK(head, 1, &result);
    printf("the kth element from the end : %d\n", result);

    findEndK(head, 5, &result);
    printf("the kth element from the end : %d\n", result);


    return 0;
}