#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ����һ�������������������һ��m_pNextָ��ָ����һ������⣬����һ��
m_pSiblingָ�������е���һ������NULL������ɺ���ComplexNode*
Clone(ComplexNode* pHead)���Ը���һ����������

����:һ��ʼ����������˼·��������������ȴ���������������Ȼ����sibling �����
��������ҪO(n^2)��ʱ�临�Ӷȣ�Ȼ��һ�����ɱ��������Ľ����⡣
������ԭʼ������Ȼ�����ǻ������ȸ���ÿһ�����NΪN*����ͬ�������ǽ�N*���ڶ�Ӧ��N���棬Ȼ������Ҫȷ��ÿһ��N*��sibling�������ǳ����ԣ�N��sibling������next����N*��sibling
������ ��󣬽����������ֳ�ԭʼ����Ϳ�����������
���������Ǿͽ����һ�����Ʒǳ����Һ͸��ӵ����⡣
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
