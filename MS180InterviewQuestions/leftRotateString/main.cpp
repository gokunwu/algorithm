#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void Reverse(string::iterator begin,string::iterator end){
	char tmp;
	end--;
	while(begin < end){
		tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}

void LeftRotateString(string* s,int len){
	string::iterator begin=(*s).begin();
	string::iterator end=(*s).end();
	Reverse(begin,begin+len);
	Reverse(begin+len,end);
	Reverse(begin,end);
	//return s;
}

int main(int argc, char **argv)
{
	string str;
	string s = "abcdef";
	int k = 4;
	if(k < s.length()){
		//str=LeftRotateString(s,k);
		LeftRotateString(&s,k);
	}
	else{
		cout<<"the value of k must less than "<<s.length()<<endl;
	}
	cout<<s<<endl;

	return 0;
}
