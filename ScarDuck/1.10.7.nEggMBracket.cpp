#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ����N��������M�����ӣ��Ѽ����ŵ�M�������ÿ�����Ӷ�����Ϊ�ա����⣬��Ҫ���㣺����һ��С��N����������������ĳ���������ڵ���������ӵĺ͵õ���д������ʹ������һ��(N,M)��������п��ܵķ��������
��������������Ӧ�ÿ��Եó�������(1,1,2,2)��(1,2,1,2)��������ϣ�Ӧ����һ���ġ�
���������M�������еļ�������������������basket[M]����ʾ�����ǰ��շǵݼ�˳��������У���basket[i] <= basket[i+1]

1.�������ù��ɷ����ܽ��һ�����ɣ�
   ����ǰn�����ӣ��伦�������ܺ�ΪSn����ô���ڵ�n+1�����ӣ��伦������Ӧ�����㣺
   basket[n+1] <= Sn + 1�����basket[n+1] > Sn + 1����ôSn + 1��������޷�ͨ����Ӧ�����Ӽ������������á�
   �����Ƿǵݼ����У����
   basket[n] <= basket[n+1] <= Sn + 1
2.������֤��������ʽ�������ܹ���������������һ��С��N����������������ĳ���������ڵ���������ӵĺ͵õ�����
   ��M = 1ʱ��basket[0] = 1����M=2ʱ��ȡbasket[1] = 1���ܹ���������������
   ȡbasket[1] = 2��Ҳ�ܹ���������������
   ����M = n-1ʱ����������������������֤����M = nʱ�����㡣
   ǰn-1�����ӵļ��������ܺ�ΪSn-1����ʱ���ϵ�n�����ӣ��ܺ�ΪSn = Sn-1 + basket[n-1]����֤��Sn - 1��Sn - 2��Sn - 3��Sn - (basket[n-1] - 1)��������ĳ���������ڵ���������ӵĺ͵õ�������basket[n-1] <= Sn-1������С�ڻ��ߵ���Sn-1��������ĳ���������ڵ���������ӵĺ͵õ�������Sn - 1��Sn - 2��Sn - 3��Sn - (basket[n-1] - 1)��ɵõ���
   ֤�ϡ�

3.����N��M��ֵ������������󼴿���һ���жϡ�
   2.1  ��N < M������������Ϊ�գ����������
   2.2  ��N >= Mʱ����һ�����ӱ�ȻҪ��1���������������������ǰ���basket[n] <= basket[n+1] <= Sn + 1ȡ���ֵ������Ϊ2,4,8,16......����������Ϊ2^M - 1����M�����ӵļ����������ֵ��

   ����M <= N < 2^M
*/
#include <cstdlib>
#include <cmath>
#include <iostream>

void nEggMBracket(int cur_sum, int cur_num, int bracket_id, int * bracket, int N, int M)
{
  if(cur_sum == N && cur_num == M){
    for(int i = 0; i < M; ++i){
      std::cout<<bracket[i];
    }
    std::cout<<std::endl;
    return;
  }
  if(cur_sum + cur_num*(M - bracket_id) > N){//prune
    return;
  }
  if(cur_sum + (cur_sum+1)*(pow(2, M-bracket_id)-1) < N){//prune
    return;
  }
  for(int i = cur_num; i <= cur_sum + 1; ++i){
    bracket[bracket_id] = i;
    nEggMBracket(cur_sum+i, i, bracket_id+1, bracket, N, M);
  }
}

int main(int argc, char ** argv)
{
  int N = 6;
  int M = 3;
  int * bracket = new int[M];
  nEggMBracket(0, 1, 0, bracket, N, M);


  //system("pause");
  return 0;
}


#endif


























