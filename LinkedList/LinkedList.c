//
// Created by zzype on 2023/11/20.
//

#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"

//头插法建立单链表 L为头指针 n为节点个数
void CreateListHead(LinkList *L, int n) {
  *L = (LinkList) malloc(sizeof(LNode));//头指针指向头节点
  (*L)->next = NULL;                    //头节点的next指针为空

  //循环建立节点
  LinkList p;                           //p为新建的节点 是个指针 指向新建的节点
  for (int i = 0; i < n; i++) {
    p = (LinkList) malloc(sizeof(LNode));//新建一个节点 是个指针 指向新建的节点
    scanf("%d", &p->data);               //输入节点的值
    p->next = (*L)->next;                //将新建的节点的next指针指向头节点的next指针指向的节点
    (*L)->next = p;                      //将头节点的next指针指向新建的节点
  }
}
