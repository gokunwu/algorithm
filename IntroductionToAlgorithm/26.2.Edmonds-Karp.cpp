
/*
copyright@nciaebupt 转载请注明出处
使用Edmonds-Karp算法求解网络最大流
*/

#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

const int MAXCNT = 200;//矩阵最大节点数
const int MAX = 10000;
int M = 0;//图中顶点数
int N = 0;//图中边的条数
int matrix[MAXCNT][MAXCNT]={0};//存储残余网络
int visit[MAXCNT]={-1};//记录节点i是否已经访问
int pre[MAXCNT]={0};//记录节点i的前向节点为pre[i]，这里的pre[i]的作用是记录具有最短路径的增广路径，从汇点根据pre[i]指示的路径访问到源节点，所经过的路径就是具有最短路径的增广路径。

int BFS(int src,int des)
{
    for(int i = 0;i < MAXCNT;++i)
    {
        visit[i] = 0;
    }
    for(int i = 0;i < MAXCNT;++i)
    {
        pre[i] = -1;
    }

    queue<int> que;
    pre[src] = src;
    visit[src] = 1;
    que.push(src);

    int cur =0;
    while(!que.empty())
    {
        cur = que.front();
        que.pop();
        for(int i = 0;i < M;++i)
        {
            if(matrix[cur][i] > 0 && visit[i] != 1)
            {
                pre[i] = cur;
                visit[i] = 1;
                if(i == des)
                    return 1;
                que.push(i);
            }
        }
    }
    return 0;
}

int min(int a,int b)
{
    if(a <= b)
        return a;
    else
        return b;
}

int EK(int src,int des)
{
    int maxflow = 0;
    int d = MAX;
    while(BFS(src,des))
    {
        d = MAX;
        for(int i = des;i != src;i = pre[i])
        {
            d = min(d,matrix[pre[i]][i]);
        }
        for(int i = des;i != src;i = pre[i])
        {
            matrix[pre[i]][i] = matrix[pre[i]][i] - d;
            matrix[i][pre[i]] = matrix[i][pre[i]] + d;
        }
        maxflow = maxflow + d;
    }
    return maxflow;
}

int main()
{
    matrix={{0,1,1,0},{0,0,1,1},{0,0,0,1},{0,0,0,0}};
    M = 4;

    int res = EK(0,M-1);
    cout << res<<endl;
    system("pause");
    return 0;
}









