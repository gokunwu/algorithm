
/*
copyright@nciaebupt ת����ע������
ʹ��Edmonds-Karp�㷨������������
*/

#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

const int MAXCNT = 200;//�������ڵ���
const int MAX = 10000;
int M = 0;//ͼ�ж�����
int N = 0;//ͼ�бߵ�����
int matrix[MAXCNT][MAXCNT]={0};//�洢��������
int visit[MAXCNT]={-1};//��¼�ڵ�i�Ƿ��Ѿ�����
int pre[MAXCNT]={0};//��¼�ڵ�i��ǰ��ڵ�Ϊpre[i]�������pre[i]�������Ǽ�¼�������·��������·�����ӻ�����pre[i]ָʾ��·�����ʵ�Դ�ڵ㣬��������·�����Ǿ������·��������·����

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









