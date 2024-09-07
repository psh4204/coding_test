/* https://www.acmicpc.net/problem/15684
사다리 조작

세로선 N개, 가로선 M개로 이루어진 사다리.
세로선에서 가로선을 H개 그을 수 있음.

만들어진 사다리게임에서 i번의 사다리는 i번으로 돌아오게끔 조작하려한다.
새로 그어야할 가로선의 최소값을 구하자.
Note: 가로선을 세로선양방향으로 연속으로 그어질 순 없다.

Input
- 세로라인N 그어진가로선수M 가로점선라인H
    (2~N~10, 1~H~30, 0~M~(N-1)*H)
- 가로선의 정보 a b (1~a~H, 1~b~N-1. a번 점선이 b+1세로선으로 그어짐 )
    - 가장위, 가장왼쪽이 1이다.
    - 중복되는 가로선은 없다.

Output
- 최소 조작가능 가로선 수(불가능 -1, 3 초과 -1.)

Try1.
- H x M 배열 만들기.
    - a b 값 잘받아서 1 표시 하기.
- 이동
    - H한칸씩 움직임.
    - 세로시프트: 본인 좌표가 1이면 왼쪽, 오른쪽좌표가1이면 오른쪽
- 탐색
    - 세로 한라인 라인 찾는건 DFS로.
    - 가로 라인 긋는건 BFS로.(zero 리스트)
        - 그을 수 있는(zero) 가로라인은 어디에 꽁겨두자.
        - 그을수있는 가로 포인트들 중 0~3개까지 그어보고 안나면 -1.

Try2.
- 시간초과
- 중복해서 하는 것들을 최소화 해보자.

Try3
- 생각해보니까.. DFS로 해야겠네. 사다리는 거의 웬만해선 지나다닌 길의 길이가 같으니까.
- 그래도 시간초과.. ㅋㅋㅋ 소주마렵네

Try4
- BFS에서 DFS로 바꾸고 중복할만한 것들 다 날려주니까 12 %  까지 올라옴
    - 더더더 효율적으로 write하고 erase 해야했음.
    - 이..작은걸 고쳐도 그렇게 빨라질까? 맞춰짐.
- 근데 이번에 틀림
- 머가틀린걸까
- BFS를 안써서 최단경로 or 최소값을 못구함.
    - min을 해줘야함.

Try5
- 자주쓰는 함수는 inline 을 붙이자.
    - 해당 키워드를 붙이면 코드를 사용할때 코드가 호출되어 사용되는것이 아닌
    코드가 그대로 사용됨(컴파일과정에서 그렇게함)
    - 오버헤드가 줄어든다는 표현을 사용함.
    - 시간이 최적화됨.
    - 단, 코드크기가 커지니까 간단한 코드에만 사용하도록.
*/
#include <bits/stdc++.h>
using namespace std;
#define MIN_CNT 0
#define MAX_CNT 3

int _N, _M, _H, _ret = -1;
vector<vector<int>> _paper;
vector<pair<int,int>> _zeros;

int _dx[2] = {0, 1};    // 밑으로갈지, 오른쪽으로갈지.. 
                        // (+) 왼쪽갈지도 코드상에서 체크해야함

struct ladder_t
{
    int y = 0;
    int x = 0;
    int start = 0;
};

// 사다리 타기.. DFS
inline bool dfs(ladder_t here)
{
    pair<int,int> n_yx;
    n_yx.first = here.y + 1;
    n_yx.second = here.x;
    if(here.x >= 1 && _paper[here.y][here.x - 1] == 1)
        n_yx.second--;
    else
        n_yx.second += _dx[_paper[here.y][here.x]];

    // 완전 끝까지 도달한 후 그 다음  x값을 봐야해서 "초과"비교함.
    if(n_yx.first < 0 || n_yx.first > _H 
        || n_yx.second <0 || n_yx.second >= _N) 
        return  false;
    // 끝에 도달하지 않았을경우 go dfs
    if(n_yx.first != _H)
    {
        return dfs({n_yx.first, n_yx.second, here.start});
    }
    // 마지막에 도달한 후
    else
    {   // 의도하지 않은 사다리라면 함수탈출
        if(here.start != n_yx.second)
            return false;
        // 마지막에 도달한 후 의도한 값이 나왔으면 true
        return true;
    }
}

inline void process_ladders_dfs(int ld_cnt)
{
    bool is_collect = false;
    for(int x = 0; x < _N; x++)
    {
        if(dfs({0, x, x}) == false)
            return;
    }
    
    // 의도한대로 조작된 사다리라면 이곳으로 도달
    if(_ret == -1 || _ret > ld_cnt)
        _ret = ld_cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>> _N >> _M >> _H;
    _paper.resize(_H, vector<int>(_N));
    for(int m = 0; m < _M; m++)
    {
        int h, n;
        cin >> h >> n;
        _paper[h-1][n-1] = 1;
    }
    
    // get zeros
    for(int y = 0; y < _H; y++)
    {
        for(int x = 0; x < _N-1; x++)   // input a b 조건에 맞게.
        {
            // 입력된 가로줄 중복조건 없다니까, 따로 처리할거없음
            if(_paper[y][x] == 0)
                _zeros.push_back({y,x});
        }
    }

    if(_zeros.size() == _paper.size()*_paper[0].size())
    {
        cout << 0;
        return 0;
    }
    
    // no combi
    process_ladders_dfs(0);
    // get combis 1.
    for(int f_i = 0; f_i < _zeros.size(); f_i++)
    {
        _paper[_zeros[f_i].first][_zeros[f_i].second] = 1;
        process_ladders_dfs(1);

        // get combis 2.
        for(int s_i = f_i+1; s_i < _zeros.size(); s_i++)
        {
            if((_zeros[f_i].first == _zeros[s_i].first) 
                && (abs(_zeros[f_i].second - _zeros[s_i].second) <= 1))
                continue;
            _paper[_zeros[s_i].first][_zeros[s_i].second] = 1;
            process_ladders_dfs(2);

            // get combis 3.
            for(int t_i = s_i+1; t_i < _zeros.size(); t_i++)
            {
                if(((_zeros[f_i].first == _zeros[t_i].first) 
                        && (abs(_zeros[f_i].second - _zeros[t_i].second) <= 1))
                    ||((_zeros[s_i].first == _zeros[t_i].first) 
                        && (abs(_zeros[s_i].second - _zeros[t_i].second) <= 1)))
                    continue;
                _paper[_zeros[t_i].first][_zeros[t_i].second] = 1;
                process_ladders_dfs(3);
                _paper[_zeros[t_i].first][_zeros[t_i].second] = 0;
            }

            _paper[_zeros[s_i].first][_zeros[s_i].second] = 0;
        }

        _paper[_zeros[f_i].first][_zeros[f_i].second] = 0;
    }

    cout << _ret;
    return 0;
}