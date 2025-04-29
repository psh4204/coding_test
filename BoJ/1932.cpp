/* 정수 삼각형
https://www.acmicpc.net/problem/1932

정수 삼각형의 탑에서 아래로 내려가며 합했을대 최대값을 구하라
이동범위는 왼쪽대각선, 오른쪽 대각선이다

입력
- N (1~500)
- 삼각형

출력
- 바닥에서 최대값

풀이
- 현재 i는 아래 i와 아래 i+1 중 최대값을 골라 합해주며 나아간다
- 근데 이거보단 아래서부터 시작하는게 더 좋을거같아보임 (차피 루프 10만번대임) (Bottom->Top)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g_N;
vector<vector<ll>> g_tri(1001,vector<ll>(1001)); // 삼각형
vector<vector<ll>> g_sums(1002, vector<ll>(1002)); // 삼각형 합

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    // g_tri.resize(g_N,vector<ll>(g_N));
    // g_sums.resize(g_N+1,vector<ll>(g_N));
    for(int yIdx = 0; yIdx < g_N; yIdx++)
    {
        for(int xIdx = 0; xIdx <= yIdx; xIdx++)
            cin >> g_tri[yIdx][xIdx];
    }
    for(int yIdx = g_N-1; yIdx >= 0; yIdx--)
    {
        for(int xIdx = 0; xIdx <= yIdx; xIdx++)
        {
            g_sums[yIdx][xIdx] =g_sums[yIdx+1][xIdx] >= g_sums[yIdx+1][xIdx+1]?
                                g_sums[yIdx+1][xIdx] + g_tri[yIdx][xIdx]:
                                g_sums[yIdx+1][xIdx+1] + g_tri[yIdx][xIdx];
        }
        // // TEST >>>
        // for(int xIdx = 0; xIdx <= yIdx; xIdx++)
        // {
        //     cout << g_sums[yIdx][xIdx] << " ";
        // }
        // cout << "\n";
        // // <<< TEST 
    }
    cout << g_sums[0][0];
    return 0;
}