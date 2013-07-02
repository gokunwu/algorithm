
/*
题目：定义Fibonacci 数列如下：
     / 0 n=0
f(n) = 1 n=1
     \ f(n-1)+f(n-2) n=2
输入n，用最快的方法求该数列的第n 项。
分析：递归方法重复计算了很多项，通过定义两个额外空间保存前两项的值，可以空间
换取时间。复杂度为O(N)。
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
