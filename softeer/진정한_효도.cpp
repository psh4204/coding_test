/* 진정한 효도
3*3 배열의 높이 1~3의 땅이 있음.
부모님이 농사를 가로세로 한줄 한줄 지으심.
근데 땅의 높이가 동일해야 농사지을 수있으심.
그래서 땅의 높이를 낮추거나 높여주기로함.
- 높이를 1높이거나 1낮추면 비용1이 소모됨.

농사를 지을 수 있게 땅을 일구는데 드는 최소비용을 구하시오.

입력
- 3*3 농지

출력
- 최소비용

풀이
- 가로 세로 3칸짜리를 묶어서 배열에 담는다.
- 각 라인마다 최소비용을 구해서 min값을 찾는다.
  - 각 라인마다 1, 2, 3 차례로 뺀후의 절대값으로 비용을 구한다.
  - 그 비용 중 가장 최소비용을 구한다.
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> _land(3,vector<int>(3));
int _min_resource = 987654321;

int main(int argc, char** argv)
{
    for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
            cin >> _land[r][c];
    }
    
    // 가로 체크
    for(int r = 0; r < 3; r++)
    {
        int resource = 0;
        for(int l_cnt = 1; l_cnt <= 3; l_cnt++)
        {
            resource = abs(_land[r][0] - l_cnt) + abs(_land[r][1] - l_cnt) + abs(_land[r][2] - l_cnt);
            _min_resource = min(_min_resource, resource);
        }
    }
    // 세로 체크
    for(int c = 0; c < 3; c++)
    {
        int resource = 0;
        for(int l_cnt = 1; l_cnt <= 3; l_cnt++)
        {
            resource = abs(_land[0][c] - l_cnt) + abs(_land[1][c] - l_cnt) + abs(_land[2][c] - l_cnt);
            _min_resource = min(_min_resource, resource);
        }
    }
    cout << _min_resource;
    return 0;
}