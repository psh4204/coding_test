/* https://www.acmicpc.net/problem/2098
외판원 순회(TSP)

1~N 도시. 사이길있음(링크).
외판원이 N개의 도시를 모두 거쳐 다시 돌아오는 순회경로로 여행계획 잡으려함.
- 한번이라도 갔던 도시는 다시 갈 수 없음 (출발했던 도시로 돌아오는건 제외)
- 가장 적은 비용이 드는 여행계획을 잡아본다.

비용 행열 W[i][j] : i에서 j로 가기위한 비용.(대칭적이지 않음, 양의정수임)
- 비용 0인 경우: (i, i)일때. (i,j)인데 못가는 경우

N과 비용행열이주어지면 최소비용 순회경로를 구하라.

입력
- 도시의수 N (2~16)
- N개의 줄에 비용행열 (각 값은 1~ 1M, 못가는곳은 0)
(참고: 항상 순회할 수 있는 경우만 값으로 주어짐)

출력
- 외판원 순회에 필요한 최소비용 출력

시도1.
- 최소값 구하기 (ret_min)
- 완전탐색 필요 & DFS.
- 단순하게 풀면 타임아웃 뜰듯(경우의수가 넘많아)
- 문제풀이
    - 0~N-1 까지 한바퀴 돌아야한다 = 0번부터 시작해도 된다.
    - 모든 경우의 수에서 가장 적은 친구를 찾아야함
- DP 파라미터
    - city 와 visited를 dp로 사용
    - visted는 최대16개의 도시밖에 없으니 비트마스킹으로 해결해보자
*/
#include <bits/stdc++.h>
#define MAX_N 16
#define INF 987654321
using namespace std;
int _N;
vector<vector<int>> _roads(MAX_N, vector<int>(MAX_N,-1));
vector<vector<int>> _dp(MAX_N,vector<int>(1<<MAX_N,-1));

int get_min_road(int here, int visited)
{
    if(visited == (1<<_N)-1) // 끝에 도달했을 때 순환이 성립하는가? 아니면 INF
    {
        if(_roads[here][0] == 0 || _roads[here][0] == -1)
            return INF;
        else
            return _roads[here][0];
    }

    int &ret = _dp[here][visited];
    if(ret != -1) return ret; // 이미 끝에 도달했었던 경우의수라면 리턴
    ret = INF;
    for(int n_idx = 0; n_idx < _N; n_idx++)
    {
        if(visited & (1<<n_idx) || 
        _roads[here][n_idx] == 0 || _roads[here][n_idx] == -1) continue;
        ret = min(ret, get_min_road(n_idx, visited | (1<<n_idx)) + _roads[here][n_idx]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    cin >> _N;
    for(int y = 0; y < _N; y++)
    {
        for(int x = 0; x < _N; x++)
            cin >> _roads[y][x];
    }

    cout << get_min_road(0, 1); // 첫요소부터 시작 후 최소값 반환
    return 0;
}
