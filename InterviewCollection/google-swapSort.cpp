#if 0
/*
copyright@nciaebupt 转载请注明出处
2013 google校招笔试题
2.2 长度为n的数组乱序存放着0至n-1. 现在只能进行0与其他数的swap，请设计并实现排序。
*/
#include <cstdlib>
#include <iostream>

void swap(int * arr, int i, int j)
{
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int sort(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return -1;
  }
  while(arr[0] != 0){
    swap(arr, 0, arr[0]);
  }
}

int swapSort(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return -1;
  }
  for(int i = 0; i < len; ++i){
    if(arr[i] != i){
      swap(arr, i, 0);
      sort(arr, len);
    }
  }
}

int main(int argc, char ** argv)
{
  int arr[] = {0,2,4,3,5,7,1,6};
  int len = sizeof(arr)/sizeof(int);
  swapSort(arr, len);
  for(int i = 0; i < len; ++i){
    std::cout<<arr[i]<<std::endl;
  }
  system("pause");
  return 0;
}
#endif
