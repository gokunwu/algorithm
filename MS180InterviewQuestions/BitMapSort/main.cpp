/*
*copyright @nciaebupt 转载请保留此标记
*用bitmap的方式来对数组进行排序，时间复杂度为O(n)
*这种方式的排序是用空间来换取时间的方法
*bitmap的排序方式属于非比较排序，比较排序的时间复杂度底线是O(nlogn),
*而非比较排序的时间复杂度可以达到O(n)，只是需要牺牲空间
*/
#include <stdio.h>
#include <memory.h>

#define BYTESIZE 8//一个字节为8bit
//这里使用char数组来实现bitmap，num数组中最大的数为14，故只需要2个char字符(2*8 = 16)
#define CHARARRAYSIZE 2
#define SHIFT 3//移动三位，左移三位相当于乘以8，右移3位相当于除以8取整

int bitSet(char *p,int num)//将逻辑位置为n的二进制位置为1
{
    //num>>SHIFT右移3位相当于除以8求算字节位置，num%CHARSIZE对8取余即求位位置
    p[num >> SHIFT] = p[num >> SHIFT] | (0x01 << (num % BYTESIZE));

    return 1;
}
int bitreset(char * p,int num)//将逻辑位置为n的二进制位置为0
{
    //num>>SHIFT右移3位相当于除以8求算字节位置，num%CHARSIZE对8取余即求位位置
    p[num >> SHIFT] = p[num >> SHIFT] & (~(0x01 << (num % BYTESIZE)));
}
int test(char * p,int num)//测试逻辑位置为n的二进制位是否为1
{
    return p[num >> SHIFT] & (0x01 << (num % BYTESIZE));
}

int bitMapSort()
{
    //创建要排序的数组,只考虑正数的情况。
    int num[] = {3,5,2,10,6,12,8,14,9};
    //开辟CHARARRAYSIZE大小的char数组
    char *chararray = new char[CHARARRAYSIZE];
    //将char数组chararray的每一位都置为0
    memset(chararray,0,CHARARRAYSIZE);
    //顺序遍历num数组，将chararray中相应下标的bit位置为1
    for(int i = 0;i < sizeof(num)/sizeof(int);++i)
    {
        bitSet(chararray,num[i]);
    }
    //遍历每个bit，输出排序结果
    char *ptmp = chararray;
    for(int i = 0;i < CHARARRAYSIZE; ++i)
    {
        for(int j = 0;j < BYTESIZE; ++j)
        {
            //int bit_value = (*ptmp) & (0x01 << j);
            //int bit_verify = 0x01 << j;
            //if(bit_value == bit_verify)
            if(test(chararray,j))
            {
                printf("%d\n",i*BYTESIZE + j);
            }
        }
        ptmp++;
    }
}

int main(int args,char **argv)
{
    bitMapSort();

    return 0;
}
