
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：求二进制中1的个数。对于一个字节（8bit）的变量，求其二进制表示中"1"的个数，要求算法的执行效率尽可能的高。
*/
#include <cstdlib>
#include <iostream>

int numOf1InBinary(int num)
{
    int count = 0;
    while(num)
    {
        num = num & (num-1);
        count++;
    }
    return count;
}


int main(int args,char ** argv)
{
    int num = 7;
    int res = numOf1InBinary(num);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

#endif

