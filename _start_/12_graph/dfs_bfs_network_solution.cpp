#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// 컴퓨터 개수 n과 네트워크 정보가 담긴 2차원 vector가 주어질때,
// 네트워크 (엣지) 갯수를 리턴하시오.
// 컴퓨터[i][j]가 연결되어있다면 1로 표시되며, 본인의 표시는 항상 1입니다.

// 시환: 깊이던, 너비던, 우선탐색을 사용해본다.
// - BFS를 위해 엣지 리스트를 인접 리스트를 만든다.
// - BFS를 통해 탐색을 하되, 탐색 시작할때나 끝날때 answer를 카운트 해준다. 

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    // 컴퓨터 개수와 네트워크정보가 일치하지 않을시 0으로 리턴 (임의로 추가함)
    if(computers.size() != n)
    {
        return 0;
    }

    // 해당 벡터를 리스트화 한다.
    vector<vector<int>> computers_list(computers.size());
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< n; j++)
        {
            if(computers[i][j] == 1)
                computers_list[i].push_back(j); // 인접 리스트의 행에 열의 번호를 넣는다.
        }
    }

    // // 인접리스트화 확인 용 코드
    // for(auto c : computers_list)
    // {
    //     for(auto i: c)
    //     {
    //         cout<< i << ", ";
    //     }
    //     cout<<endl;
    // }
    // cout<<  "====== " << endl;

    // BFS 진행
    vector<bool> visited(n);
    queue<int> q;
    
    for(int node_number = 0; node_number < n; node_number++)
    {
        if(!visited[node_number])
        {
            q.push(node_number); // 순회하지 않은 노드를 시작으로 한다.
            answer++; // 네트워크 숫자는 서브그래프 숫자를 뜻하니까, 너비탐색 시작 혹은 끝을 카운트 해주면 된다.
        }
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            if(visited[v]) // 방문했으면 continue
            {
                continue;
            }
            visited[v] = true;

            // 인접 노드 중에서 탐색하지 않은 친구 삽입
            for(auto node: computers_list[v])
            {
                if(!visited[node])
                    q.push(node);
            }
        }
    }
    return answer;
}

int main(void)
{
    vector<vector<int>> computers1 = 
    {
        {1, 1, 0}, 
        {1, 1, 0}, 
        {0, 0, 1}
    };

    vector<vector<int>> computers2 = 
    {
        {1, 1, 0}, 
        {1, 1, 1}, 
        {0, 1, 1}
    };
    cout << "1 answer is (2) :" << solution(3, computers1)<<endl;
    cout << "2 answer is (1) :" << solution(3, computers2)<<endl;
    return 0;
}