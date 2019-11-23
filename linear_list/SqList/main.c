/**
 * 线性表的动态分配顺序储存结构
 * */

#include "c1.h"
typedef int ElemType;

// 线性表的动态分配顺序储存结构
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

typedef struct {
    ElemType *elem; // 储存空间基址
    int length;      // 当前长度
    int listSize;    // 当前分配的存储容量（以sizeof(ElemType）为单位)
} SqList;

/**
 * 初始化线性表
 * @param L
 * @return
 */
Status InitList(SqList* L) {
    // 构造一个空的线性表L
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
       exit(OVERFLOW);
    }
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return OK;
}

Status DestroyList(SqList *L)
{
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listSize = 0;
    return OK;
}


Status ClearList(SqList *L) {
    L->length = 0;
    return OK;
}

Status ListEmpty(SqList L) {
    if (L.length == 0) {
        return TRUE;
    }

    return FALSE;
}

int ListLength(SqList L) {
    return L.length;
}

Status GetElem(SqList L, int i, ElemType *e) {
    if (i < 1 || i > L.length) {
        exit(ERROR);
    }

    *e = *(L.elem + i -1);
    return OK;
}

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    // 初始条件：线性表已存在，compare()是数据元素判定该函数
    // 操作结果：返回L中第一个与e满足关系compare()的数据元素的维续，若这样的数据元素不存在则返回值为0
    ElemType *p;
    int i = 1;
    p = L.elem;
    while (i <= L.length && !(*compare)(*p++, e)){
        i++;
    }

    if (i <= L.length){
        return i;
    }
    return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
    // 初始条件：顺序线性表L已存在
    // 操作结果： 若cur_e 是L的数据元素，且不是第一个，则用pre_e返回它的直接前驱
    // 否则操作失败，pre_e无定义
    int i = 2;
    ElemType *p = L.elem + 1;

    while (i <= L.length && *p != cur_e) {
        p++;
        i++;
    }

    if (i <= L.length) {
        *pre_e = *--p;
        return OK;
    }

    return INFEASIBLE;
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{
    // 初始条件： 顺序线性表已存在
    // 操作结果: 若cur_e 是L的数据元素，且不是最后一个，则用pre_e返回它的直接后继
    // 否则操作失败，pre_e无定义

    int i = 1;
    ElemType *p = L.elem;
    while (i <= L.length - 1 && *p != cur_e)
    {
        i++;
        p++;
    }

    if (i <= L.length - 1){
        *next_e = *(p++);
        return OK;
    }

    return INFEASIBLE;
}
/**
 * 插入元素
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListInsert(SqList* L, int i, ElemType e) {
    // 初始条件：顺序线性表L已存在，1 <= i <= ListLength(L)+1
    // 操作结果： 在L中第i个位置之前插入新的数据元素e, L的长度加1
    if (i<1 || i > L->length + 1){
        return ERROR;
    }
    if (L->length >= L->listSize){
        ElemType* newbase = (ElemType *)realloc(L->elem, (L->listSize + LIST_INCREMENT) * sizeof(ElemType));
        if (!newbase) {
            exit(OVERFLOW);
        }
        L->elem = newbase;
        L->listSize += LIST_INCREMENT;
    }
    ElemType* q = L->elem + i - 1;

    for (ElemType* p = L->elem + L->length - 1; p >= q; --p) {
        *(p+1) = *p;
    }
    *q = e;
    ++L->length;
    return OK;
}

/**
 * 删除元素
 * @return
 */
Status ListDelete(SqList *L, int i, ElemType *e) {
    /* 初始条件：循序线性表L已存在，1<=i<=ListLength(L) */
    // 操作结果：删除Ld的第i个数据元素，并用e返回其值
    if (i < 1 || i > L->length) {
        return ERROR;
    }

    *e = *(L->elem + i - 1); // 第i个数据元素的地址
    ElemType *p = L->elem + L->length -1; // 最后一个数据元素的地址
    for (ElemType *q = L->elem + i; q <= p; ++q) {
        *(q - 1) = *q;
    }
    L->length--;
    return OK;
}

Status  ListTraverse(SqList L, void(*vi)(ElemType*))
{
    ElemType *p;
    int i;

    p = L.elem;

    for (int i = 0; i <= L.length - 1; ++i) {
        vi(p++);
    }
    printf("\n");
    return OK;
}

Status equal(ElemType c1, ElemType c2) {
    if(c1 == c2) {
        return TRUE;
    }
    return FALSE;
}

void Union(SqList *La, SqList Lb) {
    // 将所有在线性表Lb 中但是不再La中的数据元素插入到La中

    for (int i = i;  i< Lb.length; i++) {
        ElemType *e = Lb.elem + i;
        if(LocateElem(*La, *e, equal) == INFEASIBLE) {
            ListInsert(La, La->length + 1, *e);
        }
    }
}

void print(ElemType *c)
{
    printf("%d\n", *c);
}

void MergeList(SqList La, SqList Lb, SqList *Lc){
    int i =1, j = 1, k = 0, La_len, Lb_len;
    La_len = La.length;
    Lb_len = Lb.length;

    ElemType ai, bj;

    InitList(Lc);

    while (i <= La_len && j <= Lb_len) {
        GetElem(La, i, &ai);
        GetElem(Lb, j, &bj);

        if (ai >= bj){
            ListInsert(Lc, ++k, bj);
            j++;
        }else {
            ListInsert(Lc, ++k, ai);
            i++;
        }
    }

    while (i <= La_len) {
        GetElem(La, i++, &ai);
        ListInsert(Lc, ++k, ai);
    }
    while (j <= Lb_len) {
        GetElem(Lb, j++, &bj);
        ListInsert(Lc, ++k, bj);
    }
}

int main() {
    SqList La, Lb;
    Status i;
    int j;

    i =  InitList(&La);
    if (i == 1) {
        for (int j = 0; j < 5; ++j) {
            i = ListInsert(&La, j, j);
        }
    }

    ListTraverse(La, print);

    i = InitList(&Lb);
    if (i == 1) {
        for (int j = 0; j < 5; ++j) {
            i = ListInsert(&Lb, j, j+2);
        }
    }

    ListTraverse(Lb, print);

    SqList Lc;
    MergeList(La, Lb, &Lc);
    ListTraverse(Lc, print);



//
//    ElemType c;
//    ListDelete(&La, 2, &c);
//    ListTraverse(La, print);
//    print(&c);

    printf("Hello, World!\n");
    return 0;
}