#if 0
/*
归并排序：
归并排序是利用递归与分治技术将数据序列划分成为越来越小的半子表，再对半子表排序，最后再用递归步骤将排好序的半子表合并成为越来越大的有序序列。其中“归”代表的是递归的意思，即递归的将数组折半的分离为单个数组，“并”就是将分开的数组按照从小到大的顺序再放到一个数组中。
基本原理：对于给定的一组记录（假设共有n个记录），首先将每两个相邻的长度为1的子序列进行归并，得到n/2个（向上取整）长度为2或1的有序子序列，再将其两两归并，反复执行此过程，直到得到一个有序序列为止。
性能：最好时间O(nlogn) 平均时间O(nlogn) 最坏时间O(nlogn) 空间复杂度O(n) 说明：n大时较好
例子：{38,65,97,76,13,27,49}
*/
#include <cstdlib>
#include <iostream>

void merge(int *array,int begin,int mid,int end)
{
  if(array == NULL)
    return;
  int left_len = mid - begin +1;
  int right_len = end - mid;
  int * left = new int[left_len];
  int * right = new int[right_len];
  int i,j,k;
  for(i = 0, k = begin;i <left_len;++i,++k)
  {
    left[i] = array[k];
  }
  for(j = 0, k = mid +1;j < right_len;++j,++k)
  {
    right[j] = array[k];
  }
  i = 0,j = 0, k = begin;
  while((i < left_len)&&(j < right_len))
  {
    if(left[i] < right[j])
    {
      array[k] = left[i];
      ++i;
      ++k;
    }
    else
    {
      array[k] = right[j];
      ++j;
      ++k;
    }
  }
  if(i < left_len)
  {
    while(i < left_len)
    {
      array[k] = left[i];
      ++i;
      ++k;
    }
  }
  if(j < right_len)
  {
    array[k] = right[j];
    ++j;
    ++k;
  }
}

void mergeSort(int *array,int begin,int end)
{
  if(array == NULL)
    return;
  if(begin < end)
  {
    int mid = (begin + end)/2;
    mergeSort(array,begin,mid);
    mergeSort(array,mid+1,end);
    merge(array,begin,mid,end);
  }
}

int main(int argc,char **argv)
{
  int array[] = {38,65,97,76,13,27,49};
  int len = sizeof(array)/sizeof(int);

  mergeSort(array,0,len -1);

  for(int i = 0;i < len;++i)
  {
    std::cout<<array[i]<<std::endl;
  }
  system("pause");
  return 0;
}
#endif
