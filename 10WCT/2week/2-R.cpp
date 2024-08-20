/*https://www.acmicpc.net/problem/1068
트리

트리가 주어지고, 그중 하나의 노드를 삭제할거다.
삭제되면 자식노드들은 전부 삭제된다.
리프노드의 개수를 구하라.

Input
- 노드개수_N(1~50).
- 0번노드~N-1번노드까지. (루트노드는 -1이 주어짐)
- 지울 노드

Output
- 리프노드 개수

Try1.
- 무슨 트리인지에 대해 설명이 매우 빈약하다 -> TC로 파악해보자..->실패. 이상해
- 각 노드의 부모가...주어진다라..(!)
    - 문제에서 보여주는 트리(완전이진트리)으로 주는데 "부모노드만으로" 짐작해서 "자식노드를 만들어야하는" 문제네
(ex1)
    -1:0
     1 (2)
    3 4

(ex2)
    -1:0
    (1) 2
    3 4

(ex3)
   -1:(0)
     1  2
    3 4

(ex4)
   -1:0
     1  2
       3 (4)
         5  6
           7  8
- 노드를 만들자
    - 데이터:카운트
    - L자식링크, R자식링크
- Insert: N을 받으면 DFS로 데이터체크
    - 이번꺼는 "전위순회" 로 보임
    - 찾으면 왼쪽 오른쪽 데이터 노드 만들어주면됨.
- Pop: N을 받으면 동일하게 DFS로 데이터체크.
    - 데이터 찾으면 해당노드 Pop.

Try2.
- 틀렸대.
- TC 다 맞는데 또 틀렸대.
- 루트노드가 0이 아닐 수 있다는 머같은걸 봐버렸다. 말이되나?
    - 하.. 말장난너무싫다.
    - 다시짜야하잖아..
- 트리의 노드가 차례로 안나오는걸 예상하고 작성해야했음.

Try3~5.
- 또 틀렸대
- Node Number도 체크하고 다했는데..
- 트리니까 루트노드로 부터 dfs도 하고, 예외처리 다한거같은데 왜틀릴까?\
- 너무 답답해서 TC 란 TC도 다 해봤는데 다 맞다뜸. 또 이러네 진짜.. 

==========================
Try n.
- 각 노드의 부모노드를 입력값으로 준다했음.
- 인접행렬로 트리를 구성해보자.

*/
#include <bits/stdc++.h>
using namespace std;
int _N, _D, _l_cnt;
vector<vector<int>> _tree(50);  // _N의 개수는 1~50
int _root_idx = 0; // 루트노드

int count_leafs(int here)
{
    int ret = 0;
    if(_tree[here].size() == 0) return 1;
    for(int c_idx = 0; c_idx < _tree[here].size(); c_idx++)
    {
        ret += count_leafs(_tree[here][c_idx]);
    }

    return ret;
}

int main()
{
    // Init tree
    cin >> _N;
    for(int n_idx = 0; n_idx < _N; n_idx++)
    {
        int parent = 0;
        cin >> parent;
        if(parent == -1) _root_idx = n_idx;
        else    _tree[parent].push_back(n_idx);     // 부모노드에 자식데이터 삽입
    }
    // Delete node
    cin >> _D;
    _tree[_D].clear();
    for(auto& node: _tree)
    {
        if(node.size() == 0)    continue;
        for(int c_idx = 0; c_idx < node.size(); c_idx++)
        {
            if(node[c_idx] == _D) node.erase(node.begin() + c_idx);
        }
    }
    // Count leaf with dfs
    if(_D == _root_idx)
        _l_cnt = 0;
    else if(_tree[_root_idx].size() == 0)
        _l_cnt = 1;
    else
        _l_cnt = count_leafs(_root_idx);
    cout << _l_cnt;
    return 0;
}