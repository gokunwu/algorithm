#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:把求子集运算转换为组合问题。
分析：假设集合中包含N个元素，  子集合数  =   C(N, 0) + C(N, 1) + ... + C(N, N-1) + C(N, N)，对于任一个子集合，可以用一个N元组表示，即  <S1, S2, ... Sn-1, Sn>, 其中Si取值范围为
(0, 1)，0表示不该子集合不包含该元素，1表示该子集合包含该元素。因此，求子集合就转换成了
罗列所示可能组合的算法。子集合数  = 2^n。
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

void subset(char * str, int * marks, int pos, int len)
{
  if(str == NULL || marks == NULL || len < 1){
    return;
  }
  if(pos >= len){
    int allzero = 0;
    for(int i = 0; i < len; ++i){
      if(marks[i] == 1){
        std::cout<<str[i];
        allzero = 1;
      }
    }
    if(allzero == 0){
      std::cout<<"@"<<std::endl;
    }
    else{
      std::cout<<std::endl;
    }
    return;
  }
  marks[pos] = 1;
  subset(str, marks, pos+1, len);
  marks[pos] = 0;
  subset(str, marks, pos+1, len);
}

int main(int argc, char ** argv)
{
  char str[] = "abcd";
  int len = strlen(str);
  int * marks = new int[len];
  subset(str, marks, 0, len);
  delete [] marks;
  marks = NULL;
  system("pause");
  return 0;
}
#endif
