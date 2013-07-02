
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：如果我们把二叉树看成一个图，父子节点之间的连线看成是双向的，我们姑且定义―距离为两个节点之间边的个数。写一个程序求一颗二叉树中相距最远的两个节点之间的距离。
*/
#include <cstdlib>
#include <iostream>
using namespace std;

struct BTree
{
    BTree * left;//指向左孩子
    BTree * right;//指向右孩子
    int nMaxLeft;//左子树中的最长距离
    int nMaxRight;//右子树中的最长距离
    int value;
};

int nMaxLen = 0;
//构建二叉查找树
BTree * InsertBTree(BTree * pRoot,int value)
{
    //创建节点并初始化
    BTree * pNode = new BTree();
    if(pNode != NULL)
    {
        pNode->left=NULL;
        pNode->right = NULL;
        pNode->value = value;
        pNode->nMaxLeft = 0;
        pNode->nMaxRight = 0;
    }
    BTree * pCur = pRoot;//活动指针，用来查找当前节点要插入的位置
    BTree * pParent = NULL;//始终指向pCur的父节点
    if(pRoot == NULL)//当前树为空树
    {
        pRoot = pNode;
    }
    else//当前树不为空树
    {
        while(pCur != NULL)
        {
            pParent = pCur;
            if(value <= pCur->value)
                pCur = pCur->left;
            else
                pCur = pCur->right;
        }
        if(value <= pParent->value)
            pParent->left = pNode;
        else
            pParent->right = pNode;
    }
    return pRoot;
}
//求二叉树中节点的最大距离
void MaxLenInBTree(BTree *pRoot)
{
    //遍历到叶子节点，返回
    if(pRoot == NULL)
        return;
    //若左子树为空，则左子树的最长距离为0
    if(pRoot->left == NULL)
        pRoot->nMaxLeft = 0;
    //若右子树为空，则右子树的最长距离为0
    if(pRoot->right == NULL)
        pRoot->nMaxRight = 0;
    //若左子树不为空，则递归计算左子树中节点的最大距离
    if(pRoot->left != NULL)
        MaxLenInBTree(pRoot->left);
    //若右子树不为空，则递归计算右子树中节点的最大距离
    if(pRoot->right != NULL)
        MaxLenInBTree(pRoot->right);
    //计算左子树最长节点距离
    if(pRoot->left != NULL)
    {
        int tmp = 0;
        if(pRoot->left->nMaxLeft > pRoot->left->nMaxRight)
            tmp = pRoot->left->nMaxLeft;
        else
            tmp = pRoot->left->nMaxRight;
        pRoot->nMaxLeft = tmp + 1;
    }
    //计算右子树最长节点距离
    if(pRoot->right != NULL)
    {
        int tmp = 0;
        if(pRoot->right->nMaxLeft > pRoot->right->nMaxRight)
            tmp = pRoot->right->nMaxLeft;
        else
            tmp = pRoot->right->nMaxRight;
        pRoot->nMaxRight = tmp + 1;
    }
    //更新二叉树中节点的最大距离
    if(pRoot->nMaxLeft + pRoot->nMaxRight > nMaxLen)
        nMaxLen = pRoot->nMaxLeft + pRoot->nMaxRight;

}

int main(int args,char **argv)
{
    int array[] = {5,3,8,2,4,1,6,9,7};
    //int array[] = {15,10,8,11,6,12};
    int len = sizeof(array)/sizeof(int);
    //构建二叉查找树
    BTree *pRoot = NULL;
    for(int i = 0;i < len;++i)
    {
        pRoot = InsertBTree(pRoot,array[i]);
    }
    //求二叉树中节点间的最长距离
    MaxLenInBTree(pRoot);
    cout<<nMaxLen<<endl;

    system("pause");
    return 0;
}
#endif












