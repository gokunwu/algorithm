

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*题目：输入一个整数和一棵二元树。从树的根结点开始往下访问一直到叶结点所经过的
*所有结点形成一条路径。打印出和与输入整数相等的所有路径。
*例如输入整数22和如下二元树
*
                                            10
                                           /   \
                                          5     12
                                        /   \
                                     　4     7
*则打印出两条路径：10, 12和10, 5, 7。
*分析：这是百度的一道笔试题，考查对树这种基本数据结构以及递归函数的理解。
*当访问到某一结点时，把该结点添加到路径上，并累加当前结点的值。
*如果当前结点为叶结点并且当前路径的和刚好等于输入的整数，则当前的路径符合要求，
*我们把它打印出来。如果当前结点不是叶结点，则继续访问它的子结点。
*当前结点访问结束后，递归函数将自动回到父结点。
*因此我们在函数退出之前要在路径上删除当前结点并减去当前结点的值，
*以确保返回父结点时路径刚好是根结点到父结点的路径。我们不难看出保存路径的数据结构
*实际上是一个栈结构，因为路径要与递归调用状态一致，而递归调用本质就是一个压栈和出栈的过程。
*/
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
struct BSTreeNode
{
    int value;
    BSTreeNode * left;
    BSTreeNode * right;
};

BSTreeNode *
InsertBSTree(BSTreeNode * pRoot,int value)
{
    BSTreeNode * pCur = pRoot;//活动指针，用来查找当前节点应该插入的位置
    BSTreeNode * pParent = NULL;//活动指针，始终指向pCur的父节点
    //创建新节点并初始化
    BSTreeNode * pNewNode = new BSTreeNode();
    if(pNewNode != NULL)
    {
        pNewNode->value = value;
        pNewNode->left = NULL;
        pNewNode->right = NULL;
    }
    //查找当前节点在树中应该插入的位置
    if(pRoot == NULL)//当树为空时，当前节点作为树的根节点
    {
        pRoot = pNewNode;
        //cout<<pNewNode->value<<endl;
    }
    else//当树为不空时，在树中查找应该插入的位置
    {
        while(pCur != NULL)
        {
            pParent = pCur;
            if(value <= pCur->value)
                pCur = pCur->left;
            else
                pCur = pCur->right;
        }
        if(value < pParent->value)
            pParent->left = pNewNode;
        else
            pParent->right = pNewNode;
        //cout<<value<<endl;
    }
    return pRoot;
}

void
sumOfPath(BSTreeNode * pNode,int sum,vector<int> & path_stack,int curSum)
{
    //如果当前节点为空则返回
    if(pNode == NULL)
        return;
    //将当前节点的值加到路径的和上，并将当前节点压栈
    curSum = curSum + pNode->value;
    path_stack.push_back(pNode->value);
    //判断加入当前节点后，当前路径是否为完整路径，路径上数值之和是否等于sum，若是则打印路径数值
    if((pNode->left == NULL) &&(pNode->right == NULL) && (curSum == sum))
    {
        for(int i = 0;i < path_stack.size();++i)
        {
            cout<<path_stack[i]<<" ";
        }
        cout<<endl;
    }
    //如果当前节点不是叶子节点，继续递归遍历它的字节点
    if(pNode->left)
        sumOfPath(pNode->left,sum,path_stack,curSum);
    if(pNode->right)
        sumOfPath(pNode->right,sum,path_stack,curSum);
    //当前路径遍历完成后，返回到当前的父节点继续遍历
    curSum = curSum - pNode->value;
    path_stack.pop_back();
}

void BSTreeDestroy(BSTreeNode * pNode)
{
    if(pNode->left != NULL)
        BSTreeDestroy(pNode->left);
    if(pNode->right != NULL)
        BSTreeDestroy(pNode->right);
    if(pNode != NULL)
    {
        delete pNode;
        pNode = NULL;
    }
}

int main(int args,char ** argv)
{
    int array[] = {10,5,12,4,7};
    int len = sizeof(array)/sizeof(int);
    vector<int> path_stack;
    int sum = 22;
    int curSum = 0;
    //构建二叉查找树
    BSTreeNode *pRoot = NULL;
    for(int i = 0;i < len;++i)
    {
        pRoot = InsertBSTree(pRoot,array[i]);
    }
    //遍历各个树枝计算每条路径上的节点的和
    sumOfPath(pRoot,sum,path_stack,curSum);
    //销毁二叉查找树
    BSTreeDestroy(pRoot);
    system("pause");
    return 0;
}

#endif













































