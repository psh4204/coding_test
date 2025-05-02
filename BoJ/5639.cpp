/* 이진 검색 트리
https://www.acmicpc.net/problem/5639

이진검색트리
- 가장 왼쪽 리프 노드의 키는 모든 노드의 키보다 작음
- 가장 오른쪽 리프노드의 키는 모든 노드의 키보다 크다
- 왼쪽 오른쪽 서브트리도 이진검색트리다

전위순회를 한 키값이 주어지면, 후위순회 한 키값을 출력하라

입력
- 전위순회한 결과가 주어짐 (키값1~1,000,000 ,노드 수 1~10000 )

출력
- 후위순회한 결과를 출력하라

풀이
- 전위순회한 걸 후위순회로 바꾼다라
- 노드리스트(부모,왼자,오자) 만들어서 이진트리를 만든다
- 그후 후위순회로 출력

[Note]
- 입력의 끝을 알고싶다면 입력값이 안들어오는 순간에 EOF가 나온다는 점을 활용하자
- cin 은 EOF가 들어오면 false, scanf는 EOF(-1)을 뱉음
*/
#include <bits/stdc++.h>
using namespace std;
struct Node_t{
    int parent;
    int left;
    int right;
};
int g_input, g_route;
vector<Node_t> g_nodeList(1000001);

// 전위순회로 NodeList 세팅
void SetNodeList(const int & node, const int & parent)
{
    if(parent > node)
    {
        if(g_nodeList[parent].left == 0)
        {
            g_nodeList[parent].left = node;
            g_nodeList[node].parent = parent;
        }
        else
            SetNodeList(node, g_nodeList[parent].left);
    }
    else
    {
        if(g_nodeList[parent].right == 0)
        {
            g_nodeList[parent].right = node;
            g_nodeList[node].parent = parent;
        }
        else
            SetNodeList(node, g_nodeList[parent].right);
    }
}

void PrintNodeList(const int & node)
{
    if(g_nodeList[node].left != 0)
        PrintNodeList(g_nodeList[node].left);
    if(g_nodeList[node].right != 0)
        PrintNodeList(g_nodeList[node].right);
    cout << node << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_route;
    while(cin >> g_input)
    {
        SetNodeList(g_input, g_route);
    }
    PrintNodeList(g_route);

    return 0;
}