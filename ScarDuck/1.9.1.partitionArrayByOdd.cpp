#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ������һ��������������飬������������ʹ���������Ϊ�������ұ�Ϊż��
*/
#include <cstdlib>
#include <iostream>

void exchange(int * arr, int i, int j)
{
  if(arr == NULL){
    return;
  }
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void partitionByOdd(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return;
  }
  int left = 0;
  int right = len-1;
  while(left < right){
    if(arr[left]%2 == 0 && arr[right]%2 == 1){
      exchange(arr, left, right);
      left++;
      right--;
    }
    if(arr[left]%2 == 1){
      left++;
    }
    if(arr[right]%2 == 0){
      right--;
    }
  }
}

int main(int argc, char ** argv)
{
  int arr[] = {7,10,2,6,19,22,1};
  int len = sizeof(arr)/sizeof(arr[0]);
  partitionByOdd(arr, len);
  for(int i = 0; i < len; i++){
    std::cout<<arr[i]<<std::endl;
  }

  system("pause");
  return 0;
}
#endif
