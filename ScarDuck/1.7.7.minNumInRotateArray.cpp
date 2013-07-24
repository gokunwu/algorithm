
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个排好序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
         分析：这道题最直观的解法并不难。从头到尾遍历数组一次，就能找出最小的元素，时间复杂度显然是O(N)。但这个思路没有利用输入数组的特性，我们应该能找到更好的解法。
         我们注意到旋转之后的数组实际上可以划分为两个排序的子数组，而且前面的子数组的元素都大于或者等于后面子数组的元素。我们还可以注意到最小的元素刚好是这两个子数组的分界线。我们试着用二元查找法的思路在寻找这个最小的元素。
         首先我们用两个指针，分别指向数组的第一个元素和最后一个元素。按照题目旋转的规则，第一个元素应该是大于或者等于最后一个元素的（这其实不完全对，还有特例。后面再讨论特例）。
接着我们得到处在数组中间的元素。如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素。此时数组中最小的元素应该位于该中间元素的后面。我们可以把第一指针指向该中间元素，这样可以缩小寻找的范围。同样，如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指向的元素。此时该数组中最小的元素应该位于该中间元素的前面。我们可以把第二个指针指向该中间元素，这样同样可以缩小寻找的范围。我们接着再用更新之后的两个指针，去得到和比较新的中间元素，循环下去。
按照上述的思路，我们的第一个指针总是指向前面递增数组的元素，而第二个指针总是指向后面递增数组的元素。最后第一个指针将指向前面子数组的最后一个元素，而第二个指针会指向后面子数组的第一个元素。也就是它们最终会指向两个相邻的元素，而第二个指针指向的刚好是最小的元素。这就是循环结束的条件。
*/
#include <cstdlib>
#include <iostream>

int minNumInRotateArray(int * arr, int len){
  if(arr == NULL | len < 1){
    return -1;
  }
  int low = 0;
  int high = len - 1;
  while(low < high){
    int mid = (low + high)/2;
    //如果首个元素小于最后一个元素，表明数组是排序的。
    if(arr[low] < arr[high]){
      return arr[low];
    }
    //当low指针与high指针相邻的时候，high指针指向的就是最小元素
    if(high - low == 1){
      return arr[high];
    }
    //当arr[mid]==arr[low]==arr[high]时只能线性搜索
    if(arr[mid] == arr[low] && arr[mid] == arr[high]){
      int min = arr[low];
      for(int i = low; i <= high; ++i){
        if(min > arr[i]){
          min = arr[i];
        }
      }
      return min;
    }
    if(arr[mid] >= arr[low]){//low 到mid 升序
      low = mid;
    }
    else if(arr[mid] <= arr[high]){
      high = mid;
    }
  }
}

int main(int argc, char **argv){
  //int arr[] = {3,4,5,6,7,1,2};
  //int arr[] = {9,9,9,9,9,9,9,10,1,9};
  int arr[] = {2,3,4,1,1,1,1};
  int len = sizeof(arr)/sizeof(arr[0]);

  int min = minNumInRotateArray(arr, len);
  std::cout<<"min : "<<min<<std::endl;

  system("pause");
  return 0;
}
#endif
