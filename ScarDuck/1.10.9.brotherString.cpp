#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：如果两个字符串的字符一样，但是顺序不一样，被认为是兄弟字符串，问如何迅速匹配兄弟
字符串？
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

int compare(const void * s1, const void * s2)
{
  return int(*(char *)s1)-int(*(char *)s2);
}

int isBrotherString(char * str1, char * str2)
{
  if(str1 == NULL || str2 == NULL){
    return 0;
  }
  int flag = 0;
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  char * tmpstr1 = new char[len1+1];
  char * tmpstr2 = new char[len2+1];
  strncpy(tmpstr1, str1, len1);
  tmpstr1[len1] = '\0';
  strncpy(tmpstr2, str2, len2);
  tmpstr2[len2] = '\0';
  qsort(tmpstr1, len1, sizeof(char), compare);
  qsort(tmpstr2, len2, sizeof(char), compare);

  if(compare(tmpstr1, tmpstr2) == 0){
    flag = 1;
  }
  else{
    flag = 0;
  }
  delete [] tmpstr1;
  tmpstr1 = NULL;
  delete [] tmpstr2;
  tmpstr2 = NULL;

  return flag;
}

int main(int argc, char ** argv)
{
  char str1[] = "abcd";
  char str2[] = "acdb";
  int res = isBrotherString(str1, str2);
  std::cout<<res<<std::endl;

  system("pause");
  return 0;
}
#endif
