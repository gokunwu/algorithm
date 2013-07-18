
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ�����˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�2-10
Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С�����Կ����������֡�
˼·һ:
������Ҫ���˿��Ƶı�������ɼ�������ԡ������������ǿ��԰�5���ƿ�����5������
��ɵ����顣��С������������֣����ǲ��������Ƕ�����0�������������˿��ƴ������
�־Ͳ��ظ��ˡ�
���������������������ж�5�������ǲ��������ġ���ֱ�۵��ǣ����ǰ��������򡣵�ֵ��
ע����ǣ�����0���Ե����������֣����ǿ�����0ȥ���������еĿ�ȱ��Ҳ��������֮��
�����鲻�������ģ������ڵ���������������ɸ����֣�������������㹻��0���Բ�����
�������ֵĿ�ȱ���������ʵ���ϻ��������ġ��ٸ����ӣ���������֮��Ϊ{0��1��3��4��
5}����1��3֮���ȱ��һ��2���պ�������һ��0��Ҳ�������ǿ���������2ȥ����
��ȱ��
����������Ҫ���������飺����������ͳ��������0�ĸ�����ͳ������֮�������������
��֮��Ŀ�ȱ�����������ȱ������С�ڻ��ߵ���0�ĸ�������ô���������������ģ���
֮��������������ǻ���Ҫע����ǣ���������еķ�0�����ظ����֣�������鲻��
�����ġ������˿��Ƶ�������ʽ���������һ�����ﺬ�ж��ӣ��򲻿�����˳�ӡ�

���õ�˼·��:
1��ȷ��5�����г���0����������û���ظ��ģ������ñ�ͳ�Ƶķ�����;
2) �����������߼�����max��min�ֱ����5�����еĳ�0��������ֵ��Сֵ��
       ���û��0����max-min=4����Ϊ˳�ӣ�������
       �����һ��0����max-min=4����3����Ϊ˳�ӣ�������
       ���������0����max-min=4����3����2����Ϊ˳�ӣ�������
���ֵ����Сֵ��1���оͿ��Ի�ã������Ͳ���������
*/
#include <cstdlib>
#include <iostream>
#define POKER_CNT 14
#define MAX 10000
#define MIN -10000

bool isJunko(int * poker, int len)
{
  if(poker == NULL || len < 0){
    return false;
  }
  int poker_hash[POKER_CNT];
  for(int i = 0; i < POKER_CNT; ++i){
    poker_hash[i] = 0;
  }
  int poker_max = MIN;
  int poker_min = MAX;
  for(int i = 0; i < len; ++i){
    if(poker[i] != 0 && poker_max < poker[i]){
      poker_max = poker[i];
    }
    if(poker[i] != 0 && poker_min > poker[i]){
      poker_min = poker[i];
    }
    poker_hash[poker[i]]++;
  }
  int zero_cnt = poker_hash[0];
  for(int i = 0; i < POKER_CNT; ++i){
    if(poker_hash[i] > 1){
      return false;
    }
  }
  switch(zero_cnt){
    case 0:
      if(poker_max - poker_min == 4){
        return true;
      }
      else{
        return false;
      }
      break;
    case 1:
      if((poker_max - poker_min == 4) || (poker_max - poker_min == 3)){
        return true;
      }
      else{
        return false;
      }
      break;
    case 2:
      if((poker_max - poker_min == 3) || (poker_max - poker_min == 2)){
        return true;
      }
      else{
        return false;
      }
      break;
  }
}

int main(int argc, char ** argv)
{
  int poker[] = {2,3,4,5,6};
  int len = sizeof(poker)/sizeof(poker[0]);
  bool flag = isJunko(poker, len);
  std::cout<<flag<<std::endl;
  system("pause");
  return 0;
}
#endif
