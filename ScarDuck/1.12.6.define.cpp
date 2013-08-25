#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：就是定义一个类似函数的宏，宏运算的结果来表示大于和小于。为了简单起见我们假设a,b
为整型。不许使用> <号
*/
#include <cstdlib>
#include <cmath>
#include <iostream>

#define compare(a, b) (abs(a-b) == (a-b) ? 1:-1) == -1 ? -1:((a-b) == 0 ? 0:1)

int main(int argc, char ** argv)
{
  int a = 3;
  int b = 3;
  int ret = compare(a,b);
  std::cout<<ret<<std::endl;

  system("pause");
  return 0;
}
#endif
