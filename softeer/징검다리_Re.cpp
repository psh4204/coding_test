/* 징검다리
https://softeer.ai/practice/6293

dp로 풀어봤음. 잘풀리네 ㅋㅋ
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> g_stones(3001);
vector<ll> g_dp(3001,0);
int g_N = 0;
ll g_maxCnt = 0;

int main()
{
    cin >> g_N;
    for(int inCnt = 1; inCnt <= g_N; inCnt++)
    {
        cin >> g_stones[inCnt];
        for(int checkIdx = 1; checkIdx <= inCnt; checkIdx++)
        {
            if(g_stones[inCnt] > g_stones[checkIdx])
                g_dp[inCnt] = max(g_dp[inCnt], g_dp[checkIdx]); 
        }
        g_dp[inCnt]++;
        g_maxCnt = max(g_dp[inCnt], g_maxCnt);
    }
    cout << g_maxCnt;
    return 0;
}