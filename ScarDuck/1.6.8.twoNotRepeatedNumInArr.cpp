#if 0
/*
copyright@nciaebupt 转载请注明出处
问题：一个数组中除了两个数字之外，其余数字均出现了两次(或偶数次)。请写出程序
查找出这两个只出现一次的数字，要求时间复杂度为O(n)，空间复杂度为O(1)。
分析：这是一道很新颖的关于位运算的面试题。首先考虑这个问题的一个简单版本：一
个数组中除了一个数字之外，其余的数字均出现两次，请写程序找出这个出现一次的数字。
这个问题的突破口在哪里？题目为什么强调有一个数字只出现一次，其他的出现两次？我们
想到异或运算的性质，任何一个数字异或  自身都为0。也就是说，如果我们从头到尾依次
异或数组中的每一个数字，那么最终的结果刚好是那个只出现一次的数字。因为出现两次的
数字均在异或运算中抵消了。
有了上面简单问题的解决方案后，我们回到原始问题。如果能把一个数组分为两个子数组，
在每个子数组中，包含一个只出现一次的  数字，其余数字均出现两次。如果能够这样拆分
数组，则按照前面的方法，很容易求出原始数组中两个只出现一次的数字。
我们还是从头到尾依次异或数组中每个数字，那么最终得到的结果就是两个只出现一次的的
数字的异或值，其他出现两次的数字在异  或运算中抵消了。由于这两个数字肯定不一样，
所以最终异或结果必然不为0。也就是说异或结果的二进制数值中肯定有一位为1。我们在
异或结果数字中找到第一个不为1的位的位置，记为N，我们以第N位是否为1为标准把
原始数组划分为两个子数组。第一个子数组每个数字第N位都为1，第二个子数组每个数字
第N位都为0。现在，我们已经把原始数组划分为两个子数组。两个子数组都包含一个只出
现1次的数字，而其余数字均出现两次。到此为止，原始问题就得以解决了。
*/
#include <cstdlib>
#include <iostream>

int findNotZeroBit(int num){
  int pos = 1;
  while(num&1 != 1){
    num = num >> 1;
    pos++;
  }
  return pos;
}

bool testBinary(int num, int pos){
  if((num >> pos) & 1 == 1){
    return true;
  }
  else{
    return false;
  }
}

void findNumNotRepeat(int * arr, int len, int & num1, int & num2){
  if(arr == NULL || len < 1)  return;
  int xorres = 0;
  for(int i = 0; i < len; ++i){
    xorres ^= arr[i];
  }
  int pos = findNotZeroBit(xorres);
  num1 = 0;
  num2 = 0;
  for(int i = 0; i < len; ++i){
    if(testBinary(arr[i], pos)){
      num1 ^= arr[i];
    }
    else{
      num2 ^= arr[i];
    }
  }
  return;
}

int main(int argc, char ** argv){
  int arr[] = {1,2,3,4,5,6,4,3,2,1};
  int len = sizeof(arr)/sizeof(int);
  int num1 = 0;
  int num2 = 0;
  findNumNotRepeat(arr, len, num1, num2);

  std::cout<<num1<<std::endl;
  std::cout<<num2<<std::endl;

  system("pause");
  return 0;
}
#endif
