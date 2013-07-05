#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ:Tango��΢�������о�Ժ��һ��������Ŀ���о�Ժ��Ա����ʵϰ���Ƕ���ϲ����Tango���潻����ˮ����˵��Tango��һ��ˮ������������ϲ������������ظ�����ID����ÿ�����ӡ�������Ÿá�ˮ����������Ŀ����������������һ�롣�������һ����ǰ��̳���������ӣ��������������б������������ߵ�IDҲ�ڱ��У����ܿ����ҳ������˵�е�Tangoˮ����
���������ÿ��ɾ��������ͬ��id����ʣ�µ�ˮ��id��Ȼ����������һ�룬���Բ����ظ�������̡�
1.��candidate��¼����ˮ��������������nTimes��¼��
2.���Լ������ӵĵ�һ��ID�Ǵ������ģ�nTimes=1��
3. ������һ��ID�������candidateһ����nTimes++����������һ������ˮ���������ӣ������������ˮ������һ������ɾ����Ҳ����nTimes--�����nTimes == 0����ô˵����ǰ�ĺ�ѡ����ˮ����������һ�����µ�ˮ����
4.����������nTimes>0���Ǹ�candidate����ˮ��ID�����ǻ�ʤ�ߡ�
*/
#include <cstdlib>
#include <iostream>

int findWhoPostMost(int *array,int len)
{
    int candidate = -1;
    int nTimes = 0;
    for(int i = 0;i < len;++i)
    {
        if(nTimes == 0)
        {
            candidate = array[i];
            nTimes = 1;
        }
        else
        {
            if(candidate == array[i])
                nTimes++;
            else
                nTimes--;
        }
    }
    return candidate;
}

int main(int args,char ** argv)
{
    int array[] = {1,2,3,2,3,4,3,3,2,3,1,3,3,5,6,3,3,3};
    int len = sizeof(array)/sizeof(int);
    int res = findWhoPostMost(array,len);
    std::cout<<res<<std::endl;
    system("pause");
    return 0;
}
#endif
