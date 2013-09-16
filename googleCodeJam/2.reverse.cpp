#if 0
#include <fstream>
#include <string>

void reverse(std::string & s, int begin, int end)
{
  while(begin < end){
    char tmp = s[begin];
    s[begin] = s[end];
    s[end] = tmp;
    begin++;
    end--;
  }
}

int main(int argc, char ** argv)
{
  std::ifstream infile("B-large-practice.in");
  std::ofstream outfile("B-large-practice.out");

  int cnt = 0;
  infile>>cnt;
  for(int i = 0; i <= cnt; ++i){
    std::string s;
    getline(infile, s);
    if(i == 0){
      continue;
    }
    //infile.getline(s);
    reverse(s, 0, s.size()-1);
    int begin = 0;
    int end = 0;
    while(end <= s.size()){
      if(s[end] == ' ' || end == s.size()){
        reverse(s, begin, end-1);
        begin = end+1;
      }
      end++;
    }
    outfile<<"Case #"<<i<<": "<<s<<std::endl;
  }
}
#endif
