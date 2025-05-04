/* 최소비용 구하기 2
https://www.acmicpc.net/problem/11779

A번째 도시에서 B번째 도시까지 가는데 드는 최소비용과 경로를 출력하라

입력
- n (1~1,000)
- m (1~100,000)
- u v w(0~100,000)
- ... (m개 수만큼)
- 출발도시 도착도시

출력
- 출발-도착 최소비용
- 경로에 포함된 도시 개수
- 경로 순서대로 출력

풀이
- 배열 두개 필요함
    - 다익스트라: 다익스트라로 시작 부터 도착 까지 일단 구함
    - history: 구하면서, history도 함께 표시
- history는 업데이틀 될때마다 now 를 입력
    - 초기값은 0으로
- history 인덱스 추적 후, stack에 쌓아서 출력
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node_t{
    int node;
    ll weight;
};
struct MinHeap{
    bool operator() (const Node_t &left, const Node_t &right) const
    {
        return !(left.weight < right.weight);
    }
};
priority_queue<Node_t, vector<Node_t>, MinHeap> g_pq;
vector<vector<Node_t>> g_adj(1001);
vector<ll> g_dist(1001, LONG_LONG_MAX);
vector<int> g_hist(1001);
stack<int> g_histStack;
int g_N, g_M, g_U, g_V, g_W, g_Start, g_End;

int main()
{
    cin >> g_N >> g_M;
    for(int mIdx = 0; mIdx < g_M; mIdx++)
    {
        cin >> g_U >> g_V >> g_W;
        g_adj[g_U].push_back({g_V, g_W});
    }
    cin >> g_Start >> g_End;
    g_pq.push({g_Start, 0});
    g_dist[g_Start] = 0;
    while(!g_pq.empty())
    {
        Node_t now = g_pq.top();
        g_pq.pop();
        if(now.weight >= g_dist[g_End])
            continue;
        for(auto next: g_adj[now.node])
        {
            ll nextWeight = next.weight + now.weight;
            if(nextWeight < g_dist[next.node])
            {
                g_dist[next.node] = nextWeight;
                g_hist[next.node] = now.node;
                if(next.node != g_End)
                    g_pq.push({next.node, nextWeight});
            }
        }
    }
    int histNode = g_End;
    g_histStack.push(g_End);
    while(histNode != g_Start)
    {
        histNode = g_hist[histNode];
        g_histStack.push(histNode);
    }
    cout << g_dist[g_End] << "\n";
    cout << g_histStack.size() << "\n";
    while(!g_histStack.empty())
    {
        cout << g_histStack.top() << " ";
        g_histStack.pop();
    }
    return 0;
}