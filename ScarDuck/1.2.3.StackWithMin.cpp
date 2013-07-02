
#if 0

/*
*copyright@nciaebupt 转载请注明出处
*问题：定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。
*要求函数min、push以及pop的时间复杂度都是O(1)
*思路：需要一个辅助栈，每次push一个新元素的时候，同时将最小元素
*（或最小元素的位置，考虑到栈元素的类型可能是复杂的数据结构，用最小元素的位置将
*能减少空间消耗）push到辅助栈中；每次pop一个元素出栈的时候，同时pop辅助栈
*/

#include <cstdio>
#include <cstdlib>
#include <assert.h>
#include <iostream>
#include <deque>
using namespace std;

template<typename T>
class StackWithMin
{
    public:
        StackWithMin(){};//定义类StackWithMin的构造函数
        virtual ~StackWithMin(){};//定义类StackWithMin的析构函数

        T& top();//声明成员访问函数，非const版本
        const T& top()const;//声明成员访问函数，const版本

        void push(const T& value);//声明入栈操作
        void pop();//声明出栈操作

        const T& min()const;//声明栈中最小值的访问函数

    private:
        deque<T> stack_data;//用来实现栈，存储具体数据
        deque<size_t> stack_minIndex;//用来存储栈中元素的下标
};

template<typename T>
T& StackWithMin<T>::top()
{
    assert(stack_data.size()>0);

    return stack_data.back();
}

template<typename T>
const T& StackWithMin<T>::top()const
{
    assert(stack_data.size()>0);

    return stack_data.back();
}

template<typename T>
void StackWithMin<T>::push(const T& value)
{
    stack_data.push_back(value);
    if(stack_minIndex.size() == 0)
    {
        stack_minIndex.push_back(0);
    }
    else
    {
        if(value < stack_data[stack_minIndex.size()-1])
        {
            stack_minIndex.push_back(stack_minIndex.size());
        }
        else
        {
            stack_minIndex.push_back(stack_minIndex.back());
        }
    }
}

template<typename T>
void StackWithMin<T>::pop()
{
    assert(stack_data.size()>0);
    assert(stack_minIndex.size() > 0);

    stack_data.pop_back();
    stack_minIndex.pop_back();
}

template<typename T>
const T& StackWithMin<T>::min()const
{
    assert(stack_data.size() > 0);
    assert(stack_minIndex.size() > 0);

    return stack_data[stack_minIndex.back()];
}

int main(int args,char ** argv)
{
    StackWithMin<int> stack;
    int array[] = {3,4,2,1,5};
    int len = sizeof(array)/sizeof(int);
    //数据入栈
    for(int i = 0;i <len ;++i)
    {
        cout<<"push "<<array[i]<<endl;
        stack.push(array[i]);
    }
    //输出当前栈中最小值，并使栈顶元素出栈
    for(int i = 0;i <len ;++i)
    {
        cout<<"min in stack "<<stack.min()<<endl;
        stack.pop();
    }

    system("pause");
    return 0;
}
#endif
