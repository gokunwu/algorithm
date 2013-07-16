#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入一个整数数组，调整数组中数字的顺序，使得所有奇数位于数组的前半部分，所
有偶数位于数组的后半部分。要求时间复杂度为O(n)。
分析：如果不考虑时间复杂度，最简单的思路应该是从头扫描这个数组，每碰到一个偶数时，
拿出这个数字，并把位于这个数字后面的所有数字往前挪动一位。挪完之后在数组的末尾有
一个空位，这时把该偶数放入这个空位。由于碰到一个偶数，需要移动O(n)个数字，因此
总的时间复杂度是O(n2)。
要求的是把奇数放在数组的前半部分，偶数放在数组的后半部分，因此所有的奇数应该位于
偶数的前面。也就是说我们在扫描这个数组的时候，如果发现有偶数出现在奇数的前面，我
们可以交换他们的顺序，交换之后就符合要求了。
因此我们可以维护两个指针，第一个指针初始化为数组的第一个数字，它只向  后移动；第
二个指针初始化为数组的最后一个数字，它只向前移动。在两个指针相遇之前，第一个指针
总是位于第二个指针的前面。如果第一个指针指向的数字是偶  数而第二个指针指向的数字
是奇数，我们就交换这两个数字。
*/
#include <cstdlib>
#include <iostream>

void exchange(int * arr, int i, int j){
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void partitionByOddAndEven(int *arr, int len){
  if(arr == NULL || len < 1){
    return;
  }
  int begin = 0;
  int end = len -1;
  while(begin < end){
    if((arr[begin] % 2 == 0) && (arr[end] % 2 == 1)){
      exchange(arr, begin, end);
      begin++;
      end--;
    }
    else{
      if(arr[begin] % 2 == 1){//begin point to odd
        begin++;
      }
      if(arr[end] % 2 == 0){//end point to even
        end--;
      }
    }
  }
}

int main(int argc, char ** argv){
  int arr[] = {3,4,5,6,7,8,9,10,1,2};
  int len = sizeof(arr)/sizeof(int);

  partitionByOddAndEven(arr, len);

  for(int i = 0; i < len; ++i){
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;

  system("pause");
  return 0;
}
#endif
