
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：找出两个字符串中最大公共子字符串, 如
"abccade","dgcadde"的最大子串为"cad"
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

void longestCommonString(char * str1, int len1, char * str2, int len2, char * ret)
{
  if(str1 == NULL || len1 < 1 || str2 == NULL || len2 < 1){
    return;
  }
  int maxlen = 0;
  int index = 0;
  for(int i = 0; i < len1; ++i){
    for(int j = 0; j < len2; ++j){
      int as = i;
      int bs = j;
      int cnt = 0;
      while(as < len1 && bs < len2 && str1[as] == str2[bs]){
        cnt++;
        ++as;
        ++bs;
      }
      if(cnt > maxlen){
        maxlen = cnt;
        index = i;
      }
    }
  }
  for(int i = 0; i < maxlen; ++i){
    ret[i] = str1[i+index];
  }
  ret[maxlen] = '\0';
}

int main(int argc, char ** argv)
{
  char str1[] = "abccade";
  char str2[] = "dgcadde";
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int len = len1 > len2 ? len1:len2;
  char *ret = new char[len];
  longestCommonString(str1, len1, str2, len2, ret);
  std::cout<<ret<<std::endl;

  system("pause");
  return 0;
}
#endif
