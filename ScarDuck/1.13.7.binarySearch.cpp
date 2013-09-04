#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：二分查找
*/
#include <cstdlib>
#include <iostream>

int binarySearch(int * arr, int len, int value)
{
  if(arr == NULL || len < 1){
    return -1;
  }
  int left = 0;
  int right = len;
  while(left < right){
    int mid = left + (right - left)/2;
    if(value < arr[mid]){
      right = mid;
    }
    else if(value > arr[mid]){
      left = mid + 1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

int main(int argc, char ** argv)
{
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 13, 19};
  int len = sizeof(arr)/sizeof(int);

  int ret = binarySearch(arr, len, 33);
  std::cout<<ret<<std::endl;

  system("pause");
  return 0;
}
#endif






