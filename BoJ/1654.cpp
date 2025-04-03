/* 랜선자르기
https://www.acmicpc.net/problem/1654

N개의 랜선을 만들어야함
가지고있는 길이가 각각 다른 K개의 랜선을 잘라서 만들어야함
- 300 짜리로 140 두개 만들 수 있음

N개로 만들 수 있는 최대 랜선길이를 구해보자

입력
- K N (K는 1~10,000. N은 1~1,000,000. 항상 K는 N보다 작음)
- K개의 랜선길이

출력
- N개로 만들 수 있는 최대 랜선길이

풀이
- 선형적으로 문제에 접근해서 최적화를 했지만 시간초과남
- 이분탐색법을 통해 랜선길이를 구해보자 (이분탐색이 탐색법중 가장기본)
- 가장큰값을 max로 두고, 가장큰 랜선길이를 탐색해본다
- (노트) 값의 최대범위를 항상 잘 확인하자. 문제를 잘 읽고 풀자.
*/
#include <bits/stdc++.h>
using namespace std;
int g_K, g_N;
long long g_LanCnt, g_lLan = 1, g_rLan, g_midLan, g_maxLan;
vector<int> g_kLans;

int main()
{
    cin >> g_K >> g_N;
    while(g_K--)
    {
        long long input;
        cin >> input;
        g_rLan = max(g_rLan, input);
        g_kLans.push_back(input);
    }
    // cout << "g_rLan: " << g_rLan << "\n"; // <<TEST>>

    while(g_lLan <= g_rLan)
    {
        g_LanCnt = 0;
        g_midLan = (g_lLan + g_rLan)/2;
        for(int kIdx = 0; kIdx < g_kLans.size(); kIdx++)
            g_LanCnt += g_kLans[kIdx]/g_midLan;
        // cout << "g_LanCnt: " << g_rLan << "\n"; // <<TEST>>
        if(g_LanCnt >= g_N)
        {
            g_lLan = g_midLan+1;
            g_maxLan = max(g_midLan, g_maxLan);
            // cout << "max: " << g_maxLan << "\n"; // <<TEST>>
        }
        else if(g_LanCnt < g_N)
        {
            g_rLan = g_midLan -1;
        }
    }
    cout << g_maxLan;
    return 0;
}