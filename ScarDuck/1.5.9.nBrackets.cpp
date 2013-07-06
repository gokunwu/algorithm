
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
  std::vector<std::string> strvec;
  if(n == 1){
    strvec.push_back("()");
    return strvec;
  }
  std::vector<std::string> strvec_tmp = nBrackets(n-1);
  for(int i = 0; i < strvec_tmp.size(); i++){
    strvec.push_back(strvec_tmp[i] + "()");
    strvec.push_back("(" + strvec_tmp[i] + ")");
    if("()" + strvec_tmp[i] != strvec_tmp[i] + "()"){
      strvec.push_back("()" + strvec_tmp[i]);
    }
  }
  return strvec;
}

int main(int argc, char ** argv){
  int n = 4;
  std::vector<std::string> strvec = nBrackets(n);
  std::cout<<strvec.size()<<std::endl;
  for(int i = 0; i < strvec.size(); ++i){
    std::cout<<strvec[i]<<std::endl;
  }

  system("pause");
  return 0;
}
#endif

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
#include <string>
#include <vector>

void printBracket(std::vector<std::string> & vec){
  for(std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it){
    std::cout<<*it<<" ";
  }
  std::cout<<std::endl;
}

void nBrackets(int nsize, int nlen, std::vector<std::string> & vec){
  int leftBracket = 0;
  int rightBracket = 0;
  for(int i = 0; i < vec.size(); ++i){
    if(vec[i] == "("){
      leftBracket++;
    }
    if(vec[i] == ")"){
      rightBracket++;
    }
    if(leftBracket < rightBracket){
      return;
    }
    if(leftBracket + rightBracket == nsize && leftBracket == rightBracket){
      printBracket(vec);
    }
  }
  if(nlen > 0){
    vec.push_back("(");
    nBrackets(nsize, nlen -1, vec);
    vec.pop_back();
    vec.push_back(")");
    nBrackets(nsize, nlen - 1, vec);
    vec.pop_back();
  }

}

int main(int argc, char ** argv){
  int n = 4;

  std::vector<std::string> vec;

  nBrackets(2*n, 2*n, vec);

  system("pause");
  return 0;
}
#endif


















