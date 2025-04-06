/* 기타레슨
https://www.acmicpc.net/problem/2343

N개의 강의 중 M개의 블루레이 개수에 모든 기타강의 영상을 녹화하기로했음
- 강의의 순서가 뒤바뀌면 안됨
블루레이 크기는 모두 같은 크기여야함
다 담을수 있는 블루레이의 최소길이 구하라

입력
- N M (강의수 N, 블루레이 M. 1~N,M~100,000)
- 강의타임 (10,000 안넘김)

출력
- 가능한 블루레이크기 최소크기

풀이
- 이분탐색으로 블루레이 크기를 중심으로 탐색해야할것으로 보임
- 첫 최소시간을 강의중 가장 긴 강의시간으로 (min)
- 첫 최종 강의시간의 합 (max)로
- 강의 최종길이 / N 을 블루레이 시간중간크기로 지정하자 (mid)
- 각 강의 값을 다 더하며 블루레이 카운트를 세는데, 카운트가 M과 같으면 max를 줄인다 (시간을 줄인다)
    - 카운트가 M보다 작다면 max를 줄인다 (시간을 줄인다)
    - 카운트가 더 크다면 min을 키운다
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll g_N, g_M, g_rTime, g_lTime, g_midTime, g_blrTime = 987654321;
vector<int> g_lessons;

int main()
{
    cin >> g_N >> g_M;
    for(int inCnt = 0 ; inCnt < g_N; inCnt++)
    {
        int input;
        cin >> input;
        g_lessons.push_back(input);
        g_lTime = max((ll)input, g_lTime);
        g_rTime += input;
    }
    // g_rTime /= g_M;

    while(g_lTime <= g_rTime)
    {
        g_midTime = (g_rTime+g_lTime)/2;
        ll blrCnt = 0;
        ll blrTime = 0;
        for(int lCnt = 0; lCnt < g_N; lCnt++)
        {
            if(g_midTime < g_lessons[lCnt] + blrTime)
            {
                blrTime = 0;
                blrCnt++;
            }
            if(blrCnt > g_M)
                break;
            
            blrTime += g_lessons[lCnt];
        }
        if(blrTime != 0)
            blrCnt++;
        // cout << "g_lTime: " << g_lTime << ", g_rTime: " << g_rTime <<", g_midTime: " << g_midTime << ", blrCnt"<< blrCnt<<"\n"; // <<TEST>>
        if(blrCnt > g_M)
            g_lTime = g_midTime +1;
        else if(blrCnt <= g_M)
        {
            g_rTime = g_midTime -1;
            // if(blrCnt == g_M) // <-- 이거 없앴는데 맞으면 문제가 이상한거 아님??
                g_blrTime = min(g_blrTime, g_midTime);
        }
    }
    cout << g_blrTime;
    return 0;
}