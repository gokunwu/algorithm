
#if 0
/*
堆排序：
堆是一种特殊的树形数据结构，其每个节点都有一个值，通常提到的堆都是指一颗完全二叉树，根节点的值小于（或大于）两个子节点的值，同时根节点的两个子树也分别是一个堆。
堆排序是一种树形选择排序，在排序过程中，将R[1,...,N]看成是一颗完全二叉树的顺序存储结构，利用完全二叉树中双亲节点和孩子节点之间的内在关系来选择最小的元素。
基本思想：堆排序的思想是对于给定的n个记录，初始时把这些记录看做一颗顺序存储的二叉树，然后将其调整为一个大顶堆，然后将堆的最后一个元素与对顶元素（即二叉树的根节点）进行交换后，堆的最后一个元素即为最大记录；接着将前n-1个元素（即不包括最大记录）重新调整为一个大顶堆，再将堆顶元素与当前堆的最后一个元素进行交换后得到次大的记录，重复这个过程直到调整的堆中只剩一个元素时为止，该元素即为最小元素，此时可得到一个有序序列
性能：最好时间O(nlogn) 平均时间O(nlogn) 最坏时间O(nlogn) 空间复杂度O(1) 说明：n大时较好
例子：{38,65,97,76,13,27,49}
*/
#include <cstdlib>
#include <iostream>

int leftChild(int x)
{
  return 2*x +1;
}
int rightChild(int x)
{
  return 2*x +2;
}
void exchange(int * array,int i,int j)
{
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

void max_heap_adjust(int *array,int len,int index)
{
  if(array == NULL)
    return;
  if(index > len)
    return;
  int large = index;
  int left = leftChild(index);
  int right = rightChild(index);
  if(left < len && array[left] > array[large])
    large = left;
  if(right < len && array[right] > array[large])
    large = right;
  if(large != index)
  {
    exchange(array,large,index);
    max_heap_adjust(array,len,large);
  }
}
void max_heap_creat(int * array,int len)
{
  int partition = len/2 -1;
  for(int i = partition ; i >=0;--i)
  {
    max_heap_adjust(array,len,i);
  }
}

void heapSort(int *array,int len)
{
  max_heap_creat(array,len);
  for(int i = len-1;i >0;--i)
  {
    exchange(array,0,i);
    max_heap_adjust(array,i,0);
  }
}

int main(int argc,char ** argv)
{
  int array[] = {38,65,97,76,13,27,49};
  int len = sizeof(array)/sizeof(int);

  heapSort(array,len);

  for(int i = 0;i < len;++i)
  {
    std::cout<<array[i]<<std::endl;
  }

  system("pause");
  return 0;
}

#endif
