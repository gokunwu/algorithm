
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b
解析：在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b
如果从头遍历，与后面字符进行比较出现次数是否为1，算法复杂度为O(n^ 2)，
考虑以空间换时间，因为一个字符最多两个字节，占8位。因此可用一个256
位数组保存每个字符出现的次数
*/
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>

int main(int args,char ** argv)
{
    char *pstr = "abaccdeff";
    int len = strlen(pstr);
    int cnt[256];
    for(int i = 0;i < 256;++i)
    {
        cnt[i] = 0;
    }
    for(int i = 0;i < len;++i)
    {
        cnt[int(pstr[i])]++;
    }
    for(int i = 0;i <256;++i)
    {
        if(cnt[i] == 1)
        {
            printf("%c\n",i);
        }
    }

    system("pause");
    return 0;
}
#endif
