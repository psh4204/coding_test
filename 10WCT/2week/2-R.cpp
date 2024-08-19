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

Try6. with hint
- "이진트리"라는 말을 한적이 없다.
- 그랬다한들 더 심플한 방법이 있는데, 인접리스트를 통한 구현.
    - TODO: 

*/
#include <bits/stdc++.h>
using namespace std;
int _N = 0; // node 개수
int _D = 0; // 지울 노드
int ret = 0;

typedef struct n_t
{
    n_t* p  = nullptr;      // 부모
    n_t* l_c = nullptr;     // 왼-자
    n_t* r_c = nullptr;     // 오-자
    int data = -1;          // data 확인용

    void insert(n_t* n)
    {
        if(l_c == nullptr)  l_c = n;
        else                r_c = n;
    }

    void pop(void)
    {
        l_c = nullptr;
        r_c = nullptr;
        if(p != nullptr)
        {
            if(p->l_c != nullptr && p->l_c->data == data)
                p->l_c = nullptr;
            if(p->r_c != nullptr && p->r_c->data == data)
                p->r_c = nullptr;
        }
        data = -1;
    }
}node_t;

// TODO: Delete Test Code
void print_node(node_t* node)
{
    if(node->data != -1 && node->l_c == nullptr && node->r_c == nullptr)
    {
        cout << node->data << "//";
        return;
    }
    cout << node->data << "->";
    if(node->l_c != nullptr)  print_node(node->l_c);
    if(node->r_c != nullptr)  print_node(node->r_c);
}

int count_leaf(node_t* node)
{
    int ret = 0;
    if(node->data != -1 && node->l_c == nullptr && node->r_c == nullptr)
    {
        return 1;
    }
    if(node->l_c != nullptr)  ret += count_leaf(node->l_c);
    if(node->r_c != nullptr)  ret += count_leaf(node->r_c);
    return ret;
}

int main()
{
    cin >> _N;
    vector<int> p_lst;  // parent list
    for(int in_cnt = 0; in_cnt < _N; in_cnt++)
    {
        p_lst.push_back({});
        cin >> p_lst[in_cnt];
    }
    sort(p_lst.begin(), p_lst.end()); // 부모 오름차순 sort: node list를 쉽게 짜기위해
    
    // 노드리스트 init
    vector<node_t> n_lst(_N);
    if(p_lst.size() > 1) n_lst[0].data = p_lst[1];   // head 가 0이 아닐수 있음.
    else  n_lst[0].data = 0;
    for(int n_idx = 1; n_idx < _N; n_idx++)
    {
        int here_idx = n_lst[0].data + n_idx;
        for(auto& n: n_lst)
        {
            if(n.data == p_lst[n_idx])
            {
                n.insert(&n_lst[n_idx]);  // 현재 노드를 부모노드에 insert(왼/오 구분)
                n_lst[n_idx].p = &n;
                n_lst[n_idx].data = here_idx;
                break;
            }
        }
    }

    // 노드 삭제
    cin >> _D;
    for(auto& n: n_lst)
    {
        if(n.data == _D)
        {
            n.pop();
            break;
        }
    }

    cout << count_leaf(&n_lst[0]);
    return 0;
}