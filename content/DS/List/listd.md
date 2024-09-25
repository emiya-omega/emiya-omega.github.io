---
title : '线性表基本概念'
date : 2024-09-12T16:06:55Z
tags: ["DS"]
categories: ["学习笔记"]
draft : true
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
```
ADT List{
    数据对象：D={ai|ai∈ElemSet,i=1,2,...,n,n>=0}
    数据关系：R1={<ai-1,ai>|ai-1,ai∈D,i=2,3,...,n}
    基本操作：
        InitList(&L)
        DestroyList(&L)
        ClearList(&L)
        ListEmpty(L)
        ListLength(L)
        GetElem(L,i,&e)
        LocateElem(L,e)
        PriorElem(L,e,&pre_e)
        NextElem(L,e,&next_e)
}ADT List
```
## 线性表的顺序表示和实现
- 线性表的顺序表示又称为顺序存储结构或顺序映像
- 用一组地址连续的存储单元依次存储线性表中的数据元素，从而使得线性表中在逻辑结构上相邻的数据元素在物理存储位置上也相邻
- 顺序存储的线性表称为顺序表
- 顺序表的结构体定义
```
#define MaxSize 50
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;
```
- 顺序表的基本操作
```
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
## 线性表的链式表示和实现
- 线性表的链式表示又称为链式存储结构
- 用一组任意的存储单元存储线性表中的数据元素，这组存储单元可以是连续的，也可以是不连续的
- 链式存储的线性表称为链表
- 链表中的数据元素称为结点，每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储数据元素直接后继位置的指针域

- 结点结构体定义
```
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
```
- 链表的基本操作
```
//初始化链表
void InitList(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
}
//按位查找操作