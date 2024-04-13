#include <iostream>
#include <vector>

using namespace std;

// 인접 행렬을 받아 인접 리스트로 만드는 함수
vector<vector<int>> get_adj_list(const vector<vector<int>>& adj_matrix)
{
    vector<vector<int>> adj_list(adj_matrix.size()); // 리스트 행의 크기를 matrix 행의 크기로 초기화

    for(int u = 0; u < adj_matrix.size(); u++) // 행을 차례로 순회한다.
    {
        for(int v =0; v <adj_matrix[u].size(); v++) // 열의 수가 1인지(연결된지) 체크 후 됐다면 리스트에 추가.
        {
            if(adj_matrix[u][v] == 1)
            {
                adj_list[u].push_back(v);
            }
        }
    }
    return adj_list;
}

int main(void)
{

    /*
    그래프 모양
    (0) -   (1) -   (2)
    ㅣ  \   ㅣ
    (3)     (4) -   (5)
    ㅣ
    (6)
    
    */
    /*
    에지 리스트 모양
    {0,1} {0,3} {0,4}
    {1,0} {1,2} {1,4}
    {2,1}
    {3,0} {3,6}
    {4,0} {4,1} {4,5}
    {5,4}
    {6,3} 
   */

    // 인접 행렬 (무방향)
    vector<vector<int>> adj_matrix =
    {
    //  0, 1, 2, 3, 4, 5 ,6
        {0, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
    };

    vector<vector<int>> adj_list = get_adj_list(adj_matrix);

    for(auto& lst : adj_list)
    {
        for(auto v : lst)
        {
            cout << v << ", ";
        }
        cout<< endl;
    }

    return 0;
}