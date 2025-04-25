/* https://www.acmicpc.net/problem/14500
테트로 도미노

폴리오미노: 1x1 정사각형을 여러개 붙인 도형
- 도형은 모두 연결됨
- 겹치면안됨
- 변끼리 연결됨

4개짜리 테트로노미노의 5개조합은 문제에 들어가서 확인하라

정수가 쓰여진 NxM 종이에 테트로미노를 하나 놓아 최대 정수합이 나오는 것을 구하라
- 종이안에 테트로노미노가 반드시 들어가야하며, 반전과 회전을 시켜도 된다

입력
- N M (세로 가로. 4~500)
- 종이 배열

출력
- 최대수

풀이
- 테트로노미노 종류를 가지고 한칸한칸 visited 해야겠네
    - 0001 <- 이런느낌으로 각각 만들어서 체크하자
      1111
    - {y,x},{테트로노미노 칸들}
- DFS로 체크 하고, 최대값을 구하는거니까 모든경우를 봐야함.. ㅠㅠ

*/
#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int ySize; // 현재보다 몇 y더 넘어가는지
  int xSize; // 현재보다 몇 x더 넘어가는지
  vector<pair<int,int>> diagram; // {y,x}
}TETRO_t;
vector<TETRO_t> g_tetros = 
{
  {1,1, {{0,0},{0,1},{1,0},{1,1}}}, // 사각형
  
  {0,3, {{0,0},{0,1},{0,2},{0,3}}}, // ㅡ
  {3,0, {{0,0},{1,0},{2,0},{3,0}}}, // ㅣ
  
  {2,1, {{0,0},{0,1},{1,1},{2,1}}}, // 세로 ㄱ
  {2,1, {{0,0},{0,1},{1,0},{2,0}}}, // 세로 ㄱ 거울
  {2,1, {{0,0},{1,0},{2,0},{2,1}}}, // 세로 ㄴ 
  {2,1, {{0,1},{1,1},{2,1},{2,0}}}, // 세로 ㄴ 거울
  {1,2, {{0,0},{0,1},{0,2},{1,2}}}, // 가로 ㄱ
  {1,2, {{0,0},{0,1},{0,2},{1,0}}}, // 가로 ㄱ 거울
  {1,2, {{0,0},{1,1},{1,2},{1,0}}}, // 가로 ㄴ
  {1,2, {{1,0},{1,1},{1,2},{0,2}}}, // 가로 ㄴ 거울

  {2,1, {{0,0},{1,0},{1,1},{2,1}}}, // 세로 ㄹ
  {2,1, {{0,1},{1,1},{1,0},{2,0}}}, // 세로 ㄹ 거울
  {1,2, {{0,0},{0,1},{1,1},{1,2}}}, // 가로 ㄹ 
  {1,2, {{1,0},{1,1},{0,1},{0,2}}}, // 가로 ㄹ 거울
  
  {2,1, {{0,0},{1,0},{2,0},{1,1}}}, // ㅏ
  {2,1, {{0,1},{1,1},{2,1},{1,0}}}, // ㅓ
  {1,2, {{1,0},{1,1},{1,2},{0,1}}}, // ㅗ 
  {1,2, {{0,0},{0,1},{0,2},{1,1}}}, // ㅜ
};
int g_N, g_M, g_maxSum;
vector<vector<int>> g_paper;

void CheckMaxSum(int startY, int startX)
{
    for(int ttrIdx = 0; ttrIdx < g_tetros.size(); ttrIdx++)
    {
    if(g_tetros[ttrIdx].ySize + startY >= g_N ||
        g_tetros[ttrIdx].xSize + startX >= g_M)
        continue;
        int valueSum = 0;
        for(int dgIdx = 0; dgIdx < g_tetros[ttrIdx].diagram.size(); dgIdx++)
        {
            int ny = startY + g_tetros[ttrIdx].diagram[dgIdx].first;
        int nx = startX + g_tetros[ttrIdx].diagram[dgIdx].second;
        valueSum += g_paper[ny][nx];
        }
        g_maxSum = max(valueSum, g_maxSum);
    }
}

int main()
{
    cin >> g_N >> g_M;
    g_paper.resize(g_N, vector<int>(g_M));
    for(int inY = 0; inY < g_N; inY++)
    {
        for(int inX = 0; inX < g_M; inX++)
            cin >> g_paper[inY][inX];
    }
    for(int loopY = 0; loopY < g_N; loopY++)
    {
        for(int loopX = 0; loopX < g_M; loopX++)
            CheckMaxSum(loopY, loopX);
        }
    cout << g_maxSum;
    return 0;
}