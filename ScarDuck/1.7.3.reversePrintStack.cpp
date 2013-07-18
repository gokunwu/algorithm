
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：用递归颠倒一个栈。例如输入栈{1, 2, 3, 4, 5}，1在栈顶。颠倒之后的栈为{5, 4, 3, 2, 1}，5处在栈顶。
分析：我们把栈{1, 2, 3, 4, 5}看成由两部分组成：栈顶元素1和剩下的部
分{2, 3, 4, 5}。如果我们能把{2, 3, 4, 5}颠倒过来，变成{5, 4, 3, 2}，然后在把原来的栈顶元
素1放到底部，那么就整个栈就颠倒过来了，变成{5, 4, 3, 2, 1}。
接下来我们需要考虑两件事情：一是如何把{2, 3, 4, 5}颠倒过来变成{5, 4, 3, 2}。我们只要把
{2, 3, 4, 5}看成由两部分组成：栈顶元素2和剩下的部分{3, 4, 5}。我们只要把{3, 4, 5}先颠
倒过来变成{5, 4, 3}，然后再把之前的栈顶元素2放到最底部，也就变成了{5, 4, 3, 2}。
至于怎么把{3, 4, 5}颠倒过来……很多读者可能都想到这就是递归。也就是每一次试图颠倒
一个栈的时候，现在栈顶元素pop出来，再颠倒剩下的元素组成的栈，最后把之前的栈顶元
素放到剩下元素组成的栈的底部。递归结束的条件是剩下的栈已经空了。
*/
#include <cstdlib>
#include <iostream>
#include <stack>

void initStack(int * arr, int len, std::stack<int> & istack){
  if(arr == NULL || len < 0){
    return;
  }
  for(int i = 0; i < len; ++i){
    istack.push(arr[i]);
  }
  return;
}

void reversePrintStack(std::stack<int> & istack){
  if(istack.empty()){
    return;
  }
  int top = istack.top();
  istack.pop();
  reversePrintStack(istack);
  std::cout<<top<<std::endl;
}

int main(int argc, char ** argv){
  int arr[] = {1, 2, 3, 4, 5};
  int len = sizeof(arr)/sizeof(arr[0]);
  std::stack<int> istack;
  initStack(arr, len, istack);
  reversePrintStack(istack);
  system("pause");
  return 0;
}
#endif
