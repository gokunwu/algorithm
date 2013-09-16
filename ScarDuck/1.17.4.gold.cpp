#if 0
/*
copyright@nciaebupt 转载请注明出处
题目： 10个房间里放着随机数量的金币。每个房间只能进入一次，并只能在一个房间中拿
金币。一个人采取如下策略：前四个房间只看不拿。随后的房间只要看到比前四个房间都多
的金币数，就拿。否则就拿最后一个房间的金币。 编程计算这种策略拿到最多金币的概率。
*/
#include <cstdlib>
#include <iostream>
#include <ctime>

int genRandNum(int a, int b)
{
  //srand((int)time(0));
  return rand()%(b-a+1)+a;
}

void initArray(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return;
  }
  for(int i = 0; i < len; ++i){
    arr[i] = genRandNum(2,10000);
    //std::cout<<arr[i]<<std::endl;
  }
}

int getGold(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return -1;
  }
  int max4 = 0;
  for(int i = 0; i < 4; ++i){
    if(arr[i] > max4){
      max4 = arr[i];
    }
  }
  for(int i = 4; i < len; ++i){
    if(arr[i] > max4){
      return arr[i];
    }
  }
  return arr[len-1];
}

int getMax(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return -1;
  }
  int max = 0;
  for(int i = 0; i < len; ++i){
    if(arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}

double computeProbability()
{
  int total = 1000000;
  int arr[10];
  int len = 10;
  int cnt = 0;
  for(int i = 0; i < total; ++i){
    initArray(arr, len);
    if(getGold(arr, len) == getMax(arr, len)){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return double(cnt)/double(total);
}

int main(int argc, char ** argv)
{
  double probability = computeProbability();
  std::cout<<probability<<std::endl;

  system("pause");
  return 0;
}
#endif
