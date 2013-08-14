#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ������������ɵ��������ҵ����ȴ���=3����ĵȲ�����
������������Ȳ����У�1 6 4 8 9 5 9 1 7 7
��Ȳ����У�����Ϊ6����4 5 6 7 8 9
������
��delta[i][j] (0<= i < j <= n-1) Ϊ��a[i], a[j]��β����Ȳ����еĲ���������delta[i][j] = a[j] - a[i];
��s[i][j] (0 <= i < j <= n-1)Ϊ��a[i], a[j]��β����Ȳ����еĳ��ȡ���ʼ����s[0][1] = 2; ��
���delta[i][j] = delta[x][i] (0 <= x < i - 1), s[i][j] = s[x][i] + 1; ����s[i][j] = 2;
max{s[i][j]} (0 <= i < j <= n - 1) ��Ϊ�������Ȳ����еĳ���

*/
#include <cstdlib>
#include <iostream>

int compare(const void * a, const void * b)
{
  return *(int *)a - *(int *)b;
}

int longestArithmeticSquence(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return -1;
  }
  int **delta = new int*[len];
  for(int i = 0; i < len; ++i){
    delta[i] = new int[len];
  }
  int **s = new int*[len];
  for(int i = 0; i < len; ++i){
    s[i] = new int[len];
  }
  int index = 0;
  int maxdelta = 0;
  int maxlen = 0;
  delta[0][0] = 0;
  delta[0][1] = arr[1] - arr[0];
  s[0][0] = 1;
  s[0][1] = 2;
  for(int i = 2; i < len; ++i){
    for(int j = i-1; j >=0; j--){
      delta[j][i] = arr[i] - arr[j];
      s[j][i] = 2;
      for(int k = 0; k < j; ++k){
        if(delta[k][j] == delta[j][i]){
          s[j][i] = s[k][j] + 1;
          if(s[j][i] > maxlen){
            maxlen = s[j][i];
            maxdelta = delta[j][i];
            index = i;
          }
        }
      }
    }
  }
  int num = arr[index];
  //std::cout<<num<<std::endl;
  //std::cout<<maxdelta<<std::endl;
  for(int i = 0; i < maxlen; ++i){
    std::cout<<num-i*maxdelta<<std::endl;
  }
  for(int i = 0; i < maxlen; ++i){
    delete [] delta[i];
    delta[i] = NULL;
    delete [] s[i];
    s[i] = NULL;
  }
  delete [] delta;
  delta = NULL;
  delete [] s;
  s = NULL;
  return maxlen;
}

int main(int argc, char ** argv)
{
  int arr[] = {1,6,4,8,9,5,9,1,7,7};
  int len = sizeof(arr)/sizeof(int);
  qsort(arr, len, sizeof(int), compare);
  /*
  for(int i = 0; i < len; ++i){
    std::cout<<arr[i]<<std::endl;
  }
  */
  longestArithmeticSquence(arr, len);
  system("pause");
  return 0;
}
#endif
