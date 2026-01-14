/* 최소 스패닝 트리
https://www.acmicpc.net/problem/1197

그래프가 주어졌을때, 
그래프의 모든 정점을 연결하는 부분 그래프 중 
가중치의 합이 최소인 트리를 구하라

입력
- V (1~10,000) E(1~100,000)
- 트리간선정보 U V W (W는 음수~정수 Int ?!?!)
- ... 

출력
- 최소 스패닝 트리의 가중치를 출력한다

풀이
- 신장트리: 모든 정점을 포함하는 트리 (https://blog.encrypted.gg/1024)
- 어엇? 담에 풀자 이건. 다른개념으로 접근해야함
*/
#include <bits/stdc++.h>
using namespace std;
struct Node_t{
    int node;
    int weight;
};
int g_N, g_E, g_u, g_v, g_w;
vector<vector<Node_t>> g_adjList(10001);
long long g_ans = LONG_LONG_MAX;

int main()
{
    cin >> g_N >> g_E;
    for(int eIdx = 0; eIdx < g_E; eIdx++)
    {
        cin >> g_u >> g_v >> g_w;
        g_adjList[g_u].push_back({g_v, g_w});
        g_adjList[g_v].push_back({g_u, g_w});
    }

    for(int nIdx = 1; nIdx <= g_N; nIdx++)
    {
        if(g_adjList[g_u].size() != g_N-1)
            continue;
        long long sum = 0;
        for(auto node: g_adjList[nIdx])
        {
            sum += node.weight;
        }
        g_ans = min(sum, g_ans);
    }
    cout << g_ans;

    return 0;
}