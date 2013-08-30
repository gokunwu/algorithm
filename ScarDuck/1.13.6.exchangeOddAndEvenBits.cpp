#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：将一个数中的偶数位bit和奇数位bit交换
如：21(010101) 变为 42(101010)
分析：
用0xaaaaaaaa提取出偶数位,右移一位
用0x55555555提取出奇数位,左移一位
将上诉两个操作的结果进行位或操作
*/
#include <cstdlib>
#include <iostream>

int exchangeOddAndEvenBits(int num)
{
  if(num < 0){
    return -1;
  }
  return (0xaaaaaaaa&num)>>1 | (0x55555555&num)<<1;
}

int main(int argc, char ** argv)
{
  int num = 21;
  int ret = exchangeOddAndEvenBits(num);
  std::cout<<ret<<std::endl;

  system("pause");
  return 0;
}
#endif
