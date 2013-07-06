#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入一个正数n，输出所有和为n连续正数序列。
例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以输出3个连续序列1-5、4-6和7-8。
分析：这是网易的一道面试题。
*/

#include <cstdlib>
#include <iostream>

void sumEqualN(int n){
  int small = 1;
  int big = 2;
  int sum = small + big;
  while(small < big && big <= n/2 + 1){
    if(sum < n){
      big++;
      sum += big;
    }
    else if(sum > n){
      sum -= small;
      small++;
    }
    else{
      std::cout<<small<<"-"<<big<<std::endl;
      sum -=small;
      small++;
    }
  }
}

int main(int argc, char ** argv){
  int n = 15;

  sumEqualN(n);

  system("pause");
  return 0;
}

#endif

