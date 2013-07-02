
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：一个台阶总共有n级，如果一次可以跳1级，也可以跳2级。求总共有
多少总跳法。
分析：
这道题最近经常出现，包括MicroStrategy等比较重视算法的公司都曾
先后选用过个这道题作为面试题或者笔试题。
首先我们考虑最简单的情况。如果只有1级台阶，那显然只有一种跳法。
如果有2级台阶，那就有两种跳的方法了：一种是分两次跳，每次跳1
级；另外一种就是一次跳2级。
现在我们再来讨论一般情况。我们把n级台阶时的跳法看成是n的函数，
记为f(n)。
当  n=1 时有  1 种跳法
一次跳一阶
当  n=2 时有  2 种跳法
一次跳一阶，  1 1
一次跳二阶  2
当n>2时，第一次跳的时候就有两种不同的选择：
一是第一次只跳1级，此时跳法数目等于后面剩下的n-1级台阶的跳法
数目，即为f(n-1)；
另外一种选择是第一次跳2级，此时跳法数目等于后面剩下的n-2级台
阶的跳法数目，即为f(n-2)。
因此n级台阶时的不同跳法的总数f(n)=f(n-1)+ f(n-2)。
*/
#include <cstdlib>
#include <iostream>

int Fibonacci(int n){
  int prepre = 1;
  int pre = 2;
  int res = 0;
  for(int i = 3; i <= n; ++i){
    res = pre + prepre;
    prepre = pre;
    pre = res;
  }
  return res;
}

int main(int argc, char ** argv){
  int n = 5;

  int num = Fibonacci(n);

  std::cout<<num<<std::endl;

  system("pause");
  return 0;
}

#endif





