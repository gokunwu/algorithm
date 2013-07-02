#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ������һ�Ŷ�Ԫ�����������°����ӡ����ÿ����㣬ͬһ���а��մ�
�����ҵ�˳���ӡ��
��������
8
/ \
6 10
/\ /\
5 7 9 11
���8 6 10 5 7 9 11��
˼·��
������ȱ���
*/
#include <cstdlib>
#include <iostream>
#include <queue>

struct BSTreeNode
{
    int value;
    BSTreeNode * left;
    BSTreeNode * right;
};
BSTreeNode * InsertBSTree(BSTreeNode * pRoot,int value)
{
    //�����½ڵ㲢��ʼ��
    BSTreeNode * pNode = new BSTreeNode;
    if(pNode != NULL)
    {
        pNode->value = value;
        pNode->left = NULL;
        pNode->right = NULL;
    }
    else
    {
        std::cout<<"�ڴ�����ʧ��"<<std::endl;
    }
    BSTreeNode * pCur = pRoot;
    BSTreeNode * pParent = NULL;
    if(pRoot == NULL)
    {
        pRoot = pNode;
    }
    else
    {
        while(pCur != NULL)
        {
            pParent = pCur;
            if(value < pCur->value)
                pCur = pCur->left;
            else
                pCur = pCur->right;
        }
        if(value < pParent->value)
            pParent->left = pNode;
        else
            pParent->right = pNode;
    }
    return pRoot;
}
void visitByLevel(BSTreeNode * pRoot)
{
    if(pRoot == NULL)
        return;
    BSTreeNode * pCur = pRoot;
    //std::queue<BSTreeNode *> que;
    std::queue<BSTreeNode *> que;
    que.push(pCur);
    while(!que.empty())
    {
        pCur = que.front();
        que.pop();
        std::cout<<pCur->value<<std::endl;
        if(pCur->left != NULL)
            que.push(pCur->left);
        if(pCur->right != NULL)
            que.push(pCur->right);
    }
}


int main(int args,char ** argv)
{
    int array[] = {8,6,10,5,7,9,11};
    int len = sizeof(array)/sizeof(int);
    //�������������
    BSTreeNode * pRoot = NULL;
    for(int i = 0;i < len;++i)
    {
        pRoot = InsertBSTree(pRoot,array[i]);
    }
    //��α���������
    visitByLevel(pRoot);

    system("pause");
    return 0;
}
#endif






