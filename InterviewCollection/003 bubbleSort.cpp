#if 0
/*
冒泡排序：
基本原理：（假定由小到大排序）对于给定的n个记录，从第一个记录开始依次对相邻的两个记录进行比较，当前面的记录大于后面的记录时，交换其位置，进行一轮计较和换位后，n个记录中的最大的记录将位于第n位；然后对前面n-1个记录进行第二轮比较；重复该过程直到进行比较的记录只剩下一个时为止。
性能：最好时间O(n) 平均时间O(n2) 最坏时间O(n2) 空间复杂度O(1) 说明：n小时较好
例子：{38,65,97,76,13,27,49}
*/
#include <cstdlib>
#include <iostream>

bool bubbleSort(int array[],int len)
{
  for(int i = 0; i < len; ++i)
  {
    int flag = 0;
    for(int j = len - 2;j >= i; --j)
    {
      if(array[j+1] < array[j])
      {
        int tmp = array[j+1];
        array[j+1] = array[j];
        array[j] = tmp;
        flag = 1;
      }
    }
    if(flag == 0)
    {
      break;
    }
  }
  return true;
}

int main(int argc,char *argv[])
{
  int array[] = {38,65,97,76,13,27,49};
  int len = sizeof(array)/sizeof(int);
  bubbleSort(array,len);

  for(int i = 0;i < len;++i)
    std::cout<<array[i]<<std::endl;

  system("pause");
  return 0;
}
#endif
