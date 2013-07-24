#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ����n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��ΪS������n����ӡ��S������
���ܵ�ֵ���ֵĸ��ʡ�
���������û����ĸ�����֪ʶ��������Ҫͳ�����п��ܵ�S���ֵĴ�����Ϊ�˷��㣬����������ĳ��S���ֵĸ��ʣ���ΪP(S),����
    P(S) = P(S1) + P(S2) + ... + P(Sk)

S1,S2...Sk��ʾ��ΪS�ĸ���������ϡ����⣬

    P(Si) = P(a1) + P(a2) + ... + P(an)

���У�P(ai)��ʾ��i�����ӳ���ֵΪai�ĸ��ʡ�

�ܼ򵥵ģ�����һ�������۵Ķ������ܻ����ġ�����Ҫͳ�����п��ܵ�S���ֵĴ�������ֱ�Ӽ����ΪS�ĸ��ֿ��ܵ�������ϵĸ��ʣ�Ȼ���������ϵĸ�����ӣ��͵õ��˺�ΪS�ĸ����ˡ�
���ַ�����DP�еı�񷨣��������������ķ�ʽ���ѽ����������ñ�񷨣�һ�д���һ�����ӣ��б�ʾ����Sֵ������һ����6*N�С�������Ҫ��N�еģ���������ֻ����һ����ά�����飬��Ϊ���ڼ����ֵֻ��ǰһ�μ����ֵ��أ���������һ�б�����һ�μ���Ľ������һ�б������ڼ���Ľ�����������Խ�ʡ�����Ŀռ䡣

�����е�N��ָ�м������ӣ�����˵�����˼������ӡ���һ��forѭ����ʾ��һ�����ӵ������Ȼ��ڶ���forѭ���е�k��ʾ��k�����ӡ������˵�k������ʱ���ڲ��forѭ����ʼ�Ժ͸�S��ֵ���з�����i��ʾ�ľ��Ǹ�����ͬ��S�������ѭ������ǵ�k�����ӵ�6�ֲ�ͬȡֵ��j��ʾ�ľ������ӵĵ�������Ȼ����whileѭ��������п��ܵĵõ���ΪS����ϵĸ��ʽ�����ӡ�flag�����úܼ򵥣������ڶ�ά������Ե�ʱֵ���Ѿ�����õ���ֵ����������ֻ������������кŴ���
*/
#include <cstdlib>
#include <iostream>
#define MAXVALUE 6

int sumOfNDice(int n){
  if(n < 1){
    return -1;
  }
  double pProbabilities[2][MAXVALUE*n + 1];
  int flag = 1;
  for(int i = 0; i < MAXVALUE*n + 1; ++i){
    pProbabilities[flag][i] = 0.0;
    pProbabilities[1-flag][i] = 0.0;
  }
  for(int i = 1; i <= MAXVALUE; ++i){//��ɸ����Ϊ1ʱ
    pProbabilities[flag][i] = 1.0/6;
  }
  for(int k = 2; k <= n; ++k){//��������Ϊ2-nʱ
    for(int i = k; i <= MAXVALUE*k; ++i){
      pProbabilities[1-flag][i] = 0;
      for(int j = 1; j <= i && j <= MAXVALUE; ++j){
        pProbabilities[1-flag][i] += pProbabilities[flag][i-j]/6;
      }
    }
    flag = 1 - flag;
  }
  for(int i = 0; i <= MAXVALUE*n; ++i){
    std::cout<<pProbabilities[flag][i]<<std::endl;
  }
  return 1;
}
int main(int argc, char ** argv)
{
  int n = 2;
  sumOfNDice(n);
  system("pause");
  return 0;
}
#endif
