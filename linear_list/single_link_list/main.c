/**
 * 线性表的单链表存储结构
 */
#include <stdio.h>
#include "c1.h"

typedef int ElemType;
struct LNode {
    ElemType data;
    struct LNode *next;
};

typedef struct LNode *LinkList;

Status InitList(LinkList *L)
{
    // 操作结果： 构造一个空的线性表
    *L = (LinkList)malloc(sizeof(struct LNode)); // 产生头结点
    if (!*L){
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    return OK;
}

Status DestroyList(LinkList *L) {
    // 初始条件：线性表L已存在，
    // 操作结果： 销毁线性表L
    LinkList q;
    while (*L) {
        q = (*L)->next;
        free(*L);
        *L = q;
    }
    return OK;
}

Status ClearList(LinkList L)
{
    // 初始条件：线性表L已存在，
    // 操作结果： 将L重置为空表
    LinkList p,q;
    p = L->next; // p 指向第一个结点

    while (p) {
        q = p->next; // q 指向 p 的后继结点
        free(p); // 释放p指向的结点
        p = q; // 将p指向后继结点
    }
    L->next = NULL;
    return OK;
}

Status ListEmpty(LinkList L)
{
    // 初始条件：线性表L已存在，
    // 操作结果： 若L为空表，则返回TRUE,否则返回FALSE
    if (L->next){
        return FALSE;
    }

    return TRUE;
}

int ListLength(LinkList L) {
    // 初始条件：线性表L已存在，
    // 操作结果： 返回L中数据元素的个数
    int i = 0;
    LinkList p = L->next;

    while (p) {
        i++;
        p = p->next;
    }

    return i;
}

/*
 * L 为待头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK,否则返回ERROR
 */
Status GetElem(LinkList L, int i, ElemType *e) {
    // 初始条件：线性表L已存在，
    // 操作结果： 为待头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK,否则返回ERROR
    int j = 1;
    LinkList p = L->next;

    while (p && j < i ){
        p = p->next;
        j++;
    }

    if (!p || j > i){
        return ERROR;
    }

    *e = p->data;
    return OK;
}

int LocateElem(LinkList L, ElemType e, Status(*compare(ElemType, ElemType)))
{
    // 初始条件：线性表L已存在，compare()是数据原属判断函数（满足为1，否则为0)
    // 操作结果： 返回L中第1个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在,则返回值为0
    int i = 0;
    LinkList  p = L->next;
    while (p) {
        i++;
        if ((*compare)(p->data, e)){
            return i;
        }
        p = p->next;
    }

    return 0;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e) {
    // 初始条件：线性表L已存在，compare()是数据原属判断函数（满足为1，否则为0)
    // 操作结果： 若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱, 返回OK;否则操作失败,pre_e无定义,返回INFEASIBLE
    LinkList q, p = L->next;
    while (p->next){
        q = p->next;
        if (q->data == cur_e) {
            *pre_e = p->data;
            return OK;
        }
        p = q;
    }

    return INFEASIBLE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
    LinkList p = L->next;
    while (p->next) {
        if (p->data == cur_e) {
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }

    return INFEASIBLE;
}

Status ListInsert(LinkList L, int i, ElemType e)
{
    // 寻找第i-1个结点
    int j = 0;
    LinkList p = L, s;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }

    if (!p || j > i - 1) {
        return ERROR;
    }

    // 生产新的结点
    s = (LinkList) malloc(sizeof(struct LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

Status ListDelete(LinkList L, int i, ElemType *e) {
    // 寻找第i个结点
    int j = 0;
    LinkList p = L;
    while (p && j < i -1){
        p = p->next;
        j++;
    }

    if(!p->next || j > i - 1) {
        return ERROR;
    }

    LinkList q;
    q = p->next;

    *e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

Status ListTraverse(LinkList L, void(*vi)(ElemType))
{
    LinkList p = L->next;
    while (p)
    {
        vi(p->data);
        p = p->next;
    }

    printf("\n");

    return OK;
}

void CreateList_1(LinkList *L, int n) {
    // 逆位序(插在表头)输入n个元素的值，建立带表头结点的单链线性表L
    *L = (LinkList)malloc(sizeof(struct LNode));
    LinkList p;
    for (int i = 0; i < n; ++i) {
        p = (LinkList)malloc(sizeof(struct LNode));
        scanf("%d", &p->data);
        p->next = (*L)->next;
        (*L)->next = p;
    }
}
Status CreateList_2(LinkList *L, int n) {
    // 正位序(插在表尾)输入n个元素的值，建立带表头结点的单链线性表L

    if (n < 1) {
        return ERROR;
    }
    *L = (LinkList)malloc(sizeof(struct LNode));
    LinkList p, q;
    q = *L; // 初始化q 执行头结点

    for (int i = 0; i < n; ++i) {
        p = (LinkList)malloc(sizeof(struct LNode));
        scanf("%d", &p->data);
        q->next = p;
        q = q->next; // 后移动一位
    }

    p->next = NULL;

    return OK;
}

void MergeList(LinkList *La,LinkList *Lb,LinkList *Lc) {
    /* 已知单链线性表La和Lb的元素按值非递减排列。 */
    /* 归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列 */
    LinkList pa, pb, pc;
    pa = (*La)->next;
    pb = (*Lb)->next;
    pc = (*Lc) = (*La); // 将La的头结点赋给*Lc， La Lc 只想同一个头结点

    while (pa && pb) {
        if (pa->data < pb->data){
            pc->next = pa;
            pa = pa->next;
        } else{
            pc->next = pb;
            pb = pb->next;
        }
        pc = pc->next;
    }

    pc->next = pa ? pa : pb;
}


void print(ElemType e){
    printf("%d\n", e);
}

int main() {
    LinkList La;
    LinkList Lb;
    LinkList Lc;
    CreateList_2(&La, 3);
    CreateList_2(&Lb, 3);
    MergeList(&La, &Lb, &Lc);
    ListTraverse(Lc, print);
    return 0;
}