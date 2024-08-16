/* https://www.acmicpc.net/problem/14502
연구소

바이러스를 막을 수 있게 세개의 벽을 세우자.
NxM의 연구소. (3 ~ N <=M ~ 8)
바이러스는 인접한 상하좌우로 퍼짐.
새로 새울수 있는 벽의 개수는 3개. 꼭 3개를 세워야함.
0 :빈방, 1:벽, 2:바이러스.

벽 세개를 채웠을때 최대 안정영역의 값을 구하라.

Input
- N M
- 지도

Output
- 최대 안전영역 개수

Try1.
- 문제가 난해하다.
- 경우의 수로 하기엔 너무 많다.
- 벽 3을 둘수 있는 경우의 수 -> 64 ^ 3 = 24만.. 1억을 1초라 가정하면 빠르게 끝날거같아보임.
    - 벽을 둔 후에 2를 채운 후, 0의 개수를 체크한다.
- 1은 노가다로 체크/ 2는 DFS로 체크 / 남은 0도 DFS로 체크

Try2.
- 다시풀자
- 벽세개를 효율적으로 세우는것보다 코드를 쉽게짜는 방향으로 가자.
    - 시간복잡도가 그렇게 안높음. (64x64짜리라)
- 새벽 숫자는 보기좋게 7로 하자.

Try3.
- 다시 푼 문제에서 틀림.
- 벽이 겹쳐서 틀린거 같음. 절대 안겹치게끔 조치하겠음.
*/
#include <bits/stdc++.h>
using namespace std;
int _Y, _X, _ret = 0;
int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};
vector<vector<int>> _lab;
vector<pair<int,int>> _v_list;  // virus
vector<pair<int,int>> _s_list;  // safety

// BFS로 virus simulate
void set_virus(vector<vector<int>>& lab)
{
    for(int v_idx = 0; v_idx < _v_list.size(); v_idx++)
    {
        queue<pair<int,int>> q;
        q.push(_v_list[v_idx]);
        while(!q.empty())
        {
            pair<int,int> here = q.front();
            q.pop();
            lab[here.first][here.second] = 2;
            for(int n_idx = 0; n_idx < 4; n_idx++)
            {
                int ny = _dy[n_idx] + here.first;
                int nx = _dx[n_idx] + here.second;
                if(ny < 0 || nx < 0 || ny >=_Y || nx >=_X)   continue;
                if(lab[ny][nx] == 0)    q.push({ny,nx});
            }
        }
    }
}

int get_safes(vector<vector<int>>& lab)
{
    int ret = 0;
    for(auto y : lab)
    {
        for(auto x: y)
        {
            if(x == 0)  ret++;
        }
    }
    return ret;
}

int main()
{
    cin >> _Y >> _X;
    // Init lab, virus_list, safe_list
    for(int y = 0; y <_Y; y++)
    {
        _lab.push_back({});
        for(int x = 0; x <_X; x++)
        {
            int value;
            cin >> value;
            _lab[y].push_back(value);
            if(value == 0)
                _s_list.push_back({y,x});
            else if(value == 2)
                _v_list.push_back({y,x});
        }
    }
    // Get ret
    for(int w1 = 0; w1 < _s_list.size(); w1++)
    {
        for(int w2 = w1+1; w2 < _s_list.size(); w2++)
        {
            for(int w3 = w2+1; w3 < _s_list.size(); w3++)
            {
                vector<vector<int>> copy_lab(_lab);
                int s_cnt = 0;
                // 0리스트에 7을 차례로 넣어가며 체크.// 이런식으로 벽세우기.
                copy_lab[_s_list[w1].first][_s_list[w1].second] = 7;
                copy_lab[_s_list[w2].first][_s_list[w2].second] = 7;
                copy_lab[_s_list[w3].first][_s_list[w3].second] = 7;
                set_virus(copy_lab);
                s_cnt = get_safes(copy_lab);
                if(_ret < s_cnt)
                {
                    _ret = s_cnt;
                }
            }
        }
    }
    cout << _ret << "\n";
    return 0;
}