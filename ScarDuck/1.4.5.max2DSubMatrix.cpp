#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：求一个矩阵中最大的二维矩阵(元素和最大).如:
1 2 0 3 4
2 3 4 5 1
1 1 5 3 0
中最大的是:
4 5
5 3
要求:(1)写出算法;(2)分析时间复杂度;(3)用C写出关键代码
*/
#include <cstdlib>
#include <iostream>

void max2DSubMatrix(int matrix[][5],int rowlen, int collen, int res[2][2]){
  if(matrix == NULL || rowlen < 1 || collen < 1) return;
  int sum = 0;
  for(int i = 1; i < rowlen; ++i){
    for(int j = 1; j < collen; ++j){
      int tmp = matrix[i-1][j-1] + matrix[i-1][j] + matrix[i][j-1] + matrix[i][j];
      if(tmp > sum){
        sum = tmp;
        res[0][0] = matrix[i-1][j-1];
        res[0][1] = matrix[i-1][j];
        res[1][0] = matrix[i][j-1];
        res[1][1] = matrix[i][j];
      }
    }
  }
  return;
}

int main(int argc, char ** argv){
  int matrix[][5] = {{1,2,0,3,4},{2,3,4,5,1},{1,1,5,3,0}};
  int rowlen = sizeof(matrix)/sizeof(matrix[0]);
  int collen = sizeof(matrix)/(rowlen * sizeof(int));

  int res[2][2];

  max2DSubMatrix(matrix, rowlen, collen, res);

  for(int i = 0; i < 2; ++i){
    for(int j = 0; j < 2; ++j){
      std::cout<<res[i][j]<<" ";
    }
    std::cout<<std::endl;
  }


  system("pause");
  return 0;
}
#endif

#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：求一个M*N的矩阵的最大子矩阵和。
比如在如下这个矩阵中：
 0 -2 -7  0
 9  2 -6  2
-4  1 -4  1
-1  8  0 -2
拥有最大和的子矩阵为：
 9 2
-4 1
-1 8
其和为15。
*/
#include <cstdlib>
#include <iostream>

int maxSubArray(int * array, int len){
  if(array == NULL || len < 1)  return -1;
  int max = -10000;
  int b = 0;
  for(int i = 0; i < len; ++i){
    if(b > 0){
      b += array[i];
    }
    else{
      b = array[i];
    }
    if(b > max) max = b;
  }
  return max;
}

int maxSubMatrix(int matrix[][4], int rowlen, int collen){
  if(matrix == NULL || rowlen < 1 || collen < 1) return -1;
  int max = -10000;
  int array[collen];
  for(int i = 0; i < rowlen; ++i){
    for(int j = 0; j < collen; ++j){//init array to 0
      array[j] = 0;
    }
    for(int j = i; j < rowlen; ++j){//from row i to row j
      for(int k = 0; k < collen; ++k){
        array[k] += matrix[j][k];
      }
      int maxarray = maxSubArray(array, collen);
      if(maxarray > max)  max = maxarray;
    }
  }
  return max;
}

int main(int argc, char ** argv){
  int matrix[][4] = {{0,-2,-7,0},{9,2,-6,2},{-4,1,-4,1},{-1,8,0,-2 }};
  int collen = sizeof(matrix)/sizeof(matrix[0]);
  int rowlen = sizeof(matrix)/(sizeof(collen)*sizeof(int));
  //std::cout<<"rowlen : "<<rowlen<<"collen : "<<collen<<std::endl;

  int max = maxSubMatrix(matrix, rowlen, collen);

  std::cout<<"max : "<<max<<std::endl;

  system("pause");
  return 0;
}
#endif


