
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：求1+2+…+n 要求不能使用乘除法、for、while、if、else、switch、case等关键字
以及条件判断语句（A?B:C）。
解析：循环只是让相同的代码执行n 遍而已，我们完全可以不用for 和while 达到这个效果。比如定义一个类，我们new 一含有n 个这种类型元素的数组， 那么该类的构造函数将确定会被调用n 次。我们可以将需要执行的代码放到构造函数里。
*/
#include <cstdlib>
#include <iostream>
using namespace std;

class Add
{
    public:
        Add()
        {
            N = N + 1;
            sum = sum + N;
        }
        static int getSum()
        {
            return sum;
        }
        static void reset()
        {
            N = 0;
            sum = 0;
        }
    private:
        //static int N;
        static int N;
        static int sum;
};
int Add::N = 0;
int Add::sum = 0;

int addNum(int n)
{
    Add::reset();
    Add *add = new Add[n];
    int res = add->getSum();
    if(add != NULL)
        delete []add;
    add = NULL;
    return res;
}

int main(int args,char ** argv)
{
    int n = 100;
    int res = addNum(n);
    cout<<res<<endl;

    system("pause");
    return 0;
}
#endif


