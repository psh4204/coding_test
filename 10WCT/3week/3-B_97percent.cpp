/* https://www.acmicpc.net/problem/2589
보물섬

보물섬지도. 상하좌우 이동가능. 육지L/바다W 로 구성됨.
보물은 섬에 두개가 묻혀있으며, 
지도에서 표시된 육지에서 가장 다이렉트로 거리가 먼 두곳에 묻혀있음.

이 둘 사이의 거리를 구할땐 무조건 최단거리로 구해야함. (돌아가기X, 중복으로가기X)

Input
- r_c c_c
- WL로된지도.

Output
- 보물최단거리

3-B... Try2.
- 97% 에서 틀려서 새롭게 풀겠음.

*/
#include <bits/stdc++.h>
using namespace std;

int _r, _c;
vector<vector<int>> _tm;        // 보물지도
vector<vector<pair<int,int>>> _islands;   // 섬(컨테이너)
vector<vector<int>> _start_tm;  // 시작지점 체크용 보물지도
vector<vector<int>> _end_tm;    // 끝지점 체크용 보물지도
vector<pair<int,int>> _start_pos;   // 시작지점 체크맵 + 섬컨테이너로 시작포지션 체크.

int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};

void print_test_map(vector<vector<int>> v);
void set_start_tm();
void get_islands();
void get_start_pos();
int get_answer();

/* ---- main ---- */

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _r >> _c;
    _tm.resize(_r, vector<int>(_c, 0));
    for(int r = 0; r < _r; r++)
    {
        for(int c = 0; c < _c; c++)
        {
            char in = 0;
            cin >> in;
            if(in == 'W')   _tm[r][c] = 0;
            else if(in == 'L')   _tm[r][c] = 1;
        }
    }
    _start_tm = _tm; _end_tm = _tm;
    set_start_tm();
    get_islands();
    get_start_pos();
    cout << get_answer();
    return 0;
}

/* ---- func ---- */

void print_test_map(vector<vector<int>> v)
{
    cout << "\n";
    for(auto r: v)
    {
        for(auto c: r) cout << c << " ";
        cout << "\n";
    }
}

void get_islands()
{
    vector<vector<int>> visited(_r,vector<int>(_c,0));
    queue<pair<int,int>> q;
    for(int r = 0; r < _r; r++)
    {
        for(int c = 0; c < _r; c++)
        {
            if(_tm[r][c] == 1 && visited[r][c] == 0)
            {
                _islands.push_back({});
                int i_idx = _islands.size();
                visited[r][c] = 1;
                q.push({r,c});
                while(!q.empty())
                {
                    pair<int,int> here = q.front();
                    q.pop();
                    _islands[i_idx-1].push_back(here);
                    for(int n = 0; n < 4; n++)
                    {
                        int ny = here.first + _dy[n];
                        int nx = here.second + _dx[n];
                        if(ny < 0 || nx < 0 || ny >= _r || nx >= _c)
                            continue;
                        if(_tm[ny][nx] == 1 && visited[ny][nx] == 0)
                        {
                            visited[ny][nx] = 1;
                            q.push({ny,nx});
                        }
                    }
                }
            }
        }
    }
}

void set_start_tm()
{
    for(int r = 0; r < _r; r++)
    {
        for(int c = 0; c < _c; c++)
        {
            if(_start_tm[r][c] != 0)
            {
                for(int nidx = 0; nidx < 4; nidx++)
                {
                    int ny = r + _dy[nidx];
                    int nx = c + _dx[nidx];
                    if(ny < 0 || nx < 0 || ny >= _r || nx >= _c)
                        continue;
                    if(_start_tm[ny][nx] != 0)  _start_tm[ny][nx]++;
                }
            }
        }
    }
}

void get_start_pos()
{
    for(auto island: _islands)
    {
        int w_min = 0xFFFF;
        pair<int,int> min_pos;
        vector<pair<int,int>> local_pos;
        for(auto land: island)
        {
            if(w_min > _start_tm[land.first][land.second])
            {
                local_pos.clear();
                w_min = _start_tm[land.first][land.second];
                local_pos.push_back({land.first,land.second});
            }
            else if(w_min == _start_tm[land.first][land.second])
            {
                local_pos.push_back({land.first,land.second});
            }
        }
        _start_pos.insert(_start_pos.end(),local_pos.begin(), local_pos.end()); 
    }
}

int get_answer()
{
    int answer = 1;
    for(auto start: _start_pos)
    {
        vector<vector<int>> copy_tm(_tm);
        vector<vector<int>> v(_r,vector<int>(_c,0));    // will visit and visited
        int max_count = 0; 
        queue<pair<int,int>> q;
        q.push(start);
        v[start.first][start.second] = 1;
        while(!q.empty())
        {
            pair<int,int> here = q.front();
            q.pop();
            if(max_count < copy_tm[here.first][here.second])
                max_count = copy_tm[here.first][here.second];
            for(int nidx = 0; nidx < 4; nidx++)
            {
                int ny = here.first + _dy[nidx];
                int nx = here.second + _dx[nidx];
                if(ny < 0 || nx < 0 || ny >= _r || nx >= _c)    continue;
                if(copy_tm[ny][nx] != 0 & v[ny][nx] == 0)
                {
                    v[ny][nx] = 1;
                    copy_tm[ny][nx] +=copy_tm[here.first][here.second];
                    q.push({ny,nx});
                }
            }
        }
        if(answer < max_count)
            answer = max_count;
    }
    return answer -1;   // 인덱스값을 정답에 맞춘 후 리턴
}