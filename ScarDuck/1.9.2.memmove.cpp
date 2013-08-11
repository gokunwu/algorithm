
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
}

int main(int argc, char ** argv)
{


  system("pause");
  return 0;
}
