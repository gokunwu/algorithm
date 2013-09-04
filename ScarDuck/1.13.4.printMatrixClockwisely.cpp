#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数
字。
例如：如果输入如下矩阵：

 1              2             3            4
 5              6             7            8
 9              10           11           12
 13             14           15           16

则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10。
*/
#include <cstdlib>
#include <iostream>

void printMatrixClockwisely(int matrix[][4], int columnlen, int rowlen)
{
  if(matrix == NULL || columnlen < 1 || rowlen < 1){
    return;
  }
  int ibegin = 0;
  int iend = rowlen-1;
  int jbegin = 0;
  int jend = columnlen-1;
  int direction = 0;//0->right 1->down 2->left 3->up
  while(ibegin <= iend && jbegin <= jend){
    if(direction == 0){
        for(int i = ibegin; i <= iend; ++i){
          std::cout<<matrix[jbegin][i]<<" ";
        }
        direction = 1;
        jbegin++;
    }else if(direction == 1){
        for(int j = jbegin; j <= jend; ++j){
          std::cout<<matrix[j][iend]<<" ";
        }
        direction = 2;
        iend--;
    }else if(direction == 2){
        for(int i = iend; i >= ibegin; --i){
          std::cout<<matrix[jend][i]<<" ";
        }
        direction = 3;
        jend--;
    }else if(direction == 3){
        for(int j = jend; j >= jbegin; --j){
          std::cout<<matrix[j][ibegin]<<" ";
        }
        direction = 0;
        ibegin++;
    }
  }
}

int main(int argc, char ** argv)
{
  int matrix[][4] = {
                      {1,2,3,4},
                      {5,6,7,8},
                      {9,10,11,12},
                      {13,14,15,16},
                    };
  int columnlen = sizeof(matrix)/sizeof(matrix[0]);
  int rowlen = sizeof(matrix[0])/sizeof(int);
  std::cout<<columnlen<<std::endl;
  std::cout<<rowlen<<std::endl;
  printMatrixClockwisely(matrix, rowlen, columnlen);
  system("pause");
  return 0;
}
#endif
