#include <stdio.h>
#include <stdlib.h>

/*Object Oriented*/

// attribute
typedef struct
{
    double x;
    double y;
    double z;
} point;

// method
void swap(point *p1, point *p2)
{
    point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void printPoint(point *p)
{
    printf("Point coordinates: x = %.2f, y = % .2f, z = %.2f\n", p->x, p->y, p->z);
}

int main()
{
    point *arr = malloc(2 * sizeof(point));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("address of p1: %p\n", &arr[0]);
    printf("address of p2: %p\n", &arr[1]);

    (arr)->x = 1;
    (arr)->y = 2;
    (arr)->z = 3;
    (arr + 1)->x = 4;
    (arr + 1)->y = 5;
    (arr + 1)->z = 6;

    printPoint(arr);
    printPoint(arr + 1);

    swap(arr, arr + 1);

    printPoint(arr);
    printPoint(arr + 1);
    return 0;
}
