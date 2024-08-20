/*https://www.acmicpc.net/problem/1325
효율적인 해킹

한 컴퓨터를 해킹해서 여러개의 컴퓨터를 해킹하자.
A가 B를 신뢰하면 B를 통해 A를 해킹할 수 있음.
한번에 가장많은 컴퓨터를 해킹할 수 있는 컴퓨터 넘버를 출력해보자.

Input
- N, M  (N: 1~10k.  M: 1~100k)
- A B   (M개의 줄에 신뢰하는 컴퓨터관계. A가 B를 신뢰하면, B로 A를 해킹 할 수 있음)
        (컴퓨터는 1번부터 N까지 번호가 새겨져있음)

Output
- 가장많이 해킹할 수 있는 컴퓨터번호 오름차순

Try1. 
- 무식하게 접근하자.
- 인접행렬로 관계를 엮으면 될것으로 보임.
    - "A B" -> B노드에 A 추가. 이렇게하자.
    - 변수로 메모리는 최대 100메가 쓰겠고
    - 재귀로 풀면.. 한노드에서 400kB.. 스택은 상관없겠다. 256MB언제다쓰노 ㅋㅋ
- DFS로 각 노드마다 탐색하고, 무한루프 못돌게 visited 1차원 배열만들어서 체크리스트 관리하자.
    - 카운트는 해당 노드에 들어가는 순간에 count.
    - 탐색카운트를 카운트배열에 넣어주자.
    - maximum 값은 따로 저장해두자
- maximum값을 제외한 모든값을 삭제한고 오름차순 sort해서 보여주자. (set 썼음)

Try2
- 시간초과로 인한 재풀이.
- DFS 파트를 재세팅해보자.
- set말고 vector쓰자. (set은 중복값 체크하려 쓴건데 insert 할때 속도관련해서 문제있을거같음.)

Try3
- set 말고 vector쓰니까 개빠르네
- 이번엔 근데 출력초과로 틀림
- 출력초과...가 왜 나는걸까..? 내생각엔 출력하면 안되는 값이 나와서 그런거같은데
    - 동일한 컴퓨터 값이 들어갈 리가 없을거고
- 양방향 그래프는 절대 아님.
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _M, _max_cnt = 0;
vector<vector<int>> _coms;      // coumputer and trusted coms. 
vector<pair<int,int>> _best_coms; // trusted coms.

int count_coms(int here, vector<int>& v)
{
    int ret = 0;
    v[here] = 1;
    for(auto t: _coms[here])    // com: trust1, trust2, ...
    {
        if(v[t] == 0)           // visited[trust]
        {
            v[t] = 1;
            ret += count_coms(t, v) + 1;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N >> _M;
    _coms.resize(_N);
    for(int t_idx = 0; t_idx < _M; t_idx++)
    {
        int A = 0, B = 0;
        cin >> A >> B;
        A--; B--;   // A, B --인덱스화
        _coms[B].push_back(A);
    }
    // count trusted coms
    for(int c_idx = 0; c_idx < _N; c_idx++)
    {
        if(_coms[c_idx].size() == 0) continue;
        vector<int> visited(_N, 0);
        int ret = 0;
        ret = count_coms(c_idx, visited);
        if(_max_cnt <= ret)
        {
            _max_cnt = ret;
            _best_coms.push_back({c_idx, ret});
        }
    }
    sort(_best_coms.begin(), _best_coms.end());
    for(auto bc: _best_coms)
    {
        if(bc.second == _max_cnt) cout << (bc.first+1) << ' ';    // 인덱스화 된 output에  +1해서 컴퓨터번호 복원.
    }
    return 0;
}