
/*
copyright@nciaebupt ת����ע������
��Ŀ����֪һ���������������0�ĸ�����p������1�ĸ�����1-p������Ҫ�㹹��һ����������ʹ��������0��1�ĸ��ʾ�Ϊ1/2������һ����������ʹ��������1��2��3�ĸ��ʾ�Ϊ1/3��...������һ����������ʹ��������1��2��3��...n �ĸ��ʾ�Ϊ1/n��Ҫ���Ӷ���͡�
������1/2�����������һ��������������ֵ�������00����11�������������£�01Ϊ1��10Ϊ0�����ǵĸ��ʶ���p*(1-p)����ȵģ����Եȸ����ˡ�
Ȼ����1/n������ˣ�������5Ϊ������ʱ����ȡx=2����ΪC(2x,x)=C(4,2)=6�Ǳ�5�����С��x����ʱ���Ǿ���һ��������4λ�����ƣ���1���ָ�������2�Ķ���������ʱ��ʣ����
��:0011,0101,0110,1001,1010,1100��ȡ��С��5����������1100����ô���Ƕ���ǰ5���ֱ���1��5����ʱ�����ǵĸ��ʶ���p*p*(1-p)*(1-p)����ˡ�
�ؼ������Ǹ���С��x��ʹ��C(2x,x)>=n��������������Ч�ʡ�

��ΪC(n,i)�������i�ӽ�n/2�ĵط�ȡ�ã���ʱ���и�����ʵ������������ɣ����仰˵���׵��ĸ����ˣ���������Ϊ�˱�����������˶������ж�ʹ���������ʼ�����ʵ������֮���Խ�xȡ����Ϊ������ȡ�õ��������ɵĸ��ʻ�����ȣ�����C(2x,x)�ĸ��ʾ���[p(1-p)]^x�����ȵ������ռ��ڱ�֤�˶�Ӧ��ÿ��ֵȡ�õ������ȸ��ʡ�

ʹ����֪���������������n��������������k��1�ĸ�����n!/(k!*(n-k)!)*p^k*(1-p)^(n-k)


��Ѷ������:

��֪�и�rand7()�ĺ���������1��7�����Ȼ�������������rand7()����rand10() ���1~10��

���õķ������ϸ��������ƣ�����ܹ��õ�һ���ȸ��ʵĶ����¼������������ϸ����ⲻͬ���ǣ�������������У�Ҫ��ɺ͵���ʽ������������ʽ����ô���ʾͻᷢ���仯�ˡ�

����ܹ��õ�һ��ȸ��ʵ�����������ʲô����ֻҪ�ȸ��ʶ��Ҹ�������10����ô����Ϳ��Խ���ˡ�

����(rand7()-1)*7+rand7(),���Եȸ��ʵ�����1��49��

�Ǻǣ��ⲻ�͵��ˣ�ֻҪ��11-49�����Ϳ����ˡ�����������Ч�ʱȽϵ͡����Կ���41-49��Ȼ���ڰ�1-40ӳ�䵽1-10����ô����Ҳ�ͽ���ˡ�

��Ѷ������:

�ȸ��ʲ����������е����֡�

������������еȸ��ʵĲ���k�����֡�

��ô���أ����õ��ʼ��k�����֣�Ȼ���Ժ��ÿ�����ֵȸ��ʵĺ���k�����ֽ�������ô�Ϳ��Դﵽÿ�����ֱ���ȡ�ĸ����ǵȸ��ʵġ�

��ô֤���أ�

���ù��ɷ���������ǰn�����ֵȸ��ʵĲ���k�����֣���ôÿ�����ֱ������ĸ���Ϊk/n,��������һ�����֣������n+1�����֣���ôÿ�����ֱ������ĸ��ʱ�λk/(n+1),����Ҫ֤�����

��������ڼ��������������������ᵽ����Reservoir Sampling����ˮ�ز���������������㷨��һ�֡�

���ڼٶ�������n�����֣����˵�n+1�����֣���ô��n+1�����ֱ�ѡ��ĸ�����k/n+1,��ô�����������������ֱ�ѡ��ĸ���Ҳ��k/n+1

P(��������) = p(��������|��n+1��ѡ��)*p(��n+1��ѡ��) + p(��������|��n+1����ѡ��)*p(��n+1����ѡ��)

                      =  k/n*(1-1/k)*k/(n+1) + k/n*(n+1-k)/(n+1)

                      = k*(k-1) / (n *(n+1) ) + k*(n+1-k) / (n*(n+1))

                      = k*n/(n *(n+1))

                      = k/(n+1)

��֤���������ֱ�ѡ��ĸ�����ȻҲ�� k/(n+1)
*/