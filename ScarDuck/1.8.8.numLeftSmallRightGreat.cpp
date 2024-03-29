#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：一个int 数组，里面数据无任何限制，要求求出所有这样的数a[i]，其左边的数都小
于等于它，右边的数都大于等于它。
能否只用一个额外数组和少量其它空间实现。
分析：最原始的方法是检查每一个数  array[i] ，看是否左边的数都小于等于它，右边的数都
大于等于它。这样做的话，要找出所有这样的数，时间复杂度为O(N^2)。
其实可以有更简单的方法，我们使用额外数组，比如rightMin[]，来帮我们记录原始数组
array[i]右边（包括自己）的最小值。假如原始数组为：  array[] = {7, 10, 2, 6, 19, 22, 32}，  那么rightMin[] = {2, 2, 2, 6, 19, 22, 32}.  也就是说，7右边的最小值为2, 2右边的最小值也是2。
有了这样一个额外数组，当我们从头开始遍历原始数组时，我们保存一个当前最大值  max，
如果当前最大值刚好等于rightMin[ i]，  那么这个最大值一定满足条件。还是刚才的例子。
第一个值是7，最大值也是7，因为7 不等于  2，  继续，
第二个值是10，最大值变成了10，但是10也不等于2，继续，
第三个值是2，最大值是10，但是10也不等于2，继续，
第四个值是6，最大值是10，但是10不等于6，继续，
第五个值是19，最大值变成了19，而且19也等于当前rightMin[4] = 19, 所以，满足条件。
如此继续下去，后面的几个都满足。
*/


#include <cstdlib>
#include <iostream>

void numLeftSmallRightGreat(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return;
  }
  int * rightmin = new int[len];
  int minnum = arr[len-1];
  for(int i = len -1; i >= 0; --i){
    if(arr[i] < minnum){
      minnum = arr[i];
    }
    rightmin[i] = minnum;
  }
  int maxnum = arr[0];
  for(int i = 0; i < len; ++i){
    if(arr[i] > maxnum){
      maxnum = arr[i];
    }
    if(maxnum == rightmin[i]){
      std::cout<<arr[i]<<std::endl;
    }
  }
}

int main(int argc, char ** argv)
{
  int arr[] = {7,10,2,6,19,22,32};
  int len = sizeof(arr)/sizeof(arr[0]);

  numLeftSmallRightGreat(arr, len);

  system("pause");
  return 0;
}
#endif
