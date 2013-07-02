#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：n支队伍比赛，分别编号为0，1，2。。。。n-1，已知它们之间的实力对比关系，
存储在一个二维数组w[n][n]中，w[i][j] 的值代表编号为i，j 的队伍中更强的一支。
所以w[i][j]=i 或者j，现在给出它们的出场顺序，并存储在数组order[n]中，
比如order[n] = {4,3,5,8,1......}，那么第一轮比赛就是  4对3 5对8 .......
胜者晋级，败者淘汰，同一轮淘汰的所有队伍排名不再细分，即可以随便排，
下一轮由上一轮的胜者按照顺序，再依次两两比，比如可能是4对5,直至出现第一名
编程实现，给出二维数组w，一维数组order 和  用于输出比赛名次的数组result[n]，
求出result。
*/
#include <cstdlib>
#include <iostream>

void nTroopCompete(int w[][4], int * order, int n){
  if(w == NULL || order == NULL || n < 1) return;
  int result[n];
  for(int j = 0;j < n; ++j){
    result[j] =0;
  }
  if(n == 1)  return;
  int mid = n/2;
  if(n % 2 == 1){
    mid += 1;
  }
  int i = 0;
  for(i = 0; i < mid; ++i){
    if(w[order[2*i]][order[2*i+1]] == order[2*i]){
      result[i] = order[2*i];
      result[i+mid] = order[2*i+1];
    }
    else if(w[order[2*i]][order[2*i+1]] == order[2*i+1]){
      result[i] = order[2*i+1];
      result[i+mid] = order[2*i];
    }
  }
  if(n%2 == 1){
    result[i] = order[2*i];
  }
  for(int j = 0; j < n; ++j){
    //std::cout<<result[j]<<std::endl;
    order[j] = result[j];
  }
  nTroopCompete(w,order,mid);
}

int main(int argc, char ** argv){
  int order[] = {2,3,0,1};
  int len = sizeof(order)/sizeof(int);
  int w[4][4] = {{0,0,2,3},{0,1,2,3},{2,2,2,2},{3,3,2,3}};

  nTroopCompete(w, order, len);

  for(int i = 0;i < len; ++i){
    std::cout<<order[i]<<std::endl;
  }

  system("pause");
  return 0;
}

#endif

