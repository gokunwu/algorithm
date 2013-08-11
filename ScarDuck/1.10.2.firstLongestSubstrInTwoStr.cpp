
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：求两个串中的第一个最长子串（神州数码以前试题）。如"abractyeyt","dgdsaeactyey"的最大子串为"actyey"
算法的基本思想：利用矩阵对角原理来实现
当字符匹配的时候，不是简单的给相应元素赋上1，而是赋上其左上角元素的值加一。
我们用两个标记变量来标记矩阵中值最大的元素的位置，在矩阵生成的过程中来判断
当前生成的元素的值是不是最大的，据此来改变标记变量的值，那么到矩阵完成的时
候，最长匹配子串的位置和长度就已经出来了。
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

int findLongestCommonSubstr(char * str1, char * str2, char * res)
{
  if(str1 == NULL || str2 == NULL){
    return -1;
  }
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  if(len1 < len2){//使str1始终指向最长的字符串，str2始终指向短字符串
    char * tmp = str1;
    str1 = str2;
    str2 = tmp;
    len1 = strlen(str1);
    len2 = strlen(str2);
  }
  int * record = new int[len1];
  for(int i = 0; i < len1; ++i){
    record[i] = 0;
  }
  int maxlen = 0;
  int end = 0;
  for(int i = 0; i < len2; ++i){
    for(int j = len1-1; j >= 0; --j){
      if(str1[j] == str2[i]){
        if(i == 0 || j == 0){//如果母串为第一个字符，或者子串只有一个元素
          record[j] = 1;
        }
        else{
          record[j] = record[j-1] + 1;
        }
      }
      else{
        record[j] = 0;
      }
      if(record[j] > maxlen){
        maxlen = record[j];
        end = j;
      }
    }
  }
  int start = end - maxlen + 1;
  for(int i = 0; i < maxlen; ++i){
    res[i] = str1[i+start];
  }
  res[maxlen] = '\0';
  return maxlen;
}

int findLongestCommonSubstr1(char * str1, char * str2, char * res)
{
  if(str1 == NULL || str2 == NULL){
    return -1;
  }
  int start = 0;
  int maxlen = 0;
  int pos = 0;
  for(int i = 0; i < strlen(str1); ++i){
    for(int j = 0; j < strlen(str2); ++j){
      for(int k = 0;str1[i+k] && str2[j+k] && str1[i+k]==str2[j+k];++k){
        if(k > maxlen){
          pos = i;
          maxlen = k +1;
        }
      }
    }
  }

  for(int i = 0; i < maxlen; ++i){
    res[i] = str1[i+pos];
  }
  res[maxlen] = '\0';
  return maxlen;
}

int main(int argc, char ** argv)
{
  char str1[] = "abractyeyt";
  char str2[] = "dgdsaeactyey";
  char res[1000];
  int cnt = findLongestCommonSubstr1(str1, str2, res);
  std::cout<<cnt<<std::endl;
  std::cout<<res<<std::endl;

  system("pause");
  return 0;
}

#endif
