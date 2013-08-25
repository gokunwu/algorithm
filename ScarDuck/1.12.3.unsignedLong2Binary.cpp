#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：编程实现：把十进制数(long型)分别以二进制和十六进制形式输出，不
能使用printf系列。
实现了unsigned long型的转换。
*/
#include <cstdlib>
#include <iostream>

void unsignedlong2binary(unsigned long num)
{
  int len = sizeof(unsigned long)*8;
  char * ret = new char[len+1];
  for(int i = len-1; i >= 0; --i){
    unsigned long flag = num<<i>>(len-1);
    if(flag == 1){
      ret[i] = '1';
    }
    else if(flag == 0){
      ret[i] = '0';
    }
  }
  ret[len] = '\0';
  std::cout<<ret<<std::endl;
  delete [] ret;
  ret = NULL;
  return;
}

void unsignedlong2hex(unsigned long num)
{
  int len = sizeof(unsigned long)*8/4;
  char * ret = new char[len+3];
  ret[0] = '0';
  ret[1] = 'x';
  char * ret_cur = ret+2;
  for(int i = len-1; i >=0; --i){
    unsigned long tmp = num<<(4*i)>>(4*(len-1));
    if(tmp < 10 && tmp >= 0){
      ret_cur[i] = '0' + tmp;
    }
    else if(tmp >= 10 && tmp <= 15){
      ret_cur[i] = 'a' + tmp - 10;
    }
  }
  ret_cur[len] = '\0';
  std::cout<<ret<<std::endl;
}

int main(int argc, char ** argv)
{
  unsigned long num = 11;
  unsignedlong2hex(num);
  system("pause");
  return 0;
}
#endif
