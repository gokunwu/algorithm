
/*
copyright@nciaebupt 转载请注明出处
2013 google校招笔试题
2.3 给定一个原串和目标串，能对源串进行如下操作：

1.在给定位置插入一个字符

2.替换任意字符

3.删除任意字符

要求写一个程序，返回最少的操作数，使得源串进行这些操作后等于目标串。源串和目标串长度都小于2000。

在日常应用中，文本比较是一个比较常见的问题。文本比较算法也是一个老生常谈的话题。

　　文本比较的核心就是比较两个给定的文本（可以是字节流等）之间的差异。目前，主流的比较文本之间的差异主要有两大类。一类是基于编辑距离（Edit Distance）的，例如LD算法。一类是基于最长公共子串的（Longest Common Subsequence），例如Needleman/Wunsch算法等。

　　LD算法（Levenshtein Distance）又成为编辑距离算法（Edit Distance）。他是以字符串A通过插入字符、删除字符、替换字符变成另一个字符串B，那么操作的过程的次数表示两个字符串的差异。

　　例如：字符串A：kitten如何变成字符串B：sitting。

　　　　第一步：kitten——》sitten。k替换成s

　　　　第二步：sitten——》sittin。e替换成i

　　　　第三步：sittin——》sitting。在末尾插入g

　　故kitten和sitting的编辑距离为3



　　定义说明：

　　LD(A,B)表示字符串A和字符串B的编辑距离。很显然，若LD(A,B)=0表示字符串A和字符串B完全相同

　　Rev(A)表示反转字符串A

　　Len(A)表示字符串A的长度

　　A+B表示连接字符串A和字符串B

　　

　　有下面几个性质：

　　LD(A,A)=0

　　LD(A,"")=Len(A)

　　LD(A,B)=LD(B,A)

　　0≤LD(A,B)≤Max(Len(A),Len(B))

　　LD(A,B)=LD(Rev(A),Rev(B))

　　LD(A+C,B+C)=LD(A,B)

　　LD(A+B,A+C)=LD(B,C)

　　LD(A,B)≤LD(A,C)+LD(B,C)（注：像不像“三角形，两边之和大于第三边”）

　　LD(A+C,B)≤LD(A,B)+LD(B,C)



　　为了讲解计算LD(A,B)，特给予以下几个定义

　　A=a1a2……aN，表示A是由a1a2……aN这N个字符组成，Len(A)=N

　　B=b1b2……bM，表示B是由b1b2……bM这M个字符组成，Len(B)=M

　　定义LD(i,j)=LD(a1a2……ai,b1b2……bj)，其中0≤i≤N，0≤j≤M

　　故：　　LD(N,M)=LD(A,B)

　　　　　　LD(0,0)=0

　　　　　　LD(0,j)=j

　　　　　　LD(i,0)=i



　　对于1≤i≤N，1≤j≤M，有公式一

　　若ai=bj，则LD(i,j)=LD(i-1,j-1)

　　若ai≠bj，则LD(i,j)=Min(LD(i-1,j-1),LD(i-1,j),LD(i,j-1))+1



　　举例说明：A=GGATCGA，B=GAATTCAGTTA，计算LD(A,B)

　　第一步：初始化LD矩阵　　



LD算法矩阵
 	 	G	A	A	T	T	C	A	G	T	T	A
 	0	1	2	3	4	5	6	7	8	9	10	11
G	1
G	2
A	3
T	4
C	5
G	6
A	7


　　第二步：利用上述的公式一，计算第一行



LD算法矩阵
 	 	G	A	A	T	T	C	A	G	T	T	A
 	0	1	2	3	4	5	6	7	8	9	10	11
G	1	0	1	2	3	4	5	6	7	8	9	10
G	2
A	3
T	4
C	5
G	6
A	7


　　第三步，利用上述的公示一，计算其余各行

LD算法矩阵
 	 	G	A	A	T	T	C	A	G	T	T	A
 	0	1	2	3	4	5	6	7	8	9	10	11
G	1	0	1	2	3	4	5	6	7	8	9	10
G	2	1	1	2	3	4	5	6	6	7	8	9
A	3	2	1	1	2	3	4	5	6	7	8	8
T	4	3	2	2	1	2	3	4	5	6	7	8
C	5	4	3	3	2	2	2	3	4	5	6	7
G	6	5	4	4	3	3	3	3	3	4	5	6
A	7	6	5	4	4	4	4	3	4	4	5	5


　　则LD(A,B)=LD(7,11)=5

*/
#include <cstdlib>
#include <cstring>
#include <iostream>

int min(int i, int j, int k)
{
  int min = i;
  if(j < min){
    min = j;
  }
  if(k < min){
    min = k;
  }
  return min;
}

int editDistance(char * str1, int len1, char * str2, int len2)
{
  if(str1 == NULL || len1 < 1){
    return len2;
  }
  if(str2 == NULL || len2 < 1){
    return len1;
  }
  int ** dp = new int*[len1];
  for(int i = 0; i < len1; ++i){
    dp[i] = new int[len2];
    for(int j = 0; j < len2; ++j){
      dp[i][j] = 0;
    }
  }
  for(int i = 0; i < len1; ++i){
    dp[i][0] = i;
  }
  for(int j = 0; j < len2; ++j){
    dp[0][j] = j;
  }
  for(int i = 1; i < len1; ++i){
    for(int j = 1; j < len2; ++j){
      if(str1[i] == str2[j]){
        dp[i][j] = dp[i-1][j-1];
      }
      else{
        dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
      }
    }
  }
  int ret = dp[len1-1][len2-1];
  for(int i = 0; i < len1; ++i){
    if(dp[i] != NULL){
      delete [] dp[i];
      dp[i] = NULL;
    }
  }
  if(dp != NULL){
    delete [] dp;
    dp = NULL;
  }
  return ret;
}

int main(int argc, char ** argv)
{
  char str1[] = "GGATCGA";
  char str2[] = "GAATTCAGTTA";
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int ret = editDistance(str1, len1, str2, len2);
  std::cout<<ret<<std::endl;
  system("pause");
  return 0;
}
