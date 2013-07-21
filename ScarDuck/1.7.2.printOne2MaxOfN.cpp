

/*
copyright@nciaebupt 转载请注明出处
题目：输入数字n，按顺序输出从1到最大的n位10进制数。比如输入3，则输出1、2、3
一直到最大的3位数即999。
分析：如果我们在数字前面补0的话，就会发现n位所有10进制数其实就是n个从0到9的全排列。也就是说，我们把数字的每一位都从0到9排列一遍，就得到了所有的10进制数。只是我们在输出的时候，数字排在前面的0我们不输出罢了。    全排列用递归很容易表达，数字的每一位都可能是0到9中的一个数，然后设置下一位。递归结束的条件是我们已经设置了数字的最后一位。
*/
#include <cstdlib>
#include <iostream>

void printNumber(char * number, int len){
  if(number == NULL){
    return;
  }
  bool beginFlag = true;
  for(int i = 0; i < len; ++i){
    if(beginFlag == true && number[i] != '0'){
      beginFlag = false;
    }
    if(beginFlag == false){
      std::cout<<number[i];
    }
  }
  std::cout<<std::endl;
  return;
}

void printOne2MaxOfNRecursive(char * number, int len, int index){
  if(number == NULL || len < 0){
    return;
  }
  if(index == len -1){
    printNumber(number, len);
    return;
  }
  for(int i = 0; i < 10; ++i){
    number[index + 1] = i + '0';
    printOne2MaxOfNRecursive(number, len, index + 1);
  }
}

void printOne2MaxOfN(int n){
  if(n < 0){
    return;
  }
  char * number = new char[n+1];
  for(int i = 0; i < n; ++i){
    number[i] = '0';
  }
  number[n] = '\0';
  for(int i = 0; i < 10; ++i){
    number[0] = i + '0';
    printOne2MaxOfNRecursive(number, n, 0);
  }
  if(number != NULL){
    delete [] number;
    number = NULL;
  }
  return;
}

int main(int argc, char ** argv){
  int n = 3;

  printOne2MaxOfN(n);

  system("pause");
  return 0;
}

