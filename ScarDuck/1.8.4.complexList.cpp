#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：有一个复杂链表，其结点除了有一个m_pNext指针指向下一个结点外，还有一个
m_pSibling指向链表中的任一结点或者NULL。请完成函数ComplexNode*
Clone(ComplexNode* pHead)，以复制一个复杂链表。

分析:一开始想这道题毫无思路，如果蛮来，首先创建好正常的链表，然后考虑sibling 这个分
量，则需要O(n^2)的时间复杂度，然后一个技巧便可以巧妙的解答此题。
首先是原始的链表，然后我们还是首先复制每一个结点N为N*，不同的是我们将N*让在对应的N后面，然后我们要确定每一个N*的sibling分量，非常明显，N的sibling分量的next就是N*的sibling
分量。 最后，将整个链表拆分成原始链表和拷贝出的链表。
这样，我们就解决了一个看似非常混乱和复杂的问题。
*/
#include <cstdlib>
#include <iostream>

struct List{
  int value;
  List * next;
  List * sibling;
};

List * createList(List * head)
{
  List * node1 = new List();
  node1->value = 1;
  node1->next = NULL;
  node1->sibling = NULL;

  List * node2= new List();
  node2->value = 2;
  node2->next = NULL;
  node2->sibling = NULL;

  List * node3 = new List();
  node3->value = 3;
  node3->next = NULL;
  node3->sibling = NULL;

  List * node4 = new List();
  node4->value = 4;
  node4->next = NULL;
  node4->sibling = NULL;

  List * node5 = new List();
  node5->value = 5;
  node5->next = NULL;
  node5->sibling = NULL;

  head = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  node1->sibling = node3;
  node2->sibling = node4;
  node4->sibling = node1;

  return head;
}

List * clone(List * head){
  if(head == NULL){
    return NULL;
  }
  List * cur = head;
  //create new node after cur
  while(cur != NULL){
    List * newnode = new List();
    newnode->value = cur->value;
    newnode->next = NULL;
    newnode->sibling = NULL;
    newnode->next = cur->next;
    cur->next = newnode;
    cur = cur->next->next;
  }
  //sibling connect
  cur = head;
  List * clone = NULL;
  while(cur != NULL){
    clone = cur->next;
    if(cur->sibling != NULL){
      clone->sibling = cur->sibling->next;
    }
    cur = clone->next;
  }
  //split the list
  cur = head;
  clone = head;
  List * cloneHead = NULL;
  if(cur == head){
    clone = cur->next;
    cloneHead = clone;
  }
  while(cur->next != NULL && clone->next != NULL){
    cur->next = clone->next;
    cur = cur->next;
    clone->next = cur->next;
    clone = clone->next;
  }
  return cloneHead;
}

int main(int argc, char ** argv)
{
  List * head = NULL;
  head = createList(head);

  List * cloneHead = clone(head);

  List * cur = cloneHead;
  while(cur != NULL){
    std::cout<<cur->value<<std::endl;
    cur = cur->next;
  }

  system("pause");
  return 0;
}
#endif
