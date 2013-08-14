#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：函数将字符串中的字符'*'移到串的前部分
分析：2005年11月金山笔试题。编码完成下面的处理函数。
函数将字符串中的字符'*'移到串的前部分，
前面的非'*'字符后移，但不能改变非'*'字符的先后顺序，函数返回串中字符'*'的数量。
如原始串为：ab**cd**e*12，
处理后为*****abcde12，函数并返回值为5。（要求使用尽量少的时间和辅助空间）
*/
#include <cstdlib>
#include <iostream>

void exchange(char * str, int i, int j)
{
  if(str == NULL){
    return;
  }
  char tmp = str[i];
  str[i] = str[j];
  str[j] = tmp;
}

int moveStar2Front(char * str, int len)
{
  if(str == NULL){
    return 0;
  }
  int pchar = len - 2;
  //int pchar = 0;
  int cur = len - 2;
  while(cur >= 0){
    if(str[cur] != '*'){
      str[pchar] = str[cur];
      pchar--;
    }
    cur--;
  }
  int nstar = pchar+1;
  while(pchar >=0){
    str[pchar] = '*';
    pchar--;
  }
  return nstar;
}

int main(int argc, char ** argv)
{
  char str[] = "ab**cd**e*12";
  int len = sizeof(str)/sizeof(str[0]);
  std::cout<<len<<std::endl;
  int res = moveStar2Front(str, len);
  std::cout<<res<<std::endl;
  std::cout<<str<<std::endl;
  system("pause");
  return 0;
}
#endif
