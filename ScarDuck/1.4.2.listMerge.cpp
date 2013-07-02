#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：两个非降序链表的并集，1->2->3 和  2->3->5 并为  1->2->3->5 另外只能输出结果，不能修改两个链表的数据。
*/
#include <cstdlib>
#include <iostream>

struct List{
  int value;
  List * next;
};

List * createList(int * arr, int len){
  List * head = NULL;
  for(int i = 0; i < len;++i){
    List * newnode = new List();
    if(head == NULL){
      newnode->value= arr[i];
      newnode->next = NULL;
      head = newnode;
    }
    else{
      newnode->value= arr[i];
      newnode->next = head;
      head = newnode;
    }
  }
  return head;
}

void listMerge(List * head1, List * head2){
  if(head1 == NULL && head2 == NULL)  return;
  if(head1 == NULL){
    List * cur = head2;
    while(cur != NULL){
      std::cout<<cur->value<<" ";
      cur = cur->next;
    }
    std::cout<<std::endl;
    return;
  }
  if(head2 == NULL){
    List * cur = head1;
    while(cur != NULL){
      std::cout<<cur->value<<" ";
      cur = cur->next;
    }
    std::cout<<std::endl;
    return;
  }
  List * cur1 = head1;
  List * cur2 = head2;
  while(cur1 != NULL && cur2 != NULL){
    if(cur1->value < cur2->value){
      std::cout<<cur1->value<<" ";
      cur1 = cur1->next;
    }
    else if(cur1->value > cur2->value){
      std::cout<<cur2->value<<" ";
      cur2 = cur2->next;
    }
    else{
      std::cout<<cur1->value<<" ";
      cur1 = cur1->next;
      cur2 = cur2->next;
    }
  }
  while(cur1 != NULL){
    std::cout<<cur1->value<<" ";
    cur1 = cur1->next;
  }
  while(cur2 != NULL){
    std::cout<<cur2->value<<" ";
    cur2 = cur2->next;
  }
  std::cout<<std::endl;
  return;
}

int main(int argc, char ** argv){
  int arr1[] = {3,2,1};
  int len1 = sizeof(arr1)/sizeof(int);
  int arr2[] = {5,3,2};
  int len2 = sizeof(arr2)/sizeof(int);

  List * head1 = createList(arr1,len1);
  List * head2 = createList(arr2,len2);

  listMerge(head1,head2);

  system("pause");
  return 0;
}
#endif
