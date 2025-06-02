#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node
{
    int          data;
    struct node *prev, *next;
} Node;

// 1 initialise List
Node* initList()
{
    Node* L = (Node*)malloc(sizeof(Node));
    L->prev = NULL;
    L->next = NULL;

    return L;
}

// 2 insert element in the head
void insertHead(Node* L, ElemType element)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = element;
    node->prev = L;
    node->next = L->next;
    if (L->next != NULL) {
        L->next->prev = node;
    }
    L->next = node;
}

// 3 insert element in the tail
void insertTail(Node* L, ElemType element)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;

    Node* p = L;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next    = node;
    node->prev = p;
}

// 4 insert element anywhere
bool insertAnywhere(Node* L, int pos, ElemType element)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = element;

    Node* p   = L;
    int   ind = 0;
    while (ind < pos) {
        if (p == NULL) {
            printf("Position %d out of range", pos);
            return false;
        }

        p = p->next;
        ind++;
    }   // p point pos

    node->next       = p;
    node->prev       = p->prev;
    node->prev->next = node;

    p->prev = node;
    return true;
}

// 5 delete element
bool deleteNode(Node* L, int pos)
{
    Node* p   = L;
    int   ind = 0;

    while (ind < pos) {
        if (p == NULL) {
            printf("Position %d out of range", pos);
            return false;
        }
        p = p->next;
        ind++;
    }   // p point pos

    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    return true;
}

// 6 delete List
bool deleteList(Node* L)
{
    Node* p = L->next;   // current Node
    Node* q = NULL;
    L->next = NULL;

    while (p != NULL) {
        if (p->next == NULL)   // p is end
        {
            free(p);
            return true;
        }
        q = p->next;

        free(p);
        p = q;
    }
}

// 7 list element
void listNode(Node* L)
{
    Node* p = L->next;
    while (p != NULL) {
        printf("\t%d", p->data);
        p = p->next;
    }
    printf("\n");
}

// 8 get length
int getLength(Node* L)
{
    Node* p   = L->next;
    int   len = 0;

    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

int main()
{
    Node* head = initList();
    insertHead(head, (ElemType)1);
    insertHead(head, (ElemType)2);
    insertHead(head, (ElemType)3);
    listNode(head);

    insertTail(head, (ElemType)4);
    listNode(head);

    insertAnywhere(head, 3, (ElemType)5);
    listNode(head);

    deleteNode(head, 3);
    listNode(head);
    printf("length is %d\n",getLength(head));

    deleteList(head);
    listNode(head);

    printf("length is %d\n",getLength(head));

    return 0;
}