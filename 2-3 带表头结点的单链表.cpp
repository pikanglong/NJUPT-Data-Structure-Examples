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
    struct Node *link;
} Node;
typedef struct
{
    struct Node *head;
    int n;
} HeaderList;

Status Init(HeaderList *h)
{
    h->head = (Node *)malloc(sizeof(Node));
    if (!h->head)
        return ERROR;
    h->head->link = NULL;
    h->n = 0;
    return OK;
}

Status Find(HeaderList h, int i, ElemType *x)
{
    Node *p;
    int j;
    if (i < 0 || i > h.n - 1)
        return ERROR;
    p = h.head->link;
    for (j = 0; j < i; j++)
        p = p->link;
    *x = p->element;
    return OK;
}

Status Insert(HeaderList *h, int i, ElemType x)
{
    if (i < -1 || i > h->n - 1)
        return ERROR;
    Node *p = h->head;
    for (int j = 0; j <= i; j++)
        p = p->link;
    Node *q = (Node *)malloc(sizeof(Node));
    q->element = x;
    q->link = p->link;
    p->link = q;
    h->n++;
    return OK;
}

Status Delete(HeaderList *h, int i)
{
    int j;
    Node *p, *q;
    if (!h->n)
        return ERROR;
    if (i < 0 || i > h->n - 1)
        return ERROR;
    q = h->head;
    for (j = 0; j < i; j++)
        q = q->link;
    p = q->link;
    q->link = p->link;
    free(p);
    h->n--;
    return OK;
}

Status Output(HeaderList h)
{
    Node *p;
    if (!h.n)
        return ERROR;
    p = h.head->link;
    while (p)
    {
        printf("%d ", p->element);
        p = p->link;
    }
    return OK;
}

void Destroy(HeaderList *h)
{
    Node *p, *q;
    q = h->head->link;
    while (q)
    {
        p = q->link;
        free(q);
        q = p;
    }
    free(h->head);
}

int main()
{
    int i;
    int x;
    HeaderList list;
    Init(&list);
    for (i = 0; i < 9; i++)
        Insert(&list, i - 1, i);
    printf("the linklist is: ");
    Output(list);
    Delete(&list, 0);
    printf("\nthe linklist is: ");
    Output(list);
    Find(list, 0, &x);
    printf("\nthe value is: %d", x);
    Destroy(&list);
    return 0;
}
