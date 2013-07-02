#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入一颗二元树，从上往下按层打印树的每个结点，同一层中按照从
左往右的顺序打印。
例如输入
8
/ \
6 10
/\ /\
5 7 9 11
输出8 6 10 5 7 9 11。
思路：
广度优先遍历
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
    //创建新节点并初始化
    BSTreeNode * pNode = new BSTreeNode;
    if(pNode != NULL)
    {
        pNode->value = value;
        pNode->left = NULL;
        pNode->right = NULL;
    }
    else
    {
        std::cout<<"内存申请失败"<<std::endl;
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
    //创建二叉查找树
    BSTreeNode * pRoot = NULL;
    for(int i = 0;i < len;++i)
    {
        pRoot = InsertBSTree(pRoot,array[i]);
    }
    //层次遍历二叉树
    visitByLevel(pRoot);

    system("pause");
    return 0;
}
#endif






