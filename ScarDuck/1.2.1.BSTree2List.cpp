#if 0
/*
*copyright@nciaebupt 转载请注明出处
*问题：输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
*要求不能创建任何新的结点，只调整指针的指向。
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

BSTreeNode * pListHead = NULL;//建立双向链表的头指针，指向双链表的头
BSTreeNode * pListTail = NULL;//建立双向链表的尾指针，指向双链表的尾

BSTreeNode *
BSTreeInsert(BSTreeNode * pRoot,int value)
{
    //为新节点申请空间并初始化
    BSTreeNode *pNode = new BSTreeNode();
    if(pNode != NULL)
    {
        pNode->value = value;
        pNode->left = NULL;
        pNode->right = NULL;
    }
    else
    {   cout<<"申请内存失败！"<<endl;}

    BSTreeNode * pCur = pRoot;//移动指针，用来找到当前节点要插入的位置
    BSTreeNode * pParent = NULL;//移动指正，始终指向pCur的节点的父节点

    if(pRoot == NULL)//当前树为空树时
    {
        pRoot = pNode;
    }
    else//当前树不为空树时
    {
        while(pCur != NULL)//查找当前节点在二叉查找树中应该插入的位置，pCur指向应该插入的位置，pParent指向应该插入的位置的父节点
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
    if(pListHead == NULL)//双链表头指针指向NULL，此时双链表尚未建立，使pHead指向pCur
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
        //二叉查找树当前节点链接到双向链表中
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

    BSTreeNode * pRoot = NULL;//建立二叉查找树根节点
    //建立二叉查找树
    //遍历数组中的每个元素，将每个元素作为一个树节点，插入到二叉查找树中
    for(int i = 0;i < len;++i)
    {
        cout<<array[i]<<"  ";
        pRoot = BSTreeInsert(pRoot,array[i]);
    }
    cout<<endl;
    //二叉查找树中序遍历
    InOrderBSTree(pRoot);
    //打印双向链表
    BSTreeNode *pCur = pListHead;
    while(pCur != NULL)
    {
        cout<<pCur->value<<"  ";
        pCur = pCur->right;
    }
    cout<<endl;
    //销毁双向链表
    BSTreeNodeDestory(pListHead);

    system("pause");
    return 0;
}
#endif
