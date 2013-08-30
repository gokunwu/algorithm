#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：对于从1到N的连续整集合合，能划分成两个子集合，且保证每个集合的数字和是相等的。
  举个例子，如果N=3，对于{1，2，3}能划分成两个子集合，他们每个的所有数字和是
相等的：
  {3}and {1,2}
  这是唯一一种分发（交换集合位置被认为是同一种划分方案，因此不会增加划分方案总
数）
  如果N=7，有四种方法能划分集合{1，2，3，4，5，6，7}，每一种分发的子集合各数
字和是相等的:
  {1,6,7} and {2,3,4,5} {注  1+6+7=2+3+4+5}
  {2,5,7} and {1,3,4,6}
  {3,4,7} and {1,2,5,6}
  {1,2,4,7} and {3,5,6}
  给出N，你的程序应该输出划分方案总数，如果不存在这样的划分方案，则输出0。程
序不能预存结果直接输出。
分析：变换成0-1背包问题
对于从1到N的连续整集合，划分为两个子集合，且保证每个集合的数字和
是相等的。因而，划分之后每个子集全的数字应该为n*(n+1)/2的一半，即n*(n+1)/4
由于两个子集中都是整数，所以n*(n+1)必为偶数，则可以设s=n*(n+1),并判断s%4 .
f[i]数组表示任意个数加起来等于i 的组数
f[j-i]表示加起来等于j-i的组数，f[j-i+i]表示加起来等于j的组数。
*/
#include <cstdlib>
#include <iostream>

int splitSet2TwoSet(int n)
{
  if(n < 1){
    return -1;
  }
  int m = n*(n+1);
  if(m % 4 != 0){
    return -1;
  }
  int fsize = m/4;
  int * f = new int[fsize+1];
  for(int i = 0; i <= fsize; ++i){
    f[i] = 0;
  }
  f[0] = 1;
  for(int i = 1; i <= n; ++i){
    for(int v = fsize; v >= i; --v){
      f[v] = f[v]+f[v-i];//加起来等于v-i的组数 + 加起来等于v-i+i的组数
    }
  }
  std::cout<<f[fsize]/2<<std::endl;
}

int main(int argc, char ** argv)
{
  int n = 7;
  splitSet2TwoSet(7);
  system("pause");
  return 0;
}
#endif
