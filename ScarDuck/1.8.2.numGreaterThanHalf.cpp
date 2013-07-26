#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：数组中有一个数字出现的次数超过了数组长度的一半，找出这个数字。
分析：
       1.首先我们想到如果是一个排序好的数组，那么我们只需要遍历一次数组，统计好每个数字出现的次数，
如果大于数组长度的一半就输出这个数字。或者只需要直接输出array[N/2]的值即可。
       2.如果是杂乱无章的数据我们可能回想先排序，然后按1操作即可。但是排序的最小时间复杂度（快速
排序）  O（N*logN） ,  加上遍历，时间复杂度为: O（N*logN+N） ,如果选择直接输出array[N/2]的值的话，
时间复杂度缩小为  O（N*logN） 。
       3.如果说数字只有0-9的话可以考虑设计一个Hash table，遍历一次就能知道每个数字出现的次数。但
是数字范围不知，所以Hash表不好创建。
       4.出现的次数超过数组长度的一半，表明这个数字出现的次数比其他数字出现的次数的总和还多。所以
我们可以考虑每次删除两个不同的数，那么在剩下的数中，出现的次数仍然超过总数的一半。通过不断重
复这个过程，不断排除掉其它的数，最终找到那个出现次数超过一半的数字。这个方法，免去了上述思路
一、二的排序，也避免了思路三空间O（N）的开销，总得说来，时间复杂度只有O（N），空间复杂度为
O（1），不失为最佳方法。
       例：数组 a[5]={0,1,2,1,1};
                         我们要查找的数字为1，操作步骤为：遍历整个数组，然后每次删除不同的两个数字，过程
如下：
                      0 1 2 1 1 =>2 1 1=>1
*/
#include <cstdlib>
#include <iostream>

int numGreaterThanHalf(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return -10000;
  }
  int key = 0;
  int cnt = 0;
  for(int i = 0; i < len; ++i){
    if(cnt == 0){
      key = arr[i];
      cnt = 1;
    }
    else{
      if(key == arr[i]){
        cnt++;
      }
      else{
        cnt--;
      }
    }
  }
  return key;
}

int main(int argc, char ** argv)
{
  int arr[] = {0,1,2,1,1};
  int len = sizeof(arr)/sizeof(arr[0]);

  int res = numGreaterThanHalf(arr, len);
  std::cout<<res<<std::endl;

  system("pause");
  return 0;
}
#endif
