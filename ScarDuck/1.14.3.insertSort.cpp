
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:插入排序：
分析：对于给定的一组记录，初始时假定第一个记录自成一个有序序列，其余的记录为无序序列；接着从第二个记录开始，按照记录的大小依次将当前处理的记录插入到之前的有序序列中，直到最后一个记录插入到有序序列为止。
性能：最好时间O(n) 平均时间O(n2) 最坏时间O(n2) 空间复杂度O(1) 说明：大部分已有序时较好
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

void insertSort(int * arr, int len)
{
  if(arr == NULL){
    return;
  }
  for(int i = 1; i < len; ++i){
    for(int j = i; j > 0; --j){
      if(arr[j] < arr[j-1]){
        exchange(arr, j, j-1);
      }
    }
  }
}

int main(int argc, char ** argv)
{
  int arr[] = {38,65,97,76,13,27,49};
  int len = sizeof(arr)/sizeof(int);
  insertSort(arr, len);
  for(int i = 0; i < len; ++i){
    std::cout<<arr[i]<<std::endl;
  }

  system("pause");
  return 0;
}

#endif
