/* 최단경로
https://www.acmicpc.net/problem/1753

방향 그래프에서 시작점 -> 모든 정점의 최단경로를 구하는 프로그램 작성
- 모든 간선의 가중치는 1~10

입력
- V (정점개수 1~20,000) E(간선개수, 1~300,000)
- K 시작 정점번호
- u v w
- ... 

출력
- i정점으로의 최단거리 출력
    - 자신은 0출력

풀이
- 단방향그래프
- 다익스트라 문제 (BFS + PQ)
- 시작점으로 부터 1~V 노드까지 한번에 PQ돌리면 답나올듯
    - target 지정없이 Q 끝날때까지 돌리면 답나올듯

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node_t{
    int node;
    ll weight;
};
struct MinHeapCmp{
    bool operator() (const node_t & left, const node_t & right) const
    {
        return !(left.weight < right.weight);
    }
};

int g_V, g_E, g_K;
vector<vector<int>> g_adjList(20001);
vector<vector<int>> g_weights(20001);

vector<ll> g_visited(20001,LONG_LONG_MAX);
priority_queue<node_t, vector<node_t>, MinHeapCmp> g_pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_V >> g_E >> g_K;
    for(int inIdx = 0; inIdx < g_E; inIdx++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g_adjList[u].push_back(v);
        g_weights[u].push_back(w);
    }
    g_pq.push({g_K, 0});
    g_visited[g_K] = 0;
    while(!g_pq.empty())
    {
        node_t now = g_pq.top();
        g_pq.pop();
        if(now.weight > g_visited[now.node])
            continue;
        for(int nNodeIdx = 0; nNodeIdx< g_adjList[now.node].size(); nNodeIdx++)
        {
            int nextNode = g_adjList[now.node][nNodeIdx];
            ll nextWeight = now.weight + g_weights[now.node][nNodeIdx];
            if(nextWeight < g_visited[nextNode])
            {
                g_pq.push({nextNode,nextWeight});
                g_visited[nextNode] = nextWeight;
            }
        }
    }

    for(int vIdx = 1; vIdx <=g_V; vIdx++)
    {
        if(vIdx == g_K)
            cout << 0 << "\n";
        else if(g_visited[vIdx] == LONG_LONG_MAX)
            cout << "INF\n";
        else
            cout << g_visited[vIdx] << "\n";
    }
    return 0;
}