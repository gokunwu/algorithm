#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ������һ���������ϲ������ַ���A��B���ַ���A�ĺ󼸸��ֽں��ַ���B��ǰ�����ֽ��ص�
������abcde defghij -> abcdefghij
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

void mergeStr(char * str1, int len1, char * str2, int len2, char * res)
{
  if(str1 == NULL || len1 < 1 || str2 == NULL || len2 < 1){
    return;
  }
  int i = 0;
  int j = 0;
  int p2 = 0;
  while(i < len1){
    if(str1[i] != str2[0]){
      i++;
    }
    else{
      j = 0;
      while(i < len1 && j < len2 && str1[i] == str2[j]){
        i++;
        j++;
      }
      if(i == len1){//��ȫƥ��
        p2 = j;
      }
      else{
        //i++;
      }
    }
  }
  strncpy(res, str1, len1);
  strncpy(res+len1, str2+p2, len2-p2);
  res[len1+len2-p2] = '\0';
  std::cout<<p2<<std::endl;
}

int main(int argc, char ** argv)
{
  char str1[] = "abcdede";
  char str2[] = "defghij";
  int alen = strlen(str1);
  int blen = strlen(str2);
  char * res = new char[alen+blen+1];
  mergeStr(str1, alen, str2, blen, res);
  std::cout<<res<<std::endl;
  system("pause");
  return 0;
}
#endif
