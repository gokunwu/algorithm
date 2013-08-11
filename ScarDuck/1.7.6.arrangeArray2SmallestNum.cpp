
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入一个正整数数组，将它们连接起来排成一个数，输出能排出的所有数字中最小的一个。例如输入数组{32,  321}，则输出这两个能排成的最小数字32132。请给出解决问题的算法，并证明该算法。
分析：
这道题其实是希望我们能找到一个排序规则，根据这个规则排出来的数组能排成一个最小的数字。要确定排序规则，就得比较两个数字，也就是给出两个数字m和n，我们需要确定一个规则m和n哪个更大，而不是仅仅只是比较这两个数字的数值哪个更大。
根据题目的要求，两个数字m和n排成的数字mn和nm，如果mn<nm，那么我们应该输出mn，也就是m应该排在n的前面，也就是m小于n；反之，如果nm<mn，n小于m。如果mn==mn，m等于n。
接下来我们考虑怎么去拼接数字，即给出数字m和n，怎么得到数字mn和nm并比较它们的大小。直接用数值去计算不难办到，但需要考虑到的一个潜在问题是m和n都在int能表达的范围内，但把它们拼起来的数字mn和nm就不一定能用int表示了。所以我们需要解决大数问题。一个非常直观的方法就是把数字转换成字符串。
另外，由于把数字m和n拼接起来得到的mn和nm，它们所含有的数字的个数肯定是相同的。因此比较它们的大小只需要按照字符串大小的比较规则就可以了。
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define MAXNUMLEN 10

char * g_strCombine1 = new char[MAXNUMLEN*2 + 1];
char * g_strCombine2 = new char[MAXNUMLEN*2 + 1];

int compare(const void * strnum1, const void * strnum2){
  strcpy(g_strCombine1, *(const char **)strnum1);
  strcat(g_strCombine1, *(const char **)strnum2);

  strcpy(g_strCombine2, *(const char **)strnum2);
  strcat(g_strCombine2, *(const char **)strnum1);

  return strcmp(g_strCombine1, g_strCombine2);
}

int arrangeArr2Smallest(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return -1;
  }
  char ** ppStrNumbers = (char **)(new int[len]);
  for(int i = 0; i < len; ++i){
    ppStrNumbers[i] = new char[MAXNUMLEN + 1];
    sprintf(ppStrNumbers[i], "%d", arr[i]);
  }
  qsort(ppStrNumbers, len, sizeof(char *), compare);
  for(int i = 0; i < len; ++i){
    printf("%s",ppStrNumbers[i]);
  }
  printf("\n");
  for(int i = 0; i < len; ++i){
    delete []ppStrNumbers[i];
  }
  delete []ppStrNumbers;
}

int main(int argc, char ** argv)
{
  int arr[] = {32, 321};
  int len = sizeof(arr)/sizeof(arr[0]);

  arrangeArr2Smallest(arr, len);

  system("pause");
  return 0;
}

#endif

