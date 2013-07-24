#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，则输出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。
分析：这是个递归求解的问题。递归算法有四个特性：（1)必须有可达到的终止条件，否则程序将陷入死循环；（2）子问题在规模上比原问题小；（3）子问题可通过再次递归调用求解；（4）子问题的解应能组合成整个问题的解。
对于字符串的排列问题。如果能生成
n-1个元素的全排列，就能生成n个元素的全排列。对于只有1个元素的集合，可以直接生成全排列。全排列的递归终止条件很明确，只有1个元素时。
*/
#include <cstring>
#include <cstdlib>
#include <iostream>

void exchange(char * str, int i, int j){
  if(str == NULL){
    return;
  }
  char tmp = str[i];
  str[i] = str[j];
  str[j] = tmp;
}

void permutationsOfString(char * str, int begin, int end)
{
  if(str == NULL || begin > end){
    return;
  }
  if(begin == end){
    std::cout<<str<<std::endl;
  }
  else{
    for(int i = begin; i <= end; ++i){
      exchange(str, begin, i);
      permutationsOfString(str, begin + 1, end);
      exchange(str, begin, i);
    }
  }
}

int main(int argc, char ** argv)
{
  char str[]="abc";
  int len = strlen(str);

  permutationsOfString(str, 0, len -1);

  system("pause");
  return 0;
}
#endif


#if 0
/*
copyright@nciaebupt 转载请注明出处
问题：输入一个字符串，输出该字符串中字符的所有组合。举个例子，如果输入abc，它的组合有a、b、c、ab、ac、bc、abc。
分析：用递归求解。可以考虑求长度为n的字符串中m个字符的组合，设为C(n,m)。原问题的解即为C(n, 1), C(n, 2),...C(n, n)的总和。
对于求C(n,m)，从第一个字符开始扫描，每个字符有两种情况，要么被选中，要么不被选中，如果被选中，递归求解C(n-1, m-1)。如果未被选中，递归求解C(n-1, m)。不管哪种方式，n的值都会减少，递归的终止条件n=0或m=0。
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

void combinationsOfStr(char * str, int size, std::vector<char> & chvec){
  if(str == NULL || (size != 0 && *str == '\0')){
    return;
  }
  if(size == 0){
    for(int i = 0; i < chvec.size(); ++i){
      std::cout<<chvec[i];
    }
    std::cout<<std::endl;
    return;
  }
  chvec.push_back(*str);
  combinationsOfStr(str+1, size - 1, chvec);
  chvec.pop_back();
  combinationsOfStr(str+1, size, chvec);
}

void combinationsOfStr(char * str, int len){
  if(str == NULL || len < 1){
    return ;
  }
  for(int i = 1; i <= len; ++i){
    std::vector<char> chvec;
    combinationsOfStr(str, i, chvec);
  }
}

int main(int argc, char ** argv){
  char str[] = "abc";
  int len = strlen(str);

  combinationsOfStr(str, len);

  system("pause");
  return 0;
}
#endif






