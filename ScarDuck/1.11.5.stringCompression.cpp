
/*
copyright@nciaebupt 转载请注明出处
题目:字符串原地压缩
分析："eeeeeaaaff"压缩为"e5a3f2"
      abc -> abc
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

void stringCompression(char *str, int len)
{
  if(str == NULL || len < 1){
    return;
  }

}

int main(int argc, char ** argv)
{
  char str[] = "eeeeeaaaff";
  int len = strlen(str);

  system("pause");
  return 0;
}
