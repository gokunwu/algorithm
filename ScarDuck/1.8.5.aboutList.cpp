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

#if 0
/*
copyright@nciaebupt ת����ע������
�����  ��������������(head1, head2)��������������Ƿ��н��㣬����з��ص�һ�����㡣
���head1==head2����ô��Ȼ�ཻ��ֱ�ӷ���head1��
���򣬷ֱ��head1,head2��ʼ���������������䳤��len1 ��len2������len1>=len2����
ôָ��p1��head1��sʼ����ƶ�len1-len2 ����ָ��p2=head2������p1��p2ÿ�����ǰ��
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
#endif

#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ������������(head)������л��Ļ��뷵�ش�ͷ�����뻷�ĵ�һ���ڵ㡣
��fast����slow����ʱ��slow�϶�û���߱�����������fast�Ѿ��ڻ���ѭ����nȦ(1<=n)��
����slow����s������fast����2s����fast����������s �����ڻ��϶�ת��nȦ�����軷��Ϊr����
2s = s + nr
s= nr
����ڻ������������Ϊx��x<r����㵽����ڵ�ľ���Ϊa.
a = s - x = (n-1)r+ (r-x), ��r-x��Ϊfast�ٴε�����ڵ�ʱ�Ĳ���
�ɴ˿�֪��������ͷ������ڵ����(n-1)ѭ���ڻ�+�����㵽����ڵ㣬�������Ǵ�����ͷ����������ֱ���һ��ָ�룬ÿ�θ���һ��������ָ��ض���������������һ��Ϊ����ڵ㡣
*/
#include <cstdlib>
#include <iostream>

struct List{
  int value;
  List * next;
};

List * createList(List * head)
{
  List * newnode1 = new List();
  newnode1->value = 0;
  newnode1->next = NULL;

  List * newnode2 = new List();
  newnode2->value = 1;
  newnode2->next = NULL;

  List * newnode3 = new List();
  newnode3->value = 2;
  newnode3->next = NULL;

  List * newnode4 = new List();
  newnode4->value = 3;
  newnode4->next = NULL;

  List * newnode5 = new List();
  newnode5->value = 4;
  newnode5->next = NULL;

  List * newnode6 = new List();
  newnode6->value = 5;
  newnode6->next = NULL;

  List * newnode7 = new List();
  newnode7->value = 6;
  newnode7->next = NULL;

  List * newnode8 = new List();
  newnode8->value = 7;
  newnode8->next = NULL;

  head = newnode1;
  newnode1->next = newnode2;
  newnode2->next = newnode3;
  newnode3->next = newnode4;
  newnode4->next = newnode5;
  newnode5->next = newnode6;
  newnode6->next = newnode7;
  newnode7->next = newnode8;
  newnode8->next = newnode4;
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

List * getFirstNodeInCircle(List * head)
{
  if(head == NULL){
    return NULL;
  }
  List * slow = head;
  List * fast = head;
  //get the meet point
  while(slow != NULL || fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
      break;
    }
  }
  //get the first node in circle
  slow = head;
  while(slow != NULL && fast != NULL){
    if(slow == fast){
      return slow;
    }
    slow = slow->next;
    fast = fast->next;
  }
}

int main(int argc, char ** argv)
{
  List * head = NULL;
  head = createList(head);
  //listWalk(head);

  List * firstNode = getFirstNodeInCircle(head);
  std::cout<<firstNode->value<<std::endl;

  system("pause");
  return 0;
}
#endif

#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ��ֻ������������ĳ�����p(�������һ����㣬��p->next!=NULL)ָ�룬ɾ���ý�
�㡣
*/
#include <cstdlib>
#include <iostream>

struct List{
  int value;
  List * next;
};

List * createList(List * head)
{
  List * newnode1 = new List();
  newnode1->value = 0;
  newnode1->next = NULL;

  List * newnode2 = new List();
  newnode2->value = 1;
  newnode2->next = NULL;

  List * newnode3 = new List();
  newnode3->value = 2;
  newnode3->next = NULL;

  List * newnode4 = new List();
  newnode4->value = 3;
  newnode4->next = NULL;

  List * newnode5 = new List();
  newnode5->value = 4;
  newnode5->next = NULL;

  List * newnode6 = new List();
  newnode6->value = 5;
  newnode6->next = NULL;

  List * newnode7 = new List();
  newnode7->value = 6;
  newnode7->next = NULL;

  List * newnode8 = new List();
  newnode8->value = 7;
  newnode8->next = NULL;

  head = newnode1;
  newnode1->next = newnode2;
  newnode2->next = newnode3;
  newnode3->next = newnode4;
  newnode4->next = newnode5;
  newnode5->next = newnode6;
  newnode6->next = newnode7;
  newnode7->next = newnode8;
  return head;
}

List * findNode(List * head, int value)
{
  if(head == NULL){
    return NULL;
  }
  List * cur = head;
  while(cur != NULL){
    if(cur->value == value){
      return cur;
    }
    cur = cur->next;
  }
}

bool delNode(List * head, List * node)
{
  if(head == NULL){
    return false;
  }
  List * next = node->next;
  int tmp = node->value;
  node->value = next->value;
  next->value = tmp;
  node->next = next->next;
  delete next;
  next = NULL;
  return true;
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

int main(int argc, char ** argv)
{
  List * head = NULL;
  head = createList(head);
  List * node = findNode(head, 4);
  delNode(head, node);
  listWalk(head);
  system("pause");
  return 0;
}
#endif

#if 0
/*
copyright@nciaebupt ת����ע������
����������������ͷ��㣬ɾ�������е�����k����㡣
ʹ�������ڵ�p1,p2��p1��ʼ��ָ��ͷ��㣬p2һֱָ��p1���k���ڵ㣬�������ƽ��
����ƶ�ֱ��p2��������β��(NULL),Ȼ�����p1ɾ����Ӧ��㡣
*/
#include <cstdlib>
#include <iostream>


struct List{
  int value;
  List * next;
};

List * createList(List * head)
{
  List * newnode1 = new List();
  newnode1->value = 0;
  newnode1->next = NULL;

  List * newnode2 = new List();
  newnode2->value = 1;
  newnode2->next = NULL;

  List * newnode3 = new List();
  newnode3->value = 2;
  newnode3->next = NULL;

  List * newnode4 = new List();
  newnode4->value = 3;
  newnode4->next = NULL;

  List * newnode5 = new List();
  newnode5->value = 4;
  newnode5->next = NULL;

  List * newnode6 = new List();
  newnode6->value = 5;
  newnode6->next = NULL;

  List * newnode7 = new List();
  newnode7->value = 6;
  newnode7->next = NULL;

  List * newnode8 = new List();
  newnode8->value = 7;
  newnode8->next = NULL;

  head = newnode1;
  newnode1->next = newnode2;
  newnode2->next = newnode3;
  newnode3->next = newnode4;
  newnode4->next = newnode5;
  newnode5->next = newnode6;
  newnode6->next = newnode7;
  newnode7->next = newnode8;
  return head;
}

bool delTheLastKNode(List * head, int k)
{
  if(head == NULL || k < 1){
    return false;
  }
  List * cur = head;
  List * fast = head;
  int i = 0;
  while(fast != NULL && i <= k){
    fast = fast->next;
    i++;
  }
  if(fast == NULL){
    return false;
  }
  while(fast != NULL){
    cur = cur->next;
    fast = fast->next;
  }
  List * del = cur->next;
  cur->next = del->next;
  delete del;
  del = NULL;
  return true;
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

int main(int argc, char ** argv)
{
  List * head = NULL;
  head = createList(head);
  delTheLastKNode(head, 3);
  listWalk(head);
  system("pause");
  return 0;
}
#endif
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ����������
�����������������ʹ�ù鲢�����㷨�������򡢿���������Щ����������ʱ���ܷǳ��õ��㷨��������ֻ�ܨD˳����ʵ�ħ�����޷�ʩչ���������ǹ鲢����ȴ�����ˮ���ǵ���������
O(nlogn)��ʱ�临�Ӷȣ������������������й���ڸ���Ŀռ临�Ӷ�������������Ҳ��O(n)
������O(1)���鲢��������divide and conquer��
*/
#include <cstdlib>
#include <iostream>

struct List{
  int value;
  List * next;
};

List * createList(List * head)
{
  List * newnode1 = new List();
  newnode1->value = 0;
  newnode1->next = NULL;

  List * newnode2 = new List();
  newnode2->value = 7;
  newnode2->next = NULL;

  List * newnode3 = new List();
  newnode3->value = 5;
  newnode3->next = NULL;

  List * newnode4 = new List();
  newnode4->value = 3;
  newnode4->next = NULL;

  List * newnode5 = new List();
  newnode5->value = 2;
  newnode5->next = NULL;

  List * newnode6 = new List();
  newnode6->value = 6;
  newnode6->next = NULL;

  List * newnode7 = new List();
  newnode7->value = 1;
  newnode7->next = NULL;

  List * newnode8 = new List();
  newnode8->value = 4;
  newnode8->next = NULL;

  head = newnode1;
  newnode1->next = newnode2;
  newnode2->next = newnode3;
  newnode3->next = newnode4;
  newnode4->next = newnode5;
  newnode5->next = newnode6;
  newnode6->next = newnode7;
  newnode7->next = newnode8;
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

List * mergeList(List * head1, List * head2)
{
  if(head1 == NULL && head2 == NULL){
    return NULL;
  }
  if(head1 == NULL){
    return head2;
  }
  if(head2 == NULL){
    return head1;
  }
  List * head = NULL;
  List * lastNode = NULL;
  while(head1 != NULL && head2 != NULL){
    if(lastNode == NULL){
      if(head1->value < head2->value){
        head = head1;
        lastNode = head1;
        head1 = head1->next;
      }
      else{
        head = head2;
        lastNode = head2;
        head2 = head2->next;
      }
    }
    else{
      if(head1->value < head2->value){
        lastNode->next = head1;
        lastNode = head1;
        head1 = head1->next;
      }
      else{
        lastNode->next = head2;
        lastNode = head2;
        head2 = head2->next;
      }
    }
  }
  if(head1 != NULL){
    lastNode->next = head1;
  }
  if(head2 != NULL){
    lastNode->next = head2;
  }
  return head;
}

List * listSort(List * head)
{
  if(head == NULL){
    return NULL;
  }
  List * slow = head;
  List * fast = head;
  List * r_head = head;
  while(fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  if(slow->next == NULL){//only one node
    return r_head;
  }
  fast = slow->next;
  slow->next = NULL;
  slow = head;
  r_head = mergeList(listSort(slow), listSort(fast));
  return r_head;
}

int main(int argc, char ** argv)
{
  List * head = NULL;
  head = createList(head);
  //listWalk(head);
  head = listSort(head);
  listWalk(head);
  system("pause");
  return 0;
}

#endif
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ����ת������
�������ݹ�ǵݹ�
*/
#include <cstdlib>
#include <iostream>

struct List{
  int value;
  List * next;
};

List * createList(List * head)
{
  List * newnode1 = new List();
  newnode1->value = 0;
  newnode1->next = NULL;

  List * newnode2 = new List();
  newnode2->value = 1;
  newnode2->next = NULL;

  List * newnode3 = new List();
  newnode3->value = 2;
  newnode3->next = NULL;

  List * newnode4 = new List();
  newnode4->value = 3;
  newnode4->next = NULL;

  List * newnode5 = new List();
  newnode5->value = 4;
  newnode5->next = NULL;

  List * newnode6 = new List();
  newnode6->value = 5;
  newnode6->next = NULL;

  List * newnode7 = new List();
  newnode7->value = 6;
  newnode7->next = NULL;

  List * newnode8 = new List();
  newnode8->value = 7;
  newnode8->next = NULL;

  head = newnode1;
  newnode1->next = newnode2;
  newnode2->next = newnode3;
  newnode3->next = newnode4;
  newnode4->next = newnode5;
  newnode5->next = newnode6;
  newnode6->next = newnode7;
  newnode7->next = newnode8;
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

List * reverseListRecursion(List * p, List *& head)
{
  //List * newhead = NULL;
  if(p->next == NULL){//the last node
    head = p;
    return p;
  }
  List * cur = reverseListRecursion(p->next, head);
  cur->next = p;
  p->next = NULL;
  return p;

}

List * reverseList(List * head)
{
  if(head == NULL){
    return NULL;
  }
  List * cur = head;
  head = NULL;
  while(cur != NULL){
    List * tmp = cur;
    cur = cur->next;
    tmp->next = head;
    head = tmp;
  }
  return head;
}

int main(int argc, char ** argv)
{
  List * head = NULL;
  head = createList(head);
  //listWalk(head);
  List * newhead = NULL;
  reverseListRecursion(head, head);
  //head = reverseList(head);
  listWalk(head);
  system("pause");
  return 0;
}
#endif






