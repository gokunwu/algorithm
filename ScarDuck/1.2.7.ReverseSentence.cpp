
#if 0
/*
*copyright@nciaebupt 转载请注明出处
*输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。句子中单词以空格
*符隔开。为简单起见，标点符号和普通字母一样处理。例如输入I am a *student.，则输出student. a am I。
分析：由于编写字符串相关代码能够反映程序员的编程能力和编程习惯，与字符串相关的问题一直是程序员笔试、面试题的热门题目。本题也曾多次受到包括微软在内的大量公司的青睐。
由于本题需要翻转句子，我们先颠倒句子中的所有字符。这时，不但翻转了句子中单词的顺序，而且单词内字符也被翻转了。我们再颠倒每个单词内的字符。由于单词内的字符被翻转两次，因此顺序仍然和输入时的顺序保持一致。
还是以上面的输入为例子。翻转I am a student.中所有字符得到.tneduts a ma I，再翻转每个单词中字符的顺序得到students. a am I，正是符合要求的输出。
*/
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void revert(char *str,int begin,int end)
{
    char tmp;
    int len = end - begin + 1;
    for(int i = 0;i < len/2;++i)
    {
        tmp = str[begin+i];
        str[begin+i] = str[end-i];
        str[end-i] = tmp;
    }
}

void reverseSent(char *str,int len)
{
    //revert the sentence
    revert(str,0,len-1);
    char *p = strtok(str," ");
    while(p != NULL)
    {
        revert(p,0,strlen(p)-1);
        p[strlen(p)] = ' ';
        p = strtok(NULL," ");
    }
    str[len] = '\0';

}

int main(int args,char ** argv)
{
    char str[] = "I am a student.";
    reverseSent(str,strlen(str));
    cout<<str<<endl;

    system("pause");
    return 0;
}

#endif















