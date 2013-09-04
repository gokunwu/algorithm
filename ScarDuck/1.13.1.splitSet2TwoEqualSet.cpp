<<<<<<< HEAD

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
分析：此问题可以转化成背包问题
对于从1到N的连续整集合，划分为两个子集合，且保证每个集合的数字和
是相等的。因而，划分之后每个子集全的数字应该为n*(n+1)/2的一半，即n*(n+1)/4
由于两个子集中都是整数，所以n*(n+1)必为偶数，则可以设s=n*(n+1),并判断s%4 。
可以将问题转变为01背包恰好装满的情况；将原集合分为两部分，每部分中数的和均
 为n(n+1)/4,则问题转变为从原集合中取物品，放入背包容量为n(n+1)/4的背包中，且
 恰好装满，有多少种取法。最后将所求得的方法数除以2即为可划分的子集合数
 data[i][j]=data[i-1][j-i]+data[i-1][j];
=======
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ�����ڴ�1��N�����������Ϻϣ��ܻ��ֳ������Ӽ��ϣ��ұ�֤ÿ�����ϵ����ֺ�����ȵġ�
  �ٸ����ӣ����N=3������{1��2��3}�ܻ��ֳ������Ӽ��ϣ�����ÿ�����������ֺ���
��ȵģ�
  {3}and {1,2}
  ����Ψһһ�ַַ�����������λ�ñ���Ϊ��ͬһ�ֻ��ַ�������˲������ӻ��ַ�����
����
  ���N=7�������ַ����ܻ��ּ���{1��2��3��4��5��6��7}��ÿһ�ַַ����Ӽ��ϸ���
�ֺ�����ȵ�:
  {1,6,7} and {2,3,4,5} {ע  1+6+7=2+3+4+5}
  {2,5,7} and {1,3,4,6}
  {3,4,7} and {1,2,5,6}
  {1,2,4,7} and {3,5,6}
  ����N����ĳ���Ӧ��������ַ�����������������������Ļ��ַ����������0����
����Ԥ����ֱ�������
�������任��0-1��������
���ڴ�1��N�����������ϣ�����Ϊ�����Ӽ��ϣ��ұ�֤ÿ�����ϵ����ֺ�
����ȵġ����������֮��ÿ���Ӽ�ȫ������Ӧ��Ϊn*(n+1)/2��һ�룬��n*(n+1)/4
���������Ӽ��ж�������������n*(n+1)��Ϊż�����������s=n*(n+1),���ж�s%4 .
f[i]�����ʾ�����������������i ������
f[j-i]��ʾ����������j-i��������f[j-i+i]��ʾ����������j��������
>>>>>>> 2df9ac79bf7a54a1f8cc63c682f038e91cfed506
*/
#include <cstdlib>
#include <iostream>

<<<<<<< HEAD
#define MIN -1000

int splitSet2Subset(int n)
{
  if( n < 1){
    return -1;
  }
  int sum = n*(n+1);
  if(sum % 4 != 0){
    return -1;
  }
  int m = sum/4;
  int * f = new int[m];
  for(int i = 0; i < m; ++i){
    f[i] = MIN;
  }
  int * arr = new int[n];
  for(int i = 0; i < n; ++i){
    arr[i] = i+1;
  }
  int * store = new int[m];
  for(int i = 0; i < n; ++i){
    while(m >= 0){
      if(f[m] > f[m-arr[i]){
        f[m]
      }
    }
  }
}

int main(int argc, char ** argb)
{
  int n = 7;

  system("pause");
  return 0;
}
=======
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
      f[v] = f[v]+f[v-i];//����������v-i������ + ����������v-i+i������
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
>>>>>>> 2df9ac79bf7a54a1f8cc63c682f038e91cfed506
