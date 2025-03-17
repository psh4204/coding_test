/* https://www.acmicpc.net/problem/1260
DFS와 BFS

N(노드) M(엣지) V(노드번호) 가 주어진다.
V부터 DFS와 BFS 둘다써서 나오는 출력물을 보여봐라

풀이
- Vistied1차원 하나(한번만 방문하면 돼서), 인접행렬 하나 만들어서 해보자.
(인접행렬은 노드간 관계를 표현하기 좋다는 장점이 있지만 무겁다.)
- 인접행렬을 쓴 이유 -> 더 작은 숫자로 우선접근하라는 말 때문

*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g_adjArray;
vector<int> g_visitedDFS;
vector<int> g_visitedBFS;
int g_N, g_M, g_V;

void DFS(int currV)
{
    if(g_visitedDFS[currV])
        return;
    g_visitedDFS[currV] = 1;
    cout << (currV +1) << " ";
    for(int nextV = 0; nextV < g_N; nextV++)
    {
        if(g_adjArray[currV][nextV] == 0)
            continue;
        DFS(nextV);
    }
}
void BFS(int startV)
{
    queue<int> vQ;
    vQ.push(startV);
    g_visitedBFS[startV]=1;
    while(!vQ.empty())
    {
        int currV = vQ.front();
        vQ.pop();
        cout << (currV+1) << " ";
        for(int nextV= 0; nextV < g_N; nextV++)
        {
            if(g_adjArray[currV][nextV] == 0 || g_visitedBFS[nextV] == 1)
            continue;
            vQ.push(nextV);
            g_visitedBFS[nextV]=1;
        }
    }
}

int main()
{
    cin >> g_N >> g_M >> g_V;
    g_adjArray.resize(g_N, vector<int>(g_N,0));
    
    for(int edgeCnt = 0; edgeCnt < g_M; edgeCnt++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g_adjArray[v1-1][v2-1] = 1;
        g_adjArray[v2-1][v1-1] = 1;
    }

    g_visitedDFS.resize(g_N,0);
    DFS(g_V-1);
    cout <<"\n";
    g_visitedBFS.resize(g_N,0);
    BFS(g_V-1);

    return 0;
}