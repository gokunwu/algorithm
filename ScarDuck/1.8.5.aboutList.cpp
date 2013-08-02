#if 0
/*
copyright@nciaebupt ת����ע������
��һ����������������Ƿ��л���
ʹ������ָ��p1,p2������ͷ��ʼ������p1ÿ��ǰ��һ����p2ÿ��ǰ�����������p2����
����β����˵���޻�������p1��p2��Ȼ����ĳ��ʱ������(p1==p2)���Ӷ���⵽��������
����
http://ostermiller.org/find_loop_singly_linked_list.html
��ƪ���½��˺ܶ�õĻ�������㷨��
*/
#include <cstdlib>
#include <iostream>

struct List{
  int value;
  List * next;
};

List * createList(int * arr, int len, List * head)
{
  if(arr == NULL || len < 1){
    return NULL;
  }
  List * tail = NULL;
  for(int i = 0; i < len; ++i){
    List * newnode = new List;
    newnode->value = arr[i];
    newnode->next = NULL;
    if(head == NULL){
      head = newnode;
      tail = newnode;
    }
    else{
      newnode->next = head;
      head = newnode;
    }
  }
  tail->next = head;
  return head;
}

bool hasCircleInList(List * head)
{
  if(head == NULL){
    return false;
  }
  List * slow = head;
  List * fast = head;
  while(slow != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
      return true;
    }
  }
  return false;
}

int main(int argc, char ** argv)
{
  int arr[] = {1,2,3,4,5};
  int len = sizeof(arr)/sizeof(arr[0]);
  List * head = NULL;
  head = createList(arr, len, head);
  bool flag = hasCircleInList(head);
  std::cout<<flag<<std::endl;

  system("pause");
  return 0;
}
#endif

/*
copyright@nciaebupt ת����ע������
�����  ��������������(head1, head2)��������������Ƿ��н��㣬����з��ص�һ�����㡣
���head1==head2����ô��Ȼ�ཻ��ֱ�ӷ���head1��
���򣬷ֱ��head1,head2��ʼ���������������䳤��len1 ��len2������len1>=len2����
ôָ��p1��head1��ʼ����ƶ�len1-len2 ����ָ��p2=head2������p1��p2ÿ�����ǰ��
һ�����Ƚ�p1p2�Ƿ���ȣ������ȼ����ظý�㣬����˵����������û�н��㡣
*/
#include <cstdlib>
#include <iostream>
struct List{
  int value;
  List * next;
};

void createList(List ** head1, List ** head2)
{
  List * newnode1 = new List();
  newnode1->value = 1;
  newnode1->next = NULL;

  List * newnode2 = new List();
  newnode2->value = 2;
  newnode2->next = NULL;

  List * newnode3 = new List();
  newnode3->value = 3;
  newnode3->next = NULL;

  List * newnode4 = new List();
  newnode4->value = 4;
  newnode4->next = NULL;

  List * newnode5 = new List();
  newnode5->value = 5;
  newnode5->next = NULL;

  List * newnode6 = new List();
  newnode6->value = 6;
  newnode1->next = NULL;

  List * newnode7 = new List();
  newnode7->value = 7;
  newnode7->next = NULL;

  List * newnode8 = new List();
  newnode8->value = 8;
  newnode8->next = NULL;

  *head1 = newnode1;
  newnode1->next = newnode2;
  newnode2->next = newnode3;
  newnode3->next = newnode4;
  newnode4->next = newnode5;

  *head2 = newnode6;
  newnode6->next = newnode7;
  newnode7->next = newnode8;
  newnode8->next = newnode2;
}

bool hasCommonNode(List ** head1, List ** head2)
{
  if(*head1 == NULL || *head2 == NULL){
    return false;
  }
  if(*head1 == * head2){
    return true;
  }
  List * cur1 = *head1;
  List * cur2 = *head2;
  List * last1 = NULL;
  List * last2 = NULL;
  while(cur1 != NULL){
    last1 = cur1;
    cur1 = cur1->next;
  }
  while(cur2 != NULL){
    last2 = cur2;
    cur2 = cur2->next;
  }
  if(last1 == last2){
    return true;
  }
}

List * getTheCommonNode(List ** head1, List ** head2)
{
  if(*head1 == NULL || *head2 == NULL){
    return NULL;
  }
  if(*head1 == *head2){
    return *head1;
  }
  int len1 = 0;
  int len2 = 0;
  List * cur1 = *head1;
  List * cur2 = *head2;
  while(cur1 != NULL){
    len1++;
    cur1 = cur1->next;
  }
  while(cur2 != NULL){
    len2++;
    cur2 = cur2->next;
  }
  if(len1 > len2){
    cur1 = *head1;
    cur2 = *head2;
    int diff = len1 - len2;
    for(int i =0; i < diff; ++i){
        cur1 = cur1->next;
    }
  }else if(len2 > len1){
    cur1 = *head1;
    cur2 = *head2;
    int diff = len2 - len1;
    for(int i =0; i < diff; ++i){
      cur2 = cur2->next;
    }
  }else if(len1 == len2){
    cur1 = *head1;
    cur2 = *head2;
  }
  while(cur1 != NULL && cur2 != NULL){
    if(cur1 == cur2){
      return cur1;
    }
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  return NULL;
}

int main(int argc, char ** argv)
{
  List * head1 = NULL;
  List * head2 = NULL;
  createList(&head1, &head2);
  bool flag = hasCommonNode(&head1, & head2);
  std::cout<<flag<<std::endl;
  List * common = getTheCommonNode(&head1, &head2);
  if(common != NULL){
    std::cout<<common->value<<std::endl;
  }

  system("pause");
  return 0;
}





