//
// Created by zzype on 2023/7/28.
//

//定义一个顺序表
#define MaxSize 50
typedef struct
{
  int data[MaxSize];
  int length;
} SqList;


//初始化一个顺序表
void InitList(SqList *L);

//插入操作
int ListInsert(SqList *L, int i, int e);

//删除操作
int ListDelete(SqList *L, int i, int *e);

//按位查找
int GetElem(SqList L, int i);

//按值查找
int LocateElem(SqList L, int e);


//打印顺序表
void PrintList(SqList L);