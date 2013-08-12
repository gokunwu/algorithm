#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：删除字符串中的数字并压缩字符串（神州数码以前笔试题），如字符串abc123de4fg56处理
后变为abcdefg。注意空间和效率。
*/
#include <cstdlib>
#include <iostream>

int delNumInStr(char * str)
{
  if(str == NULL){
    return -1;
  }
  char * cur = str;
  char * pcur = str;
  int numcnt = 0;
  while(*cur != '\0' && *pcur != '\0'){
    if(!(*cur >= '\0' && *cur <= '9')){
      *pcur = *cur;
      pcur++;
    }
    else{
      numcnt++;
    }
    cur++;
  }
  *pcur = '\0';
  return numcnt;
}

int main(int argc, char ** argv)
{
  char str[] = "abc123de4fg56";
  int res = delNumInStr(str);
  std::cout<<res<<std::endl;
  std::cout<<str<<std::endl;
  system("pause");
  return 0;
}
#endif
