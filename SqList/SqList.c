//
// Created by zzype on 2023/7/28.
//

#include "SqList.h"
#include "stdio.h"
//初始化一个顺序表
void InitList(SqList *L) {
  for (int i = 0; i < MaxSize; i++) {
    L->data[i] = 0;//L是个指针，要用->来访问结构体内部的成员
  }
  L->length = 0;
}

//插入操作 i为插入的位置，e为插入的元素
int ListInsert(SqList *L, int i, int e) {
  //判断i的范围是否有效, i的范围为1~L->length+1 ,因为可以在最后一个位置插入,所以是+1
  if (i < 1 || i > L->length + 1) {
    return 0;
  }
  //判断顺序表是否已满
  if (L->length >= MaxSize) {
    return 0;
  }
  //将第i个元素及之后的元素后移
  for (int j = L->length; j >= i; j--) {
    L->data[j] = L->data[j - 1];
  }
  L->data[i - 1] = e;
  L->length++;
  return 1;
}

//删除操作 i为删除的位置，e为删除的元素
int ListDelete(SqList *L, int i, int *e) {
  //判断i的范围是否有效, i的范围为1~L->length ,最后一个位置为L->length
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