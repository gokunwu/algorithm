
#if 0

#include <cstdlib>
#include <iostream>
#include<vector>

using namespace std;

int main(int argc, char *argv[])
{
    //cout<<"i am a boy!"<<endl;
	bool Insertion_sort(vector<int>::iterator begin,vector<int>::iterator end);
	vector<int> ivec;
	ivec.push_back(5);
	ivec.push_back(2);
	ivec.push_back(4);
	ivec.push_back(6);
	ivec.push_back(1);
	ivec.push_back(3);
    for(vector<int>::size_type i=0;i<ivec.size();i++)
	{
		cout<<ivec[i]<<endl;
	}
	cout<<endl;
	Insertion_sort(ivec.begin(),ivec.end());
	for(vector<int>::size_type i=0;i<ivec.size();i++)
	{
		cout<<ivec[i]<<endl;
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}


void Insertion_sort(vector<int>::iterator begin,vector<int>::iterator end)
{
	for(vector<int>::iterator it=begin+1;it!=end;it++)
	{
		int key=*it;
		for(vector<int>::iterator itj=it-1;itj!=begin-1;itj--)
		{
			if(*itj>key)
			{
				*(itj+1)=*itj;
				*itj=key;
			}
			else break;
		}
	}

}
#endif


