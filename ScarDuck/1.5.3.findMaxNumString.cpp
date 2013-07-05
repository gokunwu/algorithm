#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:在字符串中找出连续最长的数字串，并把这个串的长度返回，并把这个最长数字串付
给其中一个函数参数outputstr所指内存。例如："abcd12345ed125ss123456789"的首地址传给
intputstr 后，函数将返回9，outputstr所指的值为123456789
*/
#include <cstdlib>
#include <iostream>
#include <cstring>

int findMaxNumString(char * str, char * outputstr){
  if(str == NULL) return -1;
  int count = 0;
  int maxlen = 0;
  char * numstr;
  for(int i = 0; i < strlen(str); ++i){
    if(str[i] >= '0' && str[i] <= '9'){
      count = 0;
      for(int j = i; j < strlen(str); ++j){
        if(str[j] >= '0' && str[j] <= '9'){
          count++;
        }
        else{
          break;
        }
      }
      if(maxlen < count){
        maxlen = count;
        numstr = &str[i];
      }
    }
  }
  char * out = outputstr;
  for(int i = 0; i < maxlen; ++i){
    *out++ = *numstr++;
  }
  *out = '\0';
  return maxlen;
}


int main(int argc, char ** argv){
  char str[] = "abcd12345ed125ss123456789";
  char outputstr[100];

  int len = findMaxNumString(str, outputstr);
  std::cout<<len<<std::endl;
  std::cout<<outputstr<<std::endl;

  system("pause");
  return 0;
}
#endif
