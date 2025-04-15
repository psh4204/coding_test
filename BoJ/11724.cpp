/* 연결요소 개수
https://www.acmicpc.net/problem/11724

양방향 그래프의 
연결요소의 개수를 구하는 프로그램 작성

입력
- 정점 N(1~1000), 간선 M(0~Nx(N-1)/2)
- u v 들

풀이
- DFS로 인접 리스트 만들어서 해결하면 될듯
    - 하나는 접근용 인접리스트, 하나는 visited 표시용 인접행렬
- 양방향이니까 u v 받으면 'u,v' 'v,u' 둘다 표시해둔 뒤 어디까지 연결됐는지 체크
    - 더 돌곳이 없으면 카운트 1
- 입력받지 않은 정점의 개수도 카운트 해야함
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g_adjList;
vector<vector<int>> g_visited;
int g_N, g_M;
long long g_areaCnt;

void SearchArea(int start, int target)
{
    g_visited[start][target] = 0;
    for(int nIdx = 0; nIdx < g_adjList[target].size(); nIdx++)
    {
        int nTarget = g_adjList[target][nIdx];
        if(g_visited[target][nTarget] != 0)
            SearchArea(target, nTarget);
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    g_adjList.resize(g_N);
    g_visited.resize(g_N, vector<int>(g_N, 0));
    while(g_M--)
    {
        int u, v;
        cin >> u >> v;
        g_adjList[u-1].push_back(v-1);
        g_adjList[v-1].push_back(u-1);
        g_visited[u-1][v-1] = 1;
        g_visited[v-1][u-1] = 1;
    }

    // for(auto y: g_visited)
    // {
    //     for(auto yx: y)
    //         cout << yx << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    for(int nodeIdx = 0; nodeIdx < g_N; nodeIdx++)
    {
        if(g_adjList[nodeIdx].size() == 0)
        {
            g_areaCnt+=1;
            continue;
        }
        for(int subIdx = 0; subIdx < g_adjList[nodeIdx].size(); subIdx++)
        {
            int target = g_adjList[nodeIdx][subIdx];
            if(g_visited[nodeIdx][target] != 0)
            {
                SearchArea(nodeIdx, target);
                g_areaCnt+=1;
            }
        }
    }

    // for(auto y: g_visited)
    // {
    //     for(auto yx: y)
    //         cout << yx << " ";
    //     cout << "\n";
    // }

    cout << g_areaCnt;
    return 0;
}