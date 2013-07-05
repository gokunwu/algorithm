
#if 0
/*
*copyright@nciaebupt 转载请注明出处
*问题：有两个序列a,b，大小都为n,序列元素的值任意整数，无序；
*要求：通过交换a,b中的元素，使[序列a元素的和]与[序列b元素的和]之间的差最小。
*比如 a=[100 ,99 ,98 ,1 ,2 ,3]; b=[1, 2, 3, 4, 5, 40];结果为48
*求解思路:使用动态规划的思路
*   外阶段：在前i个数中进行选择，i=1,2...2*n。
*   内阶段：从这i个数中任意选出j个数，j=1,2...i。
*   状态：这j个数的和为s，s=1,2...sum/2。
*   决策：决定这j个数的和有两种决策，一个是这j个数中包含第i个数，另一个是不包含第i个数。
*   dp[k][s]表示从前k个数中取任意个数，且这些数之和为s的取法是否存在。
*在程序中我们给出S(k)的所有可能取值v和arr[k],去寻找v-arr[k]是否在S(k-1)={Vi}中，
*由于S(k)的可能取值的集合的大小与k无关，
*所以这样设计的动态规划算法其第k步的时间复杂度与k无关
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
    //外阶段i表示第i个数，内阶段j表示选取数的个数
    for(int i = 1;i <= 2*len;++i)//外阶段i
    {
        for(int j = min(i,len);j >=1;--j)//内阶段j
        {
            for(int s = 1;s <= sum/2;++s)//S(k)的所有可能取值s
            {
                if((s >= c[i]) && dp[j-1][s-c[i]])//j个数中是否包含第i个数
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
    //将数组a与b中的值放在数组c中
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
*copyright@nciaebupt 转载请注明出处
*问题：有两个序列a,b，大小都为n,序列元素的值任意整数，无序；
*要求：通过交换a,b中的元素，使[序列a元素的和]与[序列b元素的和]之间的差最小。
*比如 a=[100 ,99 ,98 ,1 ,2 ,3]; b=[1, 2, 3, 4, 5, 40];结果为48
*求解思路:
*当前数组a和数组b的和之差为
*A = sum(a) - sum(b)
*a的第i个元素和b的第j个元素交换后，a和b的和之差为
*A' = sum(a) - a[i] + b[j] - （sum(b) - b[j] + a[i])
*	 = sum(a) - sum(b) - 2 (a[i] - b[j])
*    = A - 2 (a[i] - b[j])
*设x = a[i] - b[j]
*所以 A' = A-2x
*假设A > 0,
*当x 在 (0,A)之间时，做这样的交换才能使得交换后的a和b的和之差变小，
*x越接近A/2效果越好,
*如果找不到在(0,A)之间的x，则当前的a和b就是答案。
*所以算法大概如下：
*在a和b中寻找使得x在(0,A)之间并且最接近A/2的i和j，交换相应的i和j元素，
*重新计算A后，重复前面的步骤直至找不到(0,A)之间的x为止。
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
    //打印数组A
    for(int i = 0;i < len;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    //打印数组B
    for(int j = 0;j < len;++j)
    {
        cout<<b[j]<<" ";
    }
    cout<<endl;
    //打印数组A的和与数组B的和的差值
    cout<<abs(sum(a,len)-sum(b,len))<<endl;

    system("pause");
    return 0;
}
//这种解法是有缺陷的，得到的结果并不一定是最优值
//一，题目要求的是差值最小的方案，所以交换一对数据是不能实现的。
//二，最后交换一对数据无法使差值减小，但是存在同时交换两对(还有更多对)数据可以减小差值的可能。
//如果两个序列分别是[-3,9,10,65]和[5,6,13,55]，按你的算法这就是最优解了。
//可是显然[-3,5,13,65]和[6,9,10,55]更好。
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*问题：从一列数中筛除尽可能少的数使得从左往右看，这些数是从小到大再从大到小的（网易）。
*比如数列1,4,3,5,6,7,2,0 删除的最少的数的个数为1
*求解思路：双端LIS问题，使用动态规划的思路求解，时间复杂度O(nlog(n))
*/
#include <cstdio>
#include <iostream>

using namespace std;

int DoubleEndLIS(int *array,int len)
{
    int left,mid,right;
    int max=0;
    int k =0;

    //LIS数组中存储的是 递增子序列中最大值最小的子序列的最后一个元素（最大元素）在array中的位置
    int *LIS = new int[len];
    //从左到右LIS中最长子序列中最大值最小的子序列的最后一个元素所在的位置,也就是0~i的数字序列中最长递增子序列的长度-1
    int *B = new int[len];
    //从右到左LIS中最长子序列中最大值最小的子序列的最后一个元素所在的位置,也就是len-1~i的数字序列中最长递增子序列的长度-1
    int *C = new int[len];
    //从左到右
    for(int i = 0;i < len;++i)//LIS数组清零
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

        LIS[left] = array[i];//将array[i]插入到LIS中
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
    //从右到左
    for(int i = 0;i < len;++i)//LIS数组清零
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

    //求max
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
*copyright@nciaebupt 转载请注明出处
*问题：求数组中最长递增子序列
*写一个时间复杂度尽可能低的程序，求一个一维数组（N个元素）中的最长递增子序列的长度。
*例如：在序列1，-1,2，-3,4，-5,6，-7中，其最长的递增子序列为1,2,4,6,最长递增子序列
*的长度为4。
*求解思路：使用动态规划+二分查找算法 时间复杂度O(nlog(n))
*/
#include <cstdio>
#include <iostream>

using namespace std;

int LIS(int *array,int len)
{
    int *LIS = new int[len];//LIS数组中存储的是 递增子序列中最大值最小的子序列的最后一个元素（最大元素）在array中的位置
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
        LIS[left] = array[i];//插入
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
*copyright@nciaebupt 转载请注明出处
*问题：求数组中最长递增子序列
*写一个时间复杂度尽可能低的程序，求一个一维数组（N个元素）中的最长递增子序列的长度。
*例如：在序列1，-1,2，-3,4，-5,6，-7中，其最长的递增子序列为1,2,4,6,最长递增子序列
*的长度为4。
*求解思路：使用动态规划算法 时间复杂度O(n^2)
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
    int *LIS = new int[len];//用于记录当前各元素作为最大元素的最长递增序列长度
    for(int i = 0;i < len;++i)
    {
        LIS[i] = 1;//设置当前元素array[i]作为最大元素的最长递增序列长度为1
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
    return res;//获得LIS中的最大值并返回；
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
*copyright@nciaebupt 转载请注明出处
*问题：输入两个整数n和m，从数列1，2，3，...，n中随意取几个数，
*使其和等于m，将其所有可能的组合列出来。
*求解思路：(回溯求解)
*回溯法是穷举法的改进，回溯法通过剪枝来降低穷举的时间复杂度
*回溯法需要使用数组空间来记录解集合
*/
#include <iostream>
#include <cstdio>

using namespace std;

void backTrack(int m,int n,int *x,int pos,int sum,int cur)
{
    if(sum == m)//如果sum==m则递归结束，打印组合
    {
        for(int i = 0;i < pos;++i)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    //将数列从当前位置cur向后遍历到n
    for(int i = cur;i <= n;++i)
    {
        if(sum > m)//剪枝，递归结束
            return;
        if(sum < m)//和小于m，继续递归
        {
            x[pos++] = i;
            backTrack(m,n,x,pos,sum+i,i+1);
            pos--;//回溯控制,因为这里涉及到是否要添加i这个树节点
        }
    }
}

int main(int args,char ** argv)
{
    int m = 10;//要求的和
    int n = 8;//数列
    int x[n+1];//记录解空间
    int pos = 0;//记录x数组中的位置
    int sum = 0;//求解过程中的和，初始化为0
    backTrack(10,8,x,pos,0,1);//第一次迭代初始化，和初始值为0，数列起始值为1
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
*copyright@nciaebupt 转载请注明出处
*问题：输入两个整数n和m，从数列1，2，3，...，n中随意取几个数，
*使其和等于m，将其所有可能的组合列出来。
*求解思路：(递归求解)
*(1)如果n>m则数列中>m的部分不可能参与组合，设置n=m
*(2)将数列中最大的数n加入并且m==n，则输出排列结果
*(3)如果将n放入排列中，则n=n-1,m = m-n,递归
*(4)如果不将n放入排列中，则n=n-1,m = m,递归
*(5)使用数组保存排列的序列
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void zeroOneBag(vector<int> vi,int m,int n)
{
    if(n > m)//如果n>m则数列中>m的部分不可能参与组合，设置n=m
        n = m;
    if(m < 1 |n < 1)
        return;
    if(m == n)//将数列中最大的数n加入并且m==n，则输出排列结果
    {
        vi[n] = 1;
        for(int i = 0;i < vi.size();++i)
        {
            if(vi[i])
                cout<<i<<" ";
        }
        cout<<endl;
    }
    //如果将n放入排列中，则n=n-1,m = m-n,递归
    vi[n] = 1;
    zeroOneBag(vi,m-n,n-1);
    //如果不将n放入排列中，则n=n-1,m = m,递归
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
*copyright@nciaebupt 转载请注明出处
*题目：输入一个数组和一个数字，在数组中查找两个数，
*使得它们的和正好是输入的那个数字。
*如果有多对数字的和等于输入的数字，输出任意一对即可。
*例如输入数组1、2、4、7、11、15和数字15。由于4+11=15，因此输出4和11。
*数组无序的情况，使用hash的方法来加快查找速度
*时间复杂度O(N) 空间复杂度O(N)
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
    double SEED = 0.618;//Knuth建议选取0.6180339887
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
*copyright@nciaebupt 转载请注明出处
*题目：输入一个数组和一个数字，在数组中查找两个数，
*使得它们的和正好是输入的那个数字。
*如果有多对数字的和等于输入的数字，输出任意一对即可。
*例如输入数组1、2、4、7、11、15和数字15。由于4+11=15，因此输出4和11。
*数组无序的情况，先快速排序然后再两个指针两端扫描
*时间复杂度O(NlogN) +O(NlogN) = O(NlogN) 空间复杂度O(1)
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
*copyright@nciaebupt 转载请注明出处
*题目：输入一个数组和一个数字，在数组中查找两个数，
*使得它们的和正好是输入的那个数字。
*如果有多对数字的和等于输入的数字，输出任意一对即可。
*例如输入数组1、2、4、7、11、15和数字15。由于4+11=15，因此输出4和11。
*数组无序的情况，先快速排序然后再二分查找
*题目相当于，对每个a[i]，然后查找判断sum-a[i]是否也在原始序列中，对于每个a[i]，
*二分查找sum-a[i]是否在原始序列中
*时间复杂度O(NlogN) +O(NlogN) = O(NlogN)   空间复杂度O(1)
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
*copyright@nciaebupt 转载请注明出处
*题目：输入一个数组和一个数字，在数组中查找两个数，
*使得它们的和正好是输入的那个数字。
*如果有多对数字的和等于输入的数字，输出任意一对即可。
*例如输入数组1、2、4、7、11、15和数字15。由于4+11=15，因此输出4和11。
*数组有序的情况，二分查找法，
*题目相当于，对每个a[i]，然后查找判断sum-a[i]是否也在原始序列中，对于每个a[i]，
*二分查找sum-a[i]是否在原始序列中
*时间复杂度O(NlogN)   空间复杂度O(1)
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
