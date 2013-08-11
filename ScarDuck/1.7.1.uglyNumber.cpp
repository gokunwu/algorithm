
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：我们假设一个数组中已经有若干丑数，并且这些丑数是按顺序排列的，我们把现有的最
大丑数记为max，则下一个丑数肯定是前面丑数乘以2，3，5得到的。不妨考虑乘以2得到
的情况，我们把数组中的每一个数都乘以2，由于原数组是有序的，因为乘以2后也是有序
递增的，这样必然存在一个数M2，它前面的每一个数都是小于等于max，而包括M2在内
的后面的数都是大于max的，因为我们还是要保持递增顺序，所以我们取第一个大于max
的数M2。同理对于乘以3的情况，可以取第一个大于max的数M3，对于乘以5的情况，
可以取第一个大于max的数M5。
  最终下一个丑数取:min{M2,M3,M5}即可
*/
#include <cstdlib>
#include <iostream>

int minInThree(int a, int b, int c){
  a = a < b ? a:b;
  if(a < c) return a;
  else return c;
}

int uglyNumber(int n){
  if(n < 0) return -1;
  int * pUglyNumbers = new int[n];
  pUglyNumbers[0] = 1;
  int nextUglyNumber = 1;

  int * pUglyMulti2 = pUglyNumbers;
  int * pUglyMulti3 = pUglyNumbers;
  int * pUglyMulti5 = pUglyNumbers;

  while(nextUglyNumber < n){
    int min = minInThree(*pUglyMulti2*2, *pUglyMulti3*3, *pUglyMulti5*5);
    pUglyNumbers[nextUglyNumber] = min;
    while(*pUglyMulti2*2 <= pUglyNumbers[nextUglyNumber]){
      pUglyMulti2++;
    }
    while(*pUglyMulti3*3 <= pUglyNumbers[nextUglyNumber]){
      pUglyMulti3++;
    }
    while(*pUglyMulti5*5 <= pUglyNumbers[nextUglyNumber]){
      pUglyMulti5++;
    }
    nextUglyNumber++;
  }
  int uglyNum = pUglyNumbers[nextUglyNumber-1];
  delete [] pUglyNumbers;
  return uglyNum;
}

int main(int argc, char ** argv){
  int n = 1500;

  int uglyNum = uglyNumber(n);
  std::cout<<uglyNum<<std::endl;

  system("pause");
  return 0;
}
<<<<<<< HEAD

=======
>>>>>>> 6d1c46c0ef193a3097e12ed94a5132a83eca1c24
#endif
