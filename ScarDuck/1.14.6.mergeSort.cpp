#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:归并排序：
归并排序是利用递归与分治技术将数据序列划分成为越来越小的半子表，再对半子表排序，最后再用递归步骤将排好序的半子表合并成为越来越大的有序序列。其中“归”代表的是递归的意思，即递归的将数组折半的分离为单个数组，“并”就是将分开的数组按照从小到大的顺序再放到一个数组中。
基本原理：对于给定的一组记录（假设共有n个记录），首先将每两个相邻的长度为1的子序列进行归并，得到n/2个（向上取整）长度为2或1的有序子序列，再将其两两归并，反复执行此过程，直到得到一个有序序列为止。
性能：最好时间O(nlogn) 平均时间O(nlogn) 最坏时间O(nlogn) 空间复杂度O(n) 说明：n大时较好
例子：{38,65,97,76,13,27,49}
*/
#include <cstdlib>
#include <iostream>

void merge(int * arr, int begin, int mid, int end)
{
  if(arr == NULL){
    return;
  }
  int leftlen = mid - begin + 1;
  int * left = new int[leftlen];
  int rightlen = end - mid;
  int * right = new int[rightlen];
  int i;
  int j;
  int index;
  for(i = 0, index = begin; i < leftlen; ++i, index++){
    left[i] = arr[index];
  }
  for(i = 0, index = mid+1; i < rightlen; ++i,index++){
    right[i] = arr[index];
  }
  i = 0;
  j = 0;
  index = begin;
  while(i < leftlen && j < rightlen){
    if(left[i] < right[j]){
      arr[index] = left[i];
      i++;
      index++;
    }else{
      arr[index] = right[j];
      j++;
      index++;
    }
  }
  while(i < leftlen){
    arr[index] = left[i];
    i++;
    index++;
  }
  while(j < rightlen){
    arr[index] = right[j];
    j++;
    index++;
  }
  if(left != NULL){
    delete [] left;
    left = NULL;
  }
  if(right != NULL){
    delete [] right;
    right = NULL;
  }
}

void mergeSort(int * arr, int begin, int end)
{
  if(arr == NULL){
    return;
  }
  if(begin < end){
    int mid = begin + (end-begin)/2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, begin, mid, end);
  }
}

int main(int argc, char ** argv)
{
  int arr[] = {38,65,97,76,13,27,49};
  int len = sizeof(arr)/sizeof(int);
  //std::cout<<len<<std::endl;
  mergeSort(arr, 0, len-1);
  for(int i = 0; i < len; ++i){
    std::cout<<arr[i]<<std::endl;
  }

  system("pause");
  return 0;
}
#endif
