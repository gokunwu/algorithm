#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：
定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部。
如把字符串abcdef左旋转2位得到字符串cdefab。
请实现字符串左旋转的函数，要求对长度为n的字符串操作的时间复杂度为O(n)，
空间复杂度为O(1)。
*/
#include <cstdlib>
#include <iostream>
#include <cstring>

void reverse(char * str, int begin, int end){
  if(str == NULL) return;
  while(begin < end){
    char tmp = str[begin];
    str[begin] = str[end];
    str[end] = tmp;
    begin++;
    end--;
  }
}

void stringLeftRotation(char * str, int n, int k){
  if(str == NULL) return;
  reverse(str, 0, k-1);
  reverse(str, k, n-1);
  reverse(str, 0, n-1);
}

int main(int argc, char ** argv){
  char str[] = "abcdef";
  int len = strlen(str);
  int k = 2;

  stringLeftRotation(str, len, k);

  for(int i = 0; i < len +1; ++i){
    std::cout<<str[i];
  }
  std::cout<<std::endl;

  system("pause");
  return 0;
}
#endif
