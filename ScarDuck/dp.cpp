
#if 0
1.状态是一维的
1.1 下降/非降子序列问题 非降子序列问题：

/*
题目：设有一个正整数的序列：d1,d2,…，dn，对于下标i1<i2<…＜im，若有di1≤di2≤…≤dim
则称存在一个长度为m的不下降序列。
  例如，下列数列
     13  7  9  16  38  24  37  18  44  19  21  22  63  15
  7, 9, 16, 24, 37, 44, 63 则存在长度为7的不下降序列。
问题分析：
如果前i-1 个数中用到ak (ak>ai或ak<=ai)构成了一个的最长的序列加上第I个数ai就是前i 个数中用
到i 的最长的序列了。那么求用到ak构成的最长的序列有要求前k-1个数中……
从上面的分析可以看出这样划分问题满足最优子结构，那满足无后效性么？显然对于第i 个数时只考
虑前i-1 个数,显然满足无后效性，可以用动态规划解。
分析到这里动态规划的三要素就不难得出了：如果按照序列编号划分阶段，设计一个状态opt[i] 表示
前i 个数中用到第i 个数所构成的最优解。那么决策就是在前i-1 个状态中找到最大的opt[j]使得aj>ai(或
aj<=ai)，opt[j]+1就是opt[i]的值；用方程表示为：{我习惯了这种写法，但不是状态转移方程的标准写法  }
opt[i]=max(opt[j])+1    (0<=j<i 且aj<=ai)        {最长非降子序列}
opt[i]=max(opt[j])+1    (0<=j<i 且aj>ai)         {最长下降子序列}
实现求解的部分代码：
opt[0]:=maxsize；{maxsize 为maxlongint或-maxlongint}
for   i:=1 to n do
for j:=0 to i-1 do
if ( a[j]>a[i]) and (opt[j]+1>opt[i]) then
opt[i]:=opt[j]+1;
ans:=-maxlongint;
for i:=1 to n do
if opt[i]>ans then ans:=opt[i];                 {ans  为最终解}
复杂度：从上面的实现不难看出时间复杂度为O（N2），空间复杂度O（N）；
*/
#include <cstdlib>
#include <iostream>

int longestRiseSquence(int *arr, int len)
{
  if(arr == NULL || len < 1){
    return 0;
  }
  int * dp = new int[len];
  for(int i = 0; i < len; ++i){
    dp[i] = 1;
  }
  for(int i = 0; i < len; ++i){
    for(int j = 0; j < i; ++j){
      if(arr[i] > arr[j] && dp[j]+1 > dp[i]){
        dp[i] = dp[j] + 1;
      }
    }
  }
  int max = 0;
  for(int i = 0; i < len; ++i){
    if(dp[i] > max){
      max = dp[i];
    }
  }
  if(dp != NULL){
    delete [] dp;
    dp = NULL;
  }
  return max;
}

int main(int argc, char ** argv)
{
  int arr[] = {13, 7, 9, 16, 38, 24, 37, 18, 44, 19, 21, 22, 63, 15};
  //int arr[] = {3, 18, 7, 14, 10, 12, 23, 41, 16, 24};
  int len = sizeof(arr)/sizeof(int);
  int ret = longestRiseSquence(arr, len);
  std::cout<<ret<<std::endl;

  system("pause");
  return 0;
}

/*
例题1   拦截导弹  来源：NOIP1999(提高组) 第一题
【问题描述】
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然
它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到
敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000 的正整数），计算这套系统最多能拦
截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。
【输入文件】missile.in
单独一行列出导弹依次飞来的高度。
【输出文件】missile.out
两行，分别是最多能拦截的导弹数，要拦截所有导弹最少要配备的系统数
【输入样例】
389 207 155 300 299 170 158 65
【输出样例】
6
2
【问题分析】
有经验的选手不难看出这是一个求最长非升子序列问题，显然标准算法是动态规划。
以导弹依次飞来的顺序为阶段，设计状态opt[i]表示前i 个导弹中拦截了导弹i 可以拦截最多能拦截到
的导弹的个数。
状态转移方程：
opt[i]=max(opt[j])+1   (h[i]>=h[j],0=<j<i)    {h[i]存，第i 个导弹的高度}
最大的opt[i]就是最终的解。
这只解决了第一问，对于第二问最直观的方法就是求完一次opt[i]后把刚才要打的导弹去掉，在求一
次opt[i]直到打完所有的导弹，但这样做就错了。
不难举出反例：  6 1 7 3 2
错解：  6 3 2/1/7    正解：6 1/7 3 2
其实认真分析一下题就回发现：每一个导弹最终的结果都是要被打的，如果它后面有一个比它高的导
弹，那打它的这个装置无论如何也不能打那个导弹了，经过这么一分析，这个问题便抽象成在已知序列里
找最长上升序列的问题。
求最长上升序列和上面说的求最长非升序列是一样的，这里就不多说了。
复杂度：时间复杂度为O（N2），空间复杂度为O（N）
*/
#include <cstdlib>
#include <iostream>

int missile(int * arr, int len, int & dec, int & inc)
{
  if(arr == NULL || len < 1){
    return -1;
  }
  int * dpinc = new int[len];
  int * dpdec = new int[len];
  for(int i = 0; i < len; ++i){
    dpinc[i] = 1;
    dpdec[i] = 1;
  }
  for(int i = 0; i < len; ++i){
    for(int j = 0; j < i; ++j){
      if(arr[i] < arr[j] && dpdec[i] < dpdec[j]+1){
        dpdec[i] = dpdec[j] + 1;
      }
      if(arr[i] > arr[j] && dpinc[j]+1 > dpinc[i]){
        dpinc[i] = dpinc[j]+1;
      }
    }
  }
  dec = 0;
  inc = 0;
  for(int i = 0; i < len; ++i){
    if(dpdec[i] > dec){
      dec = dpdec[i];
    }
    if(dpinc[i] > inc){
      inc = dpinc[i];
    }
  }
  if(dpinc != NULL){
    delete [] dpinc;
    dpinc = NULL;
  }
  if(dpdec != NULL){
    delete [] dpdec;
    dpdec = NULL;
  }
  return 1;
}


int main(int argc, char ** argv)
{
  int arr[] = {389,207,155,300,299,170,158,65};
  int len = sizeof(arr)/sizeof(int);
  int dec = 0;
  int inc = 0;
  missile(arr, len, dec, inc);
  std::cout<<dec<<std::endl;
  std::cout<<inc<<std::endl;

  system("pause");
  return 0;
}

/*
例题二 合唱队形 来源：NOIP2004(提高组) 第一题
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，
T2，…，TK，  则他们的身高满足T1<...<Ti>Ti+1>…>TK(1<=i<=K)。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱
队形。
【输入文件】
        输入文件chorus.in的第一行是一个整数N(2<=N<=100)，表示同学的总数。第一行有n个整数，
用空格分隔，第i 个整数Ti(130<=Ti<=230)是第i 位同学的身高(厘米)。
【输出文件】
        输出文件chorus.out包括一行，这一行只包含一个整数，就是最少需要几位同学出列。
【样例输入】
8
186 186 150 200 160 130 197 220
【样例输出】
4
【数据规模】
对于50％的数据，保证有n<=20；
对于全部的数据，保证有n<=100。
【问题分析】
出列人数最少，也就是说留的人最多，也就是序列最长。
这样分析就是典型的最长下降子序列问题。只要枚举每一个人站中间时可以的到的最优解。显然它就
等于，包括他在内向左求最长上升子序列，向右求最长下降子序列。
我们看一下复杂度：
计算最长下降子序列的复杂度是O（N2），一共求N次，总复杂度是O（N3）。这样的复杂度对于这
个题的数据范围来说是可以AC的。但有没有更好的方法呢？
其实最长子序列只要一次就可以了。因为最长下降（上升）子序列不受中间人的影响。
只要用OPT1 求一次最长上升子序列，OPT2 求一次最长下降子序列。这样答案就是
N-max(opt1[i]+opt2[i]-1).
复杂度由O（N3）降到了O（N2）。
*/
#include <cstdlib>
#include <iostream>

int chorus(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return -1;
  }
  int * dpinc = new int[len];
  int * dpdec = new int[len];
  for(int i = 0; i < len; ++i){
    dpinc[i] = 1;
    dpdec[i] = 1;
  }
  for(int i = 0; i < len; ++i){
    for(int j = 0; j < i; ++j){
      if(arr[i] < arr[j] && dpdec[i] < dpdec[j]+1){
        dpdec[i] = dpdec[j] + 1;
      }
      if(arr[i] > arr[j] && dpinc[i] < dpinc[j] + 1){
        dpinc[i] = dpinc[j] + 1;
      }
    }
  }
  int max = 0;
  for(int i = 0; i < len; ++i){
    if(dpdec[i]+dpinc[i] > max){
      max = dpdec[i]+dpinc[i];
    }
  }
  return len-(max-1);
}

int main(int argc, char ** argv)
{
  int arr[] = {186, 186, 150, 200, 160, 130, 197, 220};
  int len = sizeof(arr)/sizeof(int);
  int ret = chorus(arr, len);
  std::cout<<ret<<std::endl;

  system("pause");
  return 0;
}
#endif








