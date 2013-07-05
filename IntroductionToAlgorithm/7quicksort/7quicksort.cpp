/*
 * File:   main.cpp
 * Author: wk
 *
 * Created on 2012年3月11日, 下午4:33
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 *实现快速排序，排序字符串：172834956
 * 快速排序（Quicksort）是对冒泡排序的一种改进。它的基本思想是：通过一趟排序将要
 * 排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，
 * 然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，
 * 以此达到整个数据变成有序序列。
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
    int key = str[i];//以第一个字符作为比较的key
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








