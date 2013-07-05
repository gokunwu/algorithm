#if 0
/*
copyright@nciaebupt 转载请注明出处
1、 给定一个整数N，那么N的阶乘N！末尾有多少个0呢？例如：N＝10，N！＝3 628 800，N！的末尾有两个0。
2、求N！的二进制表示中最低位1的位置。
*/

#include <cstdlib>
#include <iostream>

int zeroInFactorialEnd1(int N)
{
    int res = 0;
    for(int i = 1;i <= N;++i)
    {
        int j = i;
        while(j % 5 == 0)
        {
            res++;
            j = j/5;
        }
    }
    return res;
}
//以5的倍数5,5^2,5^3,5^4 ...等为界限，每个区段中有5^n/5个5
int zeroInFactorialEnd2(int N)
{
    int res = 0;
    while(N)
    {
        res = res + N/5;
        N = N/5;
    }
    return res;
}
//其实就是计算N!的二进制表示中最后有几位0，也就是计算N!中含有质因数2的个数
int lowestOne(int N)
{
    int res = 0;
    while(N)
    {
        res = res + N>>1;
        N = N >> 1;
    }
    return res;
}

int main(int args,char ** argv)
{
    int N = 6;
    int res = zeroInFactorialEnd2(N);
    int res2 = lowestOne(N);
    std::cout<<res2<<std::endl;

    system("pause");
    return 0;
}
#endif
