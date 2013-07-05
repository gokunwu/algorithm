
#if 0
/*
*copyright@nciaebupt ת����ע������
*���⣺����������a,b����С��Ϊn,����Ԫ�ص�ֵ��������������
*Ҫ��ͨ������a,b�е�Ԫ�أ�ʹ[����aԪ�صĺ�]��[����bԪ�صĺ�]֮��Ĳ���С��
*���� a=[100 ,99 ,98 ,1 ,2 ,3]; b=[1, 2, 3, 4, 5, 40];���Ϊ48
*���˼·:ʹ�ö�̬�滮��˼·
*   ��׶Σ���ǰi�����н���ѡ��i=1,2...2*n��
*   �ڽ׶Σ�����i����������ѡ��j������j=1,2...i��
*   ״̬����j�����ĺ�Ϊs��s=1,2...sum/2��
*   ���ߣ�������j�����ĺ������־��ߣ�һ������j�����а�����i��������һ���ǲ�������i������
*   dp[k][s]��ʾ��ǰk������ȡ�������������Щ��֮��Ϊs��ȡ���Ƿ���ڡ�
*�ڳ��������Ǹ���S(k)�����п���ȡֵv��arr[k],ȥѰ��v-arr[k]�Ƿ���S(k-1)={Vi}�У�
*����S(k)�Ŀ���ȡֵ�ļ��ϵĴ�С��k�޹أ�
*����������ƵĶ�̬�滮�㷨���k����ʱ�临�Ӷ���k�޹�
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 101
#define MAXSUM 100000
bool dp[MAXN][MAXSUM];

int c_sum(int *c,int len)
{
    int sum = 0;
    for(int i = 0;i < len;++i)
    {
        sum = sum + c[i];
    }
    return sum;
}

int min(int a,int b)
{
    if(a < b)
        return a;
    else
        return b;
}

void exchangeAB(int * c,int len)
{
    int sum = c_sum(c,2*len);
    memset(dp,0,sizeof(dp));
    dp[0][0] = true;
    //��׶�i��ʾ��i�������ڽ׶�j��ʾѡȡ���ĸ���
    for(int i = 1;i <= 2*len;++i)//��׶�i
    {
        for(int j = min(i,len);j >=1;--j)//�ڽ׶�j
        {
            for(int s = 1;s <= sum/2;++s)//S(k)�����п���ȡֵs
            {
                if((s >= c[i]) && dp[j-1][s-c[i]])//j�������Ƿ������i����
                {
                    dp[j][s]=true;
                    //cout<<s<<endl;
                }
            }
        }
    }
    int s = sum/2;
    for(;s>=1 && !dp[len][s];s--)
        ;
    cout<<sum - 2*s<<endl;

}

int main(int args,char ** argv)
{
    //int a[] = {100 ,99 ,98 ,1 ,2 ,3};
    //int b[] = {1, 2, 3, 4, 5, 40};
    int a[] = {-3,9,10,65};
    int b[] = {5,6,13,55};
    int len = sizeof(a)/sizeof(int);
    //������a��b�е�ֵ��������c��
    int c[MAXN];
    int pos = 0;
    for(int i = 0;i <= len;++i)
    {
        c[i] = a[i];
        pos = i;
    }
    for(int j = 0;j <= len;++j)
    {
        c[pos+j] = b[j];
    }

    for(int i = 0;i < 2*len;++i)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
    exchangeAB(c,len);
    system("pause");
    return 0;
}
#endif


#if 0
/*
*copyright@nciaebupt ת����ע������
*���⣺����������a,b����С��Ϊn,����Ԫ�ص�ֵ��������������
*Ҫ��ͨ������a,b�е�Ԫ�أ�ʹ[����aԪ�صĺ�]��[����bԪ�صĺ�]֮��Ĳ���С��
*���� a=[100 ,99 ,98 ,1 ,2 ,3]; b=[1, 2, 3, 4, 5, 40];���Ϊ48
*���˼·:
*��ǰ����a������b�ĺ�֮��Ϊ
*A = sum(a) - sum(b)
*a�ĵ�i��Ԫ�غ�b�ĵ�j��Ԫ�ؽ�����a��b�ĺ�֮��Ϊ
*A' = sum(a) - a[i] + b[j] - ��sum(b) - b[j] + a[i])
*	 = sum(a) - sum(b) - 2 (a[i] - b[j])
*    = A - 2 (a[i] - b[j])
*��x = a[i] - b[j]
*���� A' = A-2x
*����A > 0,
*��x �� (0,A)֮��ʱ���������Ľ�������ʹ�ý������a��b�ĺ�֮���С��
*xԽ�ӽ�A/2Ч��Խ��,
*����Ҳ�����(0,A)֮���x����ǰ��a��b���Ǵ𰸡�
*�����㷨������£�
*��a��b��Ѱ��ʹ��x��(0,A)֮�䲢����ӽ�A/2��i��j��������Ӧ��i��jԪ�أ�
*���¼���A���ظ�ǰ��Ĳ���ֱ���Ҳ���(0,A)֮���xΪֹ��
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int sum(int a[],int len)
{
    int res = 0;
    for(int i=0;i<len;++i)
    {
        res = res + a[i];
    }
    return res;
}

void swap(int * a,int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool isXinRangeA(int x,int A)
{
    if((x < A && x > 0) ||(x > A && x < 0))
        return true;
    return false;
}

void exchangeAB(int *a, int *b,int len)
{
    int A = sum(a,len) - sum(b,len);
    double min = a[0]-b[0]-A/2.0;
    int ii = 0;
    int jj = 0;
    int flag = 0;
    if(A == 0)
        return ;
    for(int i = 0;i < len;++i)
    {
        for(int j = 0;j < len;++j)
        {
            int x = a[i] - b[j];
            if( x == 0)
                continue;
            if(isXinRangeA(x,A))
            {
                double tmp = x - A/2.0;
                if(tmp < min)
                {
                    min = tmp;
                    flag = 1;
                    ii = i;
                    jj = j;
                    cout<<"***"<<endl;
                }
            }
        }
    }
    if(flag == 1)
    {
        swap(&a[ii],&b[jj]);
        exchangeAB(a,b,len);
    }

}

int main(int args,char ** argv)
{
    //int a[] = {100 ,99 ,98 ,1 ,2 ,3};
    //int b[] = {1, 2, 3, 4, 5, 40};
    int a[] = {-3,9,10,65};
    int b[] = {5,6,13,55};
    int len = sizeof(a)/sizeof(int);
    exchangeAB(a,b,len);
    //��ӡ����A
    for(int i = 0;i < len;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    //��ӡ����B
    for(int j = 0;j < len;++j)
    {
        cout<<b[j]<<" ";
    }
    cout<<endl;
    //��ӡ����A�ĺ�������B�ĺ͵Ĳ�ֵ
    cout<<abs(sum(a,len)-sum(b,len))<<endl;

    system("pause");
    return 0;
}
//���ֽⷨ����ȱ�ݵģ��õ��Ľ������һ��������ֵ
//һ����ĿҪ����ǲ�ֵ��С�ķ��������Խ���һ�������ǲ���ʵ�ֵġ�
//������󽻻�һ�������޷�ʹ��ֵ��С�����Ǵ���ͬʱ��������(���и����)���ݿ��Լ�С��ֵ�Ŀ��ܡ�
//����������зֱ���[-3,9,10,65]��[5,6,13,55]��������㷨��������Ž��ˡ�
//������Ȼ[-3,5,13,65]��[6,9,10,55]���á�
#endif

#if 0
/*
*copyright@nciaebupt ת����ע������
*���⣺��һ������ɸ���������ٵ���ʹ�ô������ҿ�����Щ���Ǵ�С�����ٴӴ�С�ģ����ף���
*��������1,4,3,5,6,7,2,0 ɾ�������ٵ����ĸ���Ϊ1
*���˼·��˫��LIS���⣬ʹ�ö�̬�滮��˼·��⣬ʱ�临�Ӷ�O(nlog(n))
*/
#include <cstdio>
#include <iostream>

using namespace std;

int DoubleEndLIS(int *array,int len)
{
    int left,mid,right;
    int max=0;
    int k =0;

    //LIS�����д洢���� ���������������ֵ��С�������е����һ��Ԫ�أ����Ԫ�أ���array�е�λ��
    int *LIS = new int[len];
    //������LIS��������������ֵ��С�������е����һ��Ԫ�����ڵ�λ��,Ҳ����0~i����������������������еĳ���-1
    int *B = new int[len];
    //���ҵ���LIS��������������ֵ��С�������е����һ��Ԫ�����ڵ�λ��,Ҳ����len-1~i����������������������еĳ���-1
    int *C = new int[len];
    //������
    for(int i = 0;i < len;++i)//LIS��������
    {
        B[i] = 0;
        LIS[i] = 0;
    }
    LIS[0] = array[0];
    for(int i = 1;i < len;++i)
    {
        left = 0;
        right = B[k];
        while(left <= right)
        {
            mid = (left + right)/2;
            if(array[i] < LIS[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        LIS[left] = array[i];//��array[i]���뵽LIS��
        if(left > B[k])
        {
            B[k+1] = B[k] + 1;
            k++;
        }
    }
    for(int i = 0;i < k;++i)
    {
        B[i]++;
    }
    //���ҵ���
    for(int i = 0;i < len;++i)//LIS��������
    {
        C[i] = 0;
        LIS[i] = 0;
    }
    k = 0;
    LIS[0] = array[len-1];
    for(int i = len-2;i >= 0;--i)
    {
        left = 0;
        right = C[k];
        while(left <= right)
        {
            mid = (left + right)/2;
            if(array[i] < LIS[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        LIS[left] = array[i];
        if(left > C[k])
        {
            C[k+1] = C[k] + 1;
            k++;
        }
    }
    for(int i = 0;i <= k;++i)
    {
        C[i]++;
    }

    //��max
    for(int i = 0;i < len;++i)
    {
        //cout<<B[i]<<"  "<<C[i]<<endl;
        if(B[i]+C[i]>max)
            max=B[i] + C[i];
    }

    return len - max +1;
}

int main(int args,char ** argv)
{
    int array[] = {1,4,3,5,6,7,2,0};
    int len = sizeof(array)/sizeof(int);
    int res = DoubleEndLIS(array,len);
    cout<<res<<endl;
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt ת����ע������
*���⣺�������������������
*дһ��ʱ�临�ӶȾ����ܵ͵ĳ�����һ��һά���飨N��Ԫ�أ��е�����������еĳ��ȡ�
*���磺������1��-1,2��-3,4��-5,6��-7�У�����ĵ���������Ϊ1,2,4,6,�����������
*�ĳ���Ϊ4��
*���˼·��ʹ�ö�̬�滮+���ֲ����㷨 ʱ�临�Ӷ�O(nlog(n))
*/
#include <cstdio>
#include <iostream>

using namespace std;

int LIS(int *array,int len)
{
    int *LIS = new int[len];//LIS�����д洢���� ���������������ֵ��С�������е����һ��Ԫ�أ����Ԫ�أ���array�е�λ��
    int left,mid,right;
    int max=1;
    LIS[0]=array[0];
    for(int i = 1;i < len;++i)
    {
        left = 0;
        right = max;
        while(left <=right)
        {
            mid = (left+right)/2;
            if(LIS[mid] < array[i])
                left = mid +1;
            else
                right = mid -1;
        }
        LIS[left] = array[i];//����
        if(left > max)
        {
            max++;
        }
    }
    delete LIS;
    return max;
}

int main(int args,char **argv)
{
    int array[] = {1,-1,2,-3,4,-5,6,-7};
    int len = sizeof(array)/sizeof(int);
    int res = LIS(array,len);
    cout<<res<<endl;
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt ת����ע������
*���⣺�������������������
*дһ��ʱ�临�ӶȾ����ܵ͵ĳ�����һ��һά���飨N��Ԫ�أ��е�����������еĳ��ȡ�
*���磺������1��-1,2��-3,4��-5,6��-7�У�����ĵ���������Ϊ1,2,4,6,�����������
*�ĳ���Ϊ4��
*���˼·��ʹ�ö�̬�滮�㷨 ʱ�临�Ӷ�O(n^2)
*/
#include <cstdio>
#include <iostream>

using namespace std;

int MAX(int *LIS,int len)
{
    int max = 0;
    for(int i = 0;i < len;++i)
    {
        cout<<i<<"  "<<LIS[i]<<endl;
        if(LIS[i] > max)
            max = LIS[i];
    }
    return max;
}

int LIS(int *array,int len)
{
    int *LIS = new int[len];//���ڼ�¼��ǰ��Ԫ����Ϊ���Ԫ�ص���������г���
    for(int i = 0;i < len;++i)
    {
        LIS[i] = 1;//���õ�ǰԪ��array[i]��Ϊ���Ԫ�ص���������г���Ϊ1
        for(int j = 0; j < i;++j)
        {
            if(array[i] > array[j] && LIS[j] + 1 > LIS[i])
            {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    int res = MAX(LIS,len);
    delete LIS;
    return res;//���LIS�е����ֵ�����أ�
}

int main(int args,char ** argv)
{
    int array[] = {1,-1,2,-3,4,-5,6,-7};
    int len = sizeof(array)/sizeof(int);
    int res = LIS(array,len);
    cout<<res<<endl;
    getchar();
    return 0;
}
#endif


#if 0
/*
*copyright@nciaebupt ת����ע������
*���⣺������������n��m��������1��2��3��...��n������ȡ��������
*ʹ��͵���m���������п��ܵ�����г�����
*���˼·��(�������)
*���ݷ�����ٷ��ĸĽ������ݷ�ͨ����֦��������ٵ�ʱ�临�Ӷ�
*���ݷ���Ҫʹ������ռ�����¼�⼯��
*/
#include <iostream>
#include <cstdio>

using namespace std;

void backTrack(int m,int n,int *x,int pos,int sum,int cur)
{
    if(sum == m)//���sum==m��ݹ��������ӡ���
    {
        for(int i = 0;i < pos;++i)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    //�����дӵ�ǰλ��cur��������n
    for(int i = cur;i <= n;++i)
    {
        if(sum > m)//��֦���ݹ����
            return;
        if(sum < m)//��С��m�������ݹ�
        {
            x[pos++] = i;
            backTrack(m,n,x,pos,sum+i,i+1);
            pos--;//���ݿ���,��Ϊ�����漰���Ƿ�Ҫ���i������ڵ�
        }
    }
}

int main(int args,char ** argv)
{
    int m = 10;//Ҫ��ĺ�
    int n = 8;//����
    int x[n+1];//��¼��ռ�
    int pos = 0;//��¼x�����е�λ��
    int sum = 0;//�������еĺͣ���ʼ��Ϊ0
    backTrack(10,8,x,pos,0,1);//��һ�ε�����ʼ�����ͳ�ʼֵΪ0��������ʼֵΪ1
    getchar();
    return 0;
}
/*
1 2 3 4
1 2 7
1 3 6
1 4 5
2 3 5
2 8
3 7
4 6
*/
#endif

#if 0
/*
*copyright@nciaebupt ת����ע������
*���⣺������������n��m��������1��2��3��...��n������ȡ��������
*ʹ��͵���m���������п��ܵ�����г�����
*���˼·��(�ݹ����)
*(1)���n>m��������>m�Ĳ��ֲ����ܲ�����ϣ�����n=m
*(2)��������������n���벢��m==n����������н��
*(3)�����n���������У���n=n-1,m = m-n,�ݹ�
*(4)�������n���������У���n=n-1,m = m,�ݹ�
*(5)ʹ�����鱣�����е�����
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void zeroOneBag(vector<int> vi,int m,int n)
{
    if(n > m)//���n>m��������>m�Ĳ��ֲ����ܲ�����ϣ�����n=m
        n = m;
    if(m < 1 |n < 1)
        return;
    if(m == n)//��������������n���벢��m==n����������н��
    {
        vi[n] = 1;
        for(int i = 0;i < vi.size();++i)
        {
            if(vi[i])
                cout<<i<<" ";
        }
        cout<<endl;
    }
    //�����n���������У���n=n-1,m = m-n,�ݹ�
    vi[n] = 1;
    zeroOneBag(vi,m-n,n-1);
    //�������n���������У���n=n-1,m = m,�ݹ�
    vi[n] = 0;
    zeroOneBag(vi,m,n-1);

}

int main(int args,char ** argv)
{
    int m = 10;
    int n = 8;
    vector<int> vi;
    for(int i = 0;i < n + 1;++i)
    {
        vi.push_back(0);
    }
    zeroOneBag(vi,m,n);

    getchar();
    return 0;
}
/*
2 8
3 7
1 2 7
4 6
1 3 6
1 4 5
2 3 5
1 2 3 4
*/
#endif

#if 0
/*
*copyright@nciaebupt ת����ע������
*��Ŀ������һ�������һ�����֣��������в�����������
*ʹ�����ǵĺ�������������Ǹ����֡�
*����ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�
*������������1��2��4��7��11��15������15������4+11=15��������4��11��
*��������������ʹ��hash�ķ������ӿ�����ٶ�
*ʱ�临�Ӷ�O(N) �ռ临�Ӷ�O(N)
*/
#include <cstdio>
#define HASHLEN 100

struct HashNode
{
    int num;
    HashNode *next;
};

int hashFunction(int key)
{
    int value = 0;
    double SEED = 0.618;//Knuth����ѡȡ0.6180339887
    int m = 31;
    double tmp =key * SEED;
    value = int(m * (tmp - int(tmp)));
    return value;
}

int searchNum(HashNode * hashtable,int *array,int len,int sum,int &num1,int &num2)
{
    for(int i = 0;i < len;++i)
    {

        int pos = hashFunction(array[i]);
        HashNode * p = hashtable[pos].next;
        while(p != NULL)
        {
            if(p->num == array[i])
            {
                num1 = array[i];
                num2 = sum - array[i];
                return 1;
            }
            p = p->next;
        }
    }
    return 0;
}

int main(int args,char ** argv)
{
    int array[] = {1,2,15,7,11,4};
    int sum = 15;
    HashNode * hashtable = new HashNode[HASHLEN];
    for(int i =0 ;i < HASHLEN;++i)
    {
        hashtable[i].next = NULL;
    }
    for(int i = 0;i < sizeof(array)/sizeof(int);++i)
    {
        int pos = hashFunction(sum - array[i]);
        HashNode * p = new HashNode();
        p->num = sum - array[i];
        p->next = hashtable[pos].next;
        hashtable[pos].next = p;
    }
    int num1;
    int num2;
    int flag = searchNum(hashtable,array,sizeof(array)/sizeof(int),sum,num1,num2);
    printf("%d  %d  %d\n",flag,num1,num2);
    getchar();
    return 0;
}
#endif


#if 0
/*
*copyright@nciaebupt ת����ע������
*��Ŀ������һ�������һ�����֣��������в�����������
*ʹ�����ǵĺ�������������Ǹ����֡�
*����ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�
*������������1��2��4��7��11��15������15������4+11=15��������4��11��
*���������������ȿ�������Ȼ��������ָ������ɨ��
*ʱ�临�Ӷ�O(NlogN) +O(NlogN) = O(NlogN) �ռ临�Ӷ�O(1)
*/
#include <cstdio>

int exchange(int *array,int i,int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    return 1;
}

int partition(int *array,int left,int right)
{
    int i = left - 1;
    int key = array[right];
    for(int j = left;j < right;++j)
    {
        if(array[j] < key)
        {
            i = i + 1;
            exchange(array,i,j);
        }
    }
    exchange(array,i + 1,right);
    return i + 1;
}

int quickSort(int *array,int left,int right)
{
    if(left < right)
    {
        int k = partition(array,left,right);
        quickSort(array,left,k - 1);
        quickSort(array,k + 1,right);
    }
    return 0;
}
int findConditionedNum(int &num1,int &num2,int *array,int len,int sum)
{
    int left = 0;
    int right = len - 1;
    while(left < right)
    {
        if((array[left] + array[right]) == sum)
        {
            num1 = array[left];
            num2 = array[right];
            return 1;
        }
        else
        {
            if((array[left] + array[right]) > sum)
                right--;
            else if((array[left] + array[right]) < sum)
                left++;
        }
    }
    return 0;
}
int main(int args,char ** argv)
{
    int array[] = {1,2,15,7,11,4};
    int sum = 15;
    int num1 = 0;
    int num2 = 0;
    quickSort(array,0,sizeof(array)/sizeof(int)-1);
    for(int j = 0; j <sizeof(array)/sizeof(int); ++j)
    {
        printf("%d\n",array[j]);
    }
    int flag=findConditionedNum(num1,num2,array,sizeof(array)/sizeof(int),sum);
    printf("%d  %d  %d\n",flag,num1,num2);
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt ת����ע������
*��Ŀ������һ�������һ�����֣��������в�����������
*ʹ�����ǵĺ�������������Ǹ����֡�
*����ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�
*������������1��2��4��7��11��15������15������4+11=15��������4��11��
*���������������ȿ�������Ȼ���ٶ��ֲ���
*��Ŀ�൱�ڣ���ÿ��a[i]��Ȼ������ж�sum-a[i]�Ƿ�Ҳ��ԭʼ�����У�����ÿ��a[i]��
*���ֲ���sum-a[i]�Ƿ���ԭʼ������
*ʱ�临�Ӷ�O(NlogN) +O(NlogN) = O(NlogN)   �ռ临�Ӷ�O(1)
*/

#include <cstdio>

int exchange(int *array,int i,int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    return 1;
}

int partition(int *array,int left,int right)
{
    int key = array[right];
    int i = left - 1;
    for(int j = left;j < right;++j)
    {
        if(array[j] < key)
        {
            i = i + 1;
            exchange(array,i,j);
        }
    }
    exchange(array,i+1,right);
    return i+1;
}

int quickSort(int *array,int left,int right)
{
    if(left < right)
    {
        int k = partition(array,left,right);
        quickSort(array,left,k - 1);
        quickSort(array,k + 1,right);
    }
    return 1;
}

int binarySearch(int *array,int len,int a)
{
    int low = 0;
    int high = len - 1;
    int mid = 0;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(array[mid] == a)
            return 1;
        else
        {
            if(array[mid] < a)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return 0;
}

int findConditionedNum(int &num1,int &num2,int *array,int len,int sum)
{
    for(int i = 0;i < len;++i)
    {
        int a = sum - array[i];
        int flag = binarySearch(array,len,a);
        if(flag == 1)
        {
            num1 = array[i];
            num2 = a;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int array[] = {1,2,15,7,11,4};
    int sum = 15;
    int num1 = 0;
    int num2 = 0;
    quickSort(array,0,sizeof(array)/sizeof(int) - 1);
    int a = findConditionedNum(num1,num2,array,sizeof(array)/sizeof(int),sum);
    printf("%d  %d  %d\n",a,num1,num2);
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt ת����ע������
*��Ŀ������һ�������һ�����֣��������в�����������
*ʹ�����ǵĺ�������������Ǹ����֡�
*����ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�
*������������1��2��4��7��11��15������15������4+11=15��������4��11��
*�����������������ֲ��ҷ���
*��Ŀ�൱�ڣ���ÿ��a[i]��Ȼ������ж�sum-a[i]�Ƿ�Ҳ��ԭʼ�����У�����ÿ��a[i]��
*���ֲ���sum-a[i]�Ƿ���ԭʼ������
*ʱ�临�Ӷ�O(NlogN)   �ռ临�Ӷ�O(1)
*/

#include <cstdio>

int binarySearch(int *array,int len,int a)
{
    int low = 0;
    int high = len - 1;
    int mid = 0;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(array[mid] == a)
            return 1;
        else
        {
            if(array[mid] < a)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return 0;
}

int findConditionedNum(int &num1,int &num2,int *array,int len,int sum)
{
    for(int i = 0;i < len;++i)
    {
        int a = sum - array[i];
        int flag = binarySearch(array,len,a);
        if(flag == 1)
        {
            num1 = array[i];
            num2 = a;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int array[] = {1,2,4,7,11,15};
    int sum = 15;
    int num1 = 0;
    int num2 = 0;
    int a = findConditionedNum(num1,num2,array,sizeof(array)/sizeof(int),sum);
    printf("%d  %d  %d\n",a,num1,num2);
    getchar();
    return 0;
}
#endif
