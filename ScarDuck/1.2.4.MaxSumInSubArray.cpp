
#if 0
/*
*copyright@nciaebupt ת����ע������
*���⣺����һ���������飬������������Ҳ�и�����������һ���������Ķ���������һ�������顣
*������������ĺ͵����ֵ��Ҫ��ʱ�为���ΪO(n)��
*ʹ�ö�̬�滮������ʵ�֣�
*����ú���f(i)��ʾ�Ե�i�����ֽ�β������������ͣ���ô������Ҫ���max(f[0...n])��
*���ǿ��Ը������µݹ鹫ʽ��f(i)
*     |-- array[i] ���i==0����f(i-1)<0
*f(i)=|
*     |-- f(i-1) + array[i] ���f(i-1)>0
*�����ʽ�����壺
*   ���Ե�(i-1)������Ϊ��β�����������������ֵĺ�f(i-1)С��0ʱ���������������͵�i������ӣ��õ��Ľ����������i��������ҪС��������������������������ǵ�i��������
*   ����Ե�(i-1)������Ϊ��β�����������������ֵĺ�f(i-1)����0�����i�����ۼӾ͵õ����Ե�i������β�����������������ֵĺ͡�
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int maxSumInSubArray(int *array,int len)
{
    int *c = new int[len];//������¼�Ե�ǰԪ�ؽ�β������͵���ǰԪ�ص�λ��Ϊֹ���������������
    int max = -1000;//������¼����c[]�е����ֵ
    int start = 0;//��¼����������������͵Ŀ�ʼλ��
    int end = 0;//��¼����������������͵Ľ���λ��
    int tmp = 0;

    c[0] = array[0];
    for(int i = 1;i < len;++i)
    {
        if(c[i-1] > 0)
        {
            c[i] = c[i-1] + array[i];
        }
        else
        {
            c[i] = array[i];
            tmp = i;
        }
        if(c[i] > max)
        {
            max = c[i];
            start = tmp;
            end = i;
        }
    }
    cout<<"���������͵���ʼλ�ã�"<<start<<"~"<<end<<endl;
    return max;
}

int main(int args,char ** argv)
{
    int array[] = {1,-2,3,10,-4,7,2,-5};
    int len = sizeof(array)/sizeof(int);
    int res = maxSumInSubArray(array,len);
    cout<<"����������: "<<res<<endl;
    system("pause");
    return 0;
}
#endif


#if 0
/*
*copyright@nciaebupt ת����ע������
*���⣺����һ���������飬������������Ҳ�и�����������һ���������Ķ���������һ�������顣
*������������ĺ͵����ֵ��Ҫ��ʱ�为���ΪO(n)��
*ʵ�ַ���������������еķ����ܼ򵥣�ֻҪǰi��ĺͻ�û��С��0��ô�����о�һֱ�����չ��������֮ǰ�������п�ʼ�µ������У�
*ͬʱ����Ҫ���¸��������еĺͣ�����ҵ������������С�
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int maxSumInSubArray(int *array,int len)
{
    int max = 0;//������¼�����
    int sum = 0;
    for(int i = 0;i < len;++i)
    {
        if(sum > 0)
        {
            sum = sum + array[i];
        }
        else
        {
            sum = array[i];
        }
        if(sum > max)
            max = sum;
    }
    return max;
}

int main(int argc,char ** argv)
{
    int array[] = {1,-2,3,10,-4,7,2,-5};
    int len = sizeof(array)/sizeof(int);
    int res = maxSumInSubArray(array,len);
    cout<<res<<endl;
    system("pause");
    return 0;
}
#endif
