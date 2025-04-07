/* 듣보잡
https://www.acmicpc.net/problem/1764
듣도 못한놈 N
보도 못한놈 M

그다음 듣도못한놈 이름
그다음 보도못한놈 이름

여기서 듣도 보도 못한 잡놈을 사전순으로 나열하라

*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M;
string g_input;
unordered_set<string> g_nohears;
set<string> g_dbjobs;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    for(int dIdx = 0; dIdx < g_N; dIdx++)
    {
        cin >> g_input;
        g_nohears.insert(g_input);
    }
    for(int bIdx = 0; bIdx < g_M; bIdx++)
    {
        cin >> g_input;
        if(g_nohears.find(g_input) != g_nohears.end())
            g_dbjobs.insert(g_input);
    }
    cout << g_dbjobs.size() << "\n";
    for(auto poorMan: g_dbjobs)
        cout << poorMan << "\n";
}