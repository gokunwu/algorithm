
#if 0
/*
*copyright@nciaebupt ת����ע������
��Ŀ������һ���������飬�жϸ������ǲ���ĳ��Ԫ�������ĺ�������Ľ��������Ƿ���true�����򷵻�false����������5��7��6��9��11��10��8��������һ�����������������ĺ�����������
8
/ \
6 10
/ \ / \
5 7 9 11
��˷���true��
�������7��4��6��5��û���Ŀ����ĺ�������Ľ����������У���˷���false��
����������һ��trilogy �ı����⣬��Ҫ����Զ�Ԫ����������⡣
�ں��������õ��������У����һ��Ԫ��Ϊ���ĸ���㡣��ͷ��ʼɨ��������У��ȸ����С��Ԫ�ض�Ӧ��λ�����е���벿�֣��ӵ�һ�����ڸ���㿪ʼ�������ǰ���һ��Ԫ��Ϊֹ������Ԫ�ض�Ӧ�ô��ڸ���㣬��Ϊ�ⲿ��Ԫ�ض�Ӧ�������������������������Ļ��֣�
�����л���Ϊ���������֣����ǵݹ��ȷ�����е������������ǲ��Ƕ��Ƕ�Ԫ��������
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
    //�ҵ������бȸ��ڵ��ֵС���ǲ������У�i��ֵ�����������������ķָ��
    int i = begin;
    for(i = begin;i < end;++i)
    {
        if(array[i] > root)
            break;
    }
    //�������ж�����������������б��������Ƿ��нڵ��ֵ��rootС��������Ϊfalse
    int j = i;
    for(j = i; j < end;++j)
    {
        if(array[j] < root)
            return false;
    }
    //ȷ���������Ƿ���ȷ
    bool left = true;
    if(i > begin)
        left = varifySquenceOfBSTree(array,begin,i-1);
    //ȷ���������Ƿ���ȷ
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













































