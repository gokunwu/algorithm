
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入两个整数序列。其中一个序列表示栈的push顺序，判断另一个序列有没有可能
是对应的pop顺序。为了简单起见，我们假设push序列的任意两个整数都是不相等的。
比如输入的push序列是1、2、3、4、5，那么4、5、3、2、1就有可能是一个pop系列。
因为可以有如下的push和pop序列：push 1，push 2，push 3，push 4，pop，push  5，pop，
pop，pop，pop，这样得到的pop序列就是4、5、3、2、1。但序列4、3、5、1、2就不可
能是push序列1、2、3、4、5的pop序列。
分析：
这到题除了考查对栈这一基本数据结构的理解，还能考查我们的分析能力。
这道题的一个很直观的想法就是建立一个辅助栈，每次push的时候就把一个整数push进入
这个辅助栈，同样需要pop的时候就把该栈的栈顶整数pop出来。
我们以前面的序列4、5、3、2、1为例。第一个希望被pop出来的数字是4，因此4需要先
push到栈里面。由于push的顺序已经由push序列确定了，也就是在把4 push进栈之前，
数字1，2，3都需要push到栈里面。此时栈里的包含4个数字，分别是1，2，3，4，其中
4位于栈顶。把4 pop出栈后，剩下三个数字1，2，3。接下来希望被pop的是5，由于仍然
不是栈顶数字，我们接着在push序列中4以后的数字中寻找。找到数字5后再一次push进
栈，这个时候5就是位于栈顶，可以被pop出来。接下来希望被pop的三个数字是3，2，1。
每次操作前都位于栈顶，直接pop即可。
再来看序列4、3、5、1、2。pop数字4的情况和前面一样。把4 pop出来之后，3位于栈顶，
直接pop。接下来希望pop的数字是5，由于5不是栈顶数字，我们到push序列中没有被
push进栈的数字中去搜索该数字，幸运的时候能够找到5，于是把5 push进入栈。此时pop
5之后，栈内包含两个数字1、2，其中2位于栈顶。这个时候希望pop的数字是1，由于不
是栈顶数字，我们需要到push序列中还没有被push进栈的数字中去搜索该数字。但此时push
序列中所有数字都已被push进入栈，因此该序列不可能是一个pop序列。

也就是说，如果我们希望pop的数字正好是栈顶数字，直接pop出栈即可；如果希望pop
的数字目前不在栈顶，我们就到push序列中还没有被push到栈里的数字中去搜索这个数字，
并把在它之前的所有数字都push进栈。如果所有的数字都被push进栈仍然没有找到这个数
字，表明该序列不可能是一个pop序列。
*/

#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

bool isPossiblePushPop(std::string & push, std::string & pop){
  std::stack<char> istack;
  int ipush = 0;
  int ipop = 0;
  bool isPossible = false;
  while(ipop < pop.size()){
    while(istack.empty() || istack.top() != pop[ipop]){
      while(ipush < push.size() && push[ipush] != pop[ipop]){
        istack.push(push[ipush]);
        ipush++;
      }
      if(ipush >= push.size()){
        return isPossible;
      }
      if(push[ipush] == pop[ipop]){
        istack.push(push[ipush]);
        ipush++;
      }
    }
    if(istack.top() == pop[ipop]){
      istack.pop();
      ipop++;
    }
  }
  if(istack.empty()){
    isPossible = true;
  }
  return isPossible;
}

int main(int argc, char ** argv){
  std::string push = "12345";
  std::string pop = "45321";
  //std::string pop = "43512";

  bool flag = isPossiblePushPop(push, pop);

  if(flag == true){
    std::cout<<"yes"<<std::endl;
  }
  else{
    std::cout<<"no"<<std::endl;
  }

  system("pause");
  return 0;
}
#endif










