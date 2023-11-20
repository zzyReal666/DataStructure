//
// Created by zzype on 2023/8/2.
//
#include "SqList.h"
#include <stdbool.h>
bool question1(SqList *l, int *min);
bool question3(SqList *l, int x);
bool question2(SqList *list);
bool question4(SqList *l, int s, int t);
bool question5(SqList *l, int s, int t);
bool question6(SqList *l);
bool question7(SqList *l1, SqList *l2, SqList *l);
bool reverse(SqList *l, int left, int right, int arraySize);
bool question8(SqList *l, int m, int n, int arraySize);
bool question9(SqList *l, int x);
bool question10(SqList *l, int p);
void SqListDemo() {

  SqList L;
  InitList(&L);
  //插入6个元素
  ListInsert(&L, 1, 1);
  ListInsert(&L, 2, 2);
  ListInsert(&L, 3, 3);
  ListInsert(&L, 4, 4);
  ListInsert(&L, 5, 5);
  ListInsert(&L, 6, 6);

  //题目1
  //  int e;
  //  question1(&L, &e);
  //  printf("删除的元素为 %d \n", e);

  //题目2
  //  question2(&L);

  //题目 3
  //  question3(&L, 3);

  //题目4
  //    question4(&L, 3, 5);

  //题目5
  //    question5(&L, 3, 5);

  //题目6
  //    question6(&L);

  //题目7
  //    SqList L1;
  //    InitList(&L1);
  //    ListInsert(&L1, 1, 1);
  //    ListInsert(&L1, 2, 2);
  //    ListInsert(&L1, 3, 3);
  //    ListInsert(&L1, 4, 4);
  //    ListInsert(&L1, 5, 5);
  //    ListInsert(&L1, 6, 6);
  //
  //    SqList L2;
  //    InitList(&L2);
  //    ListInsert(&L2, 1, 1);
  //    ListInsert(&L2, 2, 2);
  //    ListInsert(&L2, 3, 3);
  //    ListInsert(&L2, 4, 4);
  //
  //    SqList L3;
  //    InitList(&L3);
  //    L3.length = 10;
  //    question7(&L1, &L2, &L3);
  //    PrintList(L3);

  //题目8
  //  question8(&L, 3, 3, 6);

  //  reverse(&L,0,2,6);

  //题目9
  //    question9(&L, 4);

  //题目10
  int p = 3;
  question10(&L, p);
  PrintList(L);
}

//题目1 从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删除元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。
bool question1(SqList *l, int *min) {
  //判断顺序表是否为空
  if (l->length == 0) {
    return false;
  }

  //找到最小值 并记录下标
  *min = l->data[0];
  int index = 0;
  for (int i = 1; i < l->length; ++i) {
    if (l->data[i] < *min) {
      *min = l->data[i];
      index = i;
    }
  }
  l->data[index] = l->data[l->length - 1];
  return true;
}

//题目2 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)。
bool question2(SqList *l) {
  //判空
  if (l->length == 0) {
    return false;
  }
  //交换前后元素
  int temp;
  for (int i = 0; i < l->length / 2; i++) {
    temp = l->data[i];
    l->data[i] = l->data[l->length - 1 - i];
    l->data[l->length - 1 - i] = temp;
  }
  return true;
}

//题目3 删除顺序表中等于X的元素
bool question3(SqList *l, int x) {
  if (l->length == 0) {
    return false;
  }
  //  //解法1 : 用K统计不等于X的个数,遍历表,当前元素放到第K个位置
  int k = 0;
  //  for (int i = 0; i < l->length; ++i) {
  //    if (l->data[i] != x) {
  //      l->data[k] = l->data[i];
  //      k++;
  //    }
  //  }
  //  l->length = k;

  //解法2 : 用K统计等于X的个数,遍历表,当前元素向前移动K个位置
  for (int i = 0; i < l->length; ++i) {
    if (l->data[i] == x) {
      k++;
    } else {
      l->data[i - k] = l->data[i];
    }
  }
  l->length = l->length - k;

  return true;
}

//题目4 从有序顺序表删除s与t之间的元素 不包含s t  (王道书解法有错误,书上写的为包含s t)
bool question4(SqList *l, int s, int t) {
  if (l->length == 0) {
    return false;
  }
  if (s > l->data[l->length - 1] || t < l->data[0]) {
    return false;
  }

  //找到第一个大于等于s的元素
  int i, j;
  for (i = 0; i < l->length & l->data[i] <= s; i++) {}
  //第一个大于t的元素
  for (j = i; j < l->length & l->data[j] < t; j++) {}
  //从下标为j的元素,全部向前移动j-i位
  for (; j < l->length; i++, j++) {
    l->data[i] = l->data[j];
  }
  l->length = i;
}

//题目5 从顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，如果s或t不合理或者顺序表为空，则显示出错信息并退出运行。  包含s t
bool question5(SqList *l, int s, int t) {
  if (l->length == 0) {
    return false;
  }
  if (s > l->data[l->length - 1] || t < l->data[0]) {
    return false;
  }

  //遍历表 用k 记录当前位于s<= x <= t 的x的个数 如果当前值不在区间内,向前移动k个位置
  int k = 0;
  for (int i = 0; i < l->length; i++) {
    if (l->data[i] <= t && l->data[i] >= s) {
      k++;
    } else {
      l->data[i - k] = l->data[i];
    }
  }
  l->length = l->length - k;
}

//题目6 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
bool question6(SqList *l) {
  if (l->length == 0) {
    return false;
  }

  //从第二个元素开始,与前面元素不同的才能放入表中
  int i, j;
  for (i = 0, j = 1; j < l->length; j++) {
    if (l->data[i] != l->data[j]) {
      l->data[++i] = l->data[j];
    }
  }
  l->length = i + 1;
  return true;
}

//题目7 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
bool question7(SqList *l1, SqList *l2, SqList *l) {
  if (l1->length + l2->length > l->length) {
    return false;
  }

  int i = 0, j = 0, k = 0;

  while (i < l1->length && j < l2->length) {
    if (l1->data[i] < l2->data[j]) {
      l->data[k++] = l1->data[i++];
    } else {
      l->data[k++] = l2->data[j++];
    }
  }

  while (i < l1->length) {
    l->data[k++] = l1->data[i++];
  }
  while (j < l2->length) {
    l->data[k++] = l2->data[j++];
  }

  l->length = k;
  return true;
}

//题目8 已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3,...,am)和(b1,b2,b3,...,bn)。编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,b3,...,bn)放在(a1,a2,a3,...,am)的前面。
bool question8(SqList *l, int m, int n, int arraySize) {
  if (m + n > l->length) {
    return false;
  }

  //解法1 : 交换前m个元素与后n个元素的位置
  //  int temp;
  //  for (int i = 0; i < m; ++i) {
  //    temp = l->data[i];
  //    l->data[i] = l->data[m + i];
  //    l->data[m + i] = temp;
  //  }

  //解法2 : 三次逆置
  reverse(l, 0, m + n - 1, m + n);
  reverse(l, 0, n - 1, m + n);
  reverse(l, n, m + n - 1, m + n);
  return true;
}

//逆置
bool reverse(SqList *l, int start, int end, int arraySize) {
  if (start < 0 || end >= arraySize || start >= end) {
    return false;
  }

  while (start < end) {
    int temp = l->data[start];
    l->data[start] = l->data[end];
    l->data[end] = temp;
    start++;
    end--;
  }

  //  int mid = (start + end) / 2;
  //  for(int i =0 ;i<=mid-start;i++){  //必须要带等于
  //    int temp = l->data[start+i];
  //    l->data[start+i] = l->data[end-i];
  //    l->data[end-i] = temp;
  //  }
  return true;
}

//题目9 线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内。要求设计一算法，完成用最少时间在表中查找数值为x的元素，若找到则将其与后继元素位置相交换，若找不到则将其插入表中并使表中元素仍递增有序。
bool question9(SqList *l, int x) {
  int low = 0, high = l->length - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (l->data[mid] == x) {
      break;
    } else if (l->data[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  if (l->data[mid] == x && mid != l->length - 1) {//X存在并且 不是最后一个 如果是最后一个 不用交换
    int temp = l->data[mid];
    l->data[mid] = l->data[mid + 1];
    l->data[mid + 1] = temp;
  }

  if (low > high) {

    //从后往前,依次往后移动一位直到x位置
    int i = l->length - 1;
    for (; i > high; --i) {
      l->data[i + 1] = l->data[i];
    }
    l->data[i + 1] = x;
    l->length++;
  }

  return true;
}

//题目10 设将n(n>1)个整数存放到一维数组R中。设计一个在时间和空间两方面都尽可能高效的算法。将R中保存的序列循环左移p(0<p<n)个位置，即将R中的数据由(X0,X1,...,Xn-1)变换为(Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1)。
bool question10(SqList *l, int p) {
  if (l->length == 0) {
    return false;
  }

  reverse(l, 0, l->length - 1, l->length);
  reverse(l, 0, l->length - p - 1, l->length);
  reverse(l, l->length - p, l->length - 1, l->length);
}

//题目11  现在有两个等长升序序列S1和S2，设计一个算法，找出S1和S2的中位数。
bool question11(SqList *l1, SqList *l2, int *result) {
  if (l1->length != l2->length) {
    return false;
  }

  //解法1 : 合并两个有序表,找到中位数
  int i = 0, j = 0, k = 0;
  while (i < l1->length && j < l2->length) {
    if (l1->data[i] < l2->data[j]) {
      result[k++] = l1->data[i++];
    } else {
      result[k++] = l2->data[j++];
    }
  }
  while (i < l1->length) {
    result[k++] = l1->data[i++];
  }
  while (j < l2->length) {
    result[k++] = l2->data[j++];
  }
  *result = result[(l1->length + l2->length - 1) / 2];
  return true;
}