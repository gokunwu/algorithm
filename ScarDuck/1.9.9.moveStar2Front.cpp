#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ���������ַ����е��ַ�'*'�Ƶ�����ǰ����
������2005��11�½�ɽ�����⡣�����������Ĵ�������
�������ַ����е��ַ�'*'�Ƶ�����ǰ���֣�
ǰ��ķ�'*'�ַ����ƣ������ܸı��'*'�ַ����Ⱥ�˳�򣬺������ش����ַ�'*'��������
��ԭʼ��Ϊ��ab**cd**e*12��
�����Ϊ*****abcde12������������ֵΪ5����Ҫ��ʹ�þ����ٵ�ʱ��͸����ռ䣩
*/
#include <cstdlib>
#include <iostream>

void exchange(char * str, int i, int j)
{
  if(str == NULL){
    return;
  }
  char tmp = str[i];
  str[i] = str[j];
  str[j] = tmp;
}

int moveStar2Front(char * str, int len)
{
  if(str == NULL){
    return 0;
  }
  int pchar = len - 2;
  //int pchar = 0;
  int cur = len - 2;
  while(cur >= 0){
    if(str[cur] != '*'){
      str[pchar] = str[cur];
      pchar--;
    }
    cur--;
  }
  int nstar = pchar+1;
  while(pchar >=0){
    str[pchar] = '*';
    pchar--;
  }
  return nstar;
}

int main(int argc, char ** argv)
{
  char str[] = "ab**cd**e*12";
  int len = sizeof(str)/sizeof(str[0]);
  std::cout<<len<<std::endl;
  int res = moveStar2Front(str, len);
  std::cout<<res<<std::endl;
  std::cout<<str<<std::endl;
  system("pause");
  return 0;
}
#endif
