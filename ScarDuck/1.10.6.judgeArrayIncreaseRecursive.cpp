#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ���õݹ�ķ����ж�������a[N]�ǲ�����������
*/
#include <cstdlib>
#include <iostream>

int isArrIncreaseRecursive(int * arr, int len)
{
  if(len == 1){
    return 1;
  }
  if(arr[len-1] > arr[len]){
    return 0;
  }
  else{
    return isArrIncreaseRecursive(arr, len-1);
  }
}

int main(int argc, char ** argv)
{
  int arr[] = {1,2,3,4,5,6,7,8,9};
  int len = sizeof(arr)/sizeof(arr[0]);
  int res = isArrIncreaseRecursive(arr, len-1);
  std::cout<<res<<std::endl;
  system("pause");
  return 0;
}
#endif
