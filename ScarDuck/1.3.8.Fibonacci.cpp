
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ������Fibonacci �������£�
     / 0 n=0
f(n) = 1 n=1
     \ f(n-1)+f(n-2) n=2
����n�������ķ���������еĵ�n �
�������ݹ鷽���ظ������˺ܶ��ͨ��������������ռ䱣��ǰ�����ֵ�����Կռ�
��ȡʱ�䡣���Ӷ�ΪO(N)��
*/
#include <cstdlib>
#include <iostream>

int FibonacciRcur(int n)
{
    if(n == 0||n == 1)
        return n;
    if(n > 2)
        return FibonacciRcur(n-1) + FibonacciRcur(n-2);
}
int Fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int res = 0;
    if(n == 0||n == 1)
        return n;
    else
    {
        for(int i = 0;i < n;++i)
        {
            res = a + b;
            a = b;
            b = res;
        }
    }
    return res;
}

int main(int args,char ** argv)
{
    int n = 5;
    int res = FibonacciRcur(n);
    int res1 = Fibonacci(n);
    std::cout<<res<<std::endl;
    std::cout<<res1<<std::endl;
    system("pause");
    return 0;
}
#endif
