
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ������һ���Ѿ�������������������һ�����֣��������в�����������ʹ�����ǵĺ�������������Ǹ����֡�Ҫ��ʱ�临�Ӷ���O(n)������ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�
������������1��2��4��7��11��15������15������4+11=15��������4��11��
����������ָ������ɨ��
*/
#include <cstdlib>
#include <iostream>

void sumOfTwoNum(int *array,int len,int sum)
{
    int left = 0;
    int right = len - 1;
    while(left < right)
    {
        if(array[left] + array[right] == sum)
        {
            std::cout<<array[left]<<" : "<<array[right]<<std::endl;
            return;
        }
        else
        {
            if(array[left] + array[right] < sum)
                left++;
            else if(array[left] + array[right] > sum)
                right--;
        }
    }
}


int main(int args,char ** argv)
{
    int array[] = {1,2,4,7,11,15};
    int len = sizeof(array)/sizeof(int);
    int sum = 15;
    sumOfTwoNum(array,len,sum);

    system("pause");
    return 0;
}
#endif
