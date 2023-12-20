//
// Created by zzype on 2023/11/20.
//

#ifndef DATASTRUCTURE_LINKEDLIST_LINKEDLIST_H_
#define DATASTRUCTURE_LINKEDLIST_LINKEDLIST_H_

#endif//DATASTRUCTURE_LINKEDLIST_LINKEDLIST_H_


/**
 * 定义一个单链表 <P>
 * 指针域为next <P>
 * 数据域为data <P>
 * 头节点 头指针 首元节点 首元指针区别
 * 头节点: 是一个节点,为了方便操作,在单链表的第一个节点之前附加一个节点,称为头节点,头节点的数据域可以不存储任何信息,也可以存储如链表的长度等附加信息,存在意义是为了方便操作,使得所有节点都有前驱节点
 * 头指针: 是一个指针,指向头节点的指针,头指针是链表的必要元素
 * 首元节点: 第一个存储数据的节点
 * 首元指针: 指向首元节点的指针,首元指针是链表的必要元素
 */
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

