#if 0
/*
*copyright@nciaebupt ת����ע������
*���⣺����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������
*Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��
*4=6=8=10=12=14=16
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct BSTreeNode
{
    int value;
    BSTreeNode * left;
    BSTreeNode * right;
};

BSTreeNode * pListHead = NULL;//����˫�������ͷָ�룬ָ��˫�����ͷ
BSTreeNode * pListTail = NULL;//����˫�������βָ�룬ָ��˫�����β

BSTreeNode *
BSTreeInsert(BSTreeNode * pRoot,int value)
{
    //Ϊ�½ڵ�����ռ䲢��ʼ��
    BSTreeNode *pNode = new BSTreeNode();
    if(pNode != NULL)
    {
        pNode->value = value;
        pNode->left = NULL;
        pNode->right = NULL;
    }
    else
    {   cout<<"�����ڴ�ʧ�ܣ�"<<endl;}

    BSTreeNode * pCur = pRoot;//�ƶ�ָ�룬�����ҵ���ǰ�ڵ�Ҫ�����λ��
    BSTreeNode * pParent = NULL;//�ƶ�ָ����ʼ��ָ��pCur�Ľڵ�ĸ��ڵ�

    if(pRoot == NULL)//��ǰ��Ϊ����ʱ
    {
        pRoot = pNode;
    }
    else//��ǰ����Ϊ����ʱ
    {
        while(pCur != NULL)//���ҵ�ǰ�ڵ��ڶ����������Ӧ�ò����λ�ã�pCurָ��Ӧ�ò����λ�ã�pParentָ��Ӧ�ò����λ�õĸ��ڵ�
        {
            pParent = pCur;
            if(pCur->value <= pNode->value)
            {
                pCur = pCur->right;
            }
            else
            {
                pCur = pCur->left;
            }
        }
        if(pNode->value <= pParent->value)
        {
            pParent->left = pNode;
        }
        else
        {
            pParent->right = pNode;
        }
    }
    return pRoot;
}

void BSTree2List(BSTreeNode * pCur)
{
    if(pCur == NULL)
        return;
    if(pListHead == NULL)//˫����ͷָ��ָ��NULL����ʱ˫������δ������ʹpHeadָ��pCur
    {
        pListHead = pCur;
        pListTail = pCur;
        pCur->left = NULL;
    }
    else
    {
        pListTail->right = pCur;
        pCur->left = pListTail;
        pListTail = pCur;
    }
}

void
InOrderBSTree(BSTreeNode * pRoot)
{
    BSTreeNode * pCur = pRoot;
    if(pCur != NULL)
    {
        InOrderBSTree(pCur->left);
        //�����������ǰ�ڵ����ӵ�˫��������
        BSTree2List(pCur);
        InOrderBSTree(pCur->right);
    }
}

void
BSTreeNodeDestory(BSTreeNode * pListHead)
{
    BSTreeNode *pCur = pListHead;
    pListHead = NULL;
    while(pCur != NULL)
    {
        BSTreeNode * pDel = pCur;
        pCur = pCur->left;
        delete pCur;
        pCur = NULL;
    }
}
int
main(int args,char ** argv)
{
    int array[] = {6,8,4,14,16,10,12};
    int len = sizeof(array)/sizeof(int);

    BSTreeNode * pRoot = NULL;//����������������ڵ�
    //�������������
    //���������е�ÿ��Ԫ�أ���ÿ��Ԫ����Ϊһ�����ڵ㣬���뵽�����������
    for(int i = 0;i < len;++i)
    {
        cout<<array[i]<<"  ";
        pRoot = BSTreeInsert(pRoot,array[i]);
    }
    cout<<endl;
    //����������������
    InOrderBSTree(pRoot);
    //��ӡ˫������
    BSTreeNode *pCur = pListHead;
    while(pCur != NULL)
    {
        cout<<pCur->value<<"  ";
        pCur = pCur->right;
    }
    cout<<endl;
    //����˫������
    BSTreeNodeDestory(pListHead);

    system("pause");
    return 0;
}
#endif
