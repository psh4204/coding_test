/* https://www.acmicpc.net/problem/15686
치킨배달

NxN의 도시. 각 칸은 집임. (1,1) 부터시작
치킨거리: 집과 가장가까운 치킨집 사이 거리
도시의 치킨거리: 모든 치킨거리의 합
거리 = (r1,c1) ~ (r2,c2) = |r1-r2| + |c1-c2| // 식 맞음
주어진 치킨집과 집에서 최대 M개의 치킨집으로 가장 최단거리의 도시치킨거리를 구할수있을까?

Input
- N M (N 2~50. M 1~13)
- 도시정보지도

Output
- M개의 치킨집의 최소 도시치킨거리

Try1
- 조합 + DFS 문제.
    - 조합재귀 = DFS+복원
- 방문할 집배열, 치킨집배열, 도시거리minValue
- 조합을 위해 탐색을 멈춰야할 것들
    - `이미 조합된` 것들
    - `도시치킨거리 최소값 보다 넘어가는 것`들

- 집을 중심으로 미리 각 치킨집의 거리를 DFS로 저장해둔다. (2차원으로)..
    - DFS도 필요없는데? 계산해서 넣어두자.
- 치킨거리를 체크할 이 저장된 거리행렬에서 min값을 저장한다.
    - 단 min값이 이전 min값보다 크면 pass. (0일경우 제외)
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _M, _all_minlen; // 도시가로세로크기, 치킨집 최대개수, 도시치킨거리(최소값저장용)
vector<vector<int>> _city;
vector<vector<int>> _chic_lens;  // (r:집, c:치킨집). 집과 치킨집 별 치킨거리
vector<pair<int,int>> _homes;       // 집들
vector<pair<int,int>> _chickens;    // 치킨집들

void set_chic_lens()
{
    _chic_lens.resize(_homes.size(), vector<int>(_chickens.size()));
    for(int home = 0; home < _homes.size(); home++)
    {
        int h_r = _homes[home].first;
        int h_c = _homes[home].second;
        for(int chick = 0; chick < _chickens.size(); chick++)
        {
            int c_r = _chickens[chick].first;
            int c_c = _chickens[chick].second;
            _chic_lens[home][chick] = abs(h_r - c_r) + abs(h_c - c_c);
        }
    }
}

void combi(int start, vector<int>& cidx_arr)
{
    if(cidx_arr.size() == _M)
    {
        int all_min = 0;
        for(auto h_c: _chic_lens)   // [home][chick] = len.
        {
            int min = h_c[cidx_arr[0]];
            for(auto c: cidx_arr)
            {
                if(h_c[c] < min)    min = h_c[c];
            }
            all_min += min;
            if(_all_minlen != 0 && _all_minlen < all_min)   return;
        }
        _all_minlen = all_min;
        return;
    }
    for(int cidx = start +1; cidx < _chickens.size(); cidx++)
    {
        cidx_arr.push_back(cidx);
        combi(cidx, cidx_arr);
        cidx_arr.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> _N >> _M;
    
    // 도시, 집들, 치킨집들 init.
    _city.resize(_N,vector<int>(_N));
    for(int r = 0; r < _N; r++)
    {
        for(int c = 0; c < _N; c++)
        {
            int input = 0;
            cin >> input;
            _city[r][c] = input;
            if(input == 1)  _homes.push_back({r,c});
            else if(input == 2) _chickens.push_back({r,c});
        }
    }

    // 집r, 치킨집c 별 미리 최단거리 구해놓기
    set_chic_lens();
    
    // 도시치킨거리 최소값 탐색
    vector<int> ch_idx_arr;
    combi(-1, ch_idx_arr);

    cout << _all_minlen;

    return 0;
}