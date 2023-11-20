//
// Created by zzype on 2023/11/20.
//

#ifndef DATASTRUCTURE_LINKEDLIST_LINKEDLIST_H_
#define DATASTRUCTURE_LINKEDLIST_LINKEDLIST_H_

#endif//DATASTRUCTURE_LINKEDLIST_LINKEDLIST_H_


//定义一个单链表
typedef struct LNode {
  int data;
  struct LNode *next;
} LNode, *LinkList;

//头插法建立单链表
void CreateListHead(LinkList *L, int n);

//尾插法建立单链表
void CreateListTail(LinkList *L, int n);

//打印单链表
void PrintList(LinkList L);

//按位查找
LNode *GetElem(LinkList L, int i);

//按值查找
LNode *LocateElem(LinkList L, int e);

//插入操作
int ListInsert(LinkList *L, int i, int e);

//删除操作
int ListDelete(LinkList *L, int i, int *e);

