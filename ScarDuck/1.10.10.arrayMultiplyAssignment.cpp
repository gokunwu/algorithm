#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：2012年4月67日的腾讯暑期实习生招聘笔试中，出了一道与上述21题类似的题，原题大
致如下：
     两个数组a[N]，b[N]，其中A[N]的各个元素值已知，现给b[i]赋值，b[i] =
a[0]*a[1]*a[2]...*a[N-1]/a[i]；
要求：
1.不准用除法运算
2.除了循环计数值，a[N],b[N]外，不准再用其他任何变量（包括局部变量，全局变量等）
3.满足时间复杂度O（n），空间复杂度O（1）。
      说白了，你要我求b=a[0]*a*...a[i-1]*a*a[i+1]..*a[N-1]/a ，就是求：
a[0]*a[1]*...a[i-1]*a[i+1]..*a[N-1]。只是我把a[i]左边部分标示为left[i]，b[i]右边部分标示为
right[i]，而实际上完全不申请left[i]，与right[i]变量，之所以那样标示，无非就是为了说明：除掉当前元素a[i]，其他所有元素(a[i]左边部分，和a[i]右边部分)的积。
*/
#include <cstdlib>
#include <iostream>

void specialMultiply(int * a, int * b, int len)
{
  if(a == NULL || len < 1){
    return;
  }
  b[0] = 1;
  for(int i = 1; i < len; ++i){
    b[0] = b[0]*a[i-1];
    b[i] = b[0];
  }
  b[0] = 1;
  for(int i = len-2; i > 0; --i){
    b[0] = b[0]*a[i+1];
    b[i] = b[i]*b[0];
  }
  b[0] = b[0]*a[1];
}

int main(int argc, char ** argv)
{
  int a[] = {2,3,4,5,6};
  int alen = sizeof(a)/sizeof(int);
  int * b = new int[alen];
  specialMultiply(a, b, alen);
  for(int i = 0; i < alen; ++i){
    std::cout<<b[i]<<std::endl;
  }
  system("pause");
  return 0;
}
#endif
