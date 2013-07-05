#if 0
/*
选择排序：
基本原理：对于给定的一组记录，经过第一轮比较后得到最小的记录，然后将该记录与第一个记录的位置进行交换；接着对不包括第一个记录以外的其他记录进行第二轮比较，得到最小的记录并与第二个记录进行位置交换；重复该过程，直到进行比较的记录只有一个时为止。
性能：最好时间O(n2) 平均时间O(n2) 最坏时间O(n2) 空间复杂度O(1) 说明：n小时较好
例子：{38,65,97,76,13,27,49}
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>

int selectSort(int array[],int len)
{
  if(len < 0)
  {
    return 0;
  }
  if(array == NULL)
  {
    return 0;
  }

  for(int i = 0;i < len;++i)
  {
    int max = array[i];
    int max_index = i;
    for(int j = i;j < len;++j)
    {
      if(max < array[j])
      {
        max = array[j];
        max_index = j;
      }
    }
    if(max_index != i)
    {
      int tmp = array[i];
      array[i] = max;
      array[max_index] = tmp;
    }
  }
  return 1;
}

int main(int argc,char *argv[])
{
  int array[] = {38,65,97,76,13,27,49};
  int len = sizeof(array)/sizeof(int);
  selectSort(array,len);
  for(int i = 0; i < len;++i)
  {
    std::cout<<array[i]<<std::endl;
  }
  system("pause");
  return 0;
}

#endif



