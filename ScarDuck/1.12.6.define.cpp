#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ�����Ƕ���һ�����ƺ����ĺ꣬������Ľ������ʾ���ں�С�ڡ�Ϊ�˼�������Ǽ���a,b
Ϊ���͡�����ʹ��> <��
*/
#include <cstdlib>
#include <cmath>
#include <iostream>

#define compare(a, b) (abs(a-b) == (a-b) ? 1:-1) == -1 ? -1:((a-b) == 0 ? 0:1)

int main(int argc, char ** argv)
{
  int a = 3;
  int b = 3;
  int ret = compare(a,b);
  std::cout<<ret<<std::endl;

  system("pause");
  return 0;
}
#endif
