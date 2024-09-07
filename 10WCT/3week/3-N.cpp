/* https://www.acmicpc.net/problem/9934
완전 이진 트리

도시가  K인 이진트리로 되어있고, 각 빌딩노드마다 번호가 적혀있음.
상근이는 들어갔던 빌딩번호를 순서대로 적어뒀는데 도시가 어떻게 생겼는지 기억하지못함.
상근이가 들어갔던 빌딩순서

1. 루트부터 시작
2. 현재위치에서 왼쪽자식에 안갔으면 "왼쪽 자식으로 방문"
3. 현재노드의 왼쪽자식X or 왼쪽자식에 이미방문 시, 현재 노드의 빌딩번호 "기입".
4. 현재 빌딩을 이미 들어갔다 온 상태이고, 오른쪽 자식을 가지고 있는 경우에는 "오른쪽 자식으로 방문".
5. 현재 빌딩과 왼쪽, 오른쪽 자식에 있는 빌딩을 모두 방문했다면, "부모 노드 이동".
==> 전위순회

빌딩번호 리스트를 주면
각 레벨에 빌딩번호를 보여라.

Input
- K (레벨, 1~10)
- 빌딩번호리스트

Output
- 완전이진트리..

Try1
- 문제가 난해하다. 근데 정답률 왜 70%?. 아직 나는 많이 부족한가보다... 잠깐..
    - 중위순회하면 되는 문제네?
- 받은 숫자로 중위순회를 해서 print 하면됨.

Try2
- 중위순회인건 알겠는데 틀림. 
- 힌트
    - 인덱스를 반으로 쪼개서 레벨화 하면 되는 문제 
- 
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> _nodes;  // 값들
vector<vector<int>> _tree;
int _K;

// start, end, level
void set_tree(int s, int e, int l)
{
    if(s == e)
    {
        _tree[l].push_back(_nodes[s]);
        return;
    } 
    int mid = (s + e)/2;
    _tree[l].push_back(_nodes[mid]);
    set_tree(s, mid-1, l+1);
    set_tree(mid+1, e, l+1);
}

int main()
{
    cin >> _K;
    int node_cnt = pow(2,_K)-1;
    _tree.resize(_K);
    for(int in = 0; in < node_cnt; in++)
    {
        int num = 0;
        cin >> num;
        _nodes.push_back(num);
    }
    set_tree(0, _nodes.size()-1, 0);

    for(auto nodes : _tree)
    {
        for(auto node : nodes)
            cout << node << " ";
        cout << "\n";
    }
    return 0;
}