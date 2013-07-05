#if 0
/*
快速排序：
快速排序采取“分而治之”的思想，把大的拆分为小的，小的再拆分为更小的。
基本原理：对于一组给定的记录，通过一趟排序后，将原序列分为两部分，其中前一部分的所有记录均比后部分的所有记录小，然后再依次对前后两部分的记录进行快速排序，递归该过程，直到序列中的所有记录均为有序为止。
性能：最好时间O(nlogn) 平均时间O(nlogn) 最坏时间O(n2) 空间复杂度O(logn) 说明：n大时较好
例子：{38,65,97,76,13,27,49}
*/
#include <cstdlib>
#include <iostream>

void exchange(int * array,int i,int j)
{
  if(array == NULL)
    return;
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

int partition(int * array,int begin,int end)
{
  if(array == NULL)
    return -1;
  if(begin > end)
    return -1;
  int key = array[end];
  int cur = begin;
  int pro = cur - 1;
  for(;cur < end;++cur)
  {
    if(array[cur] < key)
    {
      ++pro;
      exchange(array,pro,cur);
    }
  }
  exchange(array,pro+1,cur);
  return pro+1;
}

void quickSort(int * array,int begin,int end)
{
  if(array == NULL)
    return;
  if(begin < end)
  {
    int mid = partition(array,begin,end);
    quickSort(array,begin,mid-1);
    quickSort(array,mid+1,end);
  }
}

int main(int argc,char *argv[])
{
  int array[] = {38,65,97,76,13,27,49};
  int len = sizeof(array)/sizeof(int);

  quickSort(array,0,len-1);

  for(int i = 0;i < len-1;++i)
  {
    std::cout<<array[i]<<std::endl;
  }

  system("pause");
  return 0;
}
#endif
