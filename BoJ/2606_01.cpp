/*
바이러스
연결되어있는 컴퓨터에 점염되는 바이러스.
1번컴퓨터를 통해 바이러스에 걸리는 컴퓨터 수를 출력하라.

[입력]
컴퓨터수C (1~100)
네트워크상에직접 연결된 컴퓨터쌍의 수 N
컴퓨터 쌍
...

[출력]
1번컴퓨터로 부터 전염된 컴퓨터 수

[풀이]
아무 탐색으로 weight 카운트 하면 끝날 듯
근데 BFS로 푸는게 좀 맘편할 듯

*/
#include <bits/stdc++.h>
using namespace std;
int g_C, g_N, g_infect, g_first, g_second;
vector<vector<int>> g_net(101);
vector<int> g_visited(101,0);
queue<int> g_coms;

int main()
{
    cin >> g_C >> g_N;
    for(int loopCnt = 0; loopCnt < g_N; loopCnt++)
    {
        cin >> g_first >> g_second;
        g_net[g_first].push_back(g_second);
        g_net[g_second].push_back(g_first);
    }
    g_coms.push(1);
    g_visited[1] = 1;
    while(!g_coms.empty())
    {
        int nowCom = g_coms.front();
        g_coms.pop();
        for(auto next: g_net[nowCom])
        {
            if(!g_visited[next])
            {
                g_coms.push(next);
                g_visited[next] = 1;
                g_infect++;
            }
        }
    }
    cout << g_infect;
    return 0;
}