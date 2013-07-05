
#if 0
/*
插入排序：
基本原理：对于给定的一组记录，初始时假定第一个记录自成一个有序序列，其余的记录为无序序列；接着从第二个记录开始，按照记录的大小依次将当前处理的记录插入到之前的有序序列中，直到最后一个记录插入到有序序列为止。
性能：最好时间O(n) 平均时间O(n2) 最坏时间O(n2) 空间复杂度O(1) 说明：大部分已有序时较好
例子：{38,65,97,76,13,27,49}
*/
#include <cstdlib>
#include <iostream>

int insertSort(int array[],int len)
{
  if(len < 0)
    return 0;
  if(array == NULL)
    return 0;
  for(int i = 1;i < len ;++i)
  {
    int cur = array[i];
    int j = 0;
    for(j = i-1;j >= 0;--j)
    {
      if(cur < array[j])
      {
        array[j+1] = array[j];
      }
      else
        break;
    }
    array[j+1] = cur;
  }
  return 1;
}

int main(int argc,char *argv[])
{
  int array[] = {38,65,97,76,13,27,49};
  int len = sizeof(array)/sizeof(int);

  insertSort(array,len);
  for(int i = 0;i < len;++i)
    std::cout<<array[i]<<std::endl;

  system("pause");
  return 0;
}

#endif


