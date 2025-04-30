/* 스티커
https://www.acmicpc.net/problem/9465

2N개의 스티커씰에서 다음 사항을 고려하여 스티커를 떼어내어 가장 높은 가치를 만들어라
- 스티커를 떼어내면 4방향의 스티커는 사용할 수 없게된다
- 각 스티커는 가치가 부여되어있다

입력
- TC
- N (1~100,000)
- 스티커 값들
- ...

출력
- 각 TC별 최대 가치 출력 (제한시간 1초)

풀이
- 딱봐도 dp문제
- dp: 현재 칸의 스티커까지 뗐을때 최대 가치는? 
    - 현재 스티커를 떼는 경우: 왼쪽대각선 아래,위 스티커와 합쳤을때 바로 왼쪽스티커보다 값이 크면 뗌
        - 더 크지않으면 왼쪽값 이열
규칙 어케찾음?
- 감으로. 보통, 무엇이 포함되고 안되고를 체크하려면 테이블에서 좀 굴려봐야함
    - 보통은, 현재까지 가장 최고의 값만 넣어야하는 규칙이 있음.
    - 그리고 이전값은 항상 이전단계에서 최고여야함 
    (현개값을 추가했는데도 현재값이 작으면 넣을필요없음. 목표지점까지 가는데 골목길 하나하나 무시하고 가듯)
- 가설세우고 그 가설이 맞다싶으면 반례돌리고 코딩
- 드디어 DP다운문제들이 풀리네 ㅠㅠ
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g_TC, g_N;
ll g_ans;
vector<vector<ll>> g_stickers(2, vector<ll>(100001)); // [0][n]: 위칸. [1][n]: 아래칸

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_TC;
    for(int tcIdx = 0; tcIdx < g_TC; tcIdx++)
    {
        cin >> g_N;
        for(int stIdx = 0; stIdx <= 1; stIdx++)
        {
            for(int nIdx = 1; nIdx <= g_N; nIdx++)
            {
                cin >> g_stickers[stIdx][nIdx];
            }
        }

        for(int nIdx = 1; nIdx <= g_N; nIdx++)
        {
            // 위 스티커 최대가치 체크
            ll stickSum = g_stickers[1][nIdx-1]+g_stickers[0][nIdx];
            g_stickers[0][nIdx] = max(stickSum, g_stickers[0][nIdx-1]);
            // 아래 스티커 최대가치 체크
            stickSum = g_stickers[0][nIdx-1]+g_stickers[1][nIdx];
            g_stickers[1][nIdx] = max(stickSum, g_stickers[1][nIdx-1]);
        }

        // // << TEST
        // for(int stIdx = 0; stIdx <= 1; stIdx++)
        // {
        //     for(int nIdx = 0; nIdx <= g_N; nIdx++)
        //     {
        //         cout << g_stickers[stIdx][nIdx] << " ";
        //     }
        //     cout << "\n";
        // }
        // // >> TEST
        g_ans = max(g_stickers[0][g_N], g_stickers[1][g_N]);
        cout << g_ans << "\n";
    }
    return 0;
}