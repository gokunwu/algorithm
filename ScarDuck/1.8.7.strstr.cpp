
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：实现函数strstr
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

char * _strstr(const char * str1, const char * str2)
{
  if(str1 == NULL && str2 == NULL){
    return NULL;
  }
  if(str1 == NULL){
    return NULL;
  }
  if(str2 == NULL){
    return (char*)str1;
  }
  char * cp = (char *)str1;
  char * cur1 = NULL;
  char * cur2 = NULL;
  while(*cp != '\0'){
    cur1 = cp;
    cur2 = (char *)str2;
    while(*cur1 != '\0' && *cur2 != '\0' && (*cur1 - *cur2) == 0){
      cur1++;
      cur2++;
    }
    if(*cur2 == '\0'){
      return cp;
    }
    cp++;
  }
}

int main(int argc, char ** argv)
{
  char str1[] = "I am a goog boy!";
  char str2[] = "am";
  char * cp = _strstr(str1, str2);
  std::cout<<cp<<std::endl;

  system("pause");
  return 0;
}
#endif
