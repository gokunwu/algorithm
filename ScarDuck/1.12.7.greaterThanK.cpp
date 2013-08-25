#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：Google2009华南地区笔试题
给定一个集合A=[0,1,3,8](该集合中的元素都是在0，9之间的数字，但未必全部包含)，
指定任意一个正整数K，请用A中的元素组成一个大于K的最小正整数。
比如，A=[1,0] K=21 那么输出结构应该为100。
*/
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>

int genNumGreaterThanK(int arr[], int len, int k)
{
  if(arr == NULL || len < 1){
    return -1;
  }
  int ret = 0;
  //sort the array
  std::sort(arr, arr+len);
  int high_digit = 0;
  int k_len = 0;
  int k_tmp = k;
  while(k_tmp){
    high_digit = k_tmp%10;
    k_tmp = k_tmp/10;
    k_len++;
  }
  int min_in_arr = 0;
  int i = 0;
  //get the min num in arr where num > high_digit
  for(i = 0; i < len; ++i){
    if(arr[i] >= high_digit){
      min_in_arr = arr[i];
      break;
    }
  }
  if(i == len){//if all number in arr smaller than high_digit
    int min_not_zero = 0;
    for(int i = 0; i < len; ++i){
      if(arr[i] > 0){
        min_not_zero = arr[i];
        break;
      }
    }
    for(int i = 0; i < len; ++i){
      min_not_zero = min_not_zero*10 + arr[0];
    }
    ret = min_not_zero;
  }
  else if(min_in_arr == high_digit){//if there is a number equal high_digit
    int low_data = k - high_digit*pow(10,k_len-1);
    ret = min_in_arr*pow(10, k_len-1) + genNumGreaterThanK(arr, len, low_data);
  }
  else{//if there is a min number in array greater than high_digit
    for(int i = 1; i < k_len; ++i){
      min_in_arr = min_in_arr*10 + arr[0];
    }
    ret = min_in_arr;
  }
  return ret;
}

int main(int argc, char ** argv)
{
  int arr[] = {1,4,2,8};
  int len = sizeof(arr)/sizeof(int);
  //int k = 5639;
  //int k = 4612;
  int k = 9365;
  int ret = genNumGreaterThanK(arr, len, k);
  std::cout<<ret<<std::endl;
  system("pause");
  return 0;
}
#endif
