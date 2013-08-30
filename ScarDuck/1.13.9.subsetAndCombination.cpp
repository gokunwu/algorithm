#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ:�����Ӽ�����ת��Ϊ������⡣
���������輯���а���N��Ԫ�أ�  �Ӽ�����  =   C(N, 0) + C(N, 1) + ... + C(N, N-1) + C(N, N)��������һ���Ӽ��ϣ�������һ��NԪ���ʾ����  <S1, S2, ... Sn-1, Sn>, ����Siȡֵ��ΧΪ
(0, 1)��0��ʾ�����Ӽ��ϲ�������Ԫ�أ�1��ʾ���Ӽ��ϰ�����Ԫ�ء���ˣ����Ӽ��Ͼ�ת������
������ʾ������ϵ��㷨���Ӽ�����  = 2^n��
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

void subset(char * str, int * marks, int pos, int len)
{
  if(str == NULL || marks == NULL || len < 1){
    return;
  }
  if(pos >= len){
    int allzero = 0;
    for(int i = 0; i < len; ++i){
      if(marks[i] == 1){
        std::cout<<str[i];
        allzero = 1;
      }
    }
    if(allzero == 0){
      std::cout<<"@"<<std::endl;
    }
    else{
      std::cout<<std::endl;
    }
    return;
  }
  marks[pos] = 1;
  subset(str, marks, pos+1, len);
  marks[pos] = 0;
  subset(str, marks, pos+1, len);
}

int main(int argc, char ** argv)
{
  char str[] = "abcd";
  int len = strlen(str);
  int * marks = new int[len];
  subset(str, marks, 0, len);
  delete [] marks;
  marks = NULL;
  system("pause");
  return 0;
}
#endif
