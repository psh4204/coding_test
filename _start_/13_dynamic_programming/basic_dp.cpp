#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>>m)
{
    int rows = (int)m.size();
    int cols = (int)m[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols,0)); // 2차원 테이블로 초기화(0값)

    for(int y = 0; y < rows; y++) // 행 카운트 루프
    {
        for(int x = 0; x < rows; x++) // 열 카운트 루프
        {
            if(x == 0 && y == 0)    dp[y][x] = m[y][x]; // 행,열이 1번째 인 경우. 그대로 최소값으로 추가
            else if(x == 0)         dp[y][x] = dp[y-1][x] + m[y][x]; // 해당 행에서 첫번째 열이라면, 바로 상단의 값이랑 +한다. 
            else if(y == 0)         dp[y][x] = dp[y][x-1] + m[y][x]; // 해당 열에서 첫번째라면(아직 1행이라면), 바로 왼쪽값과 +한다.
            else                    dp[y][x] = min(dp[y-1][x], dp[y][x-1]) + m[y][x]; // 보통의 경우, 상단,왼쪽 중 최소 값과 +.
        }
    }
    return dp[rows-1][cols-1];
}

int main(void)
{
    vector<vector<int>> m = 
    {
        {2,7,5,4},
        {5,3,6,8},
        {7,8,7,4},
        {8,1,9,5},
    };
    cout << "Minimum cost: " << solution(m) << endl;
    
    return 0;
}