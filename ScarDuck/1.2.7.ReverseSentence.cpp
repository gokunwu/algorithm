
#if 0
/*
*copyright@nciaebupt ת����ע������
*����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣�����е����Կո�
*��������Ϊ������������ź���ͨ��ĸһ��������������I am a *student.�������student. a am I��
���������ڱ�д�ַ�����ش����ܹ���ӳ����Ա�ı�������ͱ��ϰ�ߣ����ַ�����ص�����һֱ�ǳ���Ա���ԡ��������������Ŀ������Ҳ������ܵ�����΢�����ڵĴ�����˾��������
���ڱ�����Ҫ��ת���ӣ������ȵߵ������е������ַ�����ʱ��������ת�˾����е��ʵ�˳�򣬶��ҵ������ַ�Ҳ����ת�ˡ������ٵߵ�ÿ�������ڵ��ַ������ڵ����ڵ��ַ�����ת���Σ����˳����Ȼ������ʱ��˳�򱣳�һ�¡�
���������������Ϊ���ӡ���תI am a student.�������ַ��õ�.tneduts a ma I���ٷ�תÿ���������ַ���˳��õ�students. a am I�����Ƿ���Ҫ��������
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















