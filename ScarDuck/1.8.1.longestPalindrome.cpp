#if 0
/*
copyright@nciaebupt ת����ע������
���⣺
����һ���ַ������ҳ����ַ����жԳƵ����ַ�������󳤶ȡ�
��ν�Գ����ַ���������������ַ���Ҫô��������һ���ʶԳƣ����� "aba"�� "abcba"��
Ҫô����ȫ�Գƣ�����"abba", "abccba"��
���ȣ��������ַ�����  char[] array ����������ַ��������������Ѿ���������  i  ���ַ���
Ҫ�ҳ��Ը��ַ�Ϊ�D���ġ�����Գ��ַ�����������Ҫ��������ָ��ֱ���ǰ������ƶ���
ֱ��ָ�뵽���ַ������˻�������ָ����ָ���ַ�����ȡ�
ʱ�临�Ӷ�O(n2)
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

int longestPalindromeMiddle(char * str, int cur, int len)
{
  if(str == NULL || cur >= len){
    return -1;
  }
  int gap = 1;
  int length = 1;
  while((cur - gap > 0) && (cur + gap < len) && (str[cur-gap] == str[cur+gap])){
    length += 2;
    gap++;
  }
  return length;
}

int longestPalindromeMirror(char * str, int cur, int len)
{
  if(str == NULL || cur >= len){
    return -1;
  }
  int gap = 0;
  int length = 0;
  while((cur-gap > 0) && (cur + gap + 1 < len) && str[cur-gap] == str[cur+gap+1]){
    length += 2;
    gap++;
  }
  return length;
}

int longestPalindrome(char * str, int len)
{
  if(str == NULL || len < 1){
    return -1;
  }
  int maxlength = 0;
  for(int i = 0; i < len; ++i){
    int length1 = longestPalindromeMiddle(str, i, len);
    int length2 = longestPalindromeMirror(str, i, len);
    int curlength = length1 > length2 ? length1:length2;
    if(maxlength < curlength){
      maxlength = curlength;
    }
  }
  return maxlength;
}

int main(int argc, char ** argv)
{
  char str[] = "abcba";
  int len = strlen(str);

  int res = longestPalindrome(str, len);
  std::cout<<res<<std::endl;

  system("pause");
  return 0;
}
#endif
