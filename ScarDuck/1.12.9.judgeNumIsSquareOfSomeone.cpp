#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ���ж�һ����Ȼ���Ƿ���ĳ������ƽ��
������1+3+5+7+��+(2n-1)=n^2��ȫƽ����������һ������
������д��һ����������ƽ��
*/
#include <cstdlib>

#include <iostream>

int isSquareOfSomeone(int num)
{
  if(num < 0){
    return -1;
  }
  long tmp = 0;
  for(int i = 1; i < num; ++i){
    tmp = tmp + 2*i - 1;
    if(tmp == num){
      return i;
    }
    if(tmp > num){
      return -1;
    }
  }
}

int main(int argc, char ** argv)
{
  int num = 35;
  int ret = isSquareOfSomeone(num);
  if(ret == -1){
    std::cout<<"no"<<std::endl;
  }
  else{
    std::cout<<ret<<std::endl;
  }
  system("pause");
  return 0;
}
#endif
