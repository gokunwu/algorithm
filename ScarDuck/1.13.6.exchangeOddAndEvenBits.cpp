#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ����һ�����е�ż��λbit������λbit����
�磺21(010101) ��Ϊ 42(101010)
������
��0xaaaaaaaa��ȡ��ż��λ,����һλ
��0x55555555��ȡ������λ,����һλ
���������������Ľ������λ�����
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
