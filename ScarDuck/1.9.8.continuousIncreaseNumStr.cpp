#if 0
/*
copyright@nciaebupt 转载请注明出处
问题：求最大连续递增数字串（如ads3sl456789DF3456ld345AA中的456789）
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

int continuousIncreaseNumStr(char * str, char *res)
{
  if(str == NULL){
    return 0;
  }
  int len = 1;
  int maxlen = 0;
  int ires = 0;
  for(int i = 1; str[i] != '\0'; ++i){
    if(str[i] >='0' && str[i] <='9' && str[i-1] >= '0' && str[i] <= '9'
       && str[i] == str[i-1] +1){//continuous increase num
      len++;
    }
    else{//cur not num or not continue
      if(maxlen < len){
        maxlen = len;
        ires = i;
      }
      if(str[i] >='0' && str[i] <='9'){
        len = 1;
      }
      else{
        len = 0;
      }
    }
  }
  for(int i = 0; i < maxlen; ++i){
    res[i] = str[ires-maxlen+i];
  }
  res[maxlen] = '\0';
  return maxlen;
}

int main(int argc, char ** argv)
{
  char str[] = "ads3sl456789DF3456ld345AA";
  int len = sizeof(str)/sizeof(str[0]);
  char * res = new char(len);
  int maxlen = continuousIncreaseNumStr(str, res);
  std::cout<<maxlen<<std::endl;
  std::cout<<res<<std::endl;

  system("pause");
  return 0;
}
#endif
