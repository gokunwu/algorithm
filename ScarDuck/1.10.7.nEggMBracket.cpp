#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：有N个鸡蛋和M个篮子，把鸡蛋放到M个篮子里，每个篮子都不能为空。另外，需要满足：任意一个小于N的正整数，都能由某几个篮子内蛋的数量相加的和得到。写出程序，使得输入一个(N,M)，输出所有可能的分配情况。
分析：从题意中应该可以得出，对于(1,1,2,2)和(1,2,1,2)这两种组合，应该是一样的。
因而对于这M个篮子中的鸡蛋数量，我们用数组basket[M]来表示，我们按照非递减顺序进行排列，即basket[i] <= basket[i+1]

1.我们利用归纳法来总结出一个规律：
   对于前n个篮子，其鸡蛋数量总和为Sn，那么对于第n+1个篮子，其鸡蛋数量应该满足：
   basket[n+1] <= Sn + 1，如果basket[n+1] > Sn + 1，那么Sn + 1这个数将无法通过相应的篮子鸡蛋数相加来获得。
   由于是非递减序列，因而
   basket[n] <= basket[n+1] <= Sn + 1
2.我们来证明符合上式的数组能够满足条件“任意一个小于N的正整数，都能由某几个篮子内蛋的数量相加的和得到”。
   当M = 1时，basket[0] = 1，当M=2时，取basket[1] = 1，能够满足上述条件。
   取basket[1] = 2，也能够满足上述条件。
   假设M = n-1时，满足上述条件，我们来证明当M = n时亦满足。
   前n-1个篮子的鸡蛋数量总和为Sn-1，此时加上第n个篮子，总和为Sn = Sn-1 + basket[n-1]。即证明Sn - 1，Sn - 2，Sn - 3，Sn - (basket[n-1] - 1)都可以由某几个篮子内蛋的数量相加的和得到。由于basket[n-1] <= Sn-1，而且小于或者等于Sn-1的数能由某几个篮子内蛋的数量相加的和得到，所以Sn - 1，Sn - 2，Sn - 3，Sn - (basket[n-1] - 1)亦可得到。
   证毕。

3.对于N和M的值，我们在输入后即可做一个判断。
   2.1  当N < M，明显有篮子为空，因而不符。
   2.2  当N >= M时，第一个篮子必然要放1个鸡蛋，其后面的篮子我们按照basket[n] <= basket[n+1] <= Sn + 1取最大值，依次为2,4,8,16......，鸡蛋总数为2^M - 1，即M个篮子的鸡蛋数量最大值。

   所以M <= N < 2^M
*/
#include <cstdlib>
#include <cmath>
#include <iostream>

void nEggMBracket(int cur_sum, int cur_num, int bracket_id, int * bracket, int N, int M)
{
  if(cur_sum == N && cur_num == M){
    for(int i = 0; i < M; ++i){
      std::cout<<bracket[i];
    }
    std::cout<<std::endl;
    return;
  }
  if(cur_sum + cur_num*(M - bracket_id) > N){//prune
    return;
  }
  if(cur_sum + (cur_sum+1)*(pow(2, M-bracket_id)-1) < N){//prune
    return;
  }
  for(int i = cur_num; i <= cur_sum + 1; ++i){
    bracket[bracket_id] = i;
    nEggMBracket(cur_sum+i, i, bracket_id+1, bracket, N, M);
  }
}

int main(int argc, char ** argv)
{
  int N = 6;
  int M = 3;
  int * bracket = new int[M];
  nEggMBracket(0, 1, 0, bracket, N, M);


  //system("pause");
  return 0;
}


#endif


























