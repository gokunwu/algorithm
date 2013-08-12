#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ����֪һ���ַ���������asderwsde,Ѱ�����е�һ�����ַ�������sde�ĸ��������û�з���0���еĻ��������ַ����ĸ���
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

int substrCntInStr(const char * str, const char * substr)
{
  if(str == NULL){
    return 0;
  }
  if(substr == NULL){
    return 0;
  }
  const char * pstr = str;
  int sublen = strlen(substr);
  int cnt = 0;
  while((pstr = strstr(pstr, substr)) != NULL){
    pstr = pstr + sublen;
    cnt++;
  }
  return cnt;
}

int matchsubstr(const char * str, const char * substr, int pstr){
  if(str == NULL || substr == NULL){
    return 0;
  }
  int i = 0;
  while(substr[i] != '\0' && str[i+pstr] != '\0'){
    if(substr[i] == str[i+pstr]){
      i++;
    }
    else{
      return 0;
    }
  }
  if(substr[i] == '\0'){
    return 1;
  }
}

int substrCntInStr1(const char * str, const char * substr)
{
  if(str == NULL){
    return 0;
  }
  if(substr == NULL){
    return 0;
  }
  int cnt = 0;
  int pstr = 0;
  int psubstr = 0;
  int strLen = strlen(str);
  int substrlen = strlen(substr);
  while(pstr < strLen - substrlen){
    while(str[pstr] != substr[psubstr]){
      pstr++;
    }
    if(pstr > strLen-substrlen){
      return 0;
    }
    else{
      if(matchsubstr(str, substr, pstr) != 0){
        cnt++;
        pstr++;
      }
      else{
        pstr++;
      }
    }
  }
  return cnt;
}

int main(int argc, char ** argv)
{
  char str[] = "asderwsde";
  char substr[] = "sde";

  int cnt = substrCntInStr1(str, substr);
  std::cout<<cnt<<std::endl;

  system("pause");
  return 0;
}
#endif
