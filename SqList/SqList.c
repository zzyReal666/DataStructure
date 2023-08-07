//
// Created by zzype on 2023/7/28.
//

#include "SqList.h"
#include "stdio.h"
//初始化一个顺序表
void InitList(SqList *L) {
  for (int i = 0; i < MaxSize; i++) {
    L->data[i] = 0;
  }
  L->length = 0;
}

//插入操作
int ListInsert(SqList *L, int i, int e) {
  if (i < 1 || i > L->length + 1) {
    return 0;
  }
  if (L->length >= MaxSize) {
    return 0;
  }
  for (int j = L->length; j >= i; j--) {
    L->data[j] = L->data[j - 1];
  }
  L->data[i - 1] = e;
  L->length++;
  return 1;
}

//删除操作
int ListDelete(SqList *L, int i, int *e) {
  if (i < 1 || i > L->length) {
    return 0;
  }
  *e = L->data[i - 1];
  for (int j = i; j < L->length; j++) {
    L->data[j - 1] = L->data[j];
  }
  L->length--;
  return 1;
}

//按位查找
int GetElem(SqList L, int i) {
  if (i < 1 || i > L.length) {
    return 0;
  }
  return L.data[i - 1];
}

//按值查找
int LocateElem(SqList L, int e) {
  for (int i = 0; i < L.length; i++) {
    if (L.data[i] == e) {
      return i + 1;
    }
  }
  return 0;
}

//打印顺序表
void PrintList(SqList L) {
  for (int i = 0; i < L.length; i++) {
    printf("下标为%d的值为%d\n", i, L.data[i]);
  }
  printf("\n");
}