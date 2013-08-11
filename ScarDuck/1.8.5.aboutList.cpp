#if 0
/*
copyright@nciaebupt 转载请注明出处
题一、给定单链表，检测是否有环。
使用两个指针p1,p2从链表头开始遍历，p1每次前进一步，p2每次前进两步。如果p2到达
链表尾部，说明无环，否则p1、p2必然会在某个时刻相遇(p1==p2)，从而检测到链表中有
环。
http://ostermiller.org/find_loop_singly_linked_list.html
这篇文章讲了很多好的坏得相关算法。
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
copyright@nciaebupt 转载请注明出处
题二、  给定两个单链表(head1, head2)，检测两个链表是否有交点，如果有返回第一个交点。
如果head1==head2，那么显然相交，直接返回head1。
否则，分别从head1,head2开始遍历两个链表获得其长度len1 与len2。假设len1>=len2，那
么指针p1由head1开s始向后移动len1-len2 步。指针p2=head2，下面p1、p2每次向后前进
一步并比较p1p2是否相等，如果相等即返回该结点，否则说明两个链表没有交点。
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
copyright@nciaebupt 转载请注明出处
题目：给定单链表(head)，如果有环的话请返回从头结点进入环的第一个节点。
当fast若与slow相遇时，slow肯定没有走遍历完链表，而fast已经在环内循环了n圈(1<=n)。
假设slow走了s步，则fast走了2s步（fast步数还等于s 加上在环上多转的n圈），设环长为r，则：
2s = s + nr
s= nr
设入口环与相遇点距离为x，x<r，起点到环入口点的距离为a.
a = s - x = (n-1)r+ (r-x), 而r-x即为fast再次到环入口点时的步数
由此可知，从链表头到环入口点等于(n-1)循环内环+相遇点到环入口点，于是我们从链表头、与相遇点分别设一个指针，每次各走一步，两个指针必定相遇，且相遇第一点为环入口点。
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
copyright@nciaebupt 转载请注明出处
题目：只给定单链表中某个结点p(并非最后一个结点，即p->next!=NULL)指针，删除该结
点。
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
copyright@nciaebupt 转载请注明出处
题六、给定单链表头结点，删除链表中倒数第k个结点。
使用两个节点p1,p2，p1初始化指向头结点，p2一直指向p1后第k个节点，两个结点平行
向后移动直到p2到达链表尾部(NULL),然后根据p1删除对应结点。
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
copyright@nciaebupt 转载请注明出处
题目：链表排序
分析：链表排序最好使用归并排序算法。堆排序、快速排序这些在数组排序时性能非常好的算法，在链表只能―顺序访问的魔咒下无法施展能力；但是归并排序却如鱼得水，非但保持了它
O(nlogn)的时间复杂度，而且它在数组排序中广受诟病的空间复杂度在链表排序中也从O(n)
降到了O(1)。归并排序又是divide and conquer。
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
copyright@nciaebupt 转载请注明出处
题目：倒转单链表
分析：递归非递归
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






