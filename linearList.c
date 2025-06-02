#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
    ElemType maxValue;
    ElemType minValue;
} SeqList;

void showInfo(SeqList *List)
{
    printf("\n");
    printf("\t***List length is: %d\n", List->length);
    printf("\t***Max value is: %d\n", List->maxValue);
    printf("\t***Min value is: %d\n", List->minValue);
    printf("\t***Usage: %d%%\n", (List->length) * 100 / MAXSIZE);
    printf("\n");
}

void initList(SeqList *List)
{
    List->length = 0;
    List->maxValue = (ElemType)0;
    List->minValue = (ElemType)0;
}

bool appendElem(SeqList *List, ElemType element)
{
    if (List->length >= MAXSIZE)
    {
        printf("The sequential list is full\n");
        return false;
    }

    (List->data)[List->length] = element;
    List->length += 1;
    return true;
}

bool insertElem(SeqList *List, int pos, ElemType element)
{
    if (pos < 1 || pos > List->length)
    {
        return 0;
    }

    if (List->length >= MAXSIZE)
    {
        return 0;
    }

    for (int i = List->length - 1; i >= pos - 1; i--)
    {
        List->data[i + 1] = List->data[i];
    }
    List->data[pos - 1] = element;
    List->length++;

    return true;
}

bool deleteElem(SeqList *List, int pos, ElemType *element)
{
    if (pos <= List->length)
    {
        *element = List->data[pos - 1];
        for (int i = pos; i < List->length; i++)
        {
            List->data[i - 1] = List->data[i];
        }
        List->length--;
        return true;
    }
    return false;
}

ElemType findElem(SeqList *List, ElemType element)
{
    if (List->length == 0)
    {
        printf("List is empty.\n");
        return 0;
    }

    for (int i = 0; i < List->length - 1; i++)
    {
        if (List->data[i] == element)
            return i + 1;
    }

    printf("The element is not in this List.\n");
    return 0;
}

void deleteList(SeqList *List)
{
    List->length = 0;
}

ElemType getLength(SeqList *List)
{
    return List->length;
}

void listElem(SeqList *List)
{
    for (int i = 0; i < List->length; i++)
    {
        printf(" %d ", List->data[i]);
    }
    showInfo(List);
    printf("\n");
}

void checkout(bool b)
{
    if (b == false)
        printf("\terror...\n");
}

int main()
{
    // initialize
    SeqList myList;
    initList(&myList);
    showInfo(&myList);

    // append elements
    checkout(appendElem(&myList, 5));
    checkout(appendElem(&myList, 100));
    checkout(appendElem(&myList, 32));
    checkout(appendElem(&myList, 8));
    listElem(&myList);

    // insert elements
    checkout(insertElem(&myList, 2, 3218));
    listElem(&myList);

    // delete elements
    ElemType deleteElemValue;
    checkout(deleteElem(&myList, 2, &deleteElemValue));
    printf("\tDeleted element: %d\n", deleteElemValue);
    listElem(&myList);

    // find elements
    ElemType e = 1000;
    printf("The position of %d is %d.\n", e, findElem(&myList, e));

    // get length
    printf("The length of List is %d\n",getLength(&myList));
    // delete List
    deleteList(&myList);
    listElem(&myList);

    return 0;
}