
/*
已知一个函数f 可以等概率的得到1-5间的随机数，问怎么等概率的得到1-7的随机数

int rand7()
{
int a;
while( (a=rand5()*5+rand5()) > 26 );
return (a-3)/3;
}

算法思路是：
1. 通过  rand5()*5+rand5()  产生  6 7 8 9 10 11 …… 26，27 28 29 30 这25个数，每个数的出
现机率相等
2. 只需要前面  3*7 个数，所以舍弃后面的4个数
3. 将  6 7 8 转化为  1，9 10 11 转化为  2，……，24 25 26 转化为  7。公式是  (a-3)/3

只要我们可以从  n 个数中随机选出  1 到  n 个数，反复进行这种运算，直到剩下最后一个
数即可。
我们可以调用  n 次给定函数，生成  n 个  1 到  5 之间的随机数，选取最大数所在位置即可
满足以上要求。

例如
初始的  7 个数  [1,2,3,4,5,6,7].
7 个  1 到  5 的随机数  [5, 3,1,4,2,5,5]
那么我们保留下[1,6,7],
3 个1 到  5 的随机数[2,4,1]
那么我们保留下[6]
6 就是我们这次生成的随机数。
*/



/*
编写一个生成0和1的随机函数：
step1. 调用给定的随机函数original_rand()生成一个数
如果==3 goto step1
如果<3 return 0
如果>3 return 1

编写一个生成1到7的随机函数
调用生成0和1的随机函数3次，构成000或001或010.......
如果？？？等于0返回，否则重新生成。
代码如下：
int rand_01()
{
    int r = original_rand();
    if(r == 3) return rand_01();
    if(r < 3) return 0;
    if(r > 3) return 1;
}

int rand_17()
{
    int i = 0;
    i += rand_01();
    i += rand_01() << 1;
    i += rand_01() << 2;
    if(i == 0) return rand_17();
    return i;
}
*/

