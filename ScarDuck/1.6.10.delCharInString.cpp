
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”。
分析：这是一道微软面试题。在微软的常见面试题中，与字符串相关的题目占了很大的一部分，因为写程序操作字符串能很好的反映我们的编程基本功。
要编程完成这道题要求的功能可能并不难。毕竟，这道题的基本思路就是在第一个字符串中拿到一个字符，在第二个字符串中查找一下，看它是不是在第二个字符串中。如果在的话，就从第一个字符串中删除。但如何能够把效率优化到让人满意的程度，却也不是一件容易的事情。也就是说，如何在第一个字符串中删除一个字符，以及如何在第二字符串中查找一个字符，都是需要一些小技巧的。
首先我们考虑如何在字符串中删除一个字符。由于字符串的内存分配方式是连续分配的。我们从字符串当中删除一个字符，需要把后面所有的字符往前移动一个字节的位置。但如果每次删除都需要移动字符串后面的字符的话，对于一个长度为n的字符串而言，删除一个字符的时间复杂度为O(n)。而对于本题而言，有可能要删除的字符的个数是n，因此该方法就删除而言的时间复杂度为O(n2)。
事实上，我们并不需要在每次删除一个字符的时候都去移动后面所有的字符。我们可以设想，当一个字符需要被删除的时候，我们把它所占的位置让它后面的字符来填补，也就相当于这个字符被删除了。在具体实现中，我们可以定义两个指针(pFast和pSlow)，初始的时候都指向第一字符的起始位置。当pFast指向的字符是需要删除的字符，则pFast直接跳过，指向下一个字符。如果pFast指向的字符是不需要删除的字符，那么把pFast指向的字符赋值给pSlow指向的字符，并且pFast和pStart同时向后移动指向下一个字符。这样，前面被pFast跳过的字符相当于被删除了。用这种方法，整个删除在O(n)时间内就可以完成。
接下来我们考虑如何在一个字符串中查找一个字符。当然，最简单的办法就是从头到尾扫描整个字符串。显然，这种方法需要一个循环，对于一个长度为n的字符串，时间复杂度是O(n)。
由于字符的总数是有限的。对于八位的char型字符而言，总共只有28=256个字符。我们可以新建一个大小为256的数组，把所有元素都初始化为0。然后对于字符串中每一个字符，把它的ASCII码映射成索引，把数组中该索引对应的元素设为１。这个时候，要查找一个字符就变得很快了：根据这个字符的ASCII码，在数组中对应的下标找到该元素，如果为0，表示字符串中没有该字符，否则字符串中包含该字符。此时，查找一个字符的时间复杂度是O(1)。其实，这个数组就是一个hash表。
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

void delCharInString(char * str1, char * str2){
  if(str1 == NULL || str2 == NULL)  return;
  const unsigned int charMapSize = 256;
  int charmap[charMapSize];
  memset(charmap, 0, sizeof(charmap));
  char * cur2 = str2;
  while(*cur2 != '\0'){
    charmap[*cur2] = 1;
    cur2++;
  }
  char *pslow = str1;
  char *pfast = str1;
  while(*pfast != '\0'){
    if(charmap[*pfast] != 1){
      *pslow = *pfast;
      pslow++;
    }
    pfast++;
  }
  *pslow = '\0';
  return;
}

int main(int argc, char ** argv){
  char str1[] = "They are students.";
  char str2[] = "aeiou";

  delCharInString(str1, str2);

  std::cout<<str1<<std::endl;

  system("pause");
  return 0;
}
#endif










