#include <stdlib.h>
#include <stdio.h>

#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType element;
    struct Node *lLink;
    struct Node *rLink;
} Node;
typedef struct
{
    struct Node *first;
    int n;
} DoublyList;

Status Init(DoublyList *L)
{
    L->first = NULL;
    L->n = 0;
    return OK;
}

Status Find(DoublyList L, int i, ElemType *x)
{
    Node *p;
    int j;
    if (i < 0 || i > L.n - 1)
        return ERROR;
    p = L.first;
    for (j = 0; j < i; j++)
        p = p->rLink;
    *x = p->element;
    return OK;
}

Status Insert(DoublyList *L, int i, ElemType x)
{
    Node *p, *q;
    int j;
    if (i < -1 || i > L->n - 1)
        return ERROR;
    p = L->first;
    for (j = 0; j < i; j++)
        p = p->rLink;
    q = (Node *)malloc(sizeof(Node));
    q->element = x;
    if (i > -1)
    {
        q->rLink = p->rLink;
        q->lLink = p;
        if (p->rLink != NULL)
            p->rLink->lLink = q;
        p->rLink = q;
    }
    else
    {
        q->lLink = NULL;
        q->rLink = L->first;
        if (q->rLink != NULL)
            q->rLink->lLink = q;
        L->first = q;
    }
    L->n++;
    return OK;
}

Status Delete(DoublyList *L, int i)
{
    int j;
    Node *p, *q;
    if (!L->n)
        return ERROR;
    if (i < 0 || i > L->n - 1)
        return ERROR;
    q = L->first;
    p = L->first;
    for (j = 0; j < i - 1; j++)
        q = q->rLink;
    if (i == 0)
    {
        if (L->first->rLink != NULL)
            L->first->rLink->lLink = NULL;
        L->first = L->first->rLink;
    }
    else
    {
        p = q->rLink;
        q->rLink = p->rLink;
        if (p->rLink != NULL)
            p->rLink->lLink = q;
    }
    free(p);
    L->n--;
    return OK;
}

Status Output(DoublyList L)
{
    Node *p;
    if (!L.n)
        return ERROR;
    p = L.first;
    while (p)
    {
        printf("%d ", p->element);
        p = p->rLink;
    }
    return OK;
}

void Destroy(DoublyList *L)
{
    Node *p;
    while (L->first)
    {
        p = L->first->rLink;
        free(L->first);
        L->first = p;
    }
}

int main()
{
    int i;
    int x;
    DoublyList list;
    Init(&list);
    for (i = 0; i < 9; i++)
        Insert(&list, i - 1, i);
    printf("the doublylist is: ");
    Output(list);
    Delete(&list, 0);
    printf("\nthe doublylist is: ");
    Output(list);
    Find(list, 0, &x);
    printf("\nthe value is: %d", x);
    Destroy(&list);
}
