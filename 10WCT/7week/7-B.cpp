/* https://www.acmicpc.net/problem/17070
파이프 옮기기 1

집표현: NxN. (r,c)// 1부터 시작
2칸짜리 파이프를 옮기려함. 3가지로 회전가능함
- →, ↘, ↓

파이프를 밀어서 회전시키려함. 미는방향은 오른쪽, 아래, 오른쪽아래 대각선 방향.(→, ↘, ↓)
- 이동하려는 위치에 벽있으면 이동 불가. (1x2, 2x1, 2x2 등등)

파이프위치는 (0,0). 빈칸은 0, 벽은 1. (파이프위치는 무조건 빈칸)

파이프 한쪽끝을 N,N으로 이동시키는 개수 구하기

입력
- N (3~16)
- 집 지도

출력
- 한쪽 끝(N-1,N-1)로 이동시키는 방법의 수.(이동불가 0. 방법의수는 0~1M)

도전1
<구현>
- 파이프 상태 체크 후 다음으로 움직일수있는지 체크하자.
    - enum: 가로, 세로, 대각선
- 각 상태에서 움직일 수 있는 경우의 수
    - 가로(오른쪽,대각): (y0, x0+1),(y1, x1+1) / (y0,x0+1),(y1+1,x1+1)
    - 세로(아래,대각): (y0+1, x0),(y1+1, x1) / (y0+1,x0),(y1+1,x1+1)
    - 대각(가로,아래,대각): (y0+1,x0+1),(y1,x1+1) / (y0+1,x0+1),(y1+1,x1) / (y0+1,x0+1),(y1,x1+1)
- 벽체크
    - 밀어서 움직이기 때문에 끝부분이 해당벽에 부딛히는지 체크해야함
    - 특히 어떤상태이던 대각으로 움직일때 벽체크 꼭해야함
        > 파이프끝에서 다음 3개공간: (y1,x1+1) (y1+1,x1) (y1+1,x1+1) 
- DFS로 일단 구현해보자
    - 각 State 별 단순구현 ㄱㄱ.

16
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/
#include <bits/stdc++.h>
using namespace std;

#define N_MAX 16
#define INF 987654321
enum pipe_state{
    GARO,
    SERO,
    DEAGAK,
};
struct pipe_t{
    int front[2];
    int back[2];
    pipe_state state;
};
vector<vector<int>> _room;
int _N;

inline int move_pipe(pipe_t pipe)
{
    // //[[TEST]]
    // cout << "\n";
    // for(int y = 0; y < _N; y++)
    // {
    //     for(int x = 0; x< _N; x++)
    //     {
    //         if((y == pipe.front[0] && x == pipe.front[1]) || (y == pipe.back[0] && x == pipe.back[1]))
    //             cout << 8 << " ";
    //         else
    //             cout << _room[y][x] << " ";
    //     }
    //     cout << "\n";
    // }

    if(pipe.back[0] == _N-1 && pipe.back[1] == _N-1)
        return 1;
    int ret = 0;
    if(pipe.state == GARO)
    {
        // 가로(오른쪽,대각): (y0, x0+1),(y1, x1+1) / (y0,x0+1),(y1+1,x1+1)
        if(pipe.back[1]+1 < _N && 
            !(_room[pipe.back[0]][pipe.back[1]+1]))
            ret += move_pipe({{pipe.front[0],pipe.front[1]+1},{pipe.back[0],pipe.back[1]+1},GARO});
        
        if(pipe.back[0]+1 < _N && pipe.back[1]+1 < _N && 
            !(_room[pipe.back[0]][pipe.back[1]+1] || _room[pipe.back[0]+1][pipe.back[1]]||_room[pipe.back[0]+1][pipe.back[1]+1]))
            ret += move_pipe({{pipe.front[0],pipe.front[1]+1},{pipe.back[0]+1,pipe.back[1]+1},DEAGAK});
    }
    else if(pipe.state == SERO)
    {
        // 세로(아래,대각): (y0+1, x0),(y1+1, x1) / (y0+1,x0),(y1+1,x1+1)
        if(pipe.back[0]+1 < _N && 
            !(_room[pipe.back[0]+1][pipe.back[1]]))
            ret += move_pipe({{pipe.front[0]+1,pipe.front[1]},{pipe.back[0]+1,pipe.back[1]},SERO});
        
        if(pipe.back[0]+1 < _N && pipe.back[1]+1 <_N && 
            !(_room[pipe.back[0]][pipe.back[1]+1] || _room[pipe.back[0]+1][pipe.back[1]]||_room[pipe.back[0]+1][pipe.back[1]+1]))
            ret += move_pipe({{pipe.front[0]+1,pipe.front[1]},{pipe.back[0]+1,pipe.back[1]+1},DEAGAK});
    }
    else if(pipe.state == DEAGAK)
    {
        // 대각(가로,아래,대각): (y0+1,x0+1),(y1,x1+1) / (y0+1,x0+1),(y1+1,x1) / (y0+1,x0+1),(y1+1,x1+1)
        if(pipe.back[1]+1 <_N && 
            !(_room[pipe.back[0]][pipe.back[1]+1]))
            ret += move_pipe({{pipe.front[0]+1,pipe.front[1]+1},{pipe.back[0],pipe.back[1]+1},GARO});
        
        if(pipe.back[0]+1 < _N && 
            !(_room[pipe.back[0]+1][pipe.back[1]]))
            ret += move_pipe({{pipe.front[0]+1,pipe.front[1]+1},{pipe.back[0]+1,pipe.back[1]},SERO});
        
        if(pipe.back[0]+1 < _N && pipe.back[1]+1 <_N && 
            !(_room[pipe.back[0]][pipe.back[1]+1] || _room[pipe.back[0]+1][pipe.back[1]]||_room[pipe.back[0]+1][pipe.back[1]+1]))
            ret += move_pipe({{pipe.front[0]+1,pipe.front[1]+1},{pipe.back[0]+1,pipe.back[1]+1},DEAGAK});
    }
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    _room.resize(_N,vector<int>(_N));
    for(int y = 0; y <_N; y++)
    {
        for(int x = 0; x<_N; x++)
            cin >> _room[y][x];
    }
    pipe_t pipe = {{0,0}, {0,1}, GARO};
    cout << move_pipe(pipe);
    return 0;
}