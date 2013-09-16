#if 0
#include <fstream>
#include <iostream>

int main(int argc, char ** argv)
{
  std::ifstream infile("A-small-practice.in");
  std::ofstream outfile("A-small-practice.out");
  int cnt;
  infile>>cnt;
  for(int i = 0; i < cnt; ++i){
    int
    infile>>sum;
    infile>>numcnt;
    int stores[numcnt];
    for(int j = 0; j < numcnt; ++j){
      infile>>stores[j];
    }
    int hashmap[1000+1];
    for(int i = 0; i < 1000+1; ++i){
      hashmap[i] = 0;
    }
    for(int i = 0; i < numcnt; ++i){
      hashmap[stores[i]] = 1;
    }
    int min;
    int max;
    for(int i = 0; i < numcnt; ++i){
      int query = sum-stores[i];
      if(hashmap[query] == 1){
        for(int )
      }
    }
  }

  return 0;

}
#endif
