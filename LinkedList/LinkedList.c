//
// Created by zzype on 2023/11/20.
//

#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * 头插法建立单链表<P>
 *  1.创建头节点(malloc) <P>
 *  2.头节点指针域置空  <P>
 *  3.循环创建节点,并插入到头节点后面,即新节点的next指向头节点的next,头节点的next指向新节点
 * @param L  头指针
 * @param n  节点个数
 */
void CreateListHead(LinkList *L, int n) {
  // 1.创建头节点(malloc)
  *L = (LinkList) malloc(sizeof(LNode));
  // 2.头节点指针域置空
  (*L)->next = NULL;
  // 3.循环创建节点,并插入到头节点后面,即新节点的next指向头节点的next,头节点的next指向新节点
  LinkList p;
  for (int i = 0; i < n; ++i) {
    p = (LinkList) malloc(sizeof(LNode));
    p->data = i;
    p->next = (*L)->next;
    (*L)->next = p;
  }
}

/**
 * 尾插法建立单链表
 * 1.创建头节点(malloc) <P>
 * 2.头节点指针域置空 <P>
 * 3.循环创建节点,并插入到尾节点后面,即新节点的next指向尾节点的next,尾节点的next指向新节点
 * @param L  头指针
 * @param n  节点个数
 */
void CreateListTail(LinkList *L, int n) {
  // 1.创建头节点(malloc)
  *L = (LinkList) malloc(sizeof(LNode));
  // 2.头节点指针域置空
  (*L)->next = NULL;
  // 3.循环创建节点,并插入到尾节点后面,即新节点的next指向尾节点的next,尾节点的next指向新节点
  LinkList p, tail = *L;
  for (int i = 0; i < n; ++i) {
    p = (LinkList) malloc(sizeof(LNode));
    p->data = i;
    p->next = NULL;
    tail->next = p;
    tail = p;
  }
}

/**
* 头插法尾插法总结: <P>
 * 创头置空 新N指啥N 啥N指向新
*/

/**
 * 打印单链表 不打印头节点
 * @param L 头指针
 */
void PrintList(LinkList L) {
  LinkList p = L->next;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

/**
 * 按位查找
 * @param L 头指针
 * @param i 位置
 * @return
 */
LNode *GetElem(LinkList L, int i) {
  if (i < 1) {
    return NULL;
  }
  LinkList p = L;
  int j = 0;
  while (p != NULL && j < i) {
    p = p->next;
    j++;
  }
  return p;
}
/**
 * 按值查找
 * @param L 头指针
 * @param e 值
 * @return
 */
LNode *LocateElem(LinkList L, int e) {
  LinkList p = L->next;
  while (p != NULL && p->data != e) {
    p = p->next;
  }
  return p;
}

/**
 * 插入操作
 * @param L 头指针
 * @param i 位置
 * @param e 值
 * @return 1:成功 0:失败
 */
int ListInsert(LinkList *L, int i, int e) {
 
}