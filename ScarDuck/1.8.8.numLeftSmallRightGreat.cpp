#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ��һ��int ���飬�����������κ����ƣ�Ҫ�����������������a[i]������ߵ�����С
�ڵ��������ұߵ��������ڵ�������
�ܷ�ֻ��һ��������������������ռ�ʵ�֡�
��������ԭʼ�ķ����Ǽ��ÿһ����  array[i] �����Ƿ���ߵ�����С�ڵ��������ұߵ�����
���ڵ��������������Ļ���Ҫ�ҳ���������������ʱ�临�Ӷ�ΪO(N^2)��
��ʵ�����и��򵥵ķ���������ʹ�ö������飬����rightMin[]���������Ǽ�¼ԭʼ����
array[i]�ұߣ������Լ�������Сֵ������ԭʼ����Ϊ��  array[] = {7, 10, 2, 6, 19, 22, 32}��  ��ôrightMin[] = {2, 2, 2, 6, 19, 22, 32}.  Ҳ����˵��7�ұߵ���СֵΪ2, 2�ұߵ���СֵҲ��2��
��������һ���������飬�����Ǵ�ͷ��ʼ����ԭʼ����ʱ�����Ǳ���һ����ǰ���ֵ  max��
�����ǰ���ֵ�պõ���rightMin[ i]��  ��ô������ֵһ���������������Ǹղŵ����ӡ�
��һ��ֵ��7�����ֵҲ��7����Ϊ7 ������  2��  ������
�ڶ���ֵ��10�����ֵ�����10������10Ҳ������2��������
������ֵ��2�����ֵ��10������10Ҳ������2��������
���ĸ�ֵ��6�����ֵ��10������10������6��������
�����ֵ��19�����ֵ�����19������19Ҳ���ڵ�ǰrightMin[4] = 19, ���ԣ�����������
��˼�����ȥ������ļ��������㡣
*/


#include <cstdlib>
#include <iostream>

void numLeftSmallRightGreat(int * arr, int len)
{
  if(arr == NULL || len < 1){
    return;
  }
  int * rightmin = new int[len];
  int minnum = arr[len-1];
  for(int i = len -1; i >= 0; --i){
    if(arr[i] < minnum){
      minnum = arr[i];
    }
    rightmin[i] = minnum;
  }
  int maxnum = arr[0];
  for(int i = 0; i < len; ++i){
    if(arr[i] > maxnum){
      maxnum = arr[i];
    }
    if(maxnum == rightmin[i]){
      std::cout<<arr[i]<<std::endl;
    }
  }
}

int main(int argc, char ** argv)
{
  int arr[] = {7,10,2,6,19,22,32};
  int len = sizeof(arr)/sizeof(arr[0]);

  numLeftSmallRightGreat(arr, len);

  system("pause");
  return 0;
}
#endif
