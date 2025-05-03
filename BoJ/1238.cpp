/* 파티
https://www.acmicpc.net/problem/1238


N개의 마을에 각각 학생한명씩 살고있음
M개의 단방향 도로들이 있음 (Weight 1~100)
X마을에서 파티를 할 예정

각각의 학생들은 파티 참석 후에 다시 자기마을로 돌아와야함
- 이때 최단거리로

여기서 가장 많은 시간을 소비한 학생이 누구인지 구하여라
- 제한시간 1초

입력
- N M X (N. 1~1000, M 1~10000)
- u v w
- ...  
    - 참고로 그래프 경로는 단방향이고, 중복되지않음
    - X에서 집으로 오고 갈 수 있는 데이터만 주어짐(못간다조건 없음)

출력
- 가장 오래걸린 학생의 소요시간

풀이
- 다익스트라 (BFS + PQ)
- X부터 다익스트라 = 돌아가는 길
- 각 지점에서 X까지 다익스트라
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node_t{
    int node;
    int weight;
};
struct MinHeap{
    bool operator() (const Node_t & left, const Node_t & right) const
    {
        return !(left.weight < right.weight);
    }
};
int g_N, g_M,  g_X, g_u, g_v, g_w, g_ans;
vector<vector<int>> g_dist(1001, vector<int>(1001, INT_MAX));
vector<vector<Node_t>> g_adjList(1001);
priority_queue<Node_t, vector<Node_t>, MinHeap> g_pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M >> g_X;
    for(int mIdx = 0; mIdx < g_M; mIdx++)
    {
        cin >> g_u >> g_v >> g_w;
        g_adjList[g_u].push_back({g_v, g_w});
    }
    // 모든 N에 대해 최소 경로 체크
    for(int nIdx = 1; nIdx <= g_N; nIdx++)
    {
        g_pq.push({nIdx, 0});
        g_dist[nIdx][nIdx] = 0;
        while(!g_pq.empty())
        {
            Node_t now = g_pq.top();
            g_pq.pop();
            if(now.weight > g_dist[nIdx][now.node])
                continue;
            for(auto next: g_adjList[now.node])
            {
                int nextWeight = now.weight + next.weight;
                if(g_dist[nIdx][next.node] > nextWeight)
                {
                    g_dist[nIdx][next.node] = nextWeight;
                    g_pq.push({next.node, nextWeight});
                }
            }
        }
    }

    // // TEST >>
    // cout << "--- \n";
    // for(int yIdx = 1; yIdx <= g_N; yIdx++)
    // {
    //     for(int xIdx = 1; xIdx <= g_N; xIdx++)
    //     {
    //         if(g_dist[yIdx][xIdx] == INT_MAX)
    //             cout << "X ";
    //         else
    //             cout << g_dist[yIdx][xIdx] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "--- \n";
    // // << TEST

    // g_X로 오고 가는 경로의 합 중에 Max값 출력
    for(int nIdx = 1; nIdx <= g_N; nIdx++)
    {
        if(nIdx == g_X) continue;
        g_ans = max(g_ans, (g_dist[nIdx][g_X] + g_dist[g_X][nIdx]));
    }

    cout << g_ans;
    return 0;
}