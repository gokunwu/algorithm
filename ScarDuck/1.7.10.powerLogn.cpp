
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ��ʵ�ֺ���double Power(double base,int exponent)����base��exponent�η���
����ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
������
�����Ŀ�����¼�����Ҫע�⣺
1.  0��0�η���������ģ��Ƿ�����
2.  0�ĸ����η��൱��0��Ϊ������Ҳ��������ģ��Ƿ�����
3.  base�����0�����ָ��exponentС��0����������base��|exponent|�η���Ȼ����
����
4.  �κ�����0�η���Ϊ0
5.  �ж�double���͵�base�Ƿ����0����ʹ��==�š���Ϊ���������С��(����float
��double��С��)����������ֱ��ʹ�õȺ�(==)�ж�����С���Ƿ���ȡ������
�����Ĳ�ľ���ֵ��С����ô������Ϊ����double���͵�����ȡ�
*/
#include <cstdlib>
#include <iostream>

bool doubleEqual(double x, double y)
{
  if((x > y && x-y < 0.000001) || (x < y && x-y > -0.000001)){
    return true;
  }
  else{
    return false;
  }
}

double Power(double base, int exponent)
{
  if(doubleEqual(base, 0) && exponent <= 0){
    return -1.0;
  }
  if(exponent == 0){
    return 1.0;
  }
  bool negative = false;
  if(exponent < 0){
    negative = true;
    exponent = -exponent;
  }
  double res = 1.0*base;
  for(int i = 2; i <= exponent; i +=2){
    res *= res;
  }
  if(exponent % 2 == 1){
    res *= base;
  }
  if(negative == true){
    return 1/res;
  }
  else{
    return res;
  }
}

int main(int argc, char ** argv)
{
  double base = 2.0;
  int exponent = 5;

  double res = Power(base, exponent);
  std::cout<<res<<std::endl;

  system("pause");
  return 0;
}
#endif
