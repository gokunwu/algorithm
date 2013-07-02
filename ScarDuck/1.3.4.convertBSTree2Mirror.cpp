
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入一颗二元查找树，将该树转换为它的镜像，即在转换后的二元查找树中，左子树的结点都大于右子树的结点。 用递归和循环两种方法完成树的镜像转换。
例如：
        8                     8
      /   \       转换       /   \
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

//创建二叉查找树
BSTreeNode * InsertBSTree(BSTreeNode * pRoot,int value)
{
    //创建节点并初始化
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
//中序遍历二叉树
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
//将二叉查找树转换为它的镜像，递归实现
void BSTree2MirrorRcur(BSTreeNode * pRoot)
{
    if(pRoot == NULL)
    {
        return;
    }
    //交换指针
    BSTreeNode * tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    //递归左子树
    if(pRoot->left != NULL)
    {
        BSTree2MirrorRcur(pRoot->left);
    }
    //递归右子树
    if(pRoot->right != NULL)
    {
        BSTree2MirrorRcur(pRoot->right);
    }
}
//将二叉查找树转换为它的镜像，循环实现
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
    //创建二叉查找树
    BSTreeNode * pRoot = NULL;
    for(int i = 0;i < len;++i)
    {
        pRoot = InsertBSTree(pRoot,array[i]);
    }
    //中序遍历二叉树
    InOrderBSTree(pRoot);
    //将二叉查找树转换为它的镜像，递归实现
    //BSTree2MirrorRcur(pRoot);
    //中序遍历二叉树
    //InOrderBSTree(pRoot);
    //将二叉查找树转换为它的镜像，循环实现
    BSTree2Mirror(pRoot);
    //中序遍历二叉树
    InOrderBSTree(pRoot);

    system("pause");
    return 0;
}
#endif
