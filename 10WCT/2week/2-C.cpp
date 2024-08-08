/* https://www.acmicpc.net/problem/2468
안전영역

정사작형 행열에서 높이를 각각 주어진다.
일정높이 이하의 모든 지점은 물에 잠긴다. (예시: 높이 4이하 물에잠김)
비의 양에따라 안전지역의 개수 많아질수도 적어질수도 있다.
여기서 안전지역의(물에안잠긴 컴포넌트) 최대개수를 구하라.

Input
- N
- 배열

Output
- 컨테이너 최대개수

Try1.
- 지도에서 각 컴포넌트 개수를 전부 구해야하는데, x,y,z를 전부 순회한다 했을때 최대 1M번
- 1초 1억번이라 생각했을때, 100m초안에 다 해결가능하단 소리.
- 가장 큰높이부터 가장 낮은높이 까지 지도를 만들어가며 Container 개수를 체크한다.
- DFS로 컨테이너 개수를 체크한다.
- [NOTE]
    - 컨테이너의 이터레이터 end()를 이용하여 마지막값을 가져오고싶다면
        ==> *(--it.end())
    - 귀찮더라도 테스트 코드는 꼭 주석붙여서 분리시켜두자.
*/
#include <bits/stdc++.h>
using namespace std;
int _N = 0;
int _dy[] = {-1, 0 ,1, 0};
int _dx[] = {0, 1, 0, -1};
set<int> _heights;
set<int> _cont_cnt_size_list;

void dfu(pair<int,int> here, vector<vector<int>> & r_a, vector<vector<int>> & v_a, int & cmp_cnt, int height)
{
    v_a[here.first][here.second] = 1;
    cmp_cnt++;
    for(int d_cnt = 0; d_cnt < 4; d_cnt++)
    {
        int y = here.first + _dy[d_cnt];
        int x = here.second + _dx[d_cnt];
        if(y < 0 || x < 0 || y >= _N || x >= _N)
            continue;
        if(r_a[y][x] > height && v_a[y][x] == 0)
            dfu({y,x}, r_a, v_a, cmp_cnt, height);
    }
}

int main()
{
    cin >> _N;
    vector<vector<int>> rain_arr(_N,vector<int>(_N,0));
    vector<vector<int>> zero_arr(rain_arr); // zero init용 
    for(int y_cnt = 0; y_cnt <_N; y_cnt++)
    {
        for(int x_cnt = 0; x_cnt <_N; x_cnt++)
        {
            int height = 0;
            cin >> height;
            rain_arr[y_cnt][x_cnt] = height;
            _heights.insert(height);
        }
    }
    if(_heights.size() == 1)
    {
        // 동일한 높이일 경우 1.
        cout << 1;
        return 0;
    }

    // 가장 낮은 높이부터 높은 높이까지 컴포넌츠개수를 구해서 저장하자.
    for(auto height: _heights)
    {
        // 끝까지 올라왔으면 break;
        if(height+1 > *(--_heights.end()))
            break;
        // 현재 height를 초과하는 수가 안전한 구역
        vector<vector<int>> visited(zero_arr);
        vector<int> cont_cnt_list;
        for(int y =0; y <_N; y++)
        {
            for(int x = 0; x <_N; x++)
            {
                if(rain_arr[y][x] > height && visited[y][x] == 0)
                {
                    int cont_cnt = 0;
                    dfu({y,x}, rain_arr, visited, cont_cnt, height);
                    if(cont_cnt > 0)
                        cont_cnt_list.push_back(cont_cnt);
                }
            }
        }
        if(cont_cnt_list.size() > 0) 
            _cont_cnt_size_list.insert(cont_cnt_list.size());
    }
    cout << *(--_cont_cnt_size_list.end());
}