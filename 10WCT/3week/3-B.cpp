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

Try1.
- 시작위치체크용 지도와 끝위치 체크용 지도를 만들어 답을 구한다.
    - 시작위치용 지도: 주위의 이웃땅개수를 카운트한 지도. 가장 적은 이웃을 가진 땅이 시작땅.
    - 끝위치용+카운트 지도: 이웃땅에 자신의 현재 weight를 더한 후 끝에 도달할때 까지 BFS.
- 이번에 지도 2가지의 핵심은 이거임
    - 내땅에 weight를 표시하느냐, 이웃땅에 weight를 표시하느냐
- 섬 별 시작지점 컨테이너 필요해 보임\

NOTE: insert(끝, 다른거시작,다른거끝) 하면 해당 컨테이너에 다른컨테이너도 연달아 붙일수 있음.

Try2.
- 97% 에서 틀린다.
- 초-심플하게 가보자

NOTE: 시간-메모리 계산 똑바로하자. 막쓸수있으면 코드를 심플하게 짜는게 정답이다.
*/
#include <bits/stdc++.h>
using namespace std;

int _r, _c;
vector<vector<int>> _tm;        // 보물지도

int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};

void print_test_map(vector<vector<int>> v);
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
    cout << get_answer();
    return 0;
}

/* ---- func ---- */

int get_answer()
{
    int answer = 1;
    for(int r = 0; r < _r; r++)
    {
        for(int c = 0; c < _c; c++)
        {
            if(_tm[r][c] == 1)
            {
                vector<vector<int>> copy_tm(_tm);
                vector<vector<int>> v(_r,vector<int>(_c,0));    // will visit and visited
                queue<pair<int,int>> q;
                int max_count = 0; 
                q.push({r,c});
                v[r][c] = 1;
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
        }
    }
    return answer -1;   // 인덱스값을 정답에 맞춘 후 리턴
}