
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ������һ�����������飬���������������ų�һ������������ų���������������С��һ����������������{32,  321}����������������ųɵ���С����32132����������������㷨����֤�����㷨��
������
�������ʵ��ϣ���������ҵ�һ��������򣬸�����������ų������������ų�һ����С�����֡�Ҫȷ��������򣬾͵ñȽ��������֣�Ҳ���Ǹ�����������m��n��������Ҫȷ��һ������m��n�ĸ����󣬶����ǽ���ֻ�ǱȽ����������ֵ���ֵ�ĸ�����
������Ŀ��Ҫ����������m��n�ųɵ�����mn��nm�����mn<nm����ô����Ӧ�����mn��Ҳ����mӦ������n��ǰ�棬Ҳ����mС��n����֮�����nm<mn��nС��m�����mn==mn��m����n��
���������ǿ�����ôȥƴ�����֣�����������m��n����ô�õ�����mn��nm���Ƚ����ǵĴ�С��ֱ������ֵȥ���㲻�Ѱ쵽������Ҫ���ǵ���һ��Ǳ��������m��n����int�ܱ��ķ�Χ�ڣ���������ƴ����������mn��nm�Ͳ�һ������int��ʾ�ˡ�����������Ҫ����������⡣һ���ǳ�ֱ�۵ķ������ǰ�����ת�����ַ�����
���⣬���ڰ�����m��nƴ�������õ���mn��nm�����������е����ֵĸ����϶�����ͬ�ġ���˱Ƚ����ǵĴ�Сֻ��Ҫ�����ַ�����С�ıȽϹ���Ϳ����ˡ�
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

