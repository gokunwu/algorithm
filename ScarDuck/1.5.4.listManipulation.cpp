#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:单链表就地逆置，
*/
#include <cstdlib>
#include <iostream>

struct List{
  int value;
  List * next;
};

void createList(List ** head, int * array, int len){
  if(array == NULL || len < 1)  return;
  *head = NULL;
  for(int i = 0; i < len; ++i){
    List *newnode = new List;
    newnode->value = array[i];
    newnode->next = NULL;
    if(*head == NULL){
      *head = newnode;
      newnode->next = NULL;
    }
    else{
      newnode->next = *head;
      *head = newnode;
    }
  }
}

void reverseList(List ** head){
  if(*head == NULL) return;
  List *cur = *head;
  *head = NULL;
  while(cur != NULL){
    if(*head == NULL){
      List * tmp = cur;
      cur = cur->next;
      *head = tmp;
      tmp->next = NULL;
    }
    else{
      List * tmp = cur;
      cur = cur->next;
      tmp->next = *head;
      *head = tmp;
    }
  }
}

int main(int argc, char ** argv){
  int array[] = {1,2,3,4,5,6};
  int len = sizeof(array)/sizeof(int);
  List ** head;

  createList(head, array, len);

  reverseList(head);
  List *cur = *head;
  while(cur != NULL){
    std::cout<<cur->value<<std::endl;
    cur = cur->next;
  }

  system("pause");
  return 0;
}

#endif
