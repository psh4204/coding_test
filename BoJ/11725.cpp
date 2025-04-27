/* 트리의 부모찾기
https://www.acmicpc.net/problem/11725

루트없는 트리가 주어짐
트리의 루트를 1이라 했을때, 각 노드의 부모를 구하는 프로그램 작성

입력
- 노드개수(2~100,000)
- 연결된 두노드들

출력
- 각 숫자 차례대로 부모노드를 출력한다

풀이
- 양방향 adj로 연결된 노드 기입
- 1부터 차례로 방문할텐데 visited에 최초로 들어온 idx를 부모idx로 함 
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_start, g_target, g_lastNode;
vector<int> g_parents(100001, -1);
vector<vector<int>> g_adjList(100001);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    for(int inCnt = 1; inCnt < g_N; inCnt++)
    {
        cin >> g_start >> g_target;
        g_adjList[g_start].push_back(g_target);
        g_adjList[g_target].push_back(g_start);
    }
    queue<int> nodeQ;
    nodeQ.push(1);
    g_parents[1] = 0;
    while(!nodeQ.empty())
    {
        int now = nodeQ.front();
        nodeQ.pop();
        for(int adjIdx = 0; adjIdx < g_adjList[now].size(); adjIdx++)
        {
            int next = g_adjList[now][adjIdx];
            if(g_parents[next] != -1)
                continue;
            g_parents[next] = now;
            // cout << next << "'s Parent is " << now << " << \n"; // [[TEST]]
            nodeQ.push(next);
        }
    }
    for(int nodeIdx = 2; nodeIdx <= g_N; nodeIdx++)
    {
        if(g_parents[nodeIdx] != -1)
            cout << g_parents[nodeIdx] << "\n";
    }
    return 0;
}