/*
 * File:   main.cpp
 * Author: wk
 *
 * Created on 2012��3��1��, ����9:07
 */

#include <cstdlib>
#include<iostream>
#include<string>
using namespace std;

/*�����ַ���������ת���������ַ���ǰ������ɸ��ַ��ƶ����ַ�����β��������ַ���abcdef����ת2λ�õ��ַ���cdefab��
��ʵ���ַ�������ת�ĺ�����Ҫ��Գ���Ϊn���ַ���������ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
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

