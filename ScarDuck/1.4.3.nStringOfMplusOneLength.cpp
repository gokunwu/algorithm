
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：有n 个长为m+1 的字符串，如果某个字符串的最后m 个字符与某个字符串的前m 个字符
匹配，则两个字符串可以联接，问这n 个字符串最多可以连成一个多长的字符串，如果出
现循环，则返回错误。
分析：将各个字符串作为一个节点，首尾链接就好比是一条边，将两个节点连接起来，
于是问题就变成一个有关图的路径长度的问题。链接所得的字符串最长长度即为从图的某个
节点出发所能得到的最长路径问题，与最短路径类似，可以应用弗洛伊德算法求解。对于循
环，即可认为各个节点通过其他节点又回到自己，反应在路径长度上，就表示某个节点到自
己节点的路径大于零（注：初始化个节点到自己的长度为零）。
*/
#include <cstdlib>
#include <iostream>
#include <string>

int maxCatenate(std::string * text, int len){
  if(text == NULL || len < 1) return -1;
  int G[len][len];
  //init G to 0
  for(int i = 0; i < len; ++i){
    for(int j = 0; j < len; ++j){
      G[i][j] = 0;
    }
  }
  //generate edge of graph
  for(int i = 0; i < len; ++i){
    std::string prefix = text[i].substr(1);
    for(int j = 0; j < len; ++j){
      std::string suffix = text[j].substr(0,text[j].size()-1);
      if(prefix == suffix){
        //std::cout<<text[i]<<"  "<<text[j]<<std::endl;
        G[i][j] = 1;
      }
    }
  }
  //floyd algorithm
  for(int k = 0; k < len; ++k){
    for(int i = 0; i < len; ++i){
      for(int j = 0; j < len; ++j){
        if(G[i][k] != 0 && G[k][j] != 0){//i与k必须有边相连 并且 k与j也必须有边相连
           if(G[i][k] + G[k][j] > G[i][j]){
            G[i][j] = G[i][k] + G[k][j];
           }
        }
      }
    }
  }
  //judge if there is a circle in graph
  for(int i = 0; i < len; ++i){
    if(G[i][i] > 1){
      std::cout<<"There is a circle in Graph"<<std::endl;
      return -1;
    }
  }
  //get the max length
  int max = 0;
  for(int i = 0; i < len; ++i){
    for(int j = 0; j < len; ++j){
      if(G[i][j] > max){
        max = G[i][j];
      }
    }
  }
  return max;
}

int main(int argc, char ** argv){
  std::string text[] = {"abcd",
                        "bcde",
                        "cdea",
                        "deab",
                        "eaba",
                        "abab",
                        "deac",
                        "cdei",
                        "bcdf",
                        "cdfi",
                        "dfic",
                        "cdfk",
                        "bcdg",
//                        "babc"
                       };
  int len = sizeof(text)/sizeof(std::string);

  int max = maxCatenate(text,len);

  std::cout<<"max = "<<max<<std::endl;

  system("pause");
  return 0;
}

#endif

