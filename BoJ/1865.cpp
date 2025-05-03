/* 웜홀
https://www.acmicpc.net/problem/1865

N개의 지점 M개의 도로 W개의 웜홀이 있음
- 웜홀을 타면 시간이 거꾸로 감

입력
- TC (1~5)
- N (1~500) M(도로개수1~2500) W(웜홀개수1~200)
- S E T
- ...
-

출력
- 각 TC 별 시간이 거꾸로되는지 YES or NO

풀이
- 벨만포드면 시작지점으로 부터 어차피 다시 돌아오는거까지 체크함
- 벨만포드해서 음수사이클있는지만 체크하면 됨
- 음수사이클 있으면 YES, 없으면 NO
*/
#include <bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX
typedef long long ll;
struct Node_t{
    int start;
    int target;
    int time;
};
int g_TC, g_N, g_M, g_W, g_u, g_v, g_t;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_TC;
    while(g_TC--)
    {
        cin >> g_N >> g_M >> g_W;
        vector<vector<Node_t>> nodes(g_N+1);
        vector<ll> dist(g_N+1, 0);
        // 양방향 도로 입력
        for(int mIdx = 0; mIdx < g_M; mIdx++)
        {
            cin >> g_u >> g_v >> g_t;
            nodes[g_u].push_back({g_u, g_v, g_t});
            nodes[g_v].push_back({g_v, g_u, g_t});
        }
        // 단방향 웜홀 입력
        for(int wIdx = 0; wIdx < g_W; wIdx++)
        {
            cin >> g_u >> g_v >> g_t;
            nodes[g_u].push_back({g_u, g_v, -g_t});
        }
        // 벨만포드로 시간이 계속 거꾸로가는지 확인
        queue<Node_t> sideQ;
        for(int mainLoop = 0; mainLoop < g_N; mainLoop++)
        {
            for(int start = 1; start <= g_N; start++)
            {
                for(auto next: nodes[start])
                {
                    if(dist[start]+ next.time < dist[next.target])
                    {
                        if(mainLoop == g_N-1)
                            sideQ.push(next);
                        dist[next.target] = dist[start]+ next.time;
                    }
                }
            }
        }
        if(sideQ.empty())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
