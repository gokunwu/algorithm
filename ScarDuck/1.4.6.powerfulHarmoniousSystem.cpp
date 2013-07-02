
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：实现一个挺高级的字符匹配算法：
给一串很长字符串，要求找到符合要求的字符串，例如目的串：123
1******3***2 ，12*****3 这些都要找出来，其实就是类似一些和谐系统
分析：这题的真正意思就是，给你一个目标串，如―123‖，只要一个字符串里面同
时包含1、2和3，那么这个字符串就匹配了。系统越和谐，说明错杀的可能行
也就越大。加入目标串的长度为m，模式串的长度为n，我们很容易想到O(mn)
的算法，就是两遍for 循环搞定。那么有没有更快的方法呢？
我们考虑问题的时候，如果想时间变得快，有一种方法就叫做―空间换时间‖。
哈希表是一种比较复杂的数据结构。由于比较复杂，STL中没有实现哈希表，因此需要我们自己实现一个。
但由于本题的特殊性，我们只需要一个非常简单的哈 希表就能满足要求。由于字符（char）是一个长度为8的数据类型，因此总共有
可能256 种可能。于是我们创建一个长度为256的数组，每个字母根据其ASCII
码值作为数组的下标对应数组的对应项，而数组中存储的0、1对应每个字符是
否出现。这样我们就创建了一个大小为256，以字符ASCII码为键值的哈希表。
（并不仅限于英文字符，所以这里要考虑256种可能）。
知道了这点，我们可以构建一个数组来统计模式串中某个字符是否出现，然
后在对目标串进行扫描，看看对应的所有位上是否出现，从而判断是否匹配。分
析一下复杂度，大概是O(m+n)。
*/
#include <cstdlib>
#include <iostream>
#define HASHMAPSIZE 256

int ifHarmonious(char * src, int srclen, char * des, int deslen){
  if(src == NULL || des == NULL || srclen < 1 || deslen < 1)  return -1;
  int hashmap[HASHMAPSIZE];
  for(int i = 0; i < HASHMAPSIZE; ++i){
    hashmap[i] =0;
  }
  for(int i = 0; i < srclen; ++i){
    hashmap[src[i]] =1;
  }
  for(int i = 0; i < deslen; ++i){
    if(hashmap[des[i]] == 0)  return 0;
  }
  return 1;
}

int main(int argc, char ** argv){
  char des[] = "123";
  char src[] = "1******3***2";
  int srclen = sizeof(src)/sizeof(char);
  int deslen = sizeof(des)/sizeof(char);

  if(ifHarmonious(src, srclen, des, deslen)){
    std::cout<<"yes"<<std::endl;
  }

  system("pause");
  return 0;
}

#endif

























