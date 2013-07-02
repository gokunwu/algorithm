
#if 0
/*
*copyright@nciaebupt 转载请注明出处
题目：输入一个整数数组，判断该数组是不是某二元查找树的后序遍历的结果。如果是返回true，否则返回false。例如输入5、7、6、9、11、10、8，由于这一整数序列是如下树的后序遍历结果：
8
/ \
6 10
/ \ / \
5 7 9 11
因此返回true。
如果输入7、4、6、5，没有哪棵树的后序遍历的结果是这个序列，因此返回false。
分析：这是一道trilogy 的笔试题，主要考查对二元查找树的理解。
在后续遍历得到的序列中，最后一个元素为树的根结点。从头开始扫描这个序列，比根结点小的元素都应该位于序列的左半部分；从第一个大于跟结点开始到跟结点前面的一个元素为止，所有元素都应该大于跟结点，因为这部分元素对应的是树的右子树。根据这样的划分，
把序列划分为左右两部分，我们递归地确认序列的左、右两部分是不是都是二元查找树。
*/

#include <cstdlib>
#include <iostream>
using namespace std;

bool varifySquenceOfBSTree(int *array,int begin,int end)
{
    //cout<<begin<<" "<<end<<endl;
    //if(array == NULL || (end-begin+1) <= 0)
    if(array == NULL || end < begin)
        return false;
    //cout<<"FUCK"<<endl;
    int root = array[end];
    //找到序列中比根节点的值小的那部分序列，i的值是序列中左右子树的分割点
    int i = begin;
    for(i = begin;i < end;++i)
    {
        if(array[i] > root)
            break;
    }
    //在序列中二叉查找树的右子树中遍历，看是否有节点的值比root小，若有则为false
    int j = i;
    for(j = i; j < end;++j)
    {
        if(array[j] < root)
            return false;
    }
    //确认左子树是否正确
    bool left = true;
    if(i > begin)
        left = varifySquenceOfBSTree(array,begin,i-1);
    //确认右子树是否正确
    bool right=true;
    if(i < end)
        right=varifySquenceOfBSTree(array,i,end-1);
    //cout<<"left :"<<left<<" right :"<<right<<endl;

    return(left&&right);
}

int main(int args,char ** argv)
{
    int array[] = {5,7,6,9,11,10,8};
    //int array[] = {7,4,6,5};
    int len = sizeof(array)/sizeof(int);
    bool res = varifySquenceOfBSTree(array,0,len-1);
    cout<<res<<endl;

    system("pause");
    return 0;
}
#endif













































