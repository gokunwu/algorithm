#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ���������⼯��A��Ԫ�ظ���Ϊn���ռ�n=0�����������Ӽ��ĸ���Ϊ2^n��
�缯��A={a,b,c},���Ӽ�����Ϊ8����������һ��Ԫ�أ���ÿ���Ӽ��У�
Ҫô���ڣ�Ҫô�����ڣ���Ӧ��ϵ�ǣ�
a->1��a->0
b->1��b->0
c->1��c->0
ӳ��Ϊ�Ӽ���
(a,b,c)
(1,1,1)->(a,b,c)
(1,1,0)->(a,b    )
(1,0,1)->(a,    c)
(1,0,0)->(a        )
(0,1,1)->(    b,c)
(0,1,0)->(    b    )
(0,0,1)->(        c)
(0,0,0)->@ (@��ʾ�ռ�)
������
�㷨��1����
�۲����Ϲ��ɣ������������ݴ洢��ʽ���ƣ��ʿ���ͨ��һ����������int����
����ӳ��000...000 ~ 111...111��0��ʾ�У�1��ʾ�ޣ���֮��ɣ���ͨ����������
�����1�ɱ�����ȡ���е���������ȡ���ϵ���Ӧ�Ӽ���
��������һ�£�ʹ�����ַ�ʽӳ�伯�ϣ��ڽ��м�������ʱ���൱��㣬��
�������Ӧ��λ��&��{a,b,c}��{a,b}��{a,b}<--->111&110==110
�������Ӧ��λ��|��
�������Ӧ&~��
�㷨��2����
�躯��f(n)=2^n (n>=0)�������µ��ƹ�ϵf(n)=2*f(n-1)=2*(2*f(n-2))
�ɴ˿�֪���󼯺��Ӽ����㷨�����õݹ�ķ�ʽʵ�֣�����ÿ��Ԫ����һ��ӳ���б�marks��
�����
���Ӽ��е�����
����Ȼ���ڼ���Ԫ�ظ����ٵ�����£��㷨��1�������㷨��2������Ϊֻ��ͨ���ӷ����㣬
����ӳ��
���Ӽ������㷨��2��Ҫ�ݹ���ú������ٶ����������㷨��1����һ������ȱ�ݣ����ϵĸ�
�����ܴ�����
�������һ����������λ����һ����������������Ϊ32λ�������㷨��2����û�������ơ�
*/

#include <cstdlib>
#include <cstring>
#include <iostream>

void oneSubset(char * str, int i, int len)
{
  if(str == NULL || len < 1){
    return;
  }
  int allzero = 0;
  for(int j = 0; j < len; ++j){
    if(i>>j & 1 == 1){
      std::cout<<str[j];
      allzero = 1;
    }
  }
  if(allzero == 0){
    std::cout<<"@"<<std::endl;
  }
  else{
    std::cout<<std::endl;
  }
}

void allSubsetInSet(char * str, int len)
{
  if(str == NULL || len < 1){
    return;
  }
  if(len > 31){
    return;
  }
  int lowflag = 0;//000
  int highflag = (1<<len) -1;//111
  for(int i = 0; i <= highflag; ++i){
    oneSubset(str, i, len);
  }
}

void printOneSubset(char * str, int * marks, int len)
{
  if(str == NULL || marks == NULL || len < 1){
    return;
  }
  int allzero = 0;
  for(int i = 0; i < len; ++i){
    if(marks[i] == 1){
      std::cout<<str[i];
      allzero = 1;
    }
  }
  if(allzero == 0){
    std::cout<<"@"<<std::endl;
  }
  else{
    std::cout<<std::endl;
  }
}

void allSubsetInSet1(char * str, int * marks, int pos, int len)
{
  if(str == NULL || marks == NULL || len < 1){
    return;
  }
  if(pos >= len){
    printOneSubset(str,marks,len);
    return;
  }
  marks[pos] = 1;
  allSubsetInSet1(str, marks, pos+1, len);
  marks[pos] = 0;
  allSubsetInSet1(str, marks, pos+1, len);
}

int main(int argc, char ** argv)
{
  char str[] = "abc";
  int len = strlen(str);
  int * marks = new int[len];
  allSubsetInSet1(str, marks, 0, len);
  system("pause");
  return 0;
}
#endif








