
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ����1+2+��+n Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ���
�Լ������ж���䣨A?B:C����
������ѭ��ֻ������ͬ�Ĵ���ִ��n ����ѣ�������ȫ���Բ���for ��while �ﵽ���Ч�������綨��һ���࣬����new һ����n ����������Ԫ�ص����飬 ��ô����Ĺ��캯����ȷ���ᱻ����n �Ρ����ǿ��Խ���Ҫִ�еĴ���ŵ����캯���
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


