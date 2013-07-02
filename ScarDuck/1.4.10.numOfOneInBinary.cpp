
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：
统计整数二进制表示中1的个数
分析：
可以考虑每次找到从最低位开始遇到的第一个1，计数，再把它清零，清零的位运算操作是
与一个零，但是在有1的这一位与零的操作要同时不影响未统计过的位数和已经统计过的位
数，于是可以有这样一个操作  n&(n-1) ，这个操作对比当前操作位高的位没有影响，对低
位则完全清零。拿6（110）来做例子，第一次  110&101=100，这次操作成功的把从低位起
第一个1消掉了，同时计数器加1，第二次100&011=000，同理又统计了高位的一个1，此
时n已变为0，不需要再继续了，于是110中有2个1。
*/
#include <cstdlib>
#include <iostream>

int numOfOneInBinary(int n){
  int count = 0;
  while(n){
    n = n&(n-1);
    count++;
  }
  return count;
}

int main(int argc, char ** argv){
  int n = 5;

  int num = numOfOneInBinary(n);

  std::cout<<num<<std::endl;

  system("pause");
  return 0;
}

#endif
