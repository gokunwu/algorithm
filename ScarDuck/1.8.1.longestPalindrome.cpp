#if 0
/*
copyright@nciaebupt 转载请注明出处
问题：
给你一个字符串，找出该字符串中对称的子字符串的最大长度。
所谓对称子字符串，就是这个子字符串要么是以其中一个词对称：比如 "aba"， "abcba"；
要么就完全对称：比如"abba", "abccba"。
首先，我们用字符数组  char[] array 来保持这个字符串，假设现在已经遍历到第  i  个字符，
要找出以该字符为―中心‖的最长对称字符串，我们需要用另两个指针分别向前和向后移动，
直到指针到达字符串两端或者两个指针所指的字符不相等。
时间复杂度O(n2)
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
