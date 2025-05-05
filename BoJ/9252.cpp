/* LCS 2
https://www.acmicpc.net/problem/9252

LCS 길이를 구하고, LCS를 출력하라

입력
- 문자열1
- 문자열2

출력
- LCS길이
- LCS

풀이
- LCS dp를 써야하는 문제
- History: dp로 최종사이즈 구하면, 역으로 해당 인덱스를 통해 값을 추적해서 문자열을 쌓는다
*/
#include <bits/stdc++.h>
using namespace std;
string g_A;
string g_B;
int g_aIndex, g_bIndex;
vector<vector<int>> g_dp(1001, vector<int>(1001));
stack<char> g_lcs;

int main()
{
    cin >> g_A;
    cin >> g_B;
    for(int aIdx = 1; aIdx <= g_A.size(); aIdx++)
    {
        int realA = aIdx -1;
        for(int bIdx = 1; bIdx <= g_B.size(); bIdx++)
        {
            int realB = bIdx-1;
            if(g_A[realA] == g_B[realB]) // 같은 문자 발견하면, 문자를 담을지 안담아도 될지 체크
            {
                g_dp[aIdx][bIdx] = max(g_dp[aIdx-1][bIdx-1]+1, g_dp[aIdx][bIdx-1]); // 대각+1, 위 체크
            }
            else // 같은 문자 없다면
            {
                g_dp[aIdx][bIdx] = max(g_dp[aIdx-1][bIdx], g_dp[aIdx][bIdx-1]); // 왼, 위 체크
            }
        }
    }
    int aIdx = g_A.size(), bIdx = g_B.size();
    while((aIdx > 0 || bIdx > 0) && g_lcs.size() < g_dp[g_A.size()][g_B.size()])
    {
        int realA = aIdx-1;
        int realB = bIdx-1;
        
        // 공통 문자열 찾으면
        if(g_A[realA] == g_B[realB]) // 체크 후 대각으로 이동
        {
            g_lcs.push(g_A[realA]);
            aIdx--; bIdx--;
        }
        // 공통 문자열 못찾으면
        else
        {
            if(g_dp[aIdx-1][bIdx] > g_dp[aIdx][bIdx-1])
            {
                aIdx--;
            }
            else
            {
                bIdx--;
            }
        }
    }
    cout << g_lcs.size() << "\n";
    while(!g_lcs.empty())
    {
        cout << g_lcs.top();
        g_lcs.pop();
    }

    return 0;
}