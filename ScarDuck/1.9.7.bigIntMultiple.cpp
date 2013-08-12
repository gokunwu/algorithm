#if 0
/*
copyright@nciaebupt 转载请注明出处
问题：大整数相乘
*/
#include <cstdlib>
#include <iostream>

void bigIntMultiple(char * num1, char * num2, char * res)
{
  if(num1 == NULL || num2 == NULL){
    return;
  }
  int in = 0;
  int len1 = 0;
  int len2 = 0;
  while(num1[len1] != '\0'){
    len1++;
  }
  while(num2[len2] != '\0'){
    len2++;
  }
  int rescur = len1 + len2;
  int index = 0;
  for(int i2 = len2-1; i2 >=0; --i2){
    index = --rescur;
    if(num2[i2] != '0'){
      for(int i1 = len1-1; i1 >= 0; --i1){
        int tmp = res[index]-'0' + (num2[i2]-'0')*(num1[i1]-'0') + in;
        in = tmp/10;
        tmp = tmp%10;
        res[index--] += tmp;
      }
    }
    res[index] += in;
  }
}

void printBigInt(char *res)
{
  if(res == NULL){
    return;
  }
  int flag = 0;
  while(*res != '\0'){
    if(*res != '0'){
      flag = 1;
    }
    if(flag == 1){
      std::cout<<int(*res-'0');
    }
    res++;
  }
  std::cout<<std::endl;
}

int main(int argc, char ** argv)
{
  char num1[] = "10000";
  char num2[] = "4";
  int len = sizeof(num1)/sizeof(num1[0]) + sizeof(num2)/sizeof(num2[0]);
  char * res = new char(len - 1);
  for(int i = 0; i < len-1; ++i){
    res[i] = '0';
  }
  res[len-2] = '\0';
  bigIntMultiple(num1, num2, res);
  printBigInt(res);

  system("pause");
  return 0;
}
#endif
