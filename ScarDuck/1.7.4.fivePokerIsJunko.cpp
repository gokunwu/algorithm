
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2-10
为数字本身，A为1，J为11，Q为12，K为13，而大小王可以看成任意数字。
思路一:
我们需要把扑克牌的背景抽象成计算机语言。不难想象，我们可以把5张牌看成由5个数字
组成的数组。大小王是特殊的数字，我们不妨把它们都当成0，这样和其他扑克牌代表的数
字就不重复了。
接下来我们来分析怎样判断5个数字是不是连续的。最直观的是，我们把数组排序。但值得
注意的是，由于0可以当成任意数字，我们可以用0去补满数组中的空缺。也就是排序之后
的数组不是连续的，即相邻的两个数字相隔若干个数字，但如果我们有足够的0可以补满这
两个数字的空缺，这个数组实际上还是连续的。举个例子，数组排序之后为{0，1，3，4，
5}。在1和3之间空缺了一个2，刚好我们有一个0，也就是我们可以它当成2去填补这个
空缺。
于是我们需要做三件事情：把数组排序，统计数组中0的个数，统计排序之后的数组相邻数
字之间的空缺总数。如果空缺的总数小于或者等于0的个数，那么这个数组就是连续的；反
之则不连续。最后，我们还需要注意的是，如果数组中的非0数字重复出现，则该数组不是
连续的。换成扑克牌的描述方式，就是如果一副牌里含有对子，则不可能是顺子。

更好的思路二:
1）确认5张牌中除了0，其余数字没有重复的（可以用表统计的方法）;
2) 满足这样的逻辑：（max，min分别代表5张牌中的除0以外的最大值最小值）
       如果没有0，则max-min=4，则为顺子，否则不是
       如果有一个0，则max-min=4或者3，则为顺子，否则不是
       如果有两个0，则max-min=4或者3或者2，则为顺子，否则不是
最大值和最小值在1）中就可以获得，这样就不用排序了
*/
#include <cstdlib>
#include <iostream>
#define POKER_CNT 14
#define MAX 10000
#define MIN -10000

bool isJunko(int * poker, int len)
{
  if(poker == NULL || len < 0){
    return false;
  }
  int poker_hash[POKER_CNT];
  for(int i = 0; i < POKER_CNT; ++i){
    poker_hash[i] = 0;
  }
  int poker_max = MIN;
  int poker_min = MAX;
  for(int i = 0; i < len; ++i){
    if(poker[i] != 0 && poker_max < poker[i]){
      poker_max = poker[i];
    }
    if(poker[i] != 0 && poker_min > poker[i]){
      poker_min = poker[i];
    }
    poker_hash[poker[i]]++;
  }
  int zero_cnt = poker_hash[0];
  for(int i = 0; i < POKER_CNT; ++i){
    if(poker_hash[i] > 1){
      return false;
    }
  }
  switch(zero_cnt){
    case 0:
      if(poker_max - poker_min == 4){
        return true;
      }
      else{
        return false;
      }
      break;
    case 1:
      if((poker_max - poker_min == 4) || (poker_max - poker_min == 3)){
        return true;
      }
      else{
        return false;
      }
      break;
    case 2:
      if((poker_max - poker_min == 3) || (poker_max - poker_min == 2)){
        return true;
      }
      else{
        return false;
      }
      break;
  }
}

int main(int argc, char ** argv)
{
  int poker[] = {2,3,4,5,6};
  int len = sizeof(poker)/sizeof(poker[0]);
  bool flag = isJunko(poker, len);
  std::cout<<flag<<std::endl;
  system("pause");
  return 0;
}
#endif
