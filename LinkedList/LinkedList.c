//
// Created by zzype on 2023/11/20.
//

#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * 头插法建立单链表
 *  1.创建头节点(malloc)
 *  2.头节点指针域置空
 *  3.循环创建节点,并插入到头节点后面,即新节点的next指向头节点的next,头节点的next指向新节点
 *
 * @param L  头指针
 * @param n  节点个数
 */
void CreateListHead(LinkList *L, int n) {
  *L = (LinkList) malloc(sizeof(LNode));// 1.创建头节点(malloc)
  (*L)->next = NULL;                    // 2.头节点指针域置空
  LinkList p;
  for (int i = 0; i < n; ++i) {// 3.循环创建节点,并插入到头节点后面,即新节点的next指向头节点的next,头节点的next指向新节点
    p = (LinkList) malloc(sizeof(LNode));
    p->data = i;
    p->next = (*L)->next;
    (*L)->next = p;
  }
}

/**
 * 尾插法建立单链表
 *
 * @param L  头指针
 * @param n  节点个数
 */
void CreateListTail(LinkList *L, int n) {
  *L = (LinkList) malloc(sizeof(LNode));  // 1.创建头节点(malloc)
  (*L)->next = NULL;
  LinkList p, tail = *L;
  for (int i = 0; i < n; ++i) {                // 2.循环创建节点,并插入到尾节点后面,即新节点的next指向尾节点的next,尾节点的next指向新节点
    p = (LinkList) malloc(sizeof(LNode));
    p->data = i;
    p->next = NULL;
    tail->next = p;
    tail = p;
  }
}