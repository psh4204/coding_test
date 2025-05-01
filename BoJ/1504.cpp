/* 특정한 최단 경로
https://www.acmicpc.net/problem/1504

양방향 그래프에서
1번정점에서 N번정점까지 최단거리로 가려고함
다음의 두조건을 만족하면서
- 임의로 주어지는 두 정점을 반드시 통과해야함
- 한번이동했던 정점, 간선을 통해 다시 이동가능함

반드시 최단경로로 이동하는 프로그램 작성하기

입력
- N E (노드 2~800, 엣지 0~200,000)
- a b c(노드 a<->b. c거리)
- ... 
- 지나야하는 노드 2개

출력
- 지나야하는 노드 2개를 거치는 N까지 가는 최단거리 구하기
    - 단, 최단경로가 없으면 -1 출력

풀이
- 양방향 노드 + 지나가야하는 2개 노드 + visited 중복가능 + 최단거리
    - BFS + PQ: 가중치가 다 달라서 = 이걸 다익스트라고 하더라
    - 두개 노드를 지나왔는지 체크
    - 노드 800짜리 인접리스트
    - 노드 800짜리 visited 배열 
- 각 이동방향 마다 다익스트라 적용 
    - (1 -> v1, 1 -> v2, v1->v2, v2 -> v1, v2->N, v1->N)
- 각 경로에서 못찾는경로는 무시하고, 조합중에 최소경로를 선택하자

[NOTE]
- PQ를 쓴 BFS(다익스트라) 에서 visited 체크법
    -> PQ를 써도 더 작은값이 들어올 수 도 있음 
- 이때문에 BFS랑 다르게 짜야하는 부분이 있음 
    -> 최적화는 더 큰값이 들어오는 것만 막으면 되고 나머진 미리 end문을 넣는다던지 하는건 안됨
5 7
1 2 1
1 4 4
2 4 1
2 3 2
2 5 2
3 5 5
4 5 2
4 3

[다익스트라]
- BFS + PQ로 최적값을 보다 빠르게 찾는다
- PQ로 인해 해당 노드에 최적값으로 빠르게 진입한다
- "모든 Q를 돌려서 최적값을 계속 찾는 알고리즘"
    - 중간에 최적값보다 더 큰게 들어오려하면 막아주는 형식으로 최적화 가능
- 방금 이문제에선 1차원 visited 사용해도 됐었음
    - 단순 노드방문이고, 양방향으로 여러번 접근가능해서 ㅇㅇ

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Road_t{
    int node;
    ll weight;
};

struct MinHeap{
    bool operator() (const Road_t & left, const Road_t & right) const
    {
        return !(left.weight < right.weight);
    }
};

int g_N, g_E, g_n1, g_n2;
ll g_roadSum1 = LONG_LONG_MAX, g_roadSum2 = LONG_LONG_MAX, g_ans;
vector<ll> g_roads(6); // 각 구간별 가중치 합들
vector<vector<int>> g_adjList(801);
vector<vector<int>> g_weights(801,vector<int>(801,-1));

ll CheckRoad(int start, int target)
{
    vector<ll> visited(g_N+1, LONG_LONG_MAX);
    priority_queue<Road_t, vector<Road_t>, MinHeap> roadQ;
    roadQ.push({start,0});
    visited[start] = 0;
    while(!roadQ.empty())
    {
        Road_t now = roadQ.top();
        roadQ.pop();
        if(now.weight > visited[now.node])
            continue;
        
        for(auto nextNode: g_adjList[now.node])
        {
            if(g_weights[now.node][nextNode] == -1) // 간선없으면 스킵
                continue;
            ll nextWeight = now.weight + g_weights[now.node][nextNode];
            if(nextWeight < visited[nextNode])
            {
                roadQ.push({nextNode, nextWeight});
                visited[nextNode] = nextWeight;
            }
        }
    }

    if(visited[target] == LONG_LONG_MAX)
        return -1;
    return visited[target];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_E;
    for(int eCnt = 0; eCnt < g_E; eCnt++)
    {
        int start, target, weight;
        cin >> start >> target >> weight;
        g_adjList[start].push_back(target);
        g_weights[start][target] = weight;
        g_adjList[target].push_back(start);
        g_weights[target][start] = weight;
    }
    cin  >> g_n1 >> g_n2;

    // for(int y = 1; y<= g_N; y++)
    // {
    //     for(int x = 1; x <= g_N; x++)
    //         cout << g_weights[y][x] << " ";
    //     cout << "\n";
    // }

    // 1-> n1
    g_roads[0] = CheckRoad(1,   g_n1);

    // 1-> n2
    g_roads[1] = CheckRoad(1,   g_n2);

    // n1->n2
    g_roads[2] = CheckRoad(g_n1,g_n2);

    // n2->n1
    g_roads[3] = CheckRoad(g_n2,g_n1);

    // n1->N
    g_roads[4] = CheckRoad(g_n1, g_N);

    // n2->N
    g_roads[5] = CheckRoad(g_n2, g_N);

    // 최적구간
    //cout << "road1: " << g_roads[0] << " " << g_roads[2] << " " << g_roads[5] << "\n";
    //cout << "road2: " << g_roads[1] << " " << g_roads[3] << " " << g_roads[4] << "\n";
    if(g_roads[0] != -1 && g_roads[2] != -1 && g_roads[5] != -1)
        g_roadSum1 = g_roads[0] + g_roads[2] + g_roads[5];
    if(g_roads[1] != -1 && g_roads[3] != -1 && g_roads[4]!= -1)
        g_roadSum2 = g_roads[1] + g_roads[3] + g_roads[4];
    g_ans = min(g_roadSum1, g_roadSum2);
    if(g_ans == LONG_LONG_MAX)
        cout << -1;
    else
        cout << g_ans;
    return 0;
}