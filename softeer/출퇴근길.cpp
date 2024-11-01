/* 출퇴근길
출퇴근길이 가끔 겹친다.
출퇴근 길을 그래프로 나타낼 수 잇다.
1~n까지의 정점, m개의 일방통행도로. (n 5~100,000.  m 5 ~ 200,000)
집_정점 S, 회사_정점 T. (S 1~n. T 1~n. S!=T)
출근, 퇴근길 루트에서 전부 겹치는 Vertext 수를 구하시오.

입력
- n m
- 간선정보 (m개만큼)
- 마지막엔 S T

출력
- 출근, 퇴근길 루트에서 전부 겹치는 Vertex 수 를 구하시오.

풀이
- 인접리스트가 총 두개 필요함 (정방향, 반대방향)
    - S, T를 제외한 모든 노드를 전부 탐색할 수 있음(중복가능)
    - 주의 사항은 '완탐'을 해야함. 최소경로 문제가 아님. 전부다 돌고난 후에 방문체크를 해야함. (양방향간선이 있기때문)
- S -> T의 trace, S -> T이지만 반대 trace/ T-> S의 trace, T->S이지만 반대
- DFS혹은 BFS로 풀이가능
- 탐색 4번 돌리고, 이와 겹치는 경로만 카운트하면 정답

// TC
5 9
1 2
1 4
2 1
2 3
3 4
3 5
4 1
4 3
5 1
1 3

8 14
1 2
1 5
1 7
2 3
3 1
4 1
4 2
5 4
5 8
6 2
6 3
7 1
7 6
8 7
6 5
*/
#include <bits/stdc++.h>
#define MAX_NODE 100002
using namespace std;
int _n, _m, _s, _t, _ret_cnt = 0;
vector<vector<int>> _adj(MAX_NODE); // 단방향 체크용
vector<vector<int>> _r_adj(MAX_NODE); // 양방향 체크용
vector<vector<int>> _traces(4,vector<int>(MAX_NODE));

inline void go_target_out(int here, vector<vector<int>> & adj ,vector<int>&trace)
{
    if(trace[here] == 1)
        return;
    trace[here] = 1;
    // cout << here << " ";  //TEST
    for(int t_cnt = 0; t_cnt < adj[here].size(); t_cnt++)
        go_target_out(adj[here][t_cnt], adj ,trace);
}

int main(int argc, char** argv)
{
    cin >> _n >> _m;
    for(int m_cnt = 0 ; m_cnt < _m; m_cnt++)
    {
        int y, x;
        cin >> y >> x;
        _adj[y].push_back(x);
        _r_adj[x].push_back(y);
    }
    cin >> _s >> _t;

    // cout << "\n(" <<  1 << ")\n";  //TEST
    _traces[0][_t] =1;
    go_target_out(_s, _adj ,_traces[0]);
    // cout << "\n(" <<  2 << ")\n";  //TEST
    // _traces[1][_t] =1; // 반대방향은 이게 전체를 돌까? 를 보는거기 때문에 플래그설정 안해도됨.
    go_target_out(_s, _r_adj ,_traces[1]);
    // cout << "\n(" <<  3 << ")\n";  //TEST
    _traces[2][_s] =1;
    go_target_out(_t, _adj ,_traces[2]);
    // cout << "\n(" <<  4 << ")\n";  //TEST
    // _traces[3][_s] =1;
    go_target_out(_t, _r_adj ,_traces[3]);
    // cout << "\n(" <<  "end" << ")\n";  //TEST
    for(int node_idx = 0; node_idx < MAX_NODE; node_idx++)
    {
        if(_traces[0][node_idx] && _traces[1][node_idx] &&_traces[2][node_idx] &&_traces[3][node_idx])
            _ret_cnt++;
    }
    cout << _ret_cnt-2;
    return 0;
}