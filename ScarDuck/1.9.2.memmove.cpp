#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：用C语言实现函数void * memmove(void *dest,const void *src,size_t n)
分析：由于可以把任何类型的指针赋给void类型的指针
这个函数主要是实现各种数据类型的拷贝。
用C语言实现函数void * memmove(void *dest,const void *src,size_t n)。
memmove函数的功能是拷贝src 所指的内存内容前n个字节到dest所指的地址上。
考虑到内存可能重叠的情况，要在函数中避免有以下方式
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
