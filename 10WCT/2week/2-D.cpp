/* https://www.acmicpc.net/problem/2583
영역구하기
MxN, 좌표값에 맞춰서 직사각형 K 가 주어짐(겹치기가능). 
직사각형을 제외한 나머지 영역의 개수와 아래에는 너비들을 오름차순으로 출력하라.

Input
- M N K
- lx ly (직사각형 왼쪽아래 좌표) rx ry(직사각형 오른쪽 위의 좌표)
- K만큼 반복

Output
- 나머지영역 개수
- 각 너비 오름차순으로 출력

Try1.
- M,N 그리고 좌표로 일단 네모를 지도를 그린다
    - ly_cnt, lx_cnt 부터 ry_cnt, rx_cnt 까지 1인 네모들을 그린다.
    - 
- DFS를 통해 영역을 체크하며 풀어나간다. (0인 영역)

NOTE: 변수는 꼭! 초기화하자. 안하면 봉변난다.(컴파일러와 컴퓨터는 바보니까)
*/
#include <bits/stdc++.h>
using namespace std;
int _Y, _X, _K;
int _dy[] = {-1, 0, 1, 0};
int _dx[] = {0, 1, 0, -1};

void dfs(pair<int,int> here, vector<vector<int>>& u_arr, vector<vector<int>>& v_arr, int& cmp_cnt)
{
    v_arr[here.first][here.second] = 1;
    cmp_cnt++;
    for(int d_cnt = 0; d_cnt < 4; d_cnt++)
    {
        int y = _dy[d_cnt] + here.first;
        int x = _dx[d_cnt] + here.second;
        if( y < 0 || x < 0 || y >= _Y || x >= _X)
            continue;
        if(u_arr[y][x] == 1 && v_arr[y][x] == 0)
            dfs({y,x}, u_arr, v_arr, cmp_cnt);
    }
}

int main()
{
    cin >> _Y >> _X >> _K;
    vector<vector<int>> usr_array(_Y + 1,vector<int>(_X, 1)); // 주의: 지정된 네모는 0, 빈네모는 1.
    vector<vector<int>> visited(_Y + 1,vector<int>(_X, 0)); // 방문한 네모는 1.
    vector<int> cmpnt_cnt_list;
    // 지도 초기화
    for(int square_cnt = 0; square_cnt < _K; square_cnt++)
    {
        int lx = 0, ly = 0, rx = 0, ry = 0;
        cin >> lx >> ly >> rx >> ry;
        for(int y = ly; y < ry; y++)
        {
            for(int x = lx; x < rx; x++)
            {
                if(usr_array[y][x] == 1) 
                    usr_array[y][x] = 0;
            }
        }
    }
    for(int y = 0; y < _Y; y++)
    {
        for(int x = 0; x < _X; x++)
        {
            if(usr_array[y][x] == 1 && visited[y][x] == 0)
            {
                int cmpnt_cnt = 0;
                dfs({y,x}, usr_array, visited, cmpnt_cnt);
                if(cmpnt_cnt > 0)
                    cmpnt_cnt_list.push_back(cmpnt_cnt);
            }
        }
    }
    sort(cmpnt_cnt_list.begin(), cmpnt_cnt_list.end());
    cout << cmpnt_cnt_list.size() << "\n";
    for(auto cmpnt : cmpnt_cnt_list)
        cout << cmpnt << " ";
    return 0;
}