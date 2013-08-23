#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ��strstr��strncmpԴ��ʵ��
strstr
����: �ҳ�s2�ַ�����s1�ַ����е�һ�γ��ֵ�λ�ã�������s2�Ĵ���������
���ؽ��:���ظ�λ�õ�ָ�룬���Ҳ��������ؿ�ָ�롣

strncmp
����:  �Ƚ��ַ���s1��s2��ǰn���ַ�.
���ؽ��:���ǰn�ֽ���ȫ��ȣ�����ֵ��=0����ǰn�ֽڱȽϹ����У��������s1[n]��
s2[n]���ȣ��򷵻�(s1[n]-s2[n])
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

char * _strstr(const char * s1, const char * s2)
{
  if(s2 == NULL){
    return (char *)s1;
  }
  int len2 = strlen(s2);
  for(; *s1!= '\0'; s1++){
    if(*s1 == *s2 && strncmp(s1, s2, len2) == 0){
      return (char *)s1;
    }
  }
  return NULL;
}

int _strncmp(const char * s1, const char * s2, unsigned int n)
{
  if(!n){
    return 0;
  }
  while(--n && *s1 && *s1 == *s2){
    s1++;
    s2++;
  }
  return *s1-*s2;
}

int main(int argc, char ** argv)
{
  char str1[] = "abcdef";
  char str2[] = "cde";
  char * p = _strstr(str1, str2);
  std::cout<<p<<std::endl;

  char s1[] = "abc";
  char s2[] = "adcd";
  int flag = _strncmp(s1, s2, 2);
  std::cout<<flag<<std::endl;

  system("pause");
  return 0;
}
#endif
