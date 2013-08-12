#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ����C����ʵ�ֺ���void * memmove(void *dest,const void *src,size_t n)
���������ڿ��԰��κ����͵�ָ�븳��void���͵�ָ��
���������Ҫ��ʵ�ָ����������͵Ŀ�����
��C����ʵ�ֺ���void * memmove(void *dest,const void *src,size_t n)��
memmove�����Ĺ����ǿ���src ��ָ���ڴ�����ǰn���ֽڵ�dest��ָ�ĵ�ַ�ϡ�
���ǵ��ڴ�����ص��������Ҫ�ں����б��������·�ʽ
*/
#include <cstdlib>
#include <iostream>

void * memmove(void * dest, const void *src, size_t n)
{
  void * ret = dest;
  if((char *)dest <= (char *)src || (char *)dest >= (char *)src + n){//if dest and src has overlap
    while(n--){
      *((char *)dest) = *((char *)src);
      dest = (char *)dest + 1;
      src = (char *)src + 1;
    }
  }
  else{
    dest = (char *)dest + n - 1;
    src = (char *)src + n - 1;
    while(n--){
      *((char *)dest) = *((char *)src);
      dest = (char *)dest - 1;
      src = (char *)src - 1;
    }
  }
  return ret;
}

int main(int argc, char ** argv)
{
  char str[] = "I am a good boy.";
  char * ret = (char *)memmove(str+2, str+3, 5);
  std::cout<<ret<<std::endl;

  system("pause");
  return 0;
}
#endif
