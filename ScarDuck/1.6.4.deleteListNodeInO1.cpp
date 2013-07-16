#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：给定链表的头指针和一个结点指针，在O(1)时间删除该结点。
链表结点的定义如下：
struct ListNode
{
      int        m_nKey;
      ListNode*  m_pNext;
};
函数的声明如下：
void DeleteNode( ListNode* pListHead, ListNode* pToBeDeleted);
分析：这是一道广为流传的Google面试题，能有效考察我们的编程基本功，还能考察我们的反应速度，更
重要的是，还能考察我们对时间复杂度的理解。
在链表中删除一个结点，最常规的做法是从链表的头结点开始，顺序查找要删除的结点，找到之后再删除。
由于需要顺序查找，时间复杂度自然就是O(n)了。
我们之所以需要从头结点开始查找要删除的结点，是因为我们需要得到要删除的结点的前面一个结点。我
们试着换一种思路。我们可以从给定的结点得到它的下一个结点。这个时候我们实际删除的是它的下一个
结点，由于我们已经得到实际删除的结点的前面一个结点，因此完全是可以实现的。当然，在删除之前，
我们需要需要把给定的结点的下一个结点的数据拷贝到给定的结点中。此时，时间复杂度为O(1)。
上面的思路还有一个问题：如果删除的结点位于链表的尾部，没有下一个结点，怎么办？我们仍然从链表
的头结点开始，顺便遍历得到给定结点的前序结点，并完成删除操作。这个时候时间复杂度是O(n)。
那题目要求我们需要在O(1)时间完成删除操作，我们的算法是不是不符合要求？实际上，假设链表总共有
n个结点，我们的算法在n-1总情况下时间复杂度是O(1)，只有当给定的结点处于链表末尾的时候，时间
复杂度为O(n)。那么平均时间复杂度[(n-1)*O(1)+O(n)]/n，仍然为O(1)。
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

void listPrint(ListNode * head){
  if(head == NULL){
    return;
  }
  ListNode * cur = head;
  while(cur != NULL){
    std::cout<<cur->m_nKey<<" ";
    cur = cur->m_pNext;
  }
  std::cout<<std::endl;
}

void delListNode(ListNode * head, ListNode * p){
  if(head == NULL)  return;
  if(p->m_pNext == NULL){//the last node in list
    ListNode * cur = head;
    while(cur->m_pNext != p){
      cur = cur->m_pNext;
    }
    cur->m_pNext = NULL;
    delete p;
    p = NULL;
  }
  else{
    ListNode * cur = p->m_pNext;
    int tmp = cur->m_nKey;
    cur->m_nKey = p->m_nKey;
    p->m_nKey = tmp;
    p->m_pNext = cur->m_pNext;
    delete cur;
    cur = NULL;
  }

}

int main(int argc, char ** argv){
  int arr[] = {1,2,3,4,5,6,7,8};
  int len = sizeof(arr)/sizeof(int);
  ListNode * head = NULL;

  head = createList(arr, len, head);
  ListNode * cur = head->m_pNext->m_pNext->m_pNext;

  listPrint(head);
  delListNode(head, cur);
  listPrint(head);

  system("pause");
  return 0;
}

#endif
