
/*
copyright@nciaebupt ת����ע������
��Ŀ��2012��4��67�յ���Ѷ����ʵϰ����Ƹ�����У�����һ��������21�����Ƶ��⣬ԭ���
�����£�
     ��������a[N]��b[N]������A[N]�ĸ���Ԫ��ֵ��֪���ָ�b[i]��ֵ��b[i] =
a[0]*a[1]*a[2]...*a[N-1]/a[i]��
Ҫ��
1.��׼�ó�������
2.����ѭ������ֵ��a[N],b[N]�⣬��׼���������κα����������ֲ�������ȫ�ֱ����ȣ�
3.����ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1����
      ˵���ˣ���Ҫ����b=a[0]*a*...a[i-1]*a*a[i+1]..*a[N-1]/a ��������
a[0]*a[1]*...a[i-1]*a[i+1]..*a[N-1]��ֻ���Ұ�a[i]��߲��ֱ�ʾΪleft[i]��b[i]�ұ߲��ֱ�ʾΪ
right[i]����ʵ������ȫ������left[i]����right[i]������֮����������ʾ���޷Ǿ���Ϊ��˵����������ǰԪ��a[i]����������Ԫ��(a[i]��߲��֣���a[i]�ұ߲���)�Ļ���
*/
#include <cstdlib>
#include <iostream>

void specialMultiply(int * a, int * b, int len)
{
  if(a == NULL || len < 1){
    return;
  }
  for(int i = 0; i < len; ++i){
    b[i] = a[i];
  }

  for(int i = 2; i < len; ++i){
    a[i] = a[i-1]*a[i-2];
    std::cout<<a[i];
  }
  a[1] = a[0];
  a[0] = 1;
  std::cout<<std::endl;
  std::cout<<std::endl;
  b[len-2] = b[len-1];
  b[len-1] = 1;
  for(int i = len -3; i >= 0; --i){
    b[i] = b[i+1]*b[i+2];
  }
  for(int i = 0; i < len; ++i){
    b[i] = a[i]*b[i];
  }
}

int main(int argc, char ** argv)
{
  int a[] = {1,2,3,4,5};
  int alen = sizeof(a)/sizeof(int);
  int * b = new int[alen];
  specialMultiply(a, b, alen);
  for(int i = 0; i < alen; ++i){
    std::cout<<b[i]<<std::endl;
  }

  system("pause");
  return 0;
}
