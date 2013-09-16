#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：现存在一堆面值为 V1、V2、V3 … 个单位的硬币，问最少需要多少个硬币才能找出总值为 T 个单位的零钱？假设这一堆面值分别为 1、2、5、21、25 元，需要找出总值 T 为 63 元的零钱。
分析：长度为m的数组c[1...m]中存放一系列子结果，即c[i]为要凑的钱数为i时所需的最少硬币数，则c[m]为
所求
   当要找的钱数i(1<i<m)与当前所试探的硬币面值k相等时，结果为1，即c[i]=1
   当i大于当前所试探硬币面值k时，若c[i]为0，即还未赋过值，且c[i-k]不为0，即从i元钱中刨去k元
后剩下的钱数可以找开，
              则c[i]=c[i-k]+1
        若c[i]不为0，即已赋过值，则c[i]为c[i-k]+1和c[i]中较小的
*/
#include <cstdlib>
#include <iostream>

const int MAX = 10000;

int min(int i, int j)
{
  return i<j ? i:j;
}

int leastCoins(int * coins, int len, int V)
{
  if(coins == NULL || len < 1){
    return -1;
  }
  int dp[V];
  for(int i = 0; i <= V; ++i){
    dp[i] = MAX;
  }
  dp[1] = 1;
  for(int i = 0; i < len; ++i){
    for(int v = 0; v <= V; ++v){
      dp[v] = min(dp[v], dp[v-coins[i]]+1);
    }
  }
  return dp[V];
}

int main(int argc, char ** argv)
{
  int coins[] = {1,2,5,21,25};
  int len = sizeof(coins)/sizeof(int);
  int T = 63;
  int cnt = leastCoins(coins, len, T);
  std::cout<<cnt<<std::endl;
  system("pause");
  return 0;
}
#endif
