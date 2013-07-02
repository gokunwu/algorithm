
#if 0

/*
*copyright@nciaebupt ת����ע������
*���⣺����ջ�����ݽṹ��Ҫ�����һ��min�������ܹ��õ�ջ����СԪ�ء�
*Ҫ����min��push�Լ�pop��ʱ�临�Ӷȶ���O(1)
*˼·����Ҫһ������ջ��ÿ��pushһ����Ԫ�ص�ʱ��ͬʱ����СԪ��
*������СԪ�ص�λ�ã����ǵ�ջԪ�ص����Ϳ����Ǹ��ӵ����ݽṹ������СԪ�ص�λ�ý�
*�ܼ��ٿռ����ģ�push������ջ�У�ÿ��popһ��Ԫ�س�ջ��ʱ��ͬʱpop����ջ
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
        StackWithMin(){};//������StackWithMin�Ĺ��캯��
        virtual ~StackWithMin(){};//������StackWithMin����������

        T& top();//������Ա���ʺ�������const�汾
        const T& top()const;//������Ա���ʺ�����const�汾

        void push(const T& value);//������ջ����
        void pop();//������ջ����

        const T& min()const;//����ջ����Сֵ�ķ��ʺ���

    private:
        deque<T> stack_data;//����ʵ��ջ���洢��������
        deque<size_t> stack_minIndex;//�����洢ջ��Ԫ�ص��±�
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
    //������ջ
    for(int i = 0;i <len ;++i)
    {
        cout<<"push "<<array[i]<<endl;
        stack.push(array[i]);
    }
    //�����ǰջ����Сֵ����ʹջ��Ԫ�س�ջ
    for(int i = 0;i <len ;++i)
    {
        cout<<"min in stack "<<stack.min()<<endl;
        stack.pop();
    }

    system("pause");
    return 0;
}
#endif
