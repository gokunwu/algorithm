
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ������һ��������������������е�����k����㡣����ĵ�����0�����Ϊ�����
βָ�롣�����㶨�����£�
struct ListNode
{
int value;
ListNode* next;
};
��������������ڱ���ʱά������ָ�룬��һ��ָ��������ͷָ�뿪ʼ�������ڵ�k-1��֮ǰ��
�ڶ���ָ�뱣�ֲ������ڵ�k-1����ʼ���ڶ���ָ��Ҳ��ʼ�������ͷָ�뿪ʼ����������
����ָ��ľ��뱣����k-1������һ��������ǰ��ģ�ָ�뵽�������β���ʱ���ڶ���ָ
�루���ں���ģ�ָ�������ǵ�����k�����
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
    //�����µĽڵ㲢��ʼ��
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
