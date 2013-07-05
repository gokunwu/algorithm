#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入两个整数  n 和  m，从数列1，2，3.......n 中  随意取几个数,
使其和等于  m ,要求将其中所有的可能组合列出来.
e.g
n=6,m=6   1,2,3    2,4    1,5
*/
#include <cstdlib>
#include <iostream>
#include <vector>

int vecsum(std::vector<int> & ivec){
  int sum = 0;
  for(int i= 0; i < ivec.size(); ++i){
    sum += ivec[i];
  }
  return sum;
}

void combineOfN(int n, int sum, std::vector<int> & ivec){
  if(n < 1 || sum < 1)  return;
  if(n > sum){
    combineOfN(sum, sum, ivec);
  }
  else{
    if(sum == n){
      ivec.push_back(n);
      for(int i= 0; i < ivec.size(); ++i){
        std::cout<<ivec[i]<<" ";
      }
      std::cout<<std::endl;
      ivec.pop_back();
    }
    ivec.push_back(n);
    combineOfN(n-1, sum-n, ivec);
    ivec.pop_back();
    combineOfN(n-1, sum, ivec);
  }

}

void combineOfN(int n, int m){
  if(n < 0 || m < 0)  return ;
  std::vector<int> ivec;
  combineOfN(n, m, ivec);
}

int main(int argc, char ** argv){
  int n = 6;
  int m = 6;

  combineOfN(n, m);

  system("pause");
  return 0;
}

#endif
