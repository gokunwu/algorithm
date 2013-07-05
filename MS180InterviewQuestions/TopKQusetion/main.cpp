










/* auther wukun
 * 搜索引擎热门查询统计
 * 题目描述：搜索引擎会通过日志文件把用户每次检索使用的所有检索串都记录下来，
 * 每个查询串的长度为1-255字节。
 * 假设目前有一千万个记录（这些查询串的重复度比较高，虽然总数是1千万，
 * 但如果除去重复后，不超过3百万个。一个查询串的重复度越高，说明查询它的用户越多，
 * 也就是越热门。），请你统计最热门的10个查询串，要求使用的内存不能超过1G。
 *
 * 先用hash统计每个查询串的大小，然后维护10元素的小根堆。
 * 时间复杂度 O（N）+ N'*O（logK）
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <assert.h>
#include <cstdlib>
using namespace std;

#define HASHLEN 3000000
#define WORDLEN 255

struct node_hash
{
	string word;
	int count;
	node_hash * next;
};
struct node_heap
{
	string word;
	int count;
};
//hash函数，这里使用最简单常用的乘法hash函数
int hash_function(const string & str)
{
	int value = 0;
	for(int i = 0; i < str.length(); ++i)
	{
		value = value*31 + str[i];
		if(value > HASHLEN)
			value = value % HASHLEN;
	}
	return value;
}
node_hash* findWordInList(bool & flag,node_hash * hashnode,const string str)
{
	node_hash * p = hashnode;
	while(p != NULL)
	{
		if(p->word == str)
		{
			flag = true;
			return p;
		}
		else
		{
			p = p->next;
		}
	}
}
int data2hash(vector<node_hash>& hash,string str)
{
	int index = hash_function(str);
	node_hash * hashnode = &hash[index];
	if(hashnode->next == NULL)//如果hash表的index这个节点是未被占用的节点，那么插入数据
	{
		node_hash * p = new node_hash;
		p->word = str;
		p->count = 1;
		p->next = NULL;
		hashnode->next = p;
	}
	else//否则，这个节点被占用了，那么则在链接表中查找是否存在这个单词
	{
		bool flag = false;
		node_hash * q = findWordInList(flag,hashnode->next,str);
		if(flag)//找到相应的单词，count++
		{
			q->count = q->count + 1;
		}
		else//没找到的话在链表头添加节点，加入单词
		{
			node_hash * p = new node_hash;
			p->word = str;
			p->count = 1;
			p->next = NULL;
			hashnode->next = p;
		}
	}
	return 0;
}
int writeHash2file(string filename,vector<node_hash> & hash)
{
	ofstream outfile(filename.c_str(),ofstream::out);
	for(vector<node_hash>::iterator it = hash.begin();it != hash.end();it++)
	{
		if(it->next != NULL)//hash节点的next指针不为空才表示此index中有数据
		{
			node_hash * p =it->next;
			while(p != NULL)
			{
				outfile<<p->word<<" "<<p->count<<endl;
				p = p->next;
			}
		}
	}
	return 0;
}
int leftChild(int i)
{
	return 2*i +1;
}
int rightChild(int i)
{
	return 2*i +2;
}
void exchange(vector<node_heap*> &heap,int i,int j)
{
		node_heap *tmp = new node_heap;
		tmp->word = heap[i]->word;
		tmp->count = heap[i]->count;
		heap[i]->word = heap[j]->word;
		heap[i]->count = heap[j]->count;
		heap[j]->word = tmp->word;
		heap[j]->count = tmp->count;
}
//从上向下调整，保持小根堆属性
bool heapMinAdjust(vector<node_heap*> &heap,int heaplen,int index)
{
	assert(index < heaplen);
	int min = index;
	int left = leftChild(index);
	int right = rightChild(index);
	if(left < heaplen && heap[left]->count < heap[min]->count)
		min = left;
	if(right < heaplen && heap[right]->count < heap[min]->count)
		min = right;
	if(min != index)
	{
		exchange(heap,min,index);
		heapMinAdjust(heap,heaplen,min);
	}
}
//创建小根堆
bool creatMinHeap(vector<node_heap*>& heap,int heaplen)
{
	int partition = heaplen/2 -1;
	for(int i = partition;i >= 0;--i)
	{
		heapMinAdjust(heap,heaplen,i);
	}
	return true;
}

int main(int argc, char **argv)
{
	int k = 5;//TOPK中的k，也就是出现最多的k个查询
	//建立hash表 大小为300,0000，并初始化hash表
	vector<node_hash> hash(HASHLEN);
	for(vector<node_hash>::iterator it = hash.begin();it !=hash.end();it++)
	{
		it->word = "";
		it->count = 0;
		it->next = NULL;
	}
	//从文件中读取一千万个查询传，并且映射到hash表中
	string str = "";
	string filename_in = "E:\\C++ Project\\MS180InterviewQuestions\\TopKQusetion\\searchWord.txt";
	ifstream infile(filename_in.c_str(),ifstream::in);

	while(getline(infile,str))
	{
		data2hash(hash,str);
	}
	infile.close();
	//将hash中统计的结果写入文件中，格式word count
	string filename_out = "E:\\C++ Project\\MS180InterviewQuestions\\TopKQusetion\\WordFren.txt";
	writeHash2file(filename_out.c_str(),hash);
	//将文件中的数据读出来，加载到heap中
	vector<node_heap*> heap;
	string filename_heap = "E:\\C++ Project\\MS180InterviewQuestions\\TopKQusetion\\WordFren.txt";
	ifstream infile_heap(filename_heap.c_str(),ifstream::in);
	while(getline(infile_heap,str))
	{
		string heapword = str.substr(0,str.find(" "));
		string heapcountstring = str.substr(str.find(" ") + 1);
		int heapcount = atoi(heapcountstring.c_str());
		node_heap *heapnode = new node_heap;
		heapnode->word = heapword;
		heapnode->count = heapcount;
		heap.push_back(heapnode);
		//delete heapnode;
	}
	//调用函数creatMinHeap(vector<node_heap>& heap,int heaplen)创建小根堆
	creatMinHeap(heap,k-1);
	//对后边的heap.size()个值与heap中的k个值中最小的比较，若大于，则交换
	for(int i = k;i < heap.size();++i)
	{
		if(heap[i]->count > heap[0]->count)
		{
			exchange(heap,i,0);
			heapMinAdjust(heap,k,0);
		}
	}
	for(int j = 0;j < k;++j)
	{
		cout<<heap[j]->word<<" "<<heap[j]->count<<endl;
	}
	cout<<"The program is finished!\n"<<endl;

	return 0;
}
