
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:整数的素数和分解
歌德巴赫猜想说任何一个不小于6的偶数都可以分解为两个奇素数之和。对此问题扩展，如
果一个整数能够表示成两个或多个素数之和，则得到一个素数和分解式。对于一个给定的整
数，输出所有这种素数和分解式。注意，对于同构的分解只输出一次（比如5只有一个分解
2 + 3，而3 + 2是2 + 3的同构分解式）。
例如，对于整数8，可以作为如下三种分解：
(1) 8 = 2 + 2 + 2 + 2
(2) 8 = 2 + 3 + 3
(3) 8 = 3 + 5
分析：由于要将指定整数N分解为素数之和，则首先需要计算出该整数N内的所有素数，然后递
归求解所有素数和分解即可。
*/
#include <cstdlib>
#include <iostream>
#include <vector>

void genPrimes(int n, std::vector<int> & primes)
{
  if(n < 2){
    return;
  }
  primes.push_back(2);
  for(int i = 3; i < n; i+=2){
    int flag = 0;
    for(int j = 3; j*j <= i; j++){
      if(i%j == 0){
        flag = 1;
      }
    }
    if(flag == 0){
      primes.push_back(i);
      //std::cout<<i<<std::endl;
    }
  }
}

int primesDecomposition(int n, std::vector<int> & numbers, int from, std::vector<int> & primes)
{
  if(n < 0){
    return 1;
  }
  if(n == 0){
    for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
      std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    return 0;
  }
  int cnt = 0;
  for(int i = from; i < primes.size(); ++i){
    if(n < primes[i]){
      break;
    }
    numbers.push_back(primes[i]);
    primesDecomposition(n-primes[i], numbers, i, primes);
    numbers.pop_back();
  }
  return cnt;
}

int primesDecomposition(int n)
{
  if(n < 3){
    return -1;
  }
  std::vector<int> primes;
  genPrimes(n, primes);
  std::vector<int> numbers;
  int from = 0;
  primesDecomposition(n, numbers, from, primes);
}

int main(int argc, char ** argv)
{
  int n = 8;
  primesDecomposition(n);

  system("pause");
  return 0;
}
#endif
