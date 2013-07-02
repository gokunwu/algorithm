
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ��������ǰѶ���������һ��ͼ�����ӽڵ�֮������߿�����˫��ģ����ǹ��Ҷ���D����Ϊ�����ڵ�֮��ߵĸ�����дһ��������һ�Ŷ������������Զ�������ڵ�֮��ľ��롣
*/
#include <cstdlib>
#include <iostream>
using namespace std;

struct BTree
{
    BTree * left;//ָ������
    BTree * right;//ָ���Һ���
    int nMaxLeft;//�������е������
    int nMaxRight;//�������е������
    int value;
};

int nMaxLen = 0;
//�������������
BTree * InsertBTree(BTree * pRoot,int value)
{
    //�����ڵ㲢��ʼ��
    BTree * pNode = new BTree();
    if(pNode != NULL)
    {
        pNode->left=NULL;
        pNode->right = NULL;
        pNode->value = value;
        pNode->nMaxLeft = 0;
        pNode->nMaxRight = 0;
    }
    BTree * pCur = pRoot;//�ָ�룬�������ҵ�ǰ�ڵ�Ҫ�����λ��
    BTree * pParent = NULL;//ʼ��ָ��pCur�ĸ��ڵ�
    if(pRoot == NULL)//��ǰ��Ϊ����
    {
        pRoot = pNode;
    }
    else//��ǰ����Ϊ����
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
//��������нڵ��������
void MaxLenInBTree(BTree *pRoot)
{
    //������Ҷ�ӽڵ㣬����
    if(pRoot == NULL)
        return;
    //��������Ϊ�գ����������������Ϊ0
    if(pRoot->left == NULL)
        pRoot->nMaxLeft = 0;
    //��������Ϊ�գ����������������Ϊ0
    if(pRoot->right == NULL)
        pRoot->nMaxRight = 0;
    //����������Ϊ�գ���ݹ�����������нڵ��������
    if(pRoot->left != NULL)
        MaxLenInBTree(pRoot->left);
    //����������Ϊ�գ���ݹ�����������нڵ��������
    if(pRoot->right != NULL)
        MaxLenInBTree(pRoot->right);
    //������������ڵ����
    if(pRoot->left != NULL)
    {
        int tmp = 0;
        if(pRoot->left->nMaxLeft > pRoot->left->nMaxRight)
            tmp = pRoot->left->nMaxLeft;
        else
            tmp = pRoot->left->nMaxRight;
        pRoot->nMaxLeft = tmp + 1;
    }
    //������������ڵ����
    if(pRoot->right != NULL)
    {
        int tmp = 0;
        if(pRoot->right->nMaxLeft > pRoot->right->nMaxRight)
            tmp = pRoot->right->nMaxLeft;
        else
            tmp = pRoot->right->nMaxRight;
        pRoot->nMaxRight = tmp + 1;
    }
    //���¶������нڵ��������
    if(pRoot->nMaxLeft + pRoot->nMaxRight > nMaxLen)
        nMaxLen = pRoot->nMaxLeft + pRoot->nMaxRight;

}

int main(int args,char **argv)
{
    int array[] = {5,3,8,2,4,1,6,9,7};
    //int array[] = {15,10,8,11,6,12};
    int len = sizeof(array)/sizeof(int);
    //�������������
    BTree *pRoot = NULL;
    for(int i = 0;i < len;++i)
    {
        pRoot = InsertBTree(pRoot,array[i]);
    }
    //��������нڵ��������
    MaxLenInBTree(pRoot);
    cout<<nMaxLen<<endl;

    system("pause");
    return 0;
}
#endif












