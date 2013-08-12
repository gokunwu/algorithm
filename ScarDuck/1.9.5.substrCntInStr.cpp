#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：已知一个字符串，比如asderwsde,寻找其中的一个子字符串比如sde的个数，如果没有返回0，有的话返回子字符串的个数
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

int substrCntInStr(const char * str, const char * substr)
{
  if(str == NULL){
    return 0;
  }
  if(substr == NULL){
    return 0;
  }
  const char * pstr = str;
  int sublen = strlen(substr);
  int cnt = 0;
  while((pstr = strstr(pstr, substr)) != NULL){
    pstr = pstr + sublen;
    cnt++;
  }
  return cnt;
}

int matchsubstr(const char * str, const char * substr, int pstr){
  if(str == NULL || substr == NULL){
    return 0;
  }
  int i = 0;
  while(substr[i] != '\0' && str[i+pstr] != '\0'){
    if(substr[i] == str[i+pstr]){
      i++;
    }
    else{
      return 0;
    }
  }
  if(substr[i] == '\0'){
    return 1;
  }
}

int substrCntInStr1(const char * str, const char * substr)
{
  if(str == NULL){
    return 0;
  }
  if(substr == NULL){
    return 0;
  }
  int cnt = 0;
  int pstr = 0;
  int psubstr = 0;
  int strLen = strlen(str);
  int substrlen = strlen(substr);
  while(pstr < strLen - substrlen){
    while(str[pstr] != substr[psubstr]){
      pstr++;
    }
    if(pstr > strLen-substrlen){
      return 0;
    }
    else{
      if(matchsubstr(str, substr, pstr) != 0){
        cnt++;
        pstr++;
      }
      else{
        pstr++;
      }
    }
  }
  return cnt;
}

int main(int argc, char ** argv)
{
  char str[] = "asderwsde";
  char substr[] = "sde";

  int cnt = substrCntInStr1(str, substr);
  std::cout<<cnt<<std::endl;

  system("pause");
  return 0;
}
#endif
