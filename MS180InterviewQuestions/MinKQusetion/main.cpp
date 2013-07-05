/*
 *寻找最小的k个数
 *题目描述：5.查找最小的k个元素
 *题目：输入n个整数，输出其中最小的k个。
 *例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4。
 *
 *Randomized-Select方法，线性期望时间
 *时间复杂度O(n)
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int random(int min,int max)
{
	time_t t;
	srand((unsigned) time(&t));
	int i=int(rand()%(max-min+1))+min;
}
void exchange(vector<int>& vi,int i,int j)
{
	int tmp = vi[i];
	vi[i] = vi[j];
	vi[j] = tmp;
}
int partition(vector<int>& vi,int start,int end)
{
	int key = vi[end];
	int i = start -1;
	for(int j = start;j < end;++j)
	{
		if(vi[j] < key)
		{
			++i;
			exchange(vi,i,j);
		}
	}
	exchange(vi,i+1,end);
	return i+1;
}
int randomized_partition(vector<int>& vi,int start,int end)
{

	int i = random(start,end);
	exchange(vi,i,end);

	return partition(vi,start,end);
}
int randomized_select(vector<int>& vi,int start,int end,int i)
{
	if(start == end) return vi[start];
	else if(start < end)
		{
			int q = randomized_partition(vi,start,end);
			int k = q - start + 1;
			if(i == k)	return vi[q];
			else if(i < k)
			{
				return randomized_select(vi,start,q-1,i);
			}
			else
				return randomized_select(vi,q+1,end,i-k);
		}
}
int main(int argc,char **argv)
{
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(5);
	vi.push_back(4);
	vi.push_back(6);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(8);
	vi.push_back(7);
	int k = 3;
	for(int i = 1;i <=vi.size();++i)
	{
		int res = randomized_select(vi,0,vi.size()-1,i);
		cout<<res<<endl;
	}

	return 0;
}




/*
 *寻找最小的k个数
 *题目描述：5.查找最小的k个元素
 *题目：输入n个整数，输出其中最小的k个。
 *例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4。
 *
 *Randomized-Select方法，线性期望时间
 *时间复杂度O(n)

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int random(int min,int max)
{
	time_t t;
	srand((unsigned) time(&t));
	int i=int(rand()%(max-min+1))+min;
}
void exchange(vector<int>& vi,int i,int j)
{
	int tmp = vi[i];
	vi[i] = vi[j];
	vi[j] = tmp;
}
int partition(vector<int>& vi,int start,int end)
{
	int key = vi[end];
	int i = start -1;
	for(int j = start;j < end;++j)
	{
		if(vi[j] < key)
		{
			++i;
			exchange(vi,i,j);
		}
	}
	exchange(vi,i+1,end);
	return i+1;
}
int randomized_partition(vector<int>& vi,int start,int end)
{
	return partition(vi,start,end);
}
int randomized_select(vector<int>& vi,int start,int end,int i)
{
	if(start == end) return vi[start];
	else if(start < end)
		{
			int q = randomized_partition(vi,start,end);
			int k = q - start + 1;
			if(i == k)	return vi[q];
			else if(i < k)
			{
				return randomized_select(vi,start,q-1,i);
			}
			else
				return randomized_select(vi,q+1,end,i-k);
		}
}
int main(int argc,char **argv)
{
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(5);
	vi.push_back(4);
	vi.push_back(6);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(8);
	vi.push_back(7);
	int k = 3;
	//cout<<randomized_select(vi,0,vi.size()-1,6)<<endl;
	for(int i = 1;i <=vi.size();++i)
	{
		int res = randomized_select(vi,0,vi.size()-1,i);
		cout<<res<<endl;
	}
	return 0;
}

*/




/*
 *寻找最小的k个数
 *题目描述：5.查找最小的k个元素
 *题目：输入n个整数，输出其中最小的k个。
 *例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4。
 *
 *采用维护k个元素的最大堆的方法来实现
 *时间复杂度为O(n*logk)

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
int leftChild(int i)
{
	return 2*i + 1;
}
int rightChild(int i)
{
	return 2*i +2;
}
int parent(int i)
{
	return (i+1)/2 -1;
}
bool exchange(vector<int>& vi,int i,int j)
{
	int tmp = vi[i];
	vi[i] = vi[j];
	vi[j] =tmp;
}

void heap_max_adjust(vector<int>& vi,int n,int index)
{
	assert(index <= n);
	int large = index;
	int left = leftChild(index);
	int right = rightChild(index);
	if(left <= n && vi[left] > vi[large])
	{
		large = left;
	}
	if(right <= n && vi[right] > vi[large])
	{
		large = right;
	}
	if(large != index)
	{
		int tmp = vi[index];
		vi[index] = vi[large];
		vi[large] = tmp;
		heap_max_adjust(vi,n,large);
	}
}

void heap_make(vector<int>& vi,int n)
{
	int partition = n/2 -1;
	for(int i = partition; i >= 0;--i)
	{
		heap_max_adjust(vi,n,i);
	}
}

int main(int argc,char **argv)
{
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(5);
	vi.push_back(4);
	vi.push_back(6);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(8);
	vi.push_back(7);
	int k = 3;
	heap_make(vi,k-1);
	for(int i = k;i < vi.size(); ++i)
	{
		if(vi[i] < vi[0])
		{
			exchange(vi,0,i);
			heap_max_adjust(vi,k,0);
		}
	}
	for(int i = 0; i < k; ++i)
	{
		cout<<vi[i]<<" ";
	}
	cout<<endl;
	return 0;
}
 */


/*
 *寻找最小的k个数
 *题目描述：5.查找最小的k个元素
 *题目：输入n个整数，输出其中最小的k个。
 *例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4。
 *
 *采用维护n个元素的最小堆的方法来实现
 *时间复杂度为O(n*logk)

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
int leftChild(int i)
{
	return 2*i + 1;
}
int rightChild(int i)
{
	return 2*i +2;
}
int parent(int i)
{
	return (i+1)/2 -1;
}
bool exchange(vector<int>& vi,int i,int j)
{
	int tmp = vi[i];
	vi[i] = vi[j];
	vi[j] =tmp;
}
void heap_min_adjust(vector<int>& vi,int n,int index)
{
	assert(index <= n);
	int min = index;
	int left = leftChild(index);
	int right = rightChild(index);
	if(left <= n && vi[left] < vi[min])
	{
		min = left;
	}
	if(right <= n && vi[right] < vi[min])
	{
		min = right;
	}
	if(min != index)
	{
		int tmp = vi[index];
		vi[index] = vi[min];
		vi[min] = tmp;
		heap_min_adjust(vi,n,min);
	}
}
void heap_make(vector<int>& vi,int n)
{
	int partition = n/2 -1;
	for(int i = partition; i >= 0;--i)
	{
		heap_min_adjust(vi,n,i);
	}
}
int main(int argc,char **argv)
{
	vector<int> vi;
	vi.push_back(5);
	vi.push_back(1);
	vi.push_back(4);
	vi.push_back(6);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(8);
	vi.push_back(7);
	heap_make(vi,vi.size()-1);
	int k = 3;
	//cout<<vi[0]<<endl;
	for(int i = 0;i < k; ++i)
	{
		cout<<vi[0]<<endl;
		exchange(vi,0,vi.size()-1);
		vi.pop_back();
		heap_min_adjust(vi,vi.size()-1,0);
	}

	return 0;
}
 */





/*
 *寻找最小的k个数
 *题目描述：5.查找最小的k个元素
 *题目：输入n个整数，输出其中最小的k个。
 *例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4。
 *
 *将最小的k个数放在大小为k的数组中，找到其中的最大数kmax与其后的n-k个数交换
 * 时间复杂度 O(n*k)

#include <iostream>
#include <vector>
using namespace std;
bool exchange(vector<int>& vi,int i, int j)
{
	int tmp = vi[i];
	vi[i] = vi[j];
	vi[j] = vi[i];
}
int kmax(vector<int>& vi,int k)
{
	int maxi = 0;
	for(int i= 0;i < k; i++)
	{
		if(vi[maxi] < vi[i]){
			maxi = i;
		}
	}
	return maxi;
}
bool exchangeMax(vector<int>& vi,int k)
{
	int maxi = kmax(vi,k);
	for(int i = k;i < vi.size();i++)
	{
		if(vi[maxi] > vi[i]){
			exchange(vi,maxi,i);
			maxi = kmax(vi,k);
		}
	}
}
int main(int argc, char **argv)
{
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(5);
	vi.push_back(4);
	vi.push_back(6);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(8);
	vi.push_back(0);
	cout<<vi.size()<<endl;
	exchangeMax(vi,3);
	cout<<vi[0]<<" "<<vi[1]<<" "<<vi[2]<<endl;
	return 0;
}
*/






/*
 *寻找最小的k个数
 *题目描述：5.查找最小的k个元素
 *题目：输入n个整数，输出其中最小的k个。
 *例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4。
 *
 * 先快速排序，然后输出前k个元素
 * 时间复杂度O(n*logn)
#include <iostream>
#include <vector>
using namespace std;
void exchange(vector<int>& vi,int i,int j)
{
	int tmp = vi[i];
	vi[i] = vi[j];
	vi[j] = tmp;
}
int partition(vector<int>& vi,int start,int end)
{
	int key = vi[end];
	int i = start -1;
	for(int j = start;j < end;++j)
	{
		if(vi[j] < key)
		{
			++i;
			exchange(vi,i,j);
		}
	}
	exchange(vi,i+1,end);
	//cout<<i+1<<endl;
	return i+1;
}
void quicksort(vector<int>& vi,int start,int end)
{
	if(start < end)
	{
		int q = partition(vi,start,end);
		//cout<<q<<endl;
		quicksort(vi,start,q-1);
		quicksort(vi,q+1,end);
	}
}
int main(int argc,char** argv)
{
	vector<int> vi;
	int k = 3;
	vi.push_back(1);
	vi.push_back(5);
	vi.push_back(4);
	vi.push_back(6);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(8);
	vi.push_back(7);
	//cout<<vi.size()<<endl;
	quicksort(vi,0,vi.size()-1);
	for(int i = 0;i < k;++i)
	{
		cout<<vi[i]<<" ";
	}
	cout<<endl;
	return 0;
}
 */
















































