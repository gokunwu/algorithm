

#if 0
/*
*copyright@nciaebupt ת����ע������
*��Ŀ������һ��������һ�ö�Ԫ���������ĸ���㿪ʼ���·���һֱ��Ҷ�����������
*���н���γ�һ��·������ӡ����������������ȵ�����·����
*������������22�����¶�Ԫ��
*
                                            10
                                           /   \
                                          5     12
                                        /   \
                                     ��4     7
*���ӡ������·����10, 12��10, 5, 7��
*���������ǰٶȵ�һ�������⣬����������ֻ������ݽṹ�Լ��ݹ麯������⡣
*�����ʵ�ĳһ���ʱ���Ѹý����ӵ�·���ϣ����ۼӵ�ǰ����ֵ��
*�����ǰ���ΪҶ��㲢�ҵ�ǰ·���ĺ͸պõ����������������ǰ��·������Ҫ��
*���ǰ�����ӡ�����������ǰ��㲻��Ҷ��㣬��������������ӽ�㡣
*��ǰ�����ʽ����󣬵ݹ麯�����Զ��ص�����㡣
*��������ں����˳�֮ǰҪ��·����ɾ����ǰ��㲢��ȥ��ǰ����ֵ��
*��ȷ�����ظ����ʱ·���պ��Ǹ���㵽������·�������ǲ��ѿ�������·�������ݽṹ
*ʵ������һ��ջ�ṹ����Ϊ·��Ҫ��ݹ����״̬һ�£����ݹ���ñ��ʾ���һ��ѹջ�ͳ�ջ�Ĺ��̡�
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
    BSTreeNode * pCur = pRoot;//�ָ�룬�������ҵ�ǰ�ڵ�Ӧ�ò����λ��
    BSTreeNode * pParent = NULL;//�ָ�룬ʼ��ָ��pCur�ĸ��ڵ�
    //�����½ڵ㲢��ʼ��
    BSTreeNode * pNewNode = new BSTreeNode();
    if(pNewNode != NULL)
    {
        pNewNode->value = value;
        pNewNode->left = NULL;
        pNewNode->right = NULL;
    }
    //���ҵ�ǰ�ڵ�������Ӧ�ò����λ��
    if(pRoot == NULL)//����Ϊ��ʱ����ǰ�ڵ���Ϊ���ĸ��ڵ�
    {
        pRoot = pNewNode;
        //cout<<pNewNode->value<<endl;
    }
    else//����Ϊ����ʱ�������в���Ӧ�ò����λ��
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
    //�����ǰ�ڵ�Ϊ���򷵻�
    if(pNode == NULL)
        return;
    //����ǰ�ڵ��ֵ�ӵ�·���ĺ��ϣ�������ǰ�ڵ�ѹջ
    curSum = curSum + pNode->value;
    path_stack.push_back(pNode->value);
    //�жϼ��뵱ǰ�ڵ�󣬵�ǰ·���Ƿ�Ϊ����·����·������ֵ֮���Ƿ����sum���������ӡ·����ֵ
    if((pNode->left == NULL) &&(pNode->right == NULL) && (curSum == sum))
    {
        for(int i = 0;i < path_stack.size();++i)
        {
            cout<<path_stack[i]<<" ";
        }
        cout<<endl;
    }
    //�����ǰ�ڵ㲻��Ҷ�ӽڵ㣬�����ݹ���������ֽڵ�
    if(pNode->left)
        sumOfPath(pNode->left,sum,path_stack,curSum);
    if(pNode->right)
        sumOfPath(pNode->right,sum,path_stack,curSum);
    //��ǰ·��������ɺ󣬷��ص���ǰ�ĸ��ڵ��������
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
    //�������������
    BSTreeNode *pRoot = NULL;
    for(int i = 0;i < len;++i)
    {
        pRoot = InsertBSTree(pRoot,array[i]);
    }
    //����������֦����ÿ��·���ϵĽڵ�ĺ�
    sumOfPath(pRoot,sum,path_stack,curSum);
    //���ٶ��������
    BSTreeDestroy(pRoot);
    system("pause");
    return 0;
}

#endif













































