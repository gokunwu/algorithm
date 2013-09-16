#if 0
/*
copyright@nciaebupt 转载请注明出处
2013 google校招笔试题
2.1 写函数，输出前N个素数。不需要考虑整数溢出问题，也不需要使用大数处理算法。
*/
#include <cstdlib>
#include <iostream>

int prime(int n)
{
  if(n < 1){
    return 0;
  }
  if(n == 1){
    std::cout<<"2"<<std::endl;
    return 1;
  }
  std::cout<<"2"<<std::endl;
  int num = 3;
  int pc = 0;
  while(pc < n){
    int flag = 0;
    for(int i = 2; i*i <= num; ++i){
      if(num%i == 0){
        flag = 1;
      }
    }
    if(flag == 0){
      pc++;
      std::cout<<num<<std::endl;
    }
    num += 2;
  }
}

int main(int argc, char ** argv)
{
  int n = 50;
  prime(n);
  system("pause");
  return 0;
}
#endif
