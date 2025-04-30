/* 트리순회
https://www.acmicpc.net/problem/1991

'이진트리'를 입력받으면 전위,중위,후위순회한 결과를 출력하라

순회종류
- 전위: 부-왼-오
- 중위: 왼-부-오
- 후위: 왼-오-부

입력
- N 노드개수 (1~26)
- 부 왼 오 노드
    - 자식노드가 없으면 .표시
    - A가 항상 루트노드가 됨

풀이
- 순회문제는 재귀였던거같은데
- 친절하게도 부모: 왼, 오 이런식으로 노드를 준다 함
- A가 항상 루트노드가된다는 힌트도 있음
- A를 시작으로 순회를 시작하면 될듯
    - 전위: 부모 -> 왼쪽끝-> 오른쪽 끝
    - 중위: 왼쪽끝 -> 부모끝 -> 오른쪽끝
    - 후위: 왼쪽끝 -> 오른쪽끝 -> 부모끝
- visited도 필요없음. 그냥 방문함수로만 쭉 재귀넣으면 됨
*/
#include <bits/stdc++.h>
using namespace std;
int g_N;
vector<vector<char>> g_nodes(26,vector<char>(2,-1));

void Front(char node)
{
    cout << (char)(node+'A');
    if(g_nodes[node][0] != -1)
        Front(g_nodes[node][0]);
    if(g_nodes[node][1] != -1)
        Front(g_nodes[node][1]);
}

void Mid(char node)
{
    if(g_nodes[node][0] != -1)
        Mid(g_nodes[node][0]);
    
    cout << (char)(node+'A');

    if(g_nodes[node][1] != -1)
        Mid(g_nodes[node][1]);
}

void Back(char node)
{
    if(g_nodes[node][0] != -1)
        Back(g_nodes[node][0]);
    if(g_nodes[node][1] != -1)
        Back(g_nodes[node][1]);
    cout << (char)(node+'A');
}

int main()
{
    cin >> g_N;
    for(int inY = 0; inY < g_N; inY++)
    {
        char input, parent;
        cin >> parent;
        parent -= 'A';
        for(int inX = 0; inX < 2; inX++)
        {
            cin >> input;
            if(input == '.')
                continue;
            input -= 'A';
            g_nodes[parent][inX] = input; // 알파벳으로 된 노드 삽입
        }
    }
    Front(0);
    cout << "\n";
    Mid(0);
    cout << "\n";
    Back(0);
    cout << "\n";
    
    return 0;
}