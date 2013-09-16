
#if 0

/*
copyright@nciaebupt 转载请注明出处
题目：在一个圆形操场的四周摆放着n 堆石子。现要将石子有次序地合并成一堆。规定每次只
能选相邻的2 堆石子合并成新的一堆，并将新的一堆石子数记为该次合并的得分。
     试设计一个算法，计算出将n堆石子合并成一堆的最小得分和最大得分。
比如输入：4 4 5 9
输出：
43
54
*/
#include <cstdlib>
#include <iostream>

const int MAX = 1000;

int min(int i, int j)
{
  return i<j?i:j;
}

int max(int i, int j)
{
  return i>j?i:j;
}

int sum(int * stones, int i, int j)
{
  if(stones == NULL){
    return -1;
  }
  int sum = 0;
  for(int k = i; k <= j; k++){
    sum += stones[k];
  }
  return sum;
}

int stonesCombine(int * arr, int len, int & maxscore, int & minscore)
{
  if(arr == NULL || len < 1){
    return -1;
  }
  int * stones = new int[2*len];
  for(int i = 0; i < len; ++i){
    stones[i] = arr[i];
    stones[i+len] = arr[i];
  }

  int ** dpmin = new int*[2*len];
  int ** dpmax = new int*[2*len];

  for(int i = 0; i < 2*len; ++i){
    dpmin[i] = new int[2*len];
    dpmax[i] = new int[2*len];
    for(int j = 0; j < 2*len; ++j){
      if(i == j){
        dpmin[i][j] = 0;
      }
      else{
        dpmin[i][j] = MAX;
      }
      dpmax[i][j] = 0;
    }
  }

  for(int l = 1; l < len; ++l){
    for(int i = 0; i < 2*len-l; ++i){
      int j = i + l;
      for(int k = i; k < j; ++k){
        dpmin[i][j] = min(dpmin[i][j], dpmin[i][k]+dpmin[k+1][j] + sum(stones, i, j));
        dpmax[i][j] = max(dpmax[i][j], dpmax[i][k]+dpmax[k+1][j] + sum(stones, i, j));
      }
    }
  }
  maxscore = 0;
  minscore = MAX;
  for(int i = 0; i < len; ++i){
    if(dpmax[i][i+len-1] > maxscore){
      maxscore = dpmax[i][i+len-1];
    }
    if(dpmin[i][i+len-1] < minscore){
      minscore = dpmin[i][i+len-1];
    }
  }
  if(stones != NULL){
    delete [] stones;
    stones = NULL;
  }
  for(int i = 0; i < 2*len; ++i){
    if(dpmin[i] != NULL){
      delete [] dpmin[i];
      dpmin[i] = NULL;
    }
    if(dpmax[i] != NULL){
      delete [] dpmax[i];
      dpmax[i] = NULL;
    }
  }
  if(dpmin != NULL){
    delete [] dpmin;
    dpmin = NULL;
  }
  if(dpmax != NULL){
    delete [] dpmax;
    dpmax = NULL;
  }
}
int main(int argc, char ** argv)
{
  int arr[] = {4,4,5,9};
  int len = sizeof(arr)/sizeof(int);
  int maxscore = 0;
  int minscore = 0;
  stonesCombine(arr, len, maxscore, minscore);
  std::cout<<minscore<<std::endl;
  std::cout<<maxscore<<std::endl;
  system("pause");
  return 0;
}
#endif
