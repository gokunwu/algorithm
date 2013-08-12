
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ�����Ǽ���һ���������Ѿ������ɳ�����������Щ�����ǰ�˳�����еģ����ǰ����е���
�������Ϊmax������һ�������϶���ǰ���������2��3��5�õ��ġ��������ǳ���2�õ�
����������ǰ������е�ÿһ����������2������ԭ����������ģ���Ϊ����2��Ҳ������
�����ģ�������Ȼ����һ����M2����ǰ���ÿһ��������С�ڵ���max��������M2����
�ĺ���������Ǵ���max�ģ���Ϊ���ǻ���Ҫ���ֵ���˳����������ȡ��һ������max
����M2��ͬ����ڳ���3�����������ȡ��һ������max����M3�����ڳ���5�������
����ȡ��һ������max����M5��
  ������һ������ȡ:min{M2,M3,M5}����
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
