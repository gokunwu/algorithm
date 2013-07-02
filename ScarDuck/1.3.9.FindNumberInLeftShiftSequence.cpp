
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ��һ����������һ���ݼ�������������λ�γɵģ�����{4��3��2��1��6��5}����{6��5��4��3��2��1}������λ�γɵģ������������в���ĳһ������
������������������һ���ݼ�������������λ�γɵģ����Խ��������м�Ϊ��ָ���������齫�õ������������飬һ�������ǵ����ݼ��ģ�һ������һ���ݼ�������������λ�γɵġ�����������Ҫȷ��Ҫ���ҵ��������������е��ĸ������У�Ҫ���ҵ��������ڵ����ݼ������������������н��ж��ֲ��ң���Ҫ���ҵ����ڵڶ����������򣬼�����һ����
�ж������Ƿ�Ϊ�������������array[l] >= array[mid],���������ǵ����ݼ������з����ǡ�
*/
#include <cstdlib>
#include <iostream>

int findNumInLeftShiftSeq(int *array,int num,int left,int right)
{
    if(array == NULL)
        return -1;
    if(left > right)
        return -1;
    int mid = 0;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(array[mid] == num)
            return mid;
        else
        {
            //�ж�����������ұ������ĸ��ǵ����ݼ�����
            if(array[left] >= array[mid])//��������ǵ����ݼ�����
            {
                if(num <= array[left] && num > array[mid])//Ҫ�ҵ�������ߵ���������
                {
                    right = mid - 1;
                }
                else//Ҫ�ҵ������ұ߷ǵ���������
                {
                    left = mid + 1;
                }
            }
            else//�ұ������ǵ����ݼ�����
            {
                if(num >= array[right] && num < array[mid])//Ҫ�ҵ������ұߵ���������
                {
                    left = mid + 1;
                }
                else//Ҫ�ҵ�������߷ǵ���������
                {
                    right = mid - 1;
                }
            }
        }
    }
    return -2;
}

int main(int args,char ** argv)
{
    int array[] = {4,3,2,1,6,5};
    int len = sizeof(array)/sizeof(int);
    int num = 5;
    int res = findNumInLeftShiftSeq(array,num,0,len-1);
    std::cout<<res<<std::endl;
    system("pause");
    return 0;
}
#endif
