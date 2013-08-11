#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为S。输入n，打印出S的所有
可能的值出现的概率。
分析：利用基本的概率论知识，而不需要统计所有可能的S出现的次数。为了方便，这里先讨论某个S出现的概率，设为P(S),则有
    P(S) = P(S1) + P(S2) + ... + P(Sk)

S1,S2...Sk表示和为S的各种骰子组合。另外，

    P(Si) = P(a1) + P(a2) + ... + P(an)

其中，P(ai)表示第i个骰子出现值为ai的概率。

很简单的，就是一个概率论的东西，很基本的。不需要统计所有可能的S出现的次数，而直接计算和为S的各种可能的骰子组合的概率，然后把所有组合的概率相加，就得到了和为S的概率了。
这种方法是DP中的表格法，用至底向上填表的方式，把结果求出来。用表格法，一行代表一个骰子，列表示各个S值，所以一共有6*N列。本来是要用N行的，可是这里只用了一个二维的数组，因为现在计算的值只与前一次计算的值相关，所以其中一行保存上一次计算的结果，另一行保存正在计算的结果，这样可以节省大量的空间。

代码中的N是指有几个骰子，或者说是掷了几次骰子。第一个for循环表示第一个骰子的情况，然后第二个for循环中的k表示第k个骰子。当到了第k个骰子时，内层的for循环开始对和个S的值进行分析，i表示的就是各个不同的S。在这个循环里，考虑第k个骰子的6种不同取值（j表示的就是骰子的点数），然后在while循环里把所有可能的得到和为S的组合的概率进行相加。flag的作用很简单，就是在二维数组里对当时值和已经计算得到的值进行区别，他只出现在数组的行号处。
*/
#include <cstdlib>
#include <iostream>
#define MAXVALUE 6

int sumOfNDice(int n){
  if(n < 1){
    return -1;
  }
  double pProbabilities[2][MAXVALUE*n + 1];
  int flag = 1;
  for(int i = 0; i < MAXVALUE*n + 1; ++i){
    pProbabilities[flag][i] = 0.0;
    pProbabilities[1-flag][i] = 0.0;
  }
  for(int i = 1; i <= MAXVALUE; ++i){//当筛子数为1时
    pProbabilities[flag][i] = 1.0/6;
  }
  for(int k = 2; k <= n; ++k){//当骰子数为2-n时
    for(int i = k; i <= MAXVALUE*k; ++i){
      pProbabilities[1-flag][i] = 0;
      for(int j = 1; j <= i && j <= MAXVALUE; ++j){
        pProbabilities[1-flag][i] += pProbabilities[flag][i-j]/6;
      }
    }
    flag = 1 - flag;
  }
  for(int i = 0; i <= MAXVALUE*n; ++i){
    std::cout<<pProbabilities[flag][i]<<std::endl;
  }
  return 1;
}
int main(int argc, char ** argv)
{
  int n = 2;
  sumOfNDice(n);
  system("pause");
  return 0;
}
#endif
