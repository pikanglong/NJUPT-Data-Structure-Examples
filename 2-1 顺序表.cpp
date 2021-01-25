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
typedef struct
{
    int n;
    int maxLength;
    ElemType *element;
} SeqList;

// 初始化运算。构造一个空的线性表L，若初始化成功，则返回OK，否则返回ERROR。
Status Init(SeqList *L, int mSize)
{
    L->maxLength = mSize;
    L->n = 0;
    L->element = (ElemType *)malloc(sizeof(ElemType) * mSize);
    if (!L->element)
        return ERROR;
    return OK;
}

// 撤销运算。判断线性表L是否存在，若已存在，则撤销线性表L；否则，返回ERROR。
Status Destroy(SeqList *L)
{
    if (!L->n)
        return ERROR;
    (*L).n = 0;
    (*L).maxLength = 0;
    free((*L).element);
    return OK;
}

// 判空运算。判断线性表L是否为空，若为空，则返回OK；否则返回ERROR。
Status IsEmpty(SeqList L)
{
    if (!L.n)
        return OK;
    return ERROR;
}

// 求长度运算。若线性表L已存在，返回线性表L的元素个数；否则返回ERROR。
Status Length(SeqList L)
{
    if (!L.n)
        return ERROR;
    return L.n;
}

// 查找运算。若线性表L已存在且0≤i≤n-1，则查找线性表L中元素a_i的值并通过x返回；否则，返回ERROR。
Status Find(SeqList L, int i, ElemType *x)
{
    if (i < 0 || i > L.n - 1)
        return ERROR;
    *x = L.element[i];
    return OK;
}

// 插入运算。若线性表L已存在且-1≤i≤n-1，则在元素a_i之后插入新元素x，插入成功后返回OK，否则返回ERROR。
Status Insert(SeqList *L, int i, ElemType x)
{
    int j;
    if (i < -1 || i > L->n - 1)
        return ERROR;
    if (L->n == L->maxLength)
        return ERROR;
    for (j = L->n - 1; j > i; j--)
        L->element[j + 1] = L->element[j];
    L->element[i + 1] = x;
    L->n = L->n + 1;
    return OK;
}

// 删除运算。若线性表L非空且0≤i≤n-1，则删除元素a_i，删除成功后返回OK，否则返回ERROR。
Status Delete(SeqList *L, int i)
{
    int j;
    if (i < 0 || i > L->n - 1)
        return ERROR;
    if (!L->n)
        return ERROR;
    for (j = i + 1; j < L->n; j++)
        L->element[j - 1] = L->element[j];
    L->n--;
    return OK;
}

// 更新运算。若线性表L已存在且0≤i≤n-1，则将线性表L元素a_i的值修改为x，否则返回ERROR。
Status Update(SeqList *L, int i, ElemType x)
{
    if (i < 0 || i > L->n - 1)
        return ERROR;
    L->element[i] = x;
    return OK;
}

// 输出运算。若线性表L已存在，则输出线性表L中所有数据元素，否则返回ERROR。
Status Output(SeqList L)
{
    int i;
    if (!L.n)
        return ERROR;
    for (i = 0; i <= L.n - 1; i++)
        printf("%d ", L.element[i]);
    printf("\n");
    return OK;
}

int main()
{
    int i;
    SeqList list;
    Init(&list, 10);
    for (i = 0; i < 9; i++)
        Insert(&list, i - 1, i);
    Output(list);
    Delete(&list, 0);
    Output(list);
    Destroy(&list);
    return 0;
}
