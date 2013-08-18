#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：用1、2、2、3、4、5这六个数字，用C写一个main函数，打印出所有不同的排列，如：512234、412345等，要求：”4″不能在第三位，”3″与”5″不能相连。
*/
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <string>

void exchange(char * str, int i, int j)
{
  if(str == NULL){
    return;
  }
  char ch = str[i];
  str[i] = str[j];
  str[j] = ch;
}

void specialPermutation(char * str, int begin, int end, std::set<std::string> & strset)
{
  if(str == NULL || end < begin){
    return;
  }
  if(begin == end){
    if(strstr(str, "35") == NULL && strstr(str, "53") == NULL && str[2] != '4'){
      std::string tmp = str;
      strset.insert(tmp);
    }
  }
  for(int i = begin; i <= end; ++i){
    exchange(str, begin, i);
    specialPermutation(str, begin+1, end, strset);
    exchange(str, begin, i);
  }
}

int main(int argc, char ** argv)
{
  char str[] = "122345";
  int len = strlen(str);
  std::set<std::string> strset;
  specialPermutation(str, 0, len-1, strset);
  for(std::set<std::string>::iterator it = strset.begin(); it != strset.end(); ++it){
    std::cout<<*it<<std::endl;
  }
  std::cout<<strset.size()<<std::endl;
  system("pause");
  return 0;
}
#endif
