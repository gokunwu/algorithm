
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：一个数组是由一个递减数列左移若干位形成的，比如{4，3，2，1，6，5}是由{6，5，4，3，2，1}左移两位形成的，在这种数组中查找某一个数。
分析：由于数组是由一个递减数列左移若干位形成的，所以将数组以中间为界分割成两个数组将得到这样两个数组，一个数组是单调递减的，一个是由一个递减数列左移若干位形成的。接下来我们要确定要查找的数在两个数组中的哪个数组中，要查找的数若是在单调递减的数列中则在数列中进行二分查找，若要查找的数在第二个数列中则，继续第一步。
判断数组是否为单调数组可以用array[l] >= array[mid],若成立则是单调递减的数列否则不是。
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
            //判断左边数组与右边数组哪个是单调递减数组
            if(array[left] >= array[mid])//左边数组是单调递减数组
            {
                if(num <= array[left] && num > array[mid])//要找的数在左边单调数组中
                {
                    right = mid - 1;
                }
                else//要找的数在右边非单调数组中
                {
                    left = mid + 1;
                }
            }
            else//右边数组是单调递减数组
            {
                if(num >= array[right] && num < array[mid])//要找的数在右边单调数组中
                {
                    left = mid + 1;
                }
                else//要找的数在左边非单调数组中
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
