/* 최소비용 구하기
https://www.acmicpc.net/problem/1916

N개의 도시, 한도시에서 다른도시로 도착하는 M개의 버스
A번째에서 B번째로 가는 버스 비용을 최소화 하려함
M개의 버스노선과 비용들이 나오면, 최소비용 을 각각 출력하라

입력
- N (도시수-노드) (1~1,000)
- M (버스수-엣지) (1~10,000)
- N1 N2 weight (노선과 비용. 비용은 0~100,000)
- ... 
- A B

출력
- A에서 B로가는데 최소비용

풀이
- visited를 쓰되, 현재 weight가 동일하거나 더 큰 경우 visited 못하게 한다
- BFS 나 DFS둘다 해도 될듯 하다


5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

ans 4

5
8
1 2 0
1 3 0
1 4 0
1 5 10000
2 4 0
3 4 0
3 5 0
4 5 0
1 5

ans 0

1000
6
1 4 1
1 3 3
1 2 5
4 5 2
3 5 4
2 5 6
1 5

1000
6
1 4 10000
1 3 10000
1 2 10000
4 5 10000
3 5 4
2 5 10000
1 5

1000
9
1 1 0
1 5 10000
1 2 10000
2 5 10000
2 3 0
3 5 0
5 3 10000
3 4 10000
5 4 1
1 4

ans 10001

1000

1 3
1 4
2 3
2 5
3 4
3 6
3 5
4 6
5 6
2 6

ㅋㅋㅋㅋㅋㅋ 한도시에서 타겟까지 갈때 다른버스를 탈수도 있음 (양방향도 아니고, 단선으로 두개이상 ㅋㅋㅋ 개웃기네)
3
4
1 2 10
1 2 50
2 3 1
2 3 10
1 3
ans 11

시간초과나서 미치겠어서 정답 슬적 봤음
- 큐를 우선순위 큐를 쓰네? ㅋㅋㅋ 머지? 
- 그럼 우선순위를 둬서 어떻게 잡지?
- 


[NOTE. 새로운 기법들]
- 그래프 문제 중, 단방향으로 같은방향을 중복해서 가는 경우도 고려해야함
- BFS 때 일반큐가 아니라, 우선순위큐를 사용할 수도 있음 (최소값을 찾아야하면, 최소값 우선으로 찾아야함)
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M, g_start, g_target, g_weight;
long long g_answer = LONG_LONG_MAX;
vector<vector<pair<int,int>>> g_adjList; // [start]{target, weight}
vector<vector<long long>> g_visited; // 방문 체크겸 최소weight비용 체크. 최초값 INT_MAX

struct CustomCmp{
    bool operator() (const pair<long long, int> & left, const pair<long long, int> & right) const
    {
        return left.first > right.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    g_adjList.resize(g_N);
    g_visited.resize(g_N, vector<long long>(g_N, LONG_LONG_MAX));
    for(int busCnt = 0; busCnt < g_M; busCnt++)
    {
        cin >> g_start  >> g_target >> g_weight;
        g_start--; g_target--;
        g_adjList[g_start].push_back({g_target, g_weight});
    }
    cin >> g_start >> g_target;
    g_start--;g_target--;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, CustomCmp> busQ; // {nowWeight, nowCity}
    busQ.push({0, g_start});
    g_visited[g_start][g_start] = 0;
    while(!busQ.empty())
    {
        pair<long long, int> now = busQ.top(); // {nowWeight, nowCity}
        busQ.pop();
        if(g_answer <= now.first)
            continue;
        for(int nextIdx = 0; nextIdx < g_adjList[now.second].size(); nextIdx++)
        {
            int nextCity = g_adjList[now.second][nextIdx].first;
            long long nextWeight = g_adjList[now.second][nextIdx].second + now.first;
            if(g_answer <= nextWeight ||g_visited[nextCity][now.second] <= nextWeight)
                continue;
            g_visited[nextCity][now.second] = nextWeight;

            if(nextCity == g_target)
            {
                g_answer = min(g_answer, nextWeight);
                continue;
            }
            busQ.push({nextWeight, nextCity});
        }
    }
    cout << g_answer;
    return 0;
}