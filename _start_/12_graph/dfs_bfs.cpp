#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 재귀문을 통한 DFS
const int N =6; // Node(Vertex) 개수
bool gVisited[N] ={}; // 각각의 V를 방문했는지 기록하기 위한 bool 배열

void dfs_recursion(const vector<vector<int>>& adj_list, int s)
{
    // (1) s를 이미 방문했으면 함수종료
    if(gVisited[s])
        return;

    // (2) 그렇지 않으면 s방문
    gVisited[s] = true;
    cout << s << ", ";

    // (3) s와 인접한 모든 노드에 대해 dfs 재귀 호출
    for(int v: adj_list[s])
        dfs_recursion(adj_list, v);
}

// 스택을 통한 DFS
vector<int> dfs(const vector<vector<int>>& adj_list, int s)
{
    vector<bool> visited(adj_list.size(), false);
    vector<int> visit_order;

    // 비어있는 스택을 생성하고 s(V 첫번호)를 삽입
    stack<int> stk;
    stk.push(s);

    while(!stk.empty())
    {
        // 스택에 쌓인 번호를 꺼내 v로 만듦
        int v = stk.top(); 
        stk.pop();
        
        // 이미 v를 방문했다면 스택의 다음 v번호를 꺼냄
        if(visited[v])
            continue;

        // 방문하지 않은 v면 방문
        visited[v] = true;
        visit_order.push_back(v);
        
        // v와 인접한 노드중에 아직 방문하지 않은 v 번호 삽입
        for(auto n: adj_list[v])
        {
            if(!visited[n])
                stk.push(n);
        }
    }
    return visit_order;
}

// 큐를 통한 BFS
vector<int> bfs(const vector<vector<int>>& adj_list, int s)
{
    vector<bool> visited(adj_list.size(), false);
    vector<int> visit_order;

    // 비어있는 큐를 생성하고 s(V 첫번호)를 삽입
    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        // 큐에 쌓인 번호를 꺼내 v로 만듦
        int v = q.front();
        q.pop();

        // 이미 v를 방문했다면 스택의 다음 v번호를 꺼냄
        if(visited[v])
            continue;

        // 방문하지 않은 v면 방문
        visited[v] = true;
        visit_order.push_back(v);
        
        // v와 인접한 노드중에 아직 방문하지 않은 v 번호 삽입
        for(auto n: adj_list[v])
        {
            if(!visited[n])
                q.push(n);
        }
    }
    return visit_order;
}

int main(void)
{
    vector<vector<int>> adj_list = {{1,3,4},{0,2,4},{1,5}, {0,4},{0,1,3},{2}};
    dfs_recursion(adj_list,0);
    std::cout<<endl;
    for(auto n: dfs(adj_list, 0))
    {
        cout << n << ", ";
    }
    std::cout<<endl;
    for(auto n: bfs(adj_list, 0))
    {
        cout << n << ", ";
    }
    std::cout<<endl;
    return 0;
}