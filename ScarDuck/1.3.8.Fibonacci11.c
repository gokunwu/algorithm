
/*
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


int main(int args,char ** argv)
{
    int n = 2;
    int res = FibonacciRcur(n);
    std::cout<<res<<std::endl;
    system("pause");
    return 0;
}
