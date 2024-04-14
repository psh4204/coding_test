#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 피라미드 형태의 배열이 주어진다.
// 피라미드 상단에서 가장 하단까지 가는데 수의 합이 가장 큰경우를 찾아본다.
// - 아래칸으로 움직일땐 대각선으로 오른쪽 혹은 왼쪽으로 내려가야한다.
// - 최대값 함 구해봐라 가장 밑으로 내려갔을 때 최대값 한번 구해봐라~

/*
시환
- 경우 수: 2^(마지막행사이즈-1).
- 테뷸레이션 기법으로 풀어야 할듯.
- 삼각형의 각 노드에서 최대값을 계산한 후 삼각형 테이블에 그대로 저장하자.

삼각형 이동 예시
[0][0],
[1][0],[1][1],
[2][0],[2][1],[2][2],
[3][0],[3][1],[3][2],[3][3],
- 0,0 -> 1,0 / 1,1
- 1,0 -> 2,0 / 2,1
- 1,1 -> 2,1 / 2,2
- 2,2 -> 3,2 / 3,3
이동 규칙성
- 부모 노드는 자식노드1(같은행, 같은열) 과 자식노드2(같은행,같은열+1)에 접근 가능.

DP 테이블 저장방법: 최대값 M을 구해 해당 테이블에 저장한다.
- 0,0 인경우: 그대로 저장
- 나머지: 자식노드의 최대값을 저장해나간다.
- 리턴값: 마지막 행에서 가장 큰 값

*/

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int row_size = triangle.size();

    // 삼각형 복사
    vector<vector<int>> dp = triangle;
    // 삼각형 확인용 코드
    for(auto&r : dp)
    {
        for(auto c: r)
        {
            cout<< c << ", ";
        }
        cout<<endl;
    }

    for(int r = 0; r< row_size; r++)
    {
        int colum_size = triangle[r].size();
        for(int c = 0; c < colum_size; c++)
        {
            if(r == 0 && c == 0)
                continue;
            else if(c == 0)
                dp[r][c] += dp[r-1][c];
            else if(c == colum_size-1)
            {
                dp[r][c] += dp[r-1][c-1];
            }
            else
            {
                dp[r][c] += max(dp[r-1][c],dp[r-1][c-1]);
            }
        }
    }

        // 삼각형 확인용 코드
    for(auto&r : dp)
    {
        for(auto c: r)
        {
            cout<< c << ", ";
        }
        cout<<endl;
    }

    // 마지막 경로에서 최대 값 찾기.
    for(auto data: dp[row_size-1])
    {
        if(answer < data)
            answer = data;
    }
    
    cout<< "Max: " << answer << endl;

    return answer;
}

int main(void)
{
    vector<vector<int>> triangle= {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    solution(triangle);
    return 0;
}