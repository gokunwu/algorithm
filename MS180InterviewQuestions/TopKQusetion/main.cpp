










/* auther wukun
 * �����������Ų�ѯͳ��
 * ��Ŀ���������������ͨ����־�ļ����û�ÿ�μ���ʹ�õ����м���������¼������
 * ÿ����ѯ���ĳ���Ϊ1-255�ֽڡ�
 * ����Ŀǰ��һǧ�����¼����Щ��ѯ�����ظ��ȱȽϸߣ���Ȼ������1ǧ��
 * �������ȥ�ظ��󣬲�����3�������һ����ѯ�����ظ���Խ�ߣ�˵����ѯ�����û�Խ�࣬
 * Ҳ����Խ���š���������ͳ�������ŵ�10����ѯ����Ҫ��ʹ�õ��ڴ治�ܳ���1G��
 *
 * ����hashͳ��ÿ����ѯ���Ĵ�С��Ȼ��ά��10Ԫ�ص�С���ѡ�
 * ʱ�临�Ӷ� O��N��+ N'*O��logK��
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
//hash����������ʹ����򵥳��õĳ˷�hash����
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
	if(hashnode->next == NULL)//���hash���index����ڵ���δ��ռ�õĽڵ㣬��ô��������
	{
		node_hash * p = new node_hash;
		p->word = str;
		p->count = 1;
		p->next = NULL;
		hashnode->next = p;
	}
	else//��������ڵ㱻ռ���ˣ���ô�������ӱ��в����Ƿ�����������
	{
		bool flag = false;
		node_hash * q = findWordInList(flag,hashnode->next,str);
		if(flag)//�ҵ���Ӧ�ĵ��ʣ�count++
		{
			q->count = q->count + 1;
		}
		else//û�ҵ��Ļ�������ͷ��ӽڵ㣬���뵥��
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
		if(it->next != NULL)//hash�ڵ��nextָ�벻Ϊ�ղű�ʾ��index��������
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
//�������µ���������С��������
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
//����С����
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
	int k = 5;//TOPK�е�k��Ҳ���ǳ�������k����ѯ
	//����hash�� ��СΪ300,0000������ʼ��hash��
	vector<node_hash> hash(HASHLEN);
	for(vector<node_hash>::iterator it = hash.begin();it !=hash.end();it++)
	{
		it->word = "";
		it->count = 0;
		it->next = NULL;
	}
	//���ļ��ж�ȡһǧ�����ѯ��������ӳ�䵽hash����
	string str = "";
	string filename_in = "E:\\C++ Project\\MS180InterviewQuestions\\TopKQusetion\\searchWord.txt";
	ifstream infile(filename_in.c_str(),ifstream::in);

	while(getline(infile,str))
	{
		data2hash(hash,str);
	}
	infile.close();
	//��hash��ͳ�ƵĽ��д���ļ��У���ʽword count
	string filename_out = "E:\\C++ Project\\MS180InterviewQuestions\\TopKQusetion\\WordFren.txt";
	writeHash2file(filename_out.c_str(),hash);
	//���ļ��е����ݶ����������ص�heap��
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
	//���ú���creatMinHeap(vector<node_heap>& heap,int heaplen)����С����
	creatMinHeap(heap,k-1);
	//�Ժ�ߵ�heap.size()��ֵ��heap�е�k��ֵ����С�ıȽϣ������ڣ��򽻻�
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
