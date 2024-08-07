/*
https://www.acmicpc.net/problem/2667
단지번호 붙이기

1과 0으로 된 지도가 주어진다.
연결된 단지(컴포넌트)를 정의하고, 해당 컴포넌트마다 번호를 붙인다.(flood fill)
각 컴포넌트에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램 작성하기.

Input
- "N" (지도의 가로세로 크기. 정사각형이며 2~25)
- "지도 Array"

Output
- 컴포넌트 갯수 출력
- 각 컴포넌트별 V수 출력

Try1.
- 배열을 입력받은 후 컴포넌트들을 나눠보자.
- 지도로 나왔으니 지도로 풀어본다.
    - 각 컴포넌트 별 시작을 어떻게 체크해야할까..?
        - "visited 지도" 하나를 펼친 후, visited 체크하며 시작.
        - 시작지점을 찾으면 DFS로 "인접리스트"를 만들어서 컴포넌트를 하나씩 만든다.
==> 틀렸습니다.

Try2.
- TC로 했을땐 문제없었는데..?
- 단지체크할때 4방향이라 옳게했음.
- 아~ 정렬을 오름차순으로~
*/
#include <bits/stdc++.h>
using namespace std;
int _N = 0;
int _dy[] = {-1, 0, 1, 0};
int _dx[] = {0, 1, 0, -1};

void dfs(pair<int,int> here, vector<vector<int>>& u_a, vector<vector<int>>& v_a, vector<pair<int,int>>& component)
{
    if(u_a[here.first][here.second] == 0 || v_a[here.first][here.second] == 1)
        return;
    v_a[here.first][here.second] = 1;
    component.push_back(here);
    for(int d_idx = 0 ; d_idx < 4; d_idx++)
    {
        int ny = _dy[d_idx] + here.first;
        int nx = _dx[d_idx] + here.second;
        if(ny < 0 || nx < 0 || ny >= _N || nx >= _N)
            continue;
        pair<int, int> there = {ny, nx};
        dfs(there, u_a, v_a, component);
    }
}

vector<vector<pair<int,int>>> search_components(vector<vector<int>>& u_a, vector<vector<int>>& v_a)
{
    vector<vector<pair<int,int>>> ret_comps;
    for(int y = 0; y < _N; y++)
    {
        for(int x = 0; x < _N; x++)
        {
            if(u_a[y][x] == 0 || v_a[y][x] == 1)
                continue;
            pair<int,int> usr_y_x = {y, x};
            vector<pair<int,int>> component;
            dfs(usr_y_x, u_a, v_a, component);
            ret_comps.push_back(component);
        }
    }
    return ret_comps;
}

bool custom_cmp(vector<pair<int,int>> first, vector<pair<int,int>> second)
{
    return first.size() < second.size();
}

int main()
{
    cin >> _N;
    vector<vector<int>>             usr_arr(_N);    // user_input
    vector<vector<int>>             v_arr(_N);      // visited
    vector<vector<pair<int,int>>>   components;      // [C][V][P]
    for(int input_cnt = 0; input_cnt < _N; input_cnt++)
    {
        string input;
        cin >> input;
        for(auto ch: input)
        {
            usr_arr[input_cnt].push_back(ch-'0');
            v_arr[input_cnt].push_back(0);
        }
    }
    components = search_components(usr_arr, v_arr);
    
    // cout answers
    cout << components.size() << "\n";
    sort(components.begin(), components.end(), custom_cmp);
    for(auto compo : components)
        cout << compo.size() << "\n";
    return 0;
}