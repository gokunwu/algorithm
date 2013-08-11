#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：不开辟用于交换数据的临时空间，如何完成字符串的逆序
分析：不开辟用于交换数据的临时空间，如何完成字符串的逆序(在技术一轮面试中，有些面试官
会这样问)
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

void reverseString(char * str)
{
  if(str == NULL){
    return;
  }
  int len = strlen(str);
  int left = 0;
  int right = len -1;
  while(left < right){
    str[left] = str[left]^str[right];
    str[right] = str[left]^str[right];
    str[left] = str[left]^str[right];
    left++;
    right--;
  }
}

int main(int argc, char ** argv)
{
  char str[] = "abcdef";
  reverseString(str);
  std::cout<<str<<std::endl;

  system("pause");
  return 0;
}
#endif
