/*
 * File:   main.cpp
 * Author: wk
 *
 * Created on 2012��3��11��, ����4:33
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 *ʵ�ֿ������������ַ�����172834956
 * ��������Quicksort���Ƕ�ð�������һ�ָĽ������Ļ���˼���ǣ�ͨ��һ������Ҫ
 * ��������ݷָ�ɶ����������֣�����һ���ֵ��������ݶ�������һ���ֵ��������ݶ�ҪС��
 * Ȼ���ٰ��˷����������������ݷֱ���п�����������������̿��Եݹ���У�
 * �Դ˴ﵽ�������ݱ���������С�
 */

void swap(string &a,string &b)
{
    string tmp;
    b=tmp;
    b=a;
    a=b;
}

int partition(string &str,int i,int j)
{
    int key = str[i];//�Ե�һ���ַ���Ϊ�Ƚϵ�key
    while(i < j)
    {
        if(str[j]<key)
        {
            swap(str[i],str[j]);
        }
        else
        {
            j--;
            continue;
        }
        if(str[i]>key)
        {
            swap(str[i],str[j]);
        }
        else
        {
            i++;
            continue;
        }
    }
    //cout<<i<<str[i]<<endl;
    return i;
}
void QuickSort(string &str,int i,int j)
{
    //return partition(str,i,j);
    if(i<j)
    {
        int k=partition(str,i,j);
       // cout<<k<<endl;
        QuickSort(str,i,k-1);
        //cout<<str<<endl;
        QuickSort(str,k+1,j);
        //cout<<str<<endl;
    }
}
int main(int argc, char** argv) {
    string str="572834916";
    //cout<<QuickSort(str,0,str.length()-1)<<endl;
    QuickSort(str,0,str.length()-1);
    cout<<str<<endl;

    return 0;
}








