
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ�����������1�ĸ���������һ���ֽڣ�8bit���ı�������������Ʊ�ʾ��"1"�ĸ�����Ҫ���㷨��ִ��Ч�ʾ����ܵĸߡ�
*/
#include <cstdlib>
#include <iostream>

int numOf1InBinary(int num)
{
    int count = 0;
    while(num)
    {
        num = num & (num-1);
        count++;
    }
    return count;
}


int main(int args,char ** argv)
{
    int num = 7;
    int res = numOf1InBinary(num);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

#endif

