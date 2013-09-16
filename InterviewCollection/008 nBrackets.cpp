#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：N对括号可以有多少种匹配排列方式？比如两对括号可以有两种：（）（）和（（））
主要思想是递归
卡特兰数：通项公式 h(n)=c(n,2n)-c(n-1,2n)
          h(n)= h(0)*h(n-1) + h(1)*h(n-2) + ... + h(n-1)h(0) (其中n>=2)
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> nBrackets(int n){
  std::vector<std::string> vec1;
  if(n == 1){
    vec1.push_back("()");
    return vec1;
  }
  std::vector<std::string> vec = nBrackets(n-1);
  for(int i = 0; i < vec.size(); ++i){
    vec1.push_back("("+vec[i]+")");
    vec1.push_back("()" + vec[i]);
    if("()"+vec[i] != vec[i]+"()"){
      vec1.push_back(vec[i]+"()");
    }
  }
  return vec1;
}

int main(int argc, char ** argv){
  int n = 4;

  std::vector<std::string> vec;
  vec = nBrackets(n);

  std::cout<<vec.size()<<std::endl;
  for(int i = 0; i < vec.size();++i){
    std::cout<<vec[i]<<std::endl;
  }

  system("pause");
  return 0;

}
#endif
