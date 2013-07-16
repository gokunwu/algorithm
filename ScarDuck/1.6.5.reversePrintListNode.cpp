#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入一个链表的头结点，从尾到头反到来输出每个结点的值。链表结点定义如下：
struct ListNode
{
int m_nKey;
ListNode* m_pNext;
};
分析：这是一道很故含义的面试题。该题以及它的变体经常展目前各大公司的面试、笔试题
中。
看到这道题后，第一反响是过去到后输出比拟容易。于是很慷慨地想到把链表中链接结点的
指针反转到来，改换链表的方向。然后就能够过去到后输出了。反转链表的算法详见本人面
试题精选系列的第19题，在此不再细述。但该措施必需额外的垄断，该当还有更好的措施。
接下来的设法是过去到后遍历链表，每穿越一个结点的时候，把该结点放到一个栈中。当遍
历彻底端链表后，再从栈顶开始输出结点的值，此刻输出的结点的次序曾经反转到来了。该
措施必需维护一个额外的栈，告终起来比拟繁琐。
既然想到了栈来告终这个函数，而递归性质上即便一个栈构造。于是很慷慨的又想到了用递
归来告终。要告终反到来输出链表，我们每拜会到一个结点的时候，先递归输出它后面的结
点，再输出该结点切身，这么链表的输出收获就反到来了。
*/

#include <cstdlib>
#include <iostream>

struct ListNode{
  int m_nKey;
  ListNode * m_pNext;
};

ListNode * createList(int * arr, int len, ListNode * head){
  if(arr == NULL || len < 1)  return NULL;
  for(int i = 0; i < len; ++i){
    ListNode * newnode = new ListNode;
    newnode->m_nKey = arr[i];
    newnode->m_pNext = NULL;
    if(head == NULL){
      head = newnode;
    }
    else{
      newnode->m_pNext = head;
      head = newnode;
    }
  }
  return head;
}

void printListNormal(ListNode * head){
  if(head == NULL)  return;
  ListNode * cur = head;
  while(cur != NULL){
    std::cout<<cur->m_nKey<<" ";
    cur = cur->m_pNext;
  }
  std::cout<<std::endl;
}

void printListReverse(ListNode * head){
  if(head == NULL)  return;
  printListReverse(head->m_pNext);
  std::cout<<head->m_nKey<<std::endl;
}

int main(int argc, char ** argv){
  int arr[] = {1,2,3,4,5,6,7,8};
  int len = sizeof(arr)/sizeof(int);
  ListNode * head = NULL;
  head = createList(arr, len, head);
  printListNormal(head);
  printListReverse(head);

  system("pause");
  return 0;
}
#endif
