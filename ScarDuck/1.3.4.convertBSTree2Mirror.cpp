
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ������һ�Ŷ�Ԫ��������������ת��Ϊ���ľ��񣬼���ת����Ķ�Ԫ�������У��������Ľ�㶼�����������Ľ�㡣 �õݹ��ѭ�����ַ���������ľ���ת����
���磺
        8                     8
      /   \       ת��       /   \
     6     10     -->      10    6
    /  \   / \            /  \   / \
   5    7 9   11         11   9 7   5
*/
#include <cstdlib>
#include <iostream>
#include <stack>

struct BSTreeNode
{
    int value;
    int flag;
    BSTreeNode * left;
    BSTreeNode * right;
};

//�������������
BSTreeNode * InsertBSTree(BSTreeNode * pRoot,int value)
{
    //�����ڵ㲢��ʼ��
    BSTreeNode * pNode = new BSTreeNode();
    pNode->value = value;
    pNode->flag = 0;
    pNode->left = NULL;
    pNode->right = NULL;

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
//�������������
void InOrderBSTree1(BSTreeNode * pRoot)
{
    BSTreeNode * pCur = pRoot;
    if(pCur != NULL)
    {
        InOrderBSTree1(pCur->left);
        std::cout<<pCur->value<<std::endl;
        InOrderBSTree1(pCur->right);
    }
}
void InOrderBSTree(BSTreeNode * pRoot)
{
    BSTreeNode cur = *pRoot;
    std::stack<BSTreeNode> stack;
    stack.push(cur);

    while(!stack.empty())
    {
        if(stack.top().flag == 0)
        {
            stack.top().flag = 1;
            if(stack.top().left != NULL)
            {
                stack.push(*(stack.top().left));
            }
        }
        else
        {
            std::cout<<stack.top().value<<std::endl;
            BSTreeNode tmp = stack.top();
            stack.pop();
            if(tmp.right != NULL)
            {
                stack.push(*(tmp.right));
            }
        }
    }
}
//�����������ת��Ϊ���ľ��񣬵ݹ�ʵ��
void BSTree2MirrorRcur(BSTreeNode * pRoot)
{
    if(pRoot == NULL)
    {
        return;
    }
    //����ָ��
    BSTreeNode * tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    //�ݹ�������
    if(pRoot->left != NULL)
    {
        BSTree2MirrorRcur(pRoot->left);
    }
    //�ݹ�������
    if(pRoot->right != NULL)
    {
        BSTree2MirrorRcur(pRoot->right);
    }
}
//�����������ת��Ϊ���ľ���ѭ��ʵ��
void BSTree2Mirror(BSTreeNode * pRoot)
{
    if(pRoot == NULL)
        return;
    std::stack<BSTreeNode*> pStack;
    BSTreeNode * pCur = pRoot;
    BSTreeNode * pTmp = NULL;
    pStack.push(pCur);
    while(!pStack.empty())
    {
        pCur = pStack.top();
        pStack.pop();
        pTmp = pCur->left;
        pCur->left = pCur->right;
        pCur->right = pTmp;
        if(pCur->left != NULL)
            pStack.push(pCur->left);
        if(pCur->right != NULL)
            pStack.push(pCur->right);
    }
}

int main(int args,char **argv)
{
    int array[] = {8,6,10,5,7,9,11};
    int len = sizeof(array)/sizeof(int);
    //�������������
    BSTreeNode * pRoot = NULL;
    for(int i = 0;i < len;++i)
    {
        pRoot = InsertBSTree(pRoot,array[i]);
    }
    //�������������
    InOrderBSTree(pRoot);
    //�����������ת��Ϊ���ľ��񣬵ݹ�ʵ��
    //BSTree2MirrorRcur(pRoot);
    //�������������
    //InOrderBSTree(pRoot);
    //�����������ת��Ϊ���ľ���ѭ��ʵ��
    BSTree2Mirror(pRoot);
    //�������������
    InOrderBSTree(pRoot);

    system("pause");
    return 0;
}
#endif
