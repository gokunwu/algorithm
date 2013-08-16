#if 0
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
  b[0] = 1;
  for(int i = 1; i < len; ++i){
    b[0] = b[0]*a[i-1];
    b[i] = b[0];
  }
  b[0] = 1;
  for(int i = len-2; i > 0; --i){
    b[0] = b[0]*a[i+1];
    b[i] = b[i]*b[0];
  }
  b[0] = b[0]*a[1];
}

int main(int argc, char ** argv)
{
  int a[] = {2,3,4,5,6};
  int alen = sizeof(a)/sizeof(int);
  int * b = new int[alen];
  specialMultiply(a, b, alen);
  for(int i = 0; i < alen; ++i){
    std::cout<<b[i]<<std::endl;
  }
  system("pause");
  return 0;
}
#endif
