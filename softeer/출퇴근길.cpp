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
- 입력값을 통한 인접리스트로 구현해야할 듯
- S에서 T로 간 후, T에서 S로 다시가야함.
    - 이동시 visited를 쓰는데, cnt를 플래그로 넣자. 현재 cnt보다 크면 안가는걸로.
- dfs로 경로탐색 완료 후, 각 경로 별 Vertex카운트 배열에서 카운트.
- S접점의 카운트수와 동일한 Vertex를 추려서 Ret Count.(T까지 카운트한것을 지우기위한 -1하기)

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

// TODO.. 시간초과 + 오답율 99. ㅠㅠㅠ 머야 이게 ;;
*/
#include <bits/stdc++.h>
using namespace std;
enum go_mode{
    GO_WORK = 1,
    GO_WORK_2,
    GO_HOME,
    GO_HOME_2,
};
unordered_set<int> _adj[100001];
vector<int> _history;         // trace를 위해 Stack like로 사용. 
vector<int> _visited(100001); // 중복추가 방지용 방문처리.
vector<int> _route_cnt(100001);
int _N, _M, _S, _T, _ret_cnt = 0;

inline void check_route(int here, go_mode mode)
{
    if(here == _T && mode == GO_WORK)
    {
        mode = GO_HOME;   
    }
    else if(here == _S && mode == GO_HOME)
    {
        // // [[TEST CODE]]
        // for(auto hist: _history)
        //     cout << hist << ", ";
        // cout << "\n";

        set<int> hist_copy;
        for(auto v : _history)
        {
            if(!hist_copy.empty() && hist_copy.find(v) != hist_copy.end())
            {
                // cout << v << "(o) "; // [[TEST CODE]]
                _route_cnt[v] = 1;
                continue;
            }
            hist_copy.insert(v);
        }
        // cout << "\n"; // [[TEST CODE]]
        
        return;
    }
    for(auto next: _adj[here])
    {
        int prev_flag = _visited[next];
        if((mode == GO_WORK &&  (next == _S || _visited[next] == GO_WORK_2))
            || (mode == GO_HOME && (next == _T || _visited[next] == GO_HOME_2)))
        {
            continue;
        }
        if((mode == GO_WORK &&  (next == _S || _visited[next] == GO_WORK))
            || (mode == GO_HOME && (next == _T || _visited[next] == GO_HOME)))
        {
            if(_adj[here].find(next) != _adj[here].end())
            {
                _visited[next] = mode+1;
            }
            else
                continue;
        }
        else
            _visited[next] = mode;
        
        _history.push_back(next);
        check_route(next, mode);
        _history.pop_back();
        _visited[next] = prev_flag;
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N >> _M;
    for(int m_cnt = 0; m_cnt < _M; m_cnt++)
    {
        int start, end;
        cin >> start >> end;
        _adj[start].insert(end);
    }
    cin >> _S >> _T;

    _history.push_back(_S);
    _visited[_S] = GO_WORK;
    check_route(_S, GO_WORK);
    if(_route_cnt[_S] == 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    for(auto v_value: _route_cnt)
    {
        if(v_value != 0)
            _ret_cnt++;
    }
    cout << _ret_cnt-1 << "\n";
    return 0;
}