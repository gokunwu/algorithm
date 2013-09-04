#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：对于任意集合A，元素个数为n（空集n=0），其所有子集的个数为2^n个
如集合A={a,b,c},其子集个数为8；对于任意一个元素，在每个子集中，
要么存在，要么不存在，对应关系是：
a->1或a->0
b->1或b->0
c->1或c->0
映射为子集：
(a,b,c)
(1,1,1)->(a,b,c)
(1,1,0)->(a,b    )
(1,0,1)->(a,    c)
(1,0,0)->(a        )
(0,1,1)->(    b,c)
(0,1,0)->(    b    )
(0,0,1)->(        c)
(0,0,0)->@ (@表示空集)
分析：
算法（1）：
观察以上规律，与计算机中数据存储方式相似，故可以通过一个整型数（int）与
集合映射000...000 ~ 111...111（0表示有，1表示无，反之亦可），通过该整型数
逐次增1可遍历获取所有的数，即获取集合的相应子集。
在这里提一下，使用这种方式映射集合，在进行集合运算时，相当简便，如
交运算对应按位与&，{a,b,c}交{a,b}得{a,b}<--->111&110==110
并运算对应按位或|，
差运算对应&~。
算法（2）：
设函数f(n)=2^n (n>=0)，有如下递推关系f(n)=2*f(n-1)=2*(2*f(n-2))
由此可知，求集合子集的算法可以用递归的方式实现，对于每个元素用一个映射列表marks，
标记其
在子集中的有无
很显然，在集合元素个数少的情况下，算法（1）优于算法（2），因为只需通过加法运算，
便能映射
出子集，而算法（2）要递归调用函数，速度稍慢。但算法（1）有一个严重缺陷，集合的个
数不能大于在
计算机中一个整型数的位数，一般计算机中整型数的为32位。对于算法（2）就没这样限制。
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








