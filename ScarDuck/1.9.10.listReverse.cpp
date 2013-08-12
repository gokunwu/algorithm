
#if 0
/*
题目：单链表，编程实现其逆转
分析：给定一个单链表，编程实现其逆转。单链表的逆转过程的关键是3个指针：一个记录当前逆
转节点的前一个节点，一个记录当前逆转节点的下一个节点，另外一个则记录当前的逆转节
点。为什么要3个指针呢？其原因就在于当修改了当前逆转节点的next域后（逆转），链
表就暂时断了（即无法再定位下一个节点），因此需要一个指针记录其下一个节点位置（要
能够依次遍历）。记录前一个节点位置则很明显：因为要将当前逆转节点的next域指向其
上一个节点（这样才叫逆转）
*/
#include <cstdlib>
#include <iostream>

struct List{
  int value;
  List * next;
};

List * createList(int * arr, int len, List * head)
{
  if(arr == NULL){
    return NULL;
  }
  for(int i=0; i < len; ++i){
    List * newnode = new List();
    newnode->value = arr[i];
    newnode->next = NULL;
    if(head == NULL){
      head = newnode;
    }
    else{
      newnode->next = head;
      head = newnode;
    }
  }
  return head;
}

void listWalk(List * head)
{
  if(head == NULL){
    return;
  }
  List * cur = head;
  while(cur != NULL){
    std::cout<<cur->value<<std::endl;
    cur = cur->next;
  }
}

List * listReverse(List * head)
{
  if(head == NULL){
    return NULL;
  }
  List * cur = head;
  List * next = NULL;
  while(cur != NULL){
    next = cur->next;
    if(cur == head){
      head = cur;
      cur->next = NULL;
      cur = next;
    }
    else{
      cur->next = head;
      head = cur;
      cur = next;
    }
  }
  return head;
}

int main(int argc, char ** argv)
{
  int arr[] = {1,2,3,4,5,6,7};
  int len = sizeof(arr)/sizeof(arr[0]);
  List * head = NULL;
  head = createList(arr, len, head);
  listWalk(head);
  head = listReverse(head);
  listWalk(head);
  system("pause");
  return 0;
}
#endif
