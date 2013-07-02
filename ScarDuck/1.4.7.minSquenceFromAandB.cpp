#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：通过交换a,b中的元素，使[序列a元素的和]与[序列b元素的和]之间的差最小
*/
#include <cstdlib>
#include <iostream>
#include <cmath>
#define MAX_VALUE 1000;

int sum(int * a, int alen){
  if(a == NULL || alen < 1) return -1;
  int sum = 0;
  for(int i = 0; i < alen; ++i){
    sum += a[i];
  }
  return sum;
}

void minSquenceDiff(int * a, int alen, int *b, int blen){
  if(a == NULL || b == NULL || alen < 1 || blen < 1)  return;
  int suma = sum(a, alen);
  int sumb = sum(b, blen);
  if(suma == sumb)  return;
  int * big =a;
  int biglen = alen;
  int * small = b;
  int smalllen = blen;
  if(suma < sumb){
    big = b;
    biglen = blen;
    small = a;
    smalllen = alen;
  }

  bool shift = true;
  int globalDiff = 1;
  while(shift == true && globalDiff > 0){
    shift = false;
    if(sum(big, biglen) < sum(small, smalllen)){
      int *tmp = big;
      int tmplen = biglen;
      big = small;
      biglen = smalllen;
      small = tmp;
      smalllen = tmplen;
    }
    globalDiff = sum(big, biglen) - sum(small, smalllen);
    int partDiff = MAX_VALUE;
    if(globalDiff < 0)  return;
    int pbig = -1;
    int psmall= -1;
    for(int i = 0; i < biglen; ++i){
      for(int j = 0; j < smalllen; ++j){
        int newdiff = abs(globalDiff - 2*(big[i] - small[j]));
        if(newdiff < partDiff && newdiff < globalDiff){
          partDiff = newdiff;
          shift = true;
          pbig = i;
          psmall = j;
        }
      }
    }
    if(shift == true){
      int tmp = big[pbig];
      big[pbig] = small[psmall];
      small[psmall] = tmp;
    }
  }
}

int main(int argc, char ** argv){
  int a[] = {100,99,98,1,2, 3};
  int b[] = {1, 2, 3, 4,5,40};
  int alen = sizeof(a)/sizeof(int);
  int blen = sizeof(b)/sizeof(int);

  minSquenceDiff(a, alen, b, blen);

  for(int i = 0; i < alen; ++i){
    std::cout<<a[i]<<" ";
  }
  std::cout<<std::endl;
  for(int i = 0; i < blen; ++i){
    std::cout<<b[i]<<" ";
  }
  std::cout<<std::endl;

  system("pause");
  return 0;
}
#endif
