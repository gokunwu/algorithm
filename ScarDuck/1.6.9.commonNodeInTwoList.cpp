#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：两个单向链表，找出它们的第一个公共结点。
链表的结点定义为：
struct ListNode
{
       int            m_n Key ;
       ListNode *     m_pNe xt ;


};
分析：这是一道微软的面试题。微软非常喜欢与链表相关的题目，因此在微软的面试题中，链表出现的概
率相当高。
如果两个单向链表有公共的结点，也就是说两个链表从某一结点开始，它们的  m_pNext 都指向同一个结
点。但由于是单向链表的结点，每个结点只有一个  m_pNext ，因此从第一个公共结点开始，之后它们所
有结点都是重合的，不可能再出现分叉。所以，两个有公共结点而部分重合的链表，拓扑形状看起来像一
个  Y ，而不可能像  X 。
看到这个题目，第一反应就是蛮力法：在第一链表上顺序遍历每个结点。每遍历一个结点的时候，在第二
个链表上顺序遍历每个结点。如果此时两个链表上的结点是一样的，说明此时两个链表重合，于是找到了
它们的公共结点。如果第一个链表的长度为  m ，第二个链表的长度为  n ，显然，该方法的时间复杂度为
O(mn) 。
接  下来我们试着去寻找一个线性时间复杂度的算法。我们先把问题简化：如何判断两个单向链表有没有公
共结点？前面已经提到，如果两个链表有一个公共结点，那么  该公共结点之后的所有结点都是重合的。那
么，它们的最后一个结点必然是重合的。因此，我们判断两个链表是不是有重合的部分，只要分别遍历两
个链表到最后一个结点。如果两个尾结点是一样的，说明它们用重合；否则两个链表没有公共的结点。
在上面的思路中，顺序遍历两个链表到尾结点的时候，我们不能保证在两个链表上同时到达尾结点。这是
因为两个链表不一定长度一样。但如果假设一个链表比另一个长  l  个结点，我们先在长的链表上遍历  l  个
结点，之后再同步遍历，这个时候我们就能保证同时到达最后一个结点了。由于两个链表从第一个公共结
点考试到链表的尾结点，这一部分是重合的。因此，它们肯定也是同时到达第一公共结点的。于是在遍历
中，第一个相同的结点就是第一个公共的结点。
在这个思路中，我们先要分别遍历两个链表得到它们的长度，并求出两个长度之差。在长的链表上先遍历
若干次之后，再同步遍历两个链表，知道找到相同的结点，或者一直到链表结束。此时，如果第一个链表
的长度为  m ，第二个链表的长度为  n ，该方法的时间复杂度为  O(m+n) 。
*/
#include <cstdlib>
#include <iostream>

struct ListNode{
  int m_nKey;
  ListNode * m_pNext;
};

void createCrossList(int * arr1, int len1, int * arr2, int len2, ListNode ** head1, ListNode ** head2){
  if(arr1 == NULL || len1 < 1 || arr2 == NULL || len2 < 1)  return;
  for(int i = 0; i < len1; ++i){
    ListNode * newnode = new ListNode;
    newnode->m_nKey = arr1[i];
    newnode->m_pNext = NULL;
    if(*head1 == NULL){
      *head1 = newnode;
    }
    else{
      newnode->m_pNext = *head1;
      *head1 = newnode;
    }
  }
  for(int i = 0; i<len2; ++i){
    ListNode * newnode = new ListNode;
    newnode->m_nKey = arr2[i];
    newnode->m_pNext = NULL;
    if(*head2 == NULL){
      *head2 = newnode;
    }
    else{
      newnode->m_pNext = *head2;
      *head2 = newnode;
    }
  }
  ListNode * cur1 = *head1;
  ListNode * cur1pre = *head1;
  while(cur1 != NULL){
    ListNode * cur2 = *head2;
    int flag = 0;
    while(cur2 != NULL){
      if(cur1->m_nKey == cur2->m_nKey){
        cur1pre->m_pNext = cur2;
        flag = 1;
        break;
      }
      else{
        cur2 = cur2->m_pNext;
      }
    }
    if(flag == 1){
      break;
    }
    cur1pre = cur1;
    cur1 = cur1->m_pNext;
  }
}

int commonNodeInCrossList(ListNode ** head1, ListNode ** head2){
  if(*head1 == NULL || *head2 == NULL){
    return -100;
  }
  int list1len = 0;
  int list2len = 0;
  ListNode * cur1 = *head1;
  ListNode * cur2 = *head2;
  while(cur1 != NULL){
    list1len++;
    cur1 = cur1->m_pNext;
  }
  while(cur2 != NULL){
    list2len++;
    cur2 = cur2->m_pNext;
  }
  //std::cout<<list1len<<std::endl;
  //std::cout<<list2len<<std::endl;
  int lendiff = 0;
  if(list1len > list2len){
    lendiff = list1len - list2len;
    cur1 = *head1;
    cur2 = *head2;
  }
  else{
    lendiff = list2len - list1len;
    cur1 = *head2;
    cur2 = *head1;
  }
  int i = 1;
  while(i <= lendiff){
    cur1 = cur1->m_pNext;
    i++;
  }
  while(cur1 != NULL && cur2 != NULL){
    if(cur1->m_nKey == cur2->m_nKey){
      return cur1->m_nKey;
    }
    cur1 = cur1->m_pNext;
    cur2 = cur2->m_pNext;
  }
}

void listTraverse(ListNode ** head){
  if(*head == NULL) return;
  ListNode * cur = *head;
  while(cur != NULL){
    std::cout<<cur->m_nKey<<" ";
    cur = cur->m_pNext;
  }
  std::cout<<std::endl;
}

int main(int argc, char ** argv){
  int arr1[] = {9,8,7,6,4,2,0,-2};
  int len1 = sizeof(arr1)/sizeof(int);
  int arr2[] = {9,8,7,5,3,1};
  int len2 = sizeof(arr2)/sizeof(int);
  ListNode * head1 = NULL;
  ListNode * head2 = NULL;

  createCrossList(arr1, len1, arr2, len2, &head1, &head2);
  listTraverse(&head1);
  int commonNum = commonNodeInCrossList(&head1, &head2);
  std::cout<<"num : "<<commonNum<<std::endl;


  system("pause");
  return 0;
}

#endif
