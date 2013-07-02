
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：n个数字（0,1,…,n-1）形成一个圆圈，从数字0开始，每次从这个圆圈中删除第m个数字（第一个为当前数字本身，第二个为当前数字的下一个数字）。当一个数字删除后，从被删除数字的下一个继续删除第m个数字。求出在这个圆圈中剩下的最后一个数字。
分析：本题就是有名的约瑟夫环问题。既然题目有一个数字圆圈，很自然的想法是我们用一个数据结构来模拟这个圆圈。在常用的数据结构中，我们很容易想到用环形列表。我们可以创建一个总共有m个数字的环形列表，然后每次从这个列表中删除第m个元素。
在参考代码中，我们用STL中std::list来模拟这个环形列表。由于list并不是一个环形的结构，因此每次跌代器扫描到列表末尾的时候，要记得把跌代器移到列表的头部。这样就是按照一个圆圈的顺序来遍历这个列表了。
这种思路需要一个有n个结点的环形列表来模拟这个删除的过程，因此内存开销为O(n)。而且这种方法每删除一个数字需要m步运算，总共有n个数字，因此总的时间复杂度是O(mn)。当m和n都很大的时候，这种方法是很慢的。
接下来我们试着从数学上分析出一些规律。首先定义最初的n个数字（0,1,…,n-1）中最后剩下的数字是关于n和m的方程为f(n,m)。
在这n个数字中，第一个被删除的数字是(m-1)%n，为简单起见记为k。那么删除k之后的剩下n-1的数字为0,1,…,k-1,k+1,…,n-1，并且下一个开始计数的数字是k+1。相当于在剩下的序列中，k+1排到最前面，从而形成序列k+1,…,n-1,0,…k-1。该序列最后剩下的数字也应该是关于n和m的函数。由于这个序列的规律和前面最初的序列不一样（最初的序列是从0开始的连续序列），因此该函数不同于前面函数，记为f’(n-1,m)。最初序列最后剩下的数字f(n,m)一定是剩下序列的最后剩下数字f’(n-1,m)，所以f(n,m)=f’(n-1,m)。
接下来我们把剩下的的这n-1个数字的序列k+1,…,n-1,0,…k-1作一个映射，映射的结果是形成一个从0到n-2的序列：
k+1    ->    0
k+2    ->    1
…
n-1    ->    n-k-2
0   ->    n-k-1
…
k-1   ->   n-2
把映射定义为p，则p(x)=(x-k-1)%n，即如果映射前的数字是x，则映射后的数字是(x-k-1)%n。对应的逆映射是p-1(x)=(x+k+1)%n。
由于映射之后的序列和最初的序列有同样的形式，都是从0开始的连续序列，因此仍然可以用函数f来表示，记为f(n-1,m)。根据我们的映射规则，映射之前的序列最后剩下的数字f’(n-1,m)= p-1 [f(n-1,m)]=[f(n-1,m)+k+1]%n。把k=(m-1)%n代入得到f(n,m)=f’(n-1,m)=[f(n-1,m)+m]%n。
经过上面复杂的分析，我们终于找到一个递归的公式。要得到n个数字的序列的最后剩下的数字，只需要得到n-1个数字的序列的最后剩下的数字，并可以依此类推。当n=1时，也就是序列中开始只有一个数字0，那么很显然最后剩下的数字就是0。我们把这种关系表示为：
         0                  n=1
f(n,m)={
         [f(n-1,m)+m]%n     n>1
尽管得到这个公式的分析过程非常复杂，但它用递归或者循环都很容易实现。最重要的是，这是一种时间复杂度为O(n)，空间复杂度为O(1)的方法，因此无论在时间上还是空间上都优于前面的思路
*/
#include <cstdlib>
#include <iostream>
#include <list>

int lastNumInCircle(std::list<int> lint,int m)
{
    if(m < 1)
        return -1;
    std::list<int>::iterator pcur = lint.begin();
    while(lint.size() > 1)
    {
        //在链表中找到第m个元素
        for(int i = 1;i < m;++i)
        {
            pcur++;
            if(pcur == lint.end())
                pcur = lint.begin();
        }
        //删除链表中的第m个元素
        std::list<int>::iterator pnext = ++pcur;
        if(pnext == lint.end())
            pnext = lint.begin();
        pcur--;
        //std::cout<<*pcur<<std::endl;
        lint.erase(pcur);
        pcur = pnext;
    }
    return *pcur;
}
int lastNumInCircle1(std::list<int> lint,int m)
{
    if(m < 1)
        return -1;
    int lastint = 0;
    for(int i = 2;i <= lint.size();++i)
    {
        lastint = (lastint + m )%i;
    }
    return lastint;
}
int main(int args,char ** argv)
{
    int array[] = {0,1,2,3,4,5};
    int len = sizeof(array)/sizeof(int);
    std::list<int> lint;
    for(int i = 0;i < len;++i)
    {
        lint.push_back(array[i]);
    }
    int m = 6;
    int res1 = lastNumInCircle1(lint,m);
    int res = lastNumInCircle(lint,m);
    std::cout<<res1<<std::endl;
    std::cout<<res<<std::endl;
    system("pause");
    return 0;
}
#endif











