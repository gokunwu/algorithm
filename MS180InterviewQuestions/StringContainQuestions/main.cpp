
/*
 * ��Ŀ������Ҫ��ʵ�ֿ⺯��strcpy
 * ԭ��������extern char *strcpy(char *dest,char *src);
 * ���ܣ���src��ָ��NULL�������ַ������Ƶ�dest��ָ�������С� ��
 * ˵����src��dest��ָ�ڴ����򲻿����ص���dest�������㹻�Ŀռ�������src���ַ����� ��
 * ����ָ��dest��ָ�롣
 *
 *
#include <iostream>
#include <assert.h>
using namespace std;

char* strcpy(char* dest,char* src)
{
	//assert((dest != NULL) && (src != NULL));
	char* address=dest;
	while((*dest++ = *src++) != '/0');
	return address;
}

int main(int argc,char **argv)
{
	char* src="abc";
	char* dest="def";
	dest=strcpy(dest,src);
	cout<<*dest<<endl;

	return 0;
}
*/

/*
 * ���ַ���ת��Ϊ����
 *
 *
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

int str2int(string str)
{
	assert(str.length() > 0);
	int pos=0;
	int symbol=1;

	if(str[pos] == '+')
		pos++;
	else if(str[pos] == '-')
	{
		pos++;
		symbol=-1;
	}

	int num=0;
	while(pos < str.length())
	{
		assert(str[pos] >= '0');
		assert(str[pos] <= '9');

		num=num*10 +str[pos]-'0';

		assert(num >=0);
		pos++;
	}
	num=num*symbol;
	return num;
}

int main()
{
	string str="345";
	cout<<str2int(str)<<endl;
	return 0;
}

*/


/*
 * ��Ŀ����һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b��
 * hashtable�ķ���
 *
#include <iostream>
#include <string>
using namespace std;

char FirstNotRepeatChar(string &str)
{
	int hash[256]={0};
	for(string::iterator it=str.begin();it != str.end();it++)
	{

		hash[*it]++;
	}
	for(string::iterator it=str.begin();it !=str.end();it++)
	{
		if(hash[*it] == 1)
		{
			return (*it);
		}
	}
}

int main(int argc, char **argv)
{
	string str="abaccdeff";
	cout<<FirstNotRepeatChar(str)<<endl;
	return 0;
}
*/

/*
 * ��Ŀ����һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b��
 * bitmap�ķ��� Cʵ��
 *
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define CHARARRAYSIZE 4 //����ֻ��26��СдӢ����ĸ����ֻ��Ҫ4*8=32 > 26��bit
#define CHARSIZE 8 //һ��charΪ8���ֽ�
#define SHIFT 3 //�ƶ�3λ�������൱�ڳ���8�������൱�ڳ���8ȡ��

int bitset(char * bitmap,int num)//���߼�λ��Ϊn�Ķ�����λ��Ϊ1
{
    //num>>SHIFT����3λ�൱�ڳ���8�����ֽ�λ�ã�num%CHARSIZE��8ȡ�༴��λλ��
    bitmap[num >> SHIFT] |= (0x01 << (num % CHARSIZE));
}

int bitreset(char * bitmap,int num)//���߼�λ��Ϊn�Ķ�����λ��Ϊ0
{
    //num>>SHIFT����3λ�൱�ڳ���8�����ֽ�λ�ã�num%CHARSIZE��8ȡ�༴��λλ��
    bitmap[num >> SHIFT] = bitmap[num >> SHIFT] & (~(0x01 << (num % CHARSIZE)));
}

int test(char * bitmap,int num)//�����߼�λ��Ϊn�Ķ�����λ�Ƿ�Ϊ1
{
    return bitmap[num >> SHIFT] & (0x01 << (num % CHARSIZE));
}

char FristNORepeatChar(const char * str)
{
    char * bitmap = new char[CHARARRAYSIZE];
    memset(bitmap,0,CHARARRAYSIZE);
    for(int i = 0;i < strlen(str);i++)
    {
        if(test(bitmap,str[i] - 'a'))
        {
            bitreset(bitmap,str[i] - 'a');
        }
        else
        {
            bitset(bitmap,str[i]-'a');
        }
    }
    for(int i = 0;i < strlen(str);i++)
    {
        if(test(bitmap,str[i] - 'a'))
        {
            return str[i];
        }
    }
}

int main(int args, char ** argv)
{
    char * str= "abaccdeff";
    printf("%c\n",FristNORepeatChar(str));

    return 0;
}
*/

/*
 * ��Ŀ����һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b��
 * bitmap�ķ��� C++ʵ��
 */
#include <iostream>
#include <string>
#include <bitset>
#define BITSETSIZE 1000

using namespace std;

int main(int args,char ** argv)
{
    bitset<BITSETSIZE> bit_set;
    string str = "abaccdeff";
    for(string::iterator it = str.begin();it != str.end();it++)
    {
        if(bit_set[*it - 'a'] == 0)
        {
            bit_set.set(*it - 'a',1);
        }
        else
        {
            bit_set.reset(*it - 'a');
        }
    }
    for(string::iterator it = str.begin();it != str.end();it++)
    {
        if(bit_set.test(*it - 'a'))
        {
            cout<<*it<<endl;
            break;
        }
    }

    return 0;
}


/*
 *���ַ����в����Ӵ�
 * ��Ŀ����������һ���ַ���A��Ҫ����A�в���һ���Ӵ�B��
 * ��A="ABCDF"��Ҫ����A�в����Ӵ�B=��CD����
 * ʵ��substr�⺯���Ĺ���

#include <iostream>
#include <string>
using namespace std;

int strstr(string &str, string &substr)
{
	int j=0;
	int strlen=str.length();
	int substrlen=substr.length();
	for(int i=0;i < strlen-substrlen; i++)
	{
		for(j=0;j < substrlen; j++)
		{
			if(str[i+j] != substr[j])
				break;
		}
		if(j == substrlen)
			return i+1;
	}
}

int main(int argc,char ** argv)
{
	string str="ABCDF";
	string substr="CD";
	int res=strstr(str,substr);
	cout<<res<<endl;
	return 0;
}

*/




	/*
	 * ����ַ���ƥ������ ʹ��hash����
	 * ��Ŀ���������������ַ����������е��ַ��͸�������ͬ���Ǿͽ��������ַ���ƥ�䣬���磺abcda��adabc,
	 * ���ڳ��ֵ��ַ�����������ͬ��ֻ��˳��ͬ�������������ַ�����ƥ��ġ�
	 *
	#include <iostream>
	#include <string>
	using namespace std;

	bool StringMatch(string &str1,string &str2)
	{
		int hash[58]={0};
		for(int i=0;i < str1.length();i++)
		{
			int pos=str1[i] - 'A';
			hash[pos]++;
		}
		for(int i=0;i < str2.length() ;i++)
		{
			int pos=str2[i] - 'A';
			if(hash[pos]==0)
			{
				return false;
			}
			else hash[pos]--;
		}
		return true;
	}

	int main(int argc,char **argv)
	{
		string str1="abcda";
		string str2="adaba";
		bool res=StringMatch(str1,str2);
		cout<<res<<endl;
		return 0;
	}

	*/



/*
 * ʹ��bitmap�ķ�����������ַ����Ƿ���������� ʱ�临�Ӷ�ΪO(m+n)
 *
#include <iostream>
#include <string>
using namespace std;

#define getbit(x) (0x01 << (x - 'A'))

bool AContainB(string &str1, string &str2)
{
	int dict=0;
	int j=0;
	for(int i=0;i < str1.length();i++)
	{
		dict=dict | getbit(str1[i]);
	}
	for (j=0;j < str2.length();j++)
	{
		if((dict & getbit(str2[j])) != getbit(str2[j]))
			break;
	}
	//cout<<j<<endl;
	if(j == str2.length()) return true;
	else return false;
}

int main(int argc,char **argv)
{
	string str1="ABCDEFGHLMNOPQRS";
	string str2="DCGSRQPOZ";
	bool res=AContainB(str1,str2);
	cout<<res<<endl;
	return 0;
}
*/


/*
 * ʹ��hashtable�ķ�����������ַ����Ƿ���������� ʱ�临�Ӷ�ΪO(m+n)
 *
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	string str1="ABCDEFGHLMNOPQRS";
	string str2="DCGSRQPOM";
	int hash[58];
	int num=0;
	for(int i=0;i < str2.length();i++)
	{
		int pos=str2[i]-'A';
		hash[pos] = 1;
		num++;
	}
	for(int i=0;i < str1.length();i++)
	{
		int pos=str1[i] - 'A';
		if(hash[pos] == 1)
		{
			hash[pos] =1;
			num--;
		}
	}
	if(num == 0) cout<<"true"<<endl;
	else cout<<"false"<<endl;
	return 0;
}
*/


/*
 * �ö������ַ����ȷֱ�����Ȼ����ͬʱ�������ַ���������ѯ�ķ�����������ַ����Ƿ���������� ʱ�临�Ӷ�O(mlogm)+O(nlogn)+O(m+n)
 *
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
void Exchange(char &a,char &b)
{
	char tmp;
	tmp=a;
	a=b;
	b=tmp;
}

int Partition(string &s,int p,int r)
{
	char key=s[r];
	int i=p-1;
	for(int j = p;j < r;j++)
	{
		if(s[j] <= key)
		{
			i=i+1;
			Exchange(s[i],s[j]);
		}
	}
	Exchange(s[i+1],s[r]);
	return i+1;
}

void QuickSort(string &s,int p,int r)
{
	if(p<r)
	{
		int q=Partition(s,p,r);
		QuickSort(s,p,q-1);
		QuickSort(s,q+1,r);
	}
}

bool CompareString(string s1,string s2)
{
	int posOne = 0;
	int posTwo = 0;
	while(posOne < s1.length() && posTwo < s2.length())
	{
		while(s1[posOne] < s2[posTwo] && posOne < s1.length()-1)
		{	posOne++;}
		if(s1[posOne] == s2[posTwo]){	posTwo++;}
		else{	break;}
	}
	if(posTwo == s2.length())
		return true;
	else return false;
}

int main(int argc, char **argv)
{
	string s1="ABCDEFGHLMNOPQRS";
	string s2="DCGSRQPOZ";
	QuickSort(s1,0,s1.length()-1);
	QuickSort(s2,0,s2.length()-1);
	//cout<<"***"<<s2<<endl;
	cout<<CompareString(s1,s2)<<endl;
	return 0;
}
*/



/*
 * ����ѯ������������ַ����Ƿ���������� ʱ�临�Ӷ�O(m*n)
 *
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool CompareString(string longstring , string shortstring){
	for(int i = 0;i < shortstring.length();i++)
	{
		int j=0;
		while(j < longstring.length())
		{
			if(longstring[i] != shortstring[j])
			{	j++;}
			else
			{	break;}
		}
		if(j == longstring.length())
		{
			cout<<"false"<<endl;
			return 0;
		}
	}
	cout<<"true"<<endl;
	return 1;
}

int main(int argc, char **argv)
{
	string longstring="ABCDEFGHLMNOPQRS";
	string shortstring="DCGSRQPOZ";
	CompareString(longstring,shortstring);
	return 0;
}
*/























