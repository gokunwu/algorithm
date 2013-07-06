#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：给出一个数列，找出其中最长的单调递增子序列。
*/
#include <cstdlib>
#include <iostream>
#define MIN -1000

int lis(int * array, int len){
  if(array == NULL || len < 1){
    return -1;
  }
  int maxlis = 1;
  int * lis = new int[len + 1];
  for(int i = 0; i < len +1; ++i){
    lis[i] = 0;
  }
  lis[0] = MIN;
  lis[1] = array[0];
  for(int i = 0; i < len; ++i){
    int left = 1;
    int right = maxlis;
    while(left <= right){
      int mid = (left + right)/2;
      if(array[i] > lis[mid]){
        left = mid + 1;
      }
      else{
        right = mid - 1;
      }
    }
    lis[left] = array[i];
    if(left > maxlis){
      maxlis = left;
    }
  }
  return maxlis;
}

int main(int argc, char ** argv){
  int array[] = {1,-1,2,-3,4,-5,6,-7};
  int len = sizeof(array)/sizeof(int);

  int maxLis = lis(array, len);
  if(maxLis != -1){
    std::cout<<maxLis<<std::endl;
  }
  else{
    std::cout<<"error"<<std::endl;
  }

  system("pause");
  return 0;
}

#endif
