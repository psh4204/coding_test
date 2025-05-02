/* 트리의 지름
https://www.acmicpc.net/problem/1967

트리는 사이클이 없는 무방향 그래프

트리 노드를 가장 길게 쭉 늘리면 트리의 지름이 된다
트리의 지름을 구하라
- 루트 노드는 반드시 1이다

입력
- N (1~10,000)
- u v w(간선정보_단방향. weight는 1~100)
- ...  

출력
- 트리의 지름

100,000,000

풀이
- 무방향 트리 = 양방향 그래프
- 1. 1번노드를 시작으로 가장 먼 노드를 찾는다
- 2. 가장 먼노드를 시작으로 다시 또 다른 가장먼 노드를 찾는다 <-이때 가진 가중치가 정답

[Note]
- 다익스트라: 최단경로 찾기 알고리즘(최소Weight찾기)
    - 해당문제는 최소 Weight중에서 가장 큰 값을 찾는 문제
- 인접 리스트 메모리: V+E
- 인접 행렬 메모리 : V*V
- 인접리스트는 값을 찾으려면 find를 쓰는게 빠름 
    (vector는 find 멤버함수가 없기에, algorithm에서 따와야함
    정말 만약에 해당 인덱스 번호가 필요하면 distance(00.begin(), it) 해서 받아오면됨)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node_t{
    int node;
    ll weight;
};

struct MaxHeapCmp{
    bool operator() (const Node_t & left, const Node_t & right) const{
        return !(left.weight > right.weight);
    }
};

int g_N, g_u, g_v, g_w;
vector<vector<Node_t>> g_tree(10001); // 인접 리스트
vector<ll> g_dist1(10001, LONG_LONG_MAX);
vector<ll> g_dist2(10001, LONG_LONG_MAX);
priority_queue<Node_t, vector<Node_t>, MaxHeapCmp> g_pq;
Node_t g_firstNode = {0, 0}, g_secondNode = {0, 0};

int main()
{
    cin >> g_N;
    for(int nIdx = 1; nIdx < g_N; nIdx++)
    {
        cin >> g_u >> g_v >> g_w;
        g_tree[g_u].push_back({g_v, g_w});
        g_tree[g_v].push_back({g_u, g_w});
    }
    
    // 1. 루트노드로 부터 가장 Weight가 큰 노드 찾기
    g_pq.push({1,0}); // {nextNode, weight}
    g_dist1[1] = 0;
    while(!g_pq.empty())
    {
        Node_t now = g_pq.top();
        g_pq.pop();
        if(now.weight > g_dist1[now.node])
            continue;
        for(auto next: g_tree[now.node])
        {
            ll nextWeight = now.weight + next.weight;
            if(g_dist1[next.node] <= nextWeight)
                continue;
            g_dist1[next.node] = nextWeight;
            g_pq.push({next.node, nextWeight});
        }
    }
    for(int nIdx = 1; nIdx <= g_N; nIdx++)
    {
        if(g_dist1[nIdx]!= LONG_LONG_MAX && g_dist1[nIdx] >= g_firstNode.weight)
            g_firstNode = {nIdx, g_dist1[nIdx]};
    }
    // cout << g_firstNode.weight << "<<< \n";

    // 2. 가장큰 Weight 노드로 부터 다른 가장큰 Weight가 큰 노드 찾기
    g_pq.push({g_firstNode.node, 0});
    g_dist2[g_firstNode.node] = 0;
    while(!g_pq.empty())
    {
        Node_t now = g_pq.top();
        g_pq.pop();
        if(now.weight > g_dist2[now.node])
            continue;
        if(g_secondNode.weight < now.weight)
            g_secondNode = {now.node, now.weight};
        for(auto next: g_tree[now.node])
        {
            ll nextWeight = now.weight + next.weight;
            if(g_dist2[next.node] <= nextWeight)
                continue;
            g_dist2[next.node] = nextWeight;
            g_pq.push({next.node, nextWeight});
        }
    }

    cout << g_secondNode.weight;
    return 0;
}
