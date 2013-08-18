#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:字符串原地压缩
分析："eeeeeaaaffg"压缩为"e5a3f2g"
      abc -> abc
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

void stringCompression(char *str, int len)
{
  if(str == NULL || len < 1){
    return;
  }
  int i = 0;
  int j = 0;
  int cnt = 0;
  while(i < len){
    if(str[i] == str[j]){
      cnt++;
      i++;
    }
    else{
      if(cnt > 1){
        str[++j] = '0' + cnt;
        str[++j] = str[i];
        cnt = 0;
      }
      else if(cnt == 1){
        str[++j] = str[i];
        cnt = 0;
      }
    }
  }
  if(cnt > 1){
    str[++j] = '0'+cnt;
  }
  str[++j] = '\0';
}

int main(int argc, char ** argv)
{
  //char str[] = "eeeeeaaaff";
  char str[] = "abc";
  int len = strlen(str);
  stringCompression(str, len);
  std::cout<<str<<std::endl;
  system("pause");
  return 0;
}
#endif
