#if 0
/*
copyright@nciaebupt ת����ע������
1�� ����һ������N����ôN�Ľ׳�N��ĩβ�ж��ٸ�0�أ����磺N��10��N����3 628 800��N����ĩβ������0��
2����N���Ķ����Ʊ�ʾ�����λ1��λ�á�
*/

#include <cstdlib>
#include <iostream>

int zeroInFactorialEnd1(int N)
{
    int res = 0;
    for(int i = 1;i <= N;++i)
    {
        int j = i;
        while(j % 5 == 0)
        {
            res++;
            j = j/5;
        }
    }
    return res;
}
//��5�ı���5,5^2,5^3,5^4 ...��Ϊ���ޣ�ÿ����������5^n/5��5
int zeroInFactorialEnd2(int N)
{
    int res = 0;
    while(N)
    {
        res = res + N/5;
        N = N/5;
    }
    return res;
}
//��ʵ���Ǽ���N!�Ķ����Ʊ�ʾ������м�λ0��Ҳ���Ǽ���N!�к���������2�ĸ���
int lowestOne(int N)
{
    int res = 0;
    while(N)
    {
        res = res + N>>1;
        N = N >> 1;
    }
    return res;
}

int main(int args,char ** argv)
{
    int N = 6;
    int res = zeroInFactorialEnd2(N);
    int res2 = lowestOne(N);
    std::cout<<res2<<std::endl;

    system("pause");
    return 0;
}
#endif
