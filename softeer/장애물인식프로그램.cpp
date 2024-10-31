/* 장애물 인식 프로그램
장애물과 도로를 인식할 수 있는 프로그램 만들기.
1은 장애물, 0은 도로.
장애물 그룹의 별 장애물개수를 구하시오.

입력
- 지도크기
- 지도배열

출력
- 장애물 그룹의 별 장애물개수

풀이
- dfs를 통한 장애물 그룹화.

7
0110000
0111110
0110000
0000100
0110101
0110101
1110111
*/
#include<bits/stdc++.h>
using namespace std;
int _N;
int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};
vector<vector<int>> _city;
vector<vector<pair<int,int>>> _groups;

bool cmp(vector<pair<int,int>> first, vector<pair<int,int>> second)
{
    if(first.size() < second.size())
        return true;
    return false;
}

void set_group(int here_r, int here_c)
{
    _groups[_groups.size()-1].push_back({here_r,here_c});
    for(int n = 0; n < 4; n++)
    {
        int ny = here_r + _dy[n];
        int nx = here_c + _dx[n];
        if(ny < 0 || nx < 0 || ny >= _N || nx >= _N) continue;
        if(_city[ny][nx] == 0 || _city[ny][nx] != 1) continue;
        _city[ny][nx] = _groups.size()+1;
        set_group(ny,nx);
    }
}

int main(int argc, char** argv)
{
    cin >> _N;
    _city.resize(_N, vector<int>(_N));
    for(int r_cnt = 0; r_cnt < _N; r_cnt++)
    {
        string input;
        cin >> input;
        for(int c_cnt = 0; c_cnt < _N; c_cnt++)
            _city[r_cnt][c_cnt] = input[c_cnt] -'0';
    }
    // //[[TEST]]
    // for(int r_cnt = 0; r_cnt < _N; r_cnt++)
    // {
    //     for(int c_cnt = 0; c_cnt < _N; c_cnt++)
    //         cout << (int)_city[r_cnt][c_cnt];
    //     cout << "\n";
    // }

    for(int r = 0; r < _N; r++)
    {
        for(int c = 0; c < _N; c++)
        {
            if(_city[r][c] == 1)
            {
                _groups.push_back({});
                _city[r][c] = _groups.size()+1;
                set_group(r,c);
            }
        }
    }

    // //[[TEST]]
    // for(int r_cnt = 0; r_cnt < _N; r_cnt++)
    // {
    //     for(int c_cnt = 0; c_cnt < _N; c_cnt++)
    //         cout << (int)_city[r_cnt][c_cnt];
    //     cout << "\n";
    // }
    // //[[TEST]]
    // cout << "\n";
    // for(auto group : _groups)
    // {
    //     for(auto p: group)
    //         cout << "("<< p.first << "," << p.second << ")";
    //     cout << "\n";
    // }
    
    cout << _groups.size() << "\n"; 
    sort(_groups.begin(), _groups.end(), cmp);
    for(auto group : _groups)
        cout << group.size() << "\n";
    return 0;
}