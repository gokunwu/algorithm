#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ������һ���ַ�������ӡ�����ַ������ַ����������С����������ַ���abc����������ַ�a��b��c�������г����������ַ���abc��acb��bac��bca��cab��cba��
���������Ǹ��ݹ��������⡣�ݹ��㷨���ĸ����ԣ���1)�����пɴﵽ����ֹ�������������������ѭ������2���������ڹ�ģ�ϱ�ԭ����С����3���������ͨ���ٴεݹ������⣻��4��������Ľ�Ӧ����ϳ���������Ľ⡣
�����ַ������������⡣���������
n-1��Ԫ�ص�ȫ���У���������n��Ԫ�ص�ȫ���С�����ֻ��1��Ԫ�صļ��ϣ�����ֱ������ȫ���С�ȫ���еĵݹ���ֹ��������ȷ��ֻ��1��Ԫ��ʱ��
*/
#include <cstring>
#include <cstdlib>
#include <iostream>

void exchange(char * str, int i, int j){
  if(str == NULL){
    return;
  }
  char tmp = str[i];
  str[i] = str[j];
  str[j] = tmp;
}

void permutationsOfString(char * str, int begin, int end)
{
  if(str == NULL || begin > end){
    return;
  }
  if(begin == end){
    std::cout<<str<<std::endl;
  }
  else{
    for(int i = begin; i <= end; ++i){
      exchange(str, begin, i);
      permutationsOfString(str, begin + 1, end);
      exchange(str, begin, i);
    }
  }
}

int main(int argc, char ** argv)
{
  char str[]="abc";
  int len = strlen(str);

  permutationsOfString(str, 0, len -1);

  system("pause");
  return 0;
}
#endif


#if 0
/*
copyright@nciaebupt ת����ע������
���⣺����һ���ַ�����������ַ������ַ���������ϡ��ٸ����ӣ��������abc�����������a��b��c��ab��ac��bc��abc��
�������õݹ���⡣���Կ����󳤶�Ϊn���ַ�����m���ַ�����ϣ���ΪC(n,m)��ԭ����Ľ⼴ΪC(n, 1), C(n, 2),...C(n, n)���ܺ͡�
������C(n,m)���ӵ�һ���ַ���ʼɨ�裬ÿ���ַ������������Ҫô��ѡ�У�Ҫô����ѡ�У������ѡ�У��ݹ����C(n-1, m-1)�����δ��ѡ�У��ݹ����C(n-1, m)���������ַ�ʽ��n��ֵ������٣��ݹ����ֹ����n=0��m=0��
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

void combinationsOfStr(char * str, int size, std::vector<char> & chvec){
  if(str == NULL || (size != 0 && *str == '\0')){
    return;
  }
  if(size == 0){
    for(int i = 0; i < chvec.size(); ++i){
      std::cout<<chvec[i];
    }
    std::cout<<std::endl;
    return;
  }
  chvec.push_back(*str);
  combinationsOfStr(str+1, size - 1, chvec);
  chvec.pop_back();
  combinationsOfStr(str+1, size, chvec);
}

void combinationsOfStr(char * str, int len){
  if(str == NULL || len < 1){
    return ;
  }
  for(int i = 1; i <= len; ++i){
    std::vector<char> chvec;
    combinationsOfStr(str, i, chvec);
  }
}

int main(int argc, char ** argv){
  char str[] = "abc";
  int len = strlen(str);

  combinationsOfStr(str, len);

  system("pause");
  return 0;
}
#endif






