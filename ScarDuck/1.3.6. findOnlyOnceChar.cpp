
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ����һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b
��������һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b
�����ͷ������������ַ����бȽϳ��ִ����Ƿ�Ϊ1���㷨���Ӷ�ΪO(n^ 2)��
�����Կռ任ʱ�䣬��Ϊһ���ַ���������ֽڣ�ռ8λ����˿���һ��256
λ���鱣��ÿ���ַ����ֵĴ���
*/
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>

int main(int args,char ** argv)
{
    char *pstr = "abaccdeff";
    int len = strlen(pstr);
    int cnt[256];
    for(int i = 0;i < 256;++i)
    {
        cnt[i] = 0;
    }
    for(int i = 0;i < len;++i)
    {
        cnt[int(pstr[i])]++;
    }
    for(int i = 0;i <256;++i)
    {
        if(cnt[i] == 1)
        {
            printf("%c\n",i);
        }
    }

    system("pause");
    return 0;
}
#endif
