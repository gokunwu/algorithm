
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：实现函数double Power(double base,int exponent)，求base的exponent次方。
不得使用库函数，同时不需要考虑大树问题。
分析：
这道题目有以下几点需要注意：
1.  0的0次方是无意义的，非法输入
2.  0的负数次方相当于0作为除数，也是无意义的，非法输入
3.  base如果非0，如果指数exponent小于0，可以先求base的|exponent|次方，然后再
求倒数
4.  任何数的0次方都为0
5.  判断double类型的base是否等于0不能使用==号。因为计算机表述小树(包括float
和double型小数)都有误差，不能直接使用等号(==)判断两个小数是否相等。如果两
个数的差的绝对值很小，那么可以认为两个double类型的数相等。
*/
#include <cstdlib>
#include <iostream>

bool doubleEqual(double x, double y)
{
  if((x > y && x-y < 0.000001) || (x < y && x-y > -0.000001)){
    return true;
  }
  else{
    return false;
  }
}

double Power(double base, int exponent)
{
  if(doubleEqual(base, 0) && exponent <= 0){
    return -1.0;
  }
  if(exponent == 0){
    return 1.0;
  }
  bool negative = false;
  if(exponent < 0){
    negative = true;
    exponent = -exponent;
  }
  double res = 1.0*base;
  for(int i = 2; i <= exponent; i +=2){
    res *= res;
  }
  if(exponent % 2 == 1){
    res *= base;
  }
  if(negative == true){
    return 1/res;
  }
  else{
    return res;
  }
}

int main(int argc, char ** argv)
{
  double base = 2.0;
  int exponent = 5;

  double res = Power(base, exponent);
  std::cout<<res<<std::endl;

  system("pause");
  return 0;
}
#endif
