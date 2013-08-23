#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：strstr和strncmp源码实现
strstr
功能: 找出s2字符串在s1字符串中第一次出现的位置（不包括s2的串结束符）
返回结果:返回该位置的指针，如找不到，返回空指针。

strncmp
功能:  比较字符串s1和s2的前n个字符.
返回结果:如果前n字节完全相等，返回值就=0；在前n字节比较过程中，如果出现s1[n]与
s2[n]不等，则返回(s1[n]-s2[n])
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

char * _strstr(const char * s1, const char * s2)
{
  if(s2 == NULL){
    return (char *)s1;
  }
  int len2 = strlen(s2);
  for(; *s1!= '\0'; s1++){
    if(*s1 == *s2 && strncmp(s1, s2, len2) == 0){
      return (char *)s1;
    }
  }
  return NULL;
}

int _strncmp(const char * s1, const char * s2, unsigned int n)
{
  if(!n){
    return 0;
  }
  while(--n && *s1 && *s1 == *s2){
    s1++;
    s2++;
  }
  return *s1-*s2;
}

int main(int argc, char ** argv)
{
  char str1[] = "abcdef";
  char str2[] = "cde";
  char * p = _strstr(str1, str2);
  std::cout<<p<<std::endl;

  char s1[] = "abc";
  char s2[] = "adcd";
  int flag = _strncmp(s1, s2, 2);
  std::cout<<flag<<std::endl;

  system("pause");
  return 0;
}
#endif
