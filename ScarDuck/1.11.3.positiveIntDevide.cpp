#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ�����ʵ�������������ĳ����������ó�����������
������ʹ��ѭ��������ʵ�ֳ���
*/
#include <cstdlib>
#include <iostream>

void positiveIntDevide(int a, int b, int & res, int & rev)
{
  if(a < 1 || b < 1){
    return;
  }
  if(a < b){
    res = 0;
    rev = a;
  }
  else if( a == b){
    res = 1;
    rev = 0;
  }
  else{
    res = 0;
    rev = 0;
    while(a > b){
      a = a-b;
      res++;
    }
    rev = a;
  }
}

int main(int argc, char ** argv)
{
  int a = 102;
  int b = 10;
  int res = 0;
  int rev = 0;
  positiveIntDevide(a, b, res, rev);
  std::cout<<res<<std::endl;
  std::cout<<rev<<std::endl;
  system("pause");
  return 0;
}
#endif
