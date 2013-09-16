
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:快速排序 递归实现
快速排序采取“分而治之”的思想，把大的拆分为小的，小的再拆分为更小的。
基本原理：对于一组给定的记录，通过一趟排序后，将原序列分为两部分，其中前一部分的所有记录均比后部分的所有记录小，然后再依次对前后两部分的记录进行快速排序，递归该过程，直到序列中的所有记录均为有序为止。
性能：最好时间O(nlogn) 平均时间O(nlogn) 最坏时间O(n2) 空间复杂度O(logn) 说明：n大时较好
例子：{38,65,97,76,13,27,49}
*/
#include <cstdlib>
#include <iostream>

void exchange(int * arr, int i, int j)
{
  if(arr == NULL){
    return;
  }
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int partition(int *arr, int begin, int end)
{
  if(arr == NULL){
    return -1;
  }
  int p = -1;
  int key = arr[end-1];
  for(int i = 0; i < end-1; ++i){
    if(arr[i] < key){
      p++;
      exchange(arr, p, i);
    }
  }
  p++;
  exchange(arr,p,end-1);
  return p;
}

void quickSort(int * arr, int begin, int end)
{
  if(arr == NULL){
    return;
  }
  if(begin < end){
    int mid = partition(arr, begin, end);
    quickSort(arr, begin, mid);
    quickSort(arr, mid + 1, end);
  }

}

int main(int argc, char ** argv)
{
  int arr[] = {38,65,97,76,13,27,49};
  int len = sizeof(arr)/sizeof(int);
  quickSort(arr, 0, len);
  for(int i = 0; i < len; ++i){
    std::cout<<arr[i]<<std::endl;
  }

  system("pause");
  return 0;
}
#endif

#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:快速排序 非递归实现
快速排序采取“分而治之”的思想，把大的拆分为小的，小的再拆分为更小的。
基本原理：对于一组给定的记录，通过一趟排序后，将原序列分为两部分，其中前一部分的所有记录均比后部分的所有记录小，然后再依次对前后两部分的记录进行快速排序，递归该过程，直到序列中的所有记录均为有序为止。
性能：最好时间O(nlogn) 平均时间O(nlogn) 最坏时间O(n2) 空间复杂度O(logn) 说明：n大时较好
例子：{38,65,97,76,13,27,49}
*/
#include <cstdlib>
#include <iostream>
#include <stack>

void exchange(int * arr, int i, int j)
{
  if(arr == NULL){
    return;
  }
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int partition(int * arr, int begin, int end)
{
  if(arr == NULL){
    return -1;
  }
  int p = -1;
  int key = arr[end-1];
  for(int i = 0; i < end-1; ++i){
    if(arr[i] < key){
      p++;
      exchange(arr, i, p);
    }
  }
  p++;
  exchange(arr, p, end-1);
  return p;
}

void quickSort(int *arr, int begin, int end)
{
  if(arr == NULL || begin > end){
    return;
  }
  std::stack<int> intstack;
  int mid = partition(arr, begin, end);
  if(begin < mid){
    intstack.push(begin);
    intstack.push(mid);
  }
  if(mid+1 < end){
    intstack.push(mid+1);
    intstack.push(end);
  }
  while(!intstack.empty()){
    int end = intstack.top();
    intstack.pop();
    int begin = intstack.top();
    intstack.pop();
    int mid = partition(arr, begin, end);
    if(begin < mid){
      intstack.push(begin);
      intstack.push(mid);
    }
    if(mid+1 < end){
      intstack.push(mid+1);
      intstack.push(end);
    }
  }
}

int main(int argc, char ** argv)
{
  int arr[] = {38,65,97,76,13,27,49};
  int len = sizeof(arr)/sizeof(int);
  quickSort(arr, 0, len);
  for(int i = 0; i < len; ++i){
    std::cout<<arr[i]<<std::endl;
  }
  system("pause");
  return 0;
}

#endif








