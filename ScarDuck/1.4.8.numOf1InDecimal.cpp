#if 0
/*
copyright@nciaebupt 转载请注明出处
问题描述：给定一个十进制正整数N，写下从1开始，到N的所有整数，然后数一下其中
出现的所有"1"的个数。例如：
N ＝  2，写下1，2。这样只出现了1个"1"。
N ＝  12，写下1，2，……，12，这样有5个"1"。
写一个函数f(N)，返回1到N之间出现的"1"的个数，比如f(12) = 5。
分析：
假设N ＝  abcde，这里a,b,c,d,e分别是十进制数N的各个数位上的数字。如果要计算百位
上出现1的次数，将受3方面因素影响：百位上的数字，百位以下(低位)的数字，百位(更高位)以上
的数字。
如果百位上的数字为0，则可以知道百位上可能出现1的次数由更高位决定，比如12 013，
则可以知道百位出现1的情况可能是100－199，1 100－1 199，……，11 100－11 199，一共有1 200
个。也就是由更高位数字(12)  决定，并且等于更高位数字(12)×当前位数(100)。

如果百位上的数字为1，则可以知道，百位上可能出现1的次数不仅受更高位影响，还受低
位影响，也就是由更高位和低位共同决定。例如12 113，  受更高位影响，百位出现1的情况是100
－199，1 100－1 199，……，11 100－11 199，一共有1 200个，和上面第一种情况一样，等于更高位数
字(12)×当前位数(100)。但它还受低位影响，百位出现1的情况是12 100－12 113，一共114个，等于
低位数字(113)+1。

如果百位上数字大于1(即为2－9)，则百位上可能出现1的次数也仅由更高位决定，比如12
213，则百位出现1的情况是：100－199，1 100－1 199，……，11 100－11 199，12 100－12 199，
共1300个，并且等于更高位数字+1(12+1)×当前位数(100)。
*/
#include <cstdlib>
#include <iostream>

int numOfOneInDecimal(int n){
  int icount = 0;
  int ifactor = 1;
  int iLowNum = 0;
  int iCurNum = 0;
  int iHighNum = 0;
  while(n/ifactor != 0){
    iLowNum = n - (n/ifactor)*ifactor;
    iCurNum = (n/ifactor)%10;
    iHighNum = n/(ifactor*10);
    switch(iCurNum){
      case 0:
        icount += iHighNum*ifactor;
        break;
      case 1:
        icount += iHighNum*ifactor + iLowNum + 1;
        break;
      default:
        icount += (iHighNum+1)*ifactor;
    }
    ifactor *= 10;
  }
  return icount;
}

int main(int argc, char ** argv){
  int n = 12;

  int num =numOfOneInDecimal(n);

  std::cout<<num<<std::endl;

  system("pause");
  return 0;
}

#endif
