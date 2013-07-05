/*
 * File:   main.cpp
 * Author: wk
 *
 * Created on 2012年3月1日, 下午9:07
 */

#include <cstdlib>
#include<iostream>
#include<string>
using namespace std;

/*定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部。如把字符串abcdef左旋转2位得到字符串cdefab。
请实现字符串左旋转的函数，要求对长度为n的字符串操作的时间复杂度为O(n)，空间复杂度为O(1)。
 */

/*void Reverse(char* A,int b,int e)
{
    int i=b;
    int j=e;
    int tmp;
    while(i<j)
    {
        tmp=A[i];
        A[i]=A[j];
        A[j]=tmp;
        i++;
        j--;
    }
}

int main(int argc, char** argv) {
    char A[6]={'a','b','c','d','e','f'};
    int num=2;
    Reverse(A,0,num-1);
    Reverse(A,num,5);
    Reverse(A,0,5);
    for(int i=0;i<6;i++)
    {
        cout<<A[i]<<endl;
    }
    return 0;
}
*/

void Reverse(string str,string::iterator begin,string::iterator end)
{
    char s;
    //end--;
    while(begin!=end)
    {
        s=*begin;
        *begin=*(end-1);
        *(end-1)=s;
        begin++;
        end--;
    }
}

int main(int argc, char** argv)
{
    string str="abcdef";
    int num=2;
    Reverse(str,str.begin(),str.begin()+num);
    Reverse(str,str.begin()+num,str.end());
    Reverse(str,str.begin(),str.end());
    cout<<str<<endl;

    return 0;
}

