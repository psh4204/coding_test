/* 보석 상자
https://www.acmicpc.net/problem/2792

보석을 나눠줘야하는데, 모든 보석을 나눠줘야함 
보석을 받지못하는 학생이 있어도됨
아이는 한 종류의 보석만 가지게 됨
아이들의 질투심을 최소화 하며 보석을 나눠줘야함
- 질투심: 보석을가진 아이 중, 한 아이가 가지는 최대 보석개수

보석을 다 나눠줬을때 최소 질투심을 구하라

입력
- N(아이 1~1,000,000,000) M (색상 1~300,000. 아이보다 같거나 작음)
- 각 보석별 개수

출력
- 최소 질투심 값

풀이
- 각 보석에서 1개부터 아이들이게 나눠주며 계산 -> 오래걸림 (X)
- 보석개수 중 가장 많은 보석개수에서 반으로 나눈후, 보석개수 '이분탐색'을 고려한다 (O)
- 보석개수 이분탐색 후 가장 많이 보석을 받은 아이의 값을 질투심으로 계산
- 보석 나누기 후 받는 사람 수 체크 
- 
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll g_N, g_M, g_childs, g_lGem = 1, g_rGem, g_midGem, g_envy = 987654321;
vector<int> g_gems;

int main()
{
    cin >> g_N >> g_M;
    for(int inCnt = 0; inCnt < g_M; inCnt++)
    {
        int inGem;
        cin >> inGem;
        g_gems.push_back(inGem);
    }
    sort(g_gems.begin(), g_gems.end());
    g_rGem = g_gems[g_M-1];

    while(g_lGem <= g_rGem)
    {
        g_childs = 0;
        g_midGem = (g_lGem + g_rGem)/2;
        for(int gemIdx = 0; gemIdx < g_M; gemIdx++)
        {
            g_childs += g_gems[gemIdx]/g_midGem;
            if (g_gems[gemIdx]%g_midGem > 0)
                g_childs += 1;
            if(g_childs > g_N)
                break;
        }
        // cout << "g_midGem: " << g_midGem << ", g_childs: " << g_childs << ", g_envy: " << g_envy << "\n"; // <<TEST>>
        if(g_childs > g_N)
            g_lGem = g_midGem +1;
        else if(g_childs <= g_N)
        {
            g_rGem = g_midGem -1;
            g_envy = min(g_envy, g_midGem);
        }
    }
    cout << g_envy;
    return 0;
}