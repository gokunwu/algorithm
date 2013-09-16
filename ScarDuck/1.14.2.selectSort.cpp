
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:选择排序：
分析：对于给定的一组记录，经过第一轮比较后得到最小的记录，然后将该记录与第一个记录的位置进行交换；接着对不包括第一个记录以外的其他记录进行第二轮比较，得到最小的记录并与第二个记录进行位置交换；重复该过程，直到进行比较的记录只有一个时为止。
性能：最好时间O(n2) 平均时间O(n2) 最坏时间O(n2) 空间复杂度O(1) 说明：n小时较好
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

void selectSort(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return;
  }
  for(int i = 0; i < len; ++i){
    int min = i;
    for(int j = i+1; j < len; ++j){
      if(arr[min] > arr[j]){
        min = j;
      }
    }
    if(min != i){
      exchange(arr, min, i);
    }
  }
}

int main(int argc, char ** argv)
{
  int arr[] = {38,65,97,76,13,27,49};
  int len = sizeof(arr)/sizeof(int);
  selectSort(arr, len);
  for(int i = 0; i < len; ++i){
    std::cout<<arr[i]<<std::endl;
  }

  system("pause");
  return 0;
}

#endif
