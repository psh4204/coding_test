/* 타임머신
https://www.acmicpc.net/problem/11657

N개의 도시가 있고, 버스가 M개 있고 각 Time가 든다
Time이 0인 경우는 순간이동, 0보다 작을 경우는 타임머신으로 시간을 되돌린다
1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하시오
- 최단시간을 못구하는 경우에 -1출력

입력
- N M (N 1~500, M 1~6000)
- u v T (T -10000 ~ 10000)
- ...

출력
- 도시 순으로 가장빠른 시간 출력
    - 만약 음수사이클이면 -1

풀이
- 전형적인 벨만포드문제
*/
#include <bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX
typedef long long ll;
struct Node_t{
    int start;
    int target;
    ll time;
};
int g_N, g_M, g_u, g_v, g_t;
vector<ll> g_dist(501, INF);
vector<vector<Node_t>> g_adj(501);
queue<Node_t> g_q;

int main()
{
    cin >> g_N >> g_M;
    for(int inM = 0; inM < g_M; inM++)
    {
        cin >> g_u >> g_v >> g_t;
        g_adj[g_u].push_back({g_u,g_v,g_t});
    }
    g_dist[1] = 0;
    for(int mainLoop = 0; mainLoop < g_N; mainLoop++)
    {
        for(int now = 1; now <= g_N; now++)
        {
            for(auto adj: g_adj[now])
            {
                if(g_dist[now] != INF && g_dist[now] + adj.time < g_dist[adj.target])
                {
                    if(mainLoop == g_N-1)
                        g_q.push(adj);
                    g_dist[adj.target] = g_dist[now]+adj.time;
                }
            }
        }
    }
    if(g_q.empty())
    {
        for(int nIdx = 2; nIdx <= g_N; nIdx++)
        {
            if(g_dist[nIdx] == INF)
                cout << -1 << "\n";
            else
                cout << g_dist[nIdx] << "\n";
        }
    }
    else
        cout << -1;
    return 0;
}