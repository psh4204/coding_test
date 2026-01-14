/* 
https://www.acmicpc.net/problem/1260
DFS로 탐색한 결과와 BFS탐색결과 두가지를  출력한다.
 **단, 방문할수 있는 노드가 여러개일경우 -> 노드번호가 작은것 부터 방문한다.
더이상 방문할 수 없을 때까지 방문한다.
엣지번호는 1부터 N번까지이다. 

[입력]
N M V (노드, 엣지, 탐색시작할노드번호)
A B (M개의 연결된 두 엣지번호)
...


[출력]
첫번째줄은 DFS 수행결과
두번째줄은 BFS 수행결과

*/

#include <bits/stdc++.h>
using namespace std;
int g_N, g_M, g_V, g_y, g_x;
vector<vector<int>> g_adjList;
vector<int> g_dfsV;
vector<int> g_dfsResult;
vector<int> g_bfsV;
vector<int> g_bfsResult;

void DFS(int here)
{
    g_dfsV[here] = 1;
    g_dfsResult.push_back(here);
    for(auto next: g_adjList[here])
    {
        if(g_dfsV[next] == 0)
        {
            DFS(next);
        }
    }
}

void BFS(int here)
{
    queue<int> bfsQ;
    bfsQ.push(here);
    g_bfsV[here] = 1;
    g_bfsResult.push_back(here);
    while(!bfsQ.empty())
    {
        int now = bfsQ.front();
        bfsQ.pop();
        for(auto next: g_adjList[now])
        {
            if(g_bfsV[next] == 0)
            {
                bfsQ.push(next);
                g_bfsV[next] = 1;
                g_bfsResult.push_back(next);
            }
        }
    }
}

int main()
{
    cin >> g_N >> g_M >> g_V;
    g_adjList.resize(g_N+1);
    g_dfsV.resize(g_N+1, 0);
    g_bfsV.resize(g_N+1, 0);
    for(int inCnt = 0; inCnt < g_M; inCnt++)
    {
        cin >> g_y >> g_x;
        g_adjList[g_y].push_back(g_x);
        g_adjList[g_x].push_back(g_y);
    }
    for(int sortIdx = 1; sortIdx <= g_N; sortIdx++)
        sort(g_adjList[sortIdx].begin(), g_adjList[sortIdx].end());
    
    DFS(g_V);
    BFS(g_V);

    if(!g_dfsResult.empty() && !g_bfsResult.empty())
    {
        for(auto output: g_dfsResult)
            cout << output << " ";
        cout << "\n";
        for(auto output: g_bfsResult)
            cout << output << " ";
        cout << "\n";
    }
    return 0;
}