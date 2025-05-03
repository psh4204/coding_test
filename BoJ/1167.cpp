/* 트리의 지름
https://www.acmicpc.net/problem/1167

트리의 지름을 구하라

입력
- V (2~V~100,000)
- u v w v w .. -1 (1 ~ w ~ 10,000)
- ... 

출력
- 트리의 지름

풀이
- 입력은 양방향으로 오는듯 (트리라 어차피 양방향임)
- 부모노드를 꼭 찾아야하나?
    - 아무 노드 붙잡고 최장거리노드를 처음에 잡음
    - 이 최장거리 노드에서 가장 멀리 떨어진 노드의 가중치 합이 정답 <-- 정답 예아!!
*/
#include <bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX
typedef long long ll;
struct Node_t{
    int target;
    ll weight;
};
struct MinHeap{
    bool operator() (const Node_t &left, const Node_t & right) const
    {
        return !(left.weight < right.weight);
    }
};
int g_V, g_u, g_v, g_w;
Node_t g_start ={0,0};
Node_t g_end = {0,0};
vector<vector<Node_t>> g_adj(100001);
vector<ll> g_dist1(100001, INF);
vector<ll> g_dist2(100001, INF);
priority_queue<Node_t, vector<Node_t>, MinHeap> g_pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_V;
    for(int nIdx = 1; nIdx <= g_V; nIdx++)
    {
        cin >> g_u;
        while(cin >> g_v && g_v !=-1)
        {
            cin >> g_w;
            g_adj[g_u].push_back({g_v, g_w});
        }
    }
    
    g_pq.push({1, 0});
    g_dist1[1] = 0;
    while(!g_pq.empty())
    {
        Node_t now = g_pq.top();
        g_pq.pop();
        for(auto next: g_adj[now.target])
        {
            ll nextWeight = now.weight + next.weight;
            if(nextWeight < g_dist1[next.target])
            {
                g_dist1[next.target] = nextWeight;
                g_pq.push({next.target, nextWeight});
                if(g_start.weight < nextWeight)
                    g_start = {next.target, nextWeight};
            }
        }
    }

    g_pq.push({g_start.target, 0});
    g_dist2[g_start.target] = 0;
    while(!g_pq.empty())
    {
        Node_t now = g_pq.top();
        g_pq.pop();
        for(auto next: g_adj[now.target])
        {
            ll nextWeight = now.weight + next.weight;
            if(nextWeight < g_dist2[next.target])
            {
                g_dist2[next.target] = nextWeight;
                g_pq.push({next.target, nextWeight});
                if(g_end.weight < nextWeight)
                    g_end = {next.target, nextWeight};
            }
        }
    }

    cout << g_end.weight;
    return 0;
}