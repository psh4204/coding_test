/* N-Queen 
https://www.acmicpc.net/problem/9663

체스 퀸: 상하좌우 대각 전부 자유롭게 이동가능

NxN체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제다
- N이 주어졌을때 퀸을 놓는 방법의 수를 구하라

입력
- N (N 1~15)

출력
- 퀸N개가 서로 공격할수 없게 놓는 경우의 수를 구한다

풀이
- 한행에는 한퀸밖에 못놓음 (<----- 이게  킥 포인트)
- 첫번째 핀을 중심으로 쭉 부루트 포스 해야할듯
    - 한 행에 핀 하나씩 적절히 둔 후 카운트
    - 같은 열인 애들은 쉽게 체크가능할듯 (비트연산 가능-15까지라)
    - 문제는 대각선인데, 위의 행에 대각선으로 자신이 놓여있는지 체크하면 되네
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g_N, g_xCheck = 0;
ll g_cnt;
vector<vector<bool>> g_chess(16, vector<bool>(16,false));

void CheckQueen(int yIdx)
{
    for(int xIdx = 1; xIdx <= g_N; xIdx++)
    {
        bool isContinue = false;
        for(int preIdx = 1; yIdx - preIdx > 0; preIdx++)
        {
            int preY = yIdx - preIdx;
            if((g_chess[preY][xIdx] == true)    // 상단 체크
                || (xIdx - preIdx > 0 && g_chess[preY][xIdx - preIdx] == true) // 대각선 좌쪽 체크
                || (xIdx + preIdx <= g_N && g_chess[preY][xIdx + preIdx] == true)) // 대각선 우측 체크
            {
                // 하나라도 퀸있으면 건너뜀
                isContinue = true;
                break;
            }
        }
        if(isContinue)
            continue;
        
        if(yIdx == g_N) // 마지막열 퀸핀을 둘수 있을 때 카운트
            g_cnt++;
        else            // 아직마지막열 아니면, visited 처리 후 다음 퀸 보러 가기
        {
            g_chess[yIdx][xIdx] = true;
            CheckQueen(yIdx+1);
            g_chess[yIdx][xIdx] = false;
        }
    }
}

int main()
{
    cin >> g_N;
    CheckQueen(1);

    cout << g_cnt;
    return 0;
}