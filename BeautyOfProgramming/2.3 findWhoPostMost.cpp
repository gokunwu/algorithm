#if 0
/*
copyright@nciaebupt 转载请注明出处
题目:Tango是微软亚洲研究院的一个试验项目。研究院的员工和实习生们都很喜欢在Tango上面交流灌水。传说，Tango有一大“水王”，他不但喜欢发贴，还会回复其他ID发的每个帖子。坊间风闻该“水王”发帖数目超过了帖子总数的一半。如果你有一个当前论坛上所有帖子（包括回帖）的列表，其中帖子作者的ID也在表中，你能快速找出这个传说中的Tango水王吗？
分析：如果每次删除两个不同的id，则剩下的水王id依然超过总数的一半，可以不断重复这个过程。
1.用candidate记录发帖水王，发帖次数用nTimes记录。
2.可以假设帖子的第一个ID是次数最大的，nTimes=1。
3. 遍历下一个ID，如果跟candidate一样，nTimes++，否则，遇到一个不是水王发的帖子，将这个帖子与水王发的一个帖子删掉，也就是nTimes--，如果nTimes == 0，那么说明当前的候选不是水王，假设下一个是新的水王。
4.遍历结束，nTimes>0的那个candidate就是水王ID，他是获胜者。
*/
#include <cstdlib>
#include <iostream>

int findWhoPostMost(int *array,int len)
{
    int candidate = -1;
    int nTimes = 0;
    for(int i = 0;i < len;++i)
    {
        if(nTimes == 0)
        {
            candidate = array[i];
            nTimes = 1;
        }
        else
        {
            if(candidate == array[i])
                nTimes++;
            else
                nTimes--;
        }
    }
    return candidate;
}

int main(int args,char ** argv)
{
    int array[] = {1,2,3,2,3,4,3,3,2,3,1,3,3,5,6,3,3,3};
    int len = sizeof(array)/sizeof(int);
    int res = findWhoPostMost(array,len);
    std::cout<<res<<std::endl;
    system("pause");
    return 0;
}
#endif
