/* https://www.acmicpc.net/problem/16234
인구이동

NxN의 땅, 나라는 (r,c) 좌표단위.
인구이동
- 국경이 인접한 두나라의 인구차이가 L이상 R이하라면 인구이동O
    - 그렇게 인구이동이 이루어지는 하루동안은 연합이라 칭함
- 연합을 이루고있는 각 칸의 인구수는 (연합인구/연합을이루는칸개수)로 평균을 낸다. (정수표현)
각나라의 인구수가 주어졌을때, 인구이동이 몇일동안 발생하는지 구하는 프로그램 작성

Input
- N L R (N 1~50) (1~L <= R~100)
- 각 칸마다 인구수 주어짐 (0~100)
- 인구이동이 발생하는 일수가 2000이하임.

Output
- 인구이동이 몇일동안 발생하는지 출력


Try1.
- 연합체크를 위해 각 배열마다 접경이 열린지 안열린지 체크.
    - 연합체크는 DFS로. visited  배열 필수
    - 연합 컨테이너 만들어야함
- 각 연합 컨테이너별 값 다 더한 후 평균 (소수없음. 정수로)
- 평균 낸 후 다시 배열 재배치 및 연합플래그 리셋
- 이 루프를 한번할때마다 1카운트.
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _L, _R, _year;
typedef int y_f;   // 연합플래그.. 1000 위. 0100 오른쪽, 0010 아래, 0001 왼쪽
vector<vector<int>> _lands;  // [r][c]
vector<vector<pair<int,int>>> _yeonhaps;    // 연합국들 컨테이너. [연합][나라]{r,c}

int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};

void get_yeonhaps();
bool move_peoples();

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N >> _L >> _R;
    
    // Init lands.
    _lands.resize(_N, vector<int>(_N,0));
    for(int r = 0; r < _N; r++)
    {
        for(int c = 0; c < _N; c++)
        {
            int in = 0;
            cin >> in;
            _lands[r][c] = in;
        }
    }

    do 
    {
        get_yeonhaps();
    }while(move_peoples()); // 연합이 없으면 false. (연합수 == 나라수)

    cout << _year;
    return 0;
}

void get_yeonhaps()
{
    vector<vector<int>> v(_N,vector<int>(_N,0));
    for(int r = 0; r < _N; r++)
    {
        for(int c = 0; c < _N; c++)
        {
            if(v[r][c] != 0)    continue;
            v[r][c] = 1;
            queue<pair<int,int>> q;
            q.push({r,c});
            _yeonhaps.push_back({});
            do
            {
                pair<int,int> here = q.front(); q.pop();
                _yeonhaps[_yeonhaps.size()-1].push_back({here.first,here.second});
                for(int n =0; n < 4; n++) // 4방향 연합플래그 체크
                {
                    int ny = here.first+ _dy[n];
                    int nx = here.second+ _dx[n];
                    if(ny < 0 || nx <0 || ny>=_N || nx >=_N)    continue;
                    int diff = abs(_lands[here.first][here.second] -_lands[ny][nx]);
                    if(diff >= _L && diff <= _R && v[ny][nx] == 0)
                    {
                        v[ny][nx] = 1;
                        q.push({ny,nx});
                    }
                }
            } while (!q.empty());
        }
    }
}

bool move_peoples()
{
    if(_yeonhaps.size() == (_N*_N))    return false;
    
    for(auto& yh: _yeonhaps)
    {
        int all_p = 0; // 연합내 모든인구수
        int avg_p = 0;
        
        for(auto land: yh)
            all_p += _lands[land.first][land.second];
        avg_p = all_p/yh.size();
        for(auto& land: yh)
            _lands[land.first][land.second] = avg_p;
    }
    _yeonhaps.clear();
    _year++;
    return true;
}