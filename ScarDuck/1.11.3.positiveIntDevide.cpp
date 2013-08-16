#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：编程实现两个正整数的除法（不能用除法操作符）
分析：使用循环减法来实现除法
*/
#include <cstdlib>
#include <iostream>

void positiveIntDevide(int a, int b, int & res, int & rev)
{
  if(a < 1 || b < 1){
    return;
  }
  if(a < b){
    res = 0;
    rev = a;
  }
  else if( a == b){
    res = 1;
    rev = 0;
  }
  else{
    res = 0;
    rev = 0;
    while(a > b){
      a = a-b;
      res++;
    }
    rev = a;
  }
}

int main(int argc, char ** argv)
{
  int a = 102;
  int b = 10;
  int res = 0;
  int rev = 0;
  positiveIntDevide(a, b, res, rev);
  std::cout<<res<<std::endl;
  std::cout<<rev<<std::endl;
  system("pause");
  return 0;
}
#endif
