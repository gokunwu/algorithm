
/*
copyright@nciaebupt 转载请注明出处
题目：有双向循环链表结点定义为：
struct node
{ int data;
  struct node *front,*next;
};
有两个双向循环链表A，B，知道其头指针为：pHeadA,pHeadB，请写一函数将两链表中data值相同的结点删除

1 2 3 4 5 6
3 8 7 6 9
    ||
1 2 4 5
8 7 9
*/
#include <cstdlib>
#include <iostream>

struct node{
  int data;
  node * front;
  node * next;
};

node * createListA()
{
  node * newnode1 = new node();
  newnode1->data = 1;
  newnode1->front = NULL;
  newnode1->next = NULL;

  node * newnode2 = new node();
  newnode2->data = 2;
  newnode2->front = NULL;
  newnode2->next = NULL;

  node * newnode3 = new node();
  newnode3->data = 3;
  newnode3->front = NULL;
  newnode3->next = NULL;

  node * newnode4 = new node();
  newnode4->data = 4;
  newnode4->front = NULL;
  newnode4->next = NULL;

  node * newnode5 = new node();
  newnode5->data = 5;
  newnode5->front = NULL;
  newnode5->next = NULL;

  node * newnode6 = new node();
  newnode6->data = 6;
  newnode6->front = NULL;
  newnode6->next = NULL;

  newnode1->next = newnode2;
  newnode1->front = newnode6;

  newnode2->next = newnode3;
  newnode2->front = newnode1;

  newnode3->next = newnode4;
  newnode3->front = newnode2;

  newnode4->next = newnode5;
  newnode4->front = newnode3;

  newnode5->next = newnode6;
  newnode5->front = newnode4;

  newnode6->next = newnode1;
  newnode6->front = newnode5;

  return newnode1;
}

node * createListB()
{
  node * newnode1 = new node();
  newnode1->data = 3;
  newnode1->front = NULL;
  newnode1->next = NULL;

  node * newnode2 = new node();
  newnode2->data = 8;
  newnode2->front = NULL;
  newnode2->next = NULL;

  node * newnode3 = new node();
  newnode3->data = 7;
  newnode3->front = NULL;
  newnode3->next = NULL;

  node * newnode4 = new node();
  newnode4->data = 6;
  newnode4->front = NULL;
  newnode4->next = NULL;

  node * newnode5 = new node();
  newnode5->data = 9;
  newnode5->front = NULL;
  newnode5->next = NULL;

  newnode1->next = newnode2;
  newnode1->front = newnode6;

  newnode2->next = newnode3;
  newnode2->front = newnode1;

  newnode3->next = newnode4;
  newnode3->front = newnode2;

  newnode4->next = newnode5;
  newnode4->front = newnode3;

  newnode5->next = newnode1;
  newnode5->front = newnode4;

  return newnode1;
}

int deleteNode(node * headb, int value)
{
  if(headb == NULL){
    return -1;
  }
  node * pnode = headb;
  while(pnode != )
}

int main(int argc, char ** argv)
{
  node * heada = createListA();
  node * headb = createListB();

  system("pause");
  return 0;
}
