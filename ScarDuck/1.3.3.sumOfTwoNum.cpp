
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入一个已经按升序排序过的数组和一个数字，在数组中查找两个数，使得它们的和正好是输入的那个数字。要求时间复杂度是O(n)。如果有多对数字的和等于输入的数字，输出任意一对即可。
例如输入数组1、2、4、7、11、15和数字15。由于4+11=15，因此输出4和11。
解析：两个指针两端扫描
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
