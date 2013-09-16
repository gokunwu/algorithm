
/*
copyright@nciaebupt 转载请注明出处
题目:判断图里有环
无向图：
法1：
如果存在回路，则必存在一个子图，是一个环路。环路中所有顶点的度>=2。
算法：
     第一步：删除所有度<=1的顶点及相关的边，并将另外与这些边相关的其它顶点的
度减一。
     第二步：将度数变为1的顶点排入队列，并从该队列中取出一个顶点重复步骤一。
     如果最后还有未删除顶点，则存在环，否则没有环。
算法分析：
     由于有m条边，n个顶点。如果m>=n，则根据图论知识可直接判断存在环路。
     （证明：如果没有环路，则该图必然是k棵树 k>=1。根据树的性质，边的数目m = n-k。
k>=1，所以：m<n）
     如果m<n 则按照上面的算法每删除一个度为0的顶点操作一次（最多n次），或每
删除一个度为1的顶点（同时删一条边）操作一次（最多m次）。这两种操作的总数不会超
过m+n。由于m<n，所以算法复杂度为O(n)
另：
该方法，算法复杂度不止O(V)，首先初始时刻统计所有顶点的度的时候，复杂度为(V + E)，
即使在后来的循环中E>=V，这样算法的复杂度也只能为O( V + E)。其次，在每次循环时，
删除度为1的顶点，那么就必须将与这个顶点相连的点的度减一，并且执行delete node from
list[list[node]]，这里查找的复杂度为list[list[node]]的长度，只有这样才能保证当degree[i]=1
时，list[i]里面只有一个点。这样最差的复杂度就为O(EV)了。

法2：
DFS搜索图，图中的边只可能是树边或反向边，一旦发现反向边，则表明存在环。该算法
的复杂度为O(V)。

有向图：
主要有深度优先和拓扑排序2中方法
 1、拓扑排序，如果能够用拓扑排序完成对图中所有节点的排序的话，就说明这个图中
没有环，而如果不能完成，则说明有环。
 2、可以用Strongly Connected Components来做，我们可以回忆一下强连通子图的概
念，就是说对于一个图的某个子图，该子图中的任意u->v,必有v->u，则这是一个强连通子
图。这个限定正好是环的概念。所以我想，通过寻找图的强连通子图的方法应该可以找出一
个图中到底有没有环、有几个环。
 3、就是用一个改进的DFS 刚看到这个问题的时候，我想单纯用DFS就可以解决问题了。但细想一下，是不能
够的。如果题目给出的是一个无向图，那么OK，DFS是可以解决的。但无向图得不出正确
结果的。比如：A->B, A->C->B,我们用DFS来处理这个图，我们会得出它有环，但其实没有。
     我们可以对DFS稍加变化，来解决这个问题。解决的方法如下：
     图中的一个节点，根据其C[N]的值，有三种状态：
     0，此节点没有被访问过
     -1，被访问过至少1次，其后代节点正在被访问中
     1，其后代节点都被访问过。
     按照这样的假设，当按照DFS进行搜索时，碰到一个节点时有三种可能：
     1、如果C[V]=0，这是一个新的节点，不做处理
     2、如果C[V]=-1，说明是在访问该节点的后代的过程中访问到该节点本身，则图中
有环。
     3、如果C[V]=1，类似于2的推导，没有环。     在程序中加上一些特殊的处理，即
可以找出图中有几个环，并记录每个环的路径

判断有向图是否有环有三种方法：拓扑排序、深度遍历+回溯、深度遍历  + 判断后退边
这里使用  拓扑排序  和  深度遍历  + 回溯判断是不是环。使用  深度遍历  + 判断后退边找
出环个数  以及环中元素
1、拓扑排序
思想：找入度为0的顶点，输出顶点，删除出边。循环到无顶点输出。
若：输出所有顶点，则课拓扑排序，无环；反之，则不能拓扑排序，有环
使用：可以使用拓扑排序为有向无环图每一个结点进行编号，拓扑排序输出的顺序可以为编
号顺序
*/
#if 0

#include <cstdlib>
#include <iostream>
#include <stack>

const int max_vex_num = 100;

class Graph{
  public:
    Graph():vexnum(0)//,arcnum(0)
    {
      for(int i = 0; i < max_vex_num; ++i){
        vexs[i] = 0;
      }
      for(int i = 0; i < max_vex_num; ++i){
        for(int j = 0; j < max_vex_num; ++j){
          graph[i][j] = 0;
        }
      }
    }
    void createGraph();
    int isCircleInGraph();
  private:
    int vexnum;//顶点数
    int vexs[max_vex_num];//顶点集合
    int graph[max_vex_num][max_vex_num];//邻接矩阵
};

void Graph::createGraph()
{
  vexnum = 5;
  for(int i = 0; i < vexnum; ++i){
    vexs[i] = i+1;
  }
  graph[0][1] = 1;
  graph[0][3] = 1;
  graph[1][2] = 1;
  graph[3][4] = 1;
  graph[4][0] = 1;
}

int Graph::isCircleInGraph()
{
  if(graph == NULL || vexnum < 1){
    return -1;
  }
  std::stack<int> vexindex;
  int indegree[max_vex_num] = {0};
  int cnt = 0;//拓扑排序输出顶点的个数
  for(int i = 0; i < vexnum; ++i){//查找入度为0的顶点
    for(int j = 0; j < vexnum; ++j){
      if(graph[j][i] != 0){
        indegree[i]++;
      }
    }
  }
  for(int i = 0; i < vexnum; ++i){//将入度为0的节点push到栈中
    if(indegree[i] == 0){
      vexindex.push(i);
    }
  }
  while(!vexindex.empty()){//处理入度为0的节点：将入度为0的节点出栈，并删除其出边
    int i = vexindex.top();
    vexindex.pop();
    std::cout<<vexs[i]<<std::endl;
    cnt++;
    for(int j = 0; j < vexnum; ++j){
      if(graph[i][j] != 0){
        graph[i][j] = 0;
        indegree[j]--;
        if(indegree[j] == 0){
          vexindex.push(j);
        }
      }
    }
  }
  if(cnt == vexnum){
    std::cout<<"no circle!"<<std::endl;
    return 1;
  }else{
    std::cout<<"circle"<<std::endl;
    return -1;
  }
}


int main(int argc, char ** argv)
{
  Graph graph;
  graph.createGraph();
  graph.isCircleInGraph();

  system("pause");
  return 0;
}
#endif

#if 0
/*
2、深度遍历  + 回溯
思想：用回溯法,遍历时，如果遇到了之前访问过的结点，则图中存在环。
*/
#include <cstdlib>
#include <iostream>

const int max_vex_num = 100;

class Graph{
  public:
    Graph():vexnum(0)
    {
      for(int i = 0; i < max_vex_num; ++i){
        vexs[i] = 0;
      }
      for(int i = 0; i < max_vex_num; ++i){
        for(int j = 0; j < max_vex_num; ++j){
          graph[i][j] = 0;
        }
      }
    }
    void createGraph();
    int isCircleInGraph();
    void isCircleInGraph(int i, int & isExist, int * isVisited, int * partVisited);
  private:
    int vexnum;
    int vexs[max_vex_num];
    int graph[max_vex_num][max_vex_num];
};

void Graph::createGraph()
{
  vexnum = 5;
  for(int i = 0; i < vexnum; ++i){
    vexs[i] = i+1;
  }
  graph[0][1] = 1;
  graph[0][3] = 1;
  graph[1][2] = 1;
  graph[3][4] = 1;
  graph[4][0] = 1;
}

void Graph::isCircleInGraph(int i, int & isExist, int * isVisited, int * partVisited)
{
  if(i < 0 || i > vexnum){
    return;
  }
  isVisited[i] = 1;
  partVisited[i] = 1;
  for(int j = 0; j < vexnum; ++j){
    if(graph[i][j] != 0){
      if(partVisited[j] == 0){
        isCircleInGraph(j, isExist, isVisited, partVisited);
      }else{
        isExist = 1;
      }
    }
  }
  partVisited[i] = 0;//回溯
}

int Graph::isCircleInGraph()
{
  if(graph == NULL || vexs == NULL ||vexnum < 1){
    return -1;
  }
  int isExist = -1;
  int isVisited[max_vex_num] = {0};
  int partVisited[max_vex_num] = {0};
  for(int i = 0; i < vexnum; ++i){
    if(isVisited[i] == false){
      isCircleInGraph(i, isExist, isVisited, partVisited);
      if(isExist == 1){
        std::cout<<"circle!"<<std::endl;
        return 1;
      }
    }
  }
  if(isExist == -1){
    std::cout<<"no circle!"<<std::endl;
    return 0;
  }
}

int main(int argc, char ** argv)
{
  Graph graph;
  graph.createGraph();
  graph.isCircleInGraph();

  system("pause");
  return 0;
}

#endif

#if 0
/*
3、深度遍历  + 判断后退边
思想：用DFS（深度优先遍历）,判断是否有后退边，若有，则存在环
具体来说，在遍历顶点的每一条边时，判断一下这个边的顶点是不是在栈中，如果在栈中，
说明之前已经访问过了，这里再次访问，说明有环存在
判断后退边时，借助一个栈和一个数组
栈：即可以用来输出环
数组：inStack 判断是否在栈中
*/
#include <cstdlib>
#include <iostream>

const int max_vex_num = 100;

class Graph{
  public:
    Graph():vexnum(0)
    {
      for(int i = 0; i < max_vex_num; ++i){
        vexs[i] = 0;
      }
      for(int i = 0; i < max_vex_num; ++i){
        for(int j = 0; j < max_vex_num;++j){
          graph[i][j] = 0;
        }
      }
    }
    void createGraph();
    int isCircleInGraph();
  private:
    int DFS(int i, int visited[max_vex_num], int stack[max_vex_num], int & top, int instack[max_vex_num], int &cnt);
  private:
    int vexnum;
    int vexs[max_vex_num];
    int graph[max_vex_num][max_vex_num];
};

void Graph::createGraph()
{
  vexnum = 5;
  for(int i = 0; i < vexnum; ++i){
    vexs[i] = i+1;
  }
  graph[0][1] = 1;
  graph[0][3] = 1;
  graph[1][2] = 1;
  graph[3][4] = 1;
  graph[4][0] = 1;
}

int Graph::isCircleInGraph()
{
  if(graph == NULL){
    return -1;
  }
  int visited[max_vex_num] = {0};
  int stack[max_vex_num];
  int top = -1;
  int instack[max_vex_num];
  int cnt = 0;//环的个数
  for(int i = 0; i < vexnum; ++i){
    if(visited[i] == 0){
      DFS(i, visited, stack, top, instack, cnt);
    }
  }
}

int Graph::DFS(int i, int visited[max_vex_num], int stack[max_vex_num], int & top, int instack[max_vex_num], int & cnt)
{
  visited[i] = 1;
  stack[++top] = i;
  instack[i] = 1;
  for(int j = 0; j < vexnum; ++j){
    if(graph[i][j] != 0){
      if(instack[j] == 0){
        DFS(j, visited, stack, top, instack, cnt);
      }
      else{
        std::cout<<"circle!"<<std::endl;
        cnt++;
        std::cout<<"the circle : "<<cnt<<" is: "<<std::endl;
        for(int h = 0; h <= top; ++h){
          std::cout<<vexs[stack[h]]<<" ";
        }
        std::cout<<std::endl;
      }
    }
  }
  stack[top--] = 0;
  instack[i] = 0;
}

int main(int argc, char ** argv)
{
  Graph graph;
  graph.createGraph();
  graph.isCircleInGraph();

  system("pause");
  return 0;
}

#endif


