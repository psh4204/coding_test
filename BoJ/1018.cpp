/* 체스판 다시 칠하기
https://www.acmicpc.net/problem/1018

M x N 보드를 찾았고, 8 x 8 체스판을 만들고싶음 ( 8 ~ 'M N' ~ 50 )
- 체스판 형식으로 색을 칠해야함
- 문제에서 맨왼쪽의 위의 색을 중심으로 색을 칠하라는 뜻인거로 보임

해당보드에서 8 x 8로 잘라서 체스판을 만들어야 햘때,
최소 색칠횟수를 구하라

풀이
- 해당보드에서 한칸씩 움직이며 최소값을 찾는 문제
- 코드에서 사용할 보드는 세가지
    - MxN보드: 내가받은 보드
    - 8x8정답보드: 받은보드에서 미리 제대로 색칠된 8x8체스판을 만든다
- 8x8씩 탐색하며 8x8정답보드와 해당 칸의 보드가 얼마나 다른지 카운트하여 최소값을 구해본다
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> g_board;
const vector<vector<char>> g_wStartBoard = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
};
const vector<vector<char>> g_bStartBoard = {
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
};

int g_M, g_N, g_minCnt = 987654321;

int CheckMinPaints(int currMIdx, int currNIdx, const vector<vector<char>> & chessBoard)
{
    int diffCnt = 0;
    for(int mIdx = currMIdx; mIdx < currMIdx+8; mIdx++)
    {
        for(int nIdx = currNIdx; nIdx < currNIdx+8; nIdx++)
        {
            int chessMIdx = mIdx - currMIdx;
            int chessNIdx = nIdx - currNIdx;
            if(g_board[mIdx][nIdx] != chessBoard[chessMIdx][chessNIdx])
                diffCnt++;
        }
    }
    return diffCnt;
}

int main()
{
    cin >> g_M >> g_N;
    g_board.resize(g_M, vector<char>(g_N,0));
    for(int mIdx = 0; mIdx < g_M; mIdx++)
    {
        for(int nIdx = 0; nIdx < g_N; nIdx++)
            cin >> g_board[mIdx][nIdx];
    }

    for(int mIdx = 0; mIdx <= g_M-8; mIdx++)
    {
        for(int nIdx = 0; nIdx <= g_N-8; nIdx++)
        {
            vector<vector<char>> answerBoard;
            // 두가지경우 전부다 체크한다
            g_minCnt = min(g_minCnt ,CheckMinPaints(mIdx, nIdx, g_wStartBoard));
            g_minCnt = min(g_minCnt ,CheckMinPaints(mIdx, nIdx, g_bStartBoard));
        }
    }
    cout << g_minCnt;
    return 0;
}