#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:冒泡排序
分析：（假定由小到大排序）对于给定的n个记录，从第一个记录开始依次对相邻的两个记录进行比较，当前面的记录大于后面的记录时，交换其位置，进行一轮计较和换位后，n个记录中的最大的记录将位于第n位；然后对前面n-1个记录进行第二轮比较；重复该过程直到进行比较的记录只剩下一个时为止。
性能：最好时间O(n) 平均时间O(n2) 最坏时间O(n2) 空间复杂度O(1) 说明：n小时较好
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

void bubbleSort(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return;
  }
  int flag = 0;
  for(int i = 0; i < len; ++i){
    for(int j = len-1; j > i; j--){
      if(arr[j] < arr[j-1]){
        exchange(arr, j, j-1);
        flag = 1;
      }
    }
    if(flag == 0){
      break;
    }
  }
}

int main(int argc, char ** argv)
{
  int arr[] = {38,65,97,76,13,27,49};
  int len = sizeof(arr)/sizeof(int);
  bubbleSort(arr, len);
  for(int i = 0; i < len; ++i){
    std::cout<<arr[i]<<std::endl;
  }

  system("pause");
  return 0;
}

#endif
