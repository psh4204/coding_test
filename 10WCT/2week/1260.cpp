/*
https://www.acmicpc.net/problem/1260
DFS/BFS

그래프 탐색인 DFS, BFS의 각 탐색 결과를 출력하라. (양방향 그래프)

Input
- V E startV (정점, 간선, 시작할 정점시작번호)
- V-V (E수만큼 간선이 연결된 V들을 보여준다)

Output
- DFS 수행결과
- BFS 수행결과

Try1
- 인접리스트로 구현해보자.
- DFS는 재귀, BFS는 중첩루프로 구현해보자.
*/
#include <bits/stdc++.h>
using namespace std;

int _V = 0, _E =0, _startV =0;

void dfs(int here, vector<vector<int>> &adj_list, vector<int> &v)
{
    if(v[here] != 0)
    {
        return;
    }
    v[here] = 1;
    cout << here << " "; //TODO: Add space well.
    for(auto adj_v : adj_list[here])
    {
        dfs(adj_v, adj_list, v);
    }
}

void bfs(int here, vector<vector<int>> & adj_list, vector<int> v)
{
    queue<int> q;
    q.push(here);
    v[here] = 1;
    do
    {
        int there = q.front();
        q.pop();
        cout << there << " "; // TODO: Add space well.
        for(auto adj : adj_list[there])
        {
            if(v[adj] != 0)
                continue;
            v[adj] = 1;
            q.push(adj);
        }
    } while (q.size() != 0);
    
}

int main()
{
    cin >> _V >> _E >> _startV;
    vector<vector<int>> adj_list(_V+1);
    vector<int> visited_list(_V+1);
    for(int e_cnt = 0; e_cnt < _E ; e_cnt++)
    {
        int v1 = 0, v2 = 0;
        cin >> v1 >> v2;
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }
    for(auto& adj: adj_list)
        sort(adj.begin(), adj.end());
    dfs(_startV, adj_list, visited_list);
    cout << "\n";
    for(auto& v: visited_list)
        v = 0;
    bfs(_startV, adj_list, visited_list);
    return 0;
}