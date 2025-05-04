/* 서강 그라운드
https://www.acmicpc.net/problem/14938

지역(노드)간 길 길이는 1~15에 양방향
지역엔 아이템이 각각 있음
예은이의 수색범위(1~15)일때 아이템을 가장 많이 먹었을때의 개수를 구하라

입력
- n (지역 1~100) m(예은이의 수색범위 1~15) r(길의 개수 1~100)
- 각 구역에 있는 아이템 수 (1~30)
- u v w (엣지정보.참고로 양방향)

출력
- 최대 아이템 개수

풀이
- 해당 엣지의 weight와 아이템 카운트를 해야할 듯
- 다익스트라로 일단 최단거리 구한 후, 수색범위 내에 있는 노드들의 아이템 수를 카운트 해야할 것으로 보임
- 노드 최대 개수가 100개니까 전부 다익스트라로 해도 문제 없을 듯
*/
#include <bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX
typedef long long ll;
struct Node_t{
    int node;   // next node
    ll road;   // weight
};
struct MinHeap{
    bool operator() (const Node_t & left, const Node_t & right)const
    {
        return !(left.road < right.road);
    }
};
int g_N, g_R ,g_u, g_v, g_w;
ll g_M, g_maxItemCnt = 0;
vector<int> g_items(101); // 아이템 수
vector<vector<Node_t>> g_adj(101);
vector<vector<ll>> g_dist(101,vector<ll>(101, INF));
priority_queue<Node_t, vector<Node_t>, MinHeap> g_pq;

int main()
{
    cin >> g_N >> g_M >> g_R;
    for(int nIdx = 1; nIdx <= g_N; nIdx++)
    {
        cin >> g_items[nIdx];
    }
    for(int rIdx = 0; rIdx < g_R; rIdx++)
    {
        cin >> g_u >> g_v >> g_w;
        g_adj[g_u].push_back({g_v, g_w});
        g_adj[g_v].push_back({g_u, g_w});
    }

    for(int here = 1; here <= g_N; here++)
    {
        g_pq.push({here,0});
        g_dist[here][here] = 0;
        while(!g_pq.empty())
        {
            Node_t now = g_pq.top();
            g_pq.pop();
            if(now.road >= g_M)
                continue;
            for(auto next: g_adj[now.node])
            {
                ll nextRoad = now.road + next.road;
                if(nextRoad <= (ll)g_M && nextRoad < g_dist[here][next.node])
                {
                    g_dist[here][next.node] = nextRoad;
                    g_pq.push({next.node, nextRoad});
                }
            }
        }
        ll itemCnt = 0;
        for(int nIdx = 1; nIdx<= g_N; nIdx++)
        {
            if(g_dist[here][nIdx] <= g_M)
                itemCnt += g_items[nIdx];
        }
        g_maxItemCnt = max(g_maxItemCnt, itemCnt);
    }

    cout << g_maxItemCnt;

    return 0;
}