---
title : '线性表'
date : 2024-09-14T05:23:59Z
tags: ["DS"]
categories: ["学习笔记"]
draft : false
---

# 线性表的基本概念

## 线性表的定义
- 线性表：具有相同特性的数据元素的有限序列
- 线性表中的数据元素称为元素
- 线性表中的数据元素个数称为线性表的长度，用n表示，n大于等于0，当n=0时，称为空表
```
A=(a1,a2,a3,...,an)
```
- 线性表中的数据元素ai(1<=i<=n)称为线性表中的第i个元素，ai的序号i称为元素ai在线性表中的位置
- 线性表中的第一个元素a1没有前驱，最后一个元素an没有后继，其余元素ai(2<=i<=n-1)既有前驱ai-1，也有后继ai+1
- 线性表中的数据元素之间是一对一的关系
## 线性表的抽象数据类型
```cpp
ADT List{
    数据对象：D={ai|ai∈ElemSet,i=1,2,...,n,n>=0}
    数据关系：R1={<ai-1,ai>|ai-1,ai∈D,i=2,3,...,n}
    基本操作：
        InitList(&L);
        DestroyList(&L);
        ClearList(&L);
        ListEmpty(L);
        ListLength(L);
        GetElem(L,i,&e);
        LocateElem(L,e);
        PriorElem(L,e,&pre_e);
        NextElem(L,e,&next_e);
}ADT List
```
# 线性表的顺序表示和实现
- 线性表的顺序表示又称为顺序存储结构或顺序映像
- 用一组地址连续的存储单元依次存储线性表中的数据元素，从而使得线性表中在逻辑结构上相邻的数据元素在物理存储位置上也相邻
- 顺序存储的线性表称为顺序表
- 顺序表的结构体定义
```cpp
#define MaxSize 50
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;
```
- 顺序表的基本操作
```cpp
//初始化线性表
void InitList(SqList &L){
    for(int i=0;i<MaxSize;i++){
        L.data[i]=0;
    }
    L.length=0;
}
//插入操作
bool ListInsert(SqList &L,int i,ElemType e){
    if(i<1||i>L.length+1){
        return false;
    }
    if(L.length>=MaxSize){
    
}
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}
//删除操作
bool ListDelete(SqList &L,int i,ElemType &e){
    if(i<1||i>L.length){
        return false;
    }
    e=L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}
//按位查找操作
ElemType GetElem(SqList L,int i){
    return L.data[i-1];
}
//按值查找操作
int LocateElem(SqList L,ElemType e){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}
```
# 线性表的链式表示和实现
- 线性表的链式表示又称为链式存储结构
- 用一组任意的存储单元存储线性表中的数据元素，这组存储单元可以是连续的，也可以是不连续的
- 链式存储的线性表称为链表
- 链表中的数据元素称为结点，每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储数据元素直接后继位置的指针域

- 结点结构体定义
```cpp
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
```
- 链表的基本操作
```cpp
//初始化链表
void InitList(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
}
//按位查找操作

LNode *GetElem(LinkList L,int i){
    int j=1;
    LNode *p=L->next;
    if(i==0){
        return L;
    }
    if(i<1){
        return NULL;
    }
    while(p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    return p;
}
//按值查找操作
LNode *LocateElem(LinkList L,ElemType e){
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
}
//插入操作
bool ListInsert(LinkList &L,int i,ElemType e){
    LNode *p=GetElem(L,i-1);//找到第i-1个结点   
    if(p==NULL){
        return false;
    }
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
//删除操作
bool ListDelete(LinkList &L,int i,ElemType &e){
    LNode *p=GetElem(L,i-1);
    if(p==NULL){
        return false;
    }
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}
```
## 建立单链表
- 头插法
```cpp
void CreateList_H(LinkList &L,int n){
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    for(int i=0;i<n;i++){
        LNode *p=(LNode *)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next=L->next;
        L->next=p;
    }
}
```
- 尾插法
```cpp
void CreateList_L(LinkList &L,int n){
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;

    LNode *r=L;
    for(int i=0;i<n;i++){
        LNode *p=(LNode *)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        r->next=p;
        r=p;
    }
    r->next=NULL;
}
```
## 双向链表
- 双向链表的结构体定义
```cpp
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinkList;
```
- 双向链表的基本操作
```cpp
//初始化双向链表
void InitDList(DLinkList &L){
    L=(DLinkList)malloc(sizeof(DNode));
    L->prior=NULL;
    L->next=NULL;
}
//按位查找操作
DNode *GetElem(DLinkList L,int i){
    int j=1;
    DNode *p=L->next;
    if(i==0){
        return L;
    }
    if(i<1){
        return NULL;
    }
    while(p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    return p;
}
//按值查找操作
DNode *LocateElem(DLinkList L,ElemType e){
    DNode *p=L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
}
//插入操作
bool ListInsert(DLinkList &L,int i,ElemType e){
    DNode *p=GetElem(L,i-1);//找到第i-1个结点   
    if(p==NULL){
        return false;
    }
    DNode *s=(DNode *)malloc(sizeof(DNode));
    s->data=e;
    s->next=p->next;
    s->prior=p;
    if(p->next!=NULL){
        p->next->prior=s;
    }
    p->next=s;
    return true;
}
//删除操作
bool ListDelete(DLinkList &L,int i,ElemType &e){
    DNode *p=GetElem(L,i-1);
    if(p==NULL){
        return false;
    }
    DNode *q=p->next;
    e=q->data;
    p->next=q->next;
    if(q->next!=NULL){
        q->next->prior=p;
    }
    free(q);
    return true;
}
```
## 线性表的顺序表示和链式表示的比较
- 顺序表
    - 优点：可以随机存取，存储密度高
    - 缺点：大片连续空间分配不方便，改变容量不方便
- 链表
    - 优点：离散的小空间分配方便，改变容量方便
    - 缺点：不可随机存取，存储密度低
# 线性表的应用
## 线性表的合并
- 假设线性表La和Lb分别表示两个集合A和B，现要求一个新的集合A∪B
- 合并操作
```cpp
void unionL(LList &La,LList Lb){
    int La_len=Llength(La);
    int Lb_len=Llength(Lb);
    for(int i=1;i<=Lb_len;i++){
        ElemType e;
        GetElem(Lb,i,e);
        if(!LocateElem(La,e)){
            ListInsert(La,++La_len,e);
        }
    }
}
``` 
## 静态链表
- 静态链表的结构体定义
```cpp
#define MaxSize 50
typedef struct{
    ElemType data;
    int next;
}SLinkList[MaxSize];
```
- 静态链表的基本操作
```cpp
//初始化静态链表
void InitList(SLinkList &L){
    for(int i=0;i<MaxSize-1;i++){
        L[i].next=i+1;
    }
    L[MaxSize-1].next=0;
}
//按位查找操作
int GetElem(SLinkList L,int i){
    if(i<1||i>MaxSize){
        return 0;
    }
    return L[i].next;
}
//按值查找操作
int LocateElem(SLinkList L,ElemType e){
    int i=1;
    while(i!=0&&L[i].data!=e){
        i=L[i].next;
    }
    return i;
}
//插入操作
bool ListInsert(SLinkList &L,int i,ElemType e){
    int j=GetElem(L,0);
    int k=0;
    for(int l=1;l<i;l++){
        k=j;
        j=L[j].next;
    }
    int q=GetElem(L,0);
    L[0].next=j;
    L[j].next=q;
    L[k].next=i;
    L[i].data=e;
    L[i].next=q;
    return true;
}
//删除操作
bool ListDelete(SLinkList &L,int i,ElemType &e){
    int j=GetElem(L,0);
    int k=0;
    for(int l=1;l<i;l++){
        k=j;
        j=L[j].next;
    }
    int q=L[j].next;
    e=L[j].data;
    L[j].next=L[q].next;//将q结点从链表中断开
    L[q].next=GetElem(L,0);//回收结点q
    L[0].next=j;
    return true;
}
```
- 静态链表的使用跟顺序表一样，都需要预先分配较大的空间
- 在进行插入删除操作时，只需要改变指针的指向，不需要移动元素，所以时间复杂度为O(1)
- 静态链表也可以用于解决哈希冲突问题
## 循环链表
- 循环链表的结构体定义
```cpp
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
```
- 循环链表的基本操作
```cpp
//初始化循环链表
void InitList(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));
    L->next=L;
}
//按位查找操作
LNode *GetElem(LinkList L,int i){
    int j=1;
    LNode *p=L->next;
    if(i==0){
        return L;
    }
    if(i<1){
        return NULL;
    }
    while(p!=L&&j<i){
        p=p->next;
        j++;
    }
    return p;
}
//按值查找操作
LNode *LocateElem(LinkList L,ElemType e){
    LNode *p=L->next;
    while(p!=L&&p->data!=e){
        
    }
}
//插入操作
bool ListInsert(LinkList &L,int i,ElemType e){
    LNode *p=GetElem(L,i-1);
    if(p == NULL){
        return false;
    }
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
//删除操作
bool ListDelete(LinkList &L,int i,ElemType &e){
    LNode *p=GetElem(L,i-1);
    if(p==NULL){
        return false;
    }
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}
```
- 特点
    - 表中最后一个结点的指针指向头结点而不再是NULL，整个链表形成一个环
    - 从表中任一结点出发均可找到链表中的其他结点
    - 循环链表可以避免单链表判空操作
    - 循环链表的最后一个结点的next指针指向头结点
    - 循环链表可以用来解决约瑟夫环问题
# 有序表
## 有序表定义
- 有序表是一种线性表，其元素是按关键字有序排列的
- 所有元素以递增or递减方式有序排列的线性表称为有序表
- 有序表和线性表的逻辑结构相同，区别是个别运算不同
- 以顺序结构进行存储时，其中只有ListInsert()基本运算有所差异，其余基本相同。
- 有序顺序表的ListInsert()运算
```cpp
void ListInsert(SqList &L,int i,ElemType e){
    int j;
    for(j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
}
```
  
## 有序表的查找
- 有序表的查找
    - 二分查找
    - 插值查找
    - 斐波那契查找
- 二分查找
    - 假设有序表为L，要查找的元素为e，L的长度为n，则查找过程如下：
        - 取L的中间元素L[mid]，如果L[mid]==e，则查找成功，返回mid
        - 如果L[mid]>e，则在L的左半部分继续查找
        - 如果L[mid]<e，则在L的右半部分继续查找
## TBD