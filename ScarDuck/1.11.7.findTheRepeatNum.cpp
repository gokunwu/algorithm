#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:数组a[N]，1至N-1这N-1个数存放在a[N]中，其中某个数重复一次。写一个函数，找出被
重复的数字。
分析：a[n]求和 减去 sum(1,n-1)
也可以使用位图法
*/
#include <cstdlib>
#include <iostream>

int findTheRepeatNum(int * a, int len, int n)
{
  if(a == NULL || len < 1){
    return -1;
  }
  int sum = 0;
  for(int i = 0; i < len; ++i){
    sum = sum + a[i];
  }
  int subsum = n*(1 + n)/2;
  return sum - subsum;
}

int main(int argc, char ** argv)
{
  int a[] = {1,2,3,4,5,6,6,7,8,9};
  int len = sizeof(a)/sizeof(int);
  int res = findTheRepeatNum(a, len, 9);
  std::cout<<res<<std::endl;
  system("pause");
  return 0;
}
#endif
