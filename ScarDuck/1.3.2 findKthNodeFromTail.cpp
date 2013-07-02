
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入一个单向链表，输出该链表中倒数第k个结点。链表的倒数第0个结点为链表的
尾指针。链表结点定义如下：
struct ListNode
{
int value;
ListNode* next;
};
分析：如果我们在遍历时维持两个指针，第一个指针从链表的头指针开始遍历，在第k-1步之前，
第二个指针保持不动；在第k-1步开始，第二个指针也开始从链表的头指针开始遍历。由于
两个指针的距离保持在k-1，当第一个（走在前面的）指针到达链表的尾结点时，第二个指
针（走在后面的）指针正好是倒数第k个结点
*/
#include <cstdlib>
#include <iostream>

struct ListNode
{
    int value;
    ListNode * next;
};

ListNode * appendList(ListNode * head,int value)
{
    //创建新的节点并初始化
    ListNode *pNode = new ListNode();
    pNode->value = value;
    pNode->next = NULL;
    if(head == NULL)
    {
        head = pNode;
    }
    else
    {
        pNode->next=head;
        head = pNode;
    }
    return head;
}

int getKthNode(ListNode * pHead,int n)
{
    ListNode * pCur = pHead;
    ListNode * pKth = pHead;
    int cnt = 0;
    while(pCur != NULL)
    {
        if(cnt >= n)
        {
            pKth = pKth->next;
        }
        cnt++;
        pCur = pCur->next;
    }
    if(pKth != NULL)
        return pKth->value;
}

int main(int args,char ** argv)
{
    int array[] = {1,2,4,7,11,15};
    int array_len = sizeof(array)/sizeof(int);
    ListNode *pHead = NULL;
    for(int i = 0;i < array_len; ++i)
    {
        pHead = appendList(pHead,array[i]);
    }
    ListNode *pCur = pHead;
    while(pCur != NULL)
    {
        std::cout<<pCur->value<<std::endl;
        pCur = pCur->next;
    }
    int n = 3;
    std::cout<<getKthNode(pHead,n)<<std::endl;
    system("pause");
    return 0;
}
#endif
