#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：求随机数构成的数组中找到长度大于=3的最长的等差数列
从数列中求最长等差数列：1 6 4 8 9 5 9 1 7 7
最长等差数列（长度为6）：4 5 6 7 8 9
分析：
设delta[i][j] (0<= i < j <= n-1) 为以a[i], a[j]结尾的最长等差数列的差。很容易算出delta[i][j] = a[j] - a[i];
设s[i][j] (0 <= i < j <= n-1)为以a[i], a[j]结尾的最长等差数列的长度。初始条件s[0][1] = 2; 则：
如果delta[i][j] = delta[x][i] (0 <= x < i - 1), s[i][j] = s[x][i] + 1; 否则，s[i][j] = 2;
max{s[i][j]} (0 <= i < j <= n - 1) 即为所求的最长等差序列的长度

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
