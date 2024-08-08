/* https://www.acmicpc.net/problem/1012
유기농 배추

유기농배추를 위한 배추흰지렁이 마리수를 구해보자.
배추밭에 배추의 컴포넌트 수 구하기.

Input
- 입력 첫줄엔 TestCase T (T 만큼 좌표를 줄 거임.)
- 배추밭 가로M, 세로N, 배추수K (M,N: 1~50, K: 1~2500)
- 배추위치 X(0~M-1), Y(0~N-1) (배추의 위치가 같은경우X)

Output
- 각 테스트케이스에 대한 최소의 배추흰지렁이 수를 출력한다.

Try1.
- 테스트..케이스? 무슨 테스트인데? 아~ 케이스를 두개준다 이말이구나.
- 배추 2개씩 좌표를 보여준다니까, 이건 인접리스트로 해도 됨. 근데 지도로 해보자.
- 각케이스에서 DFS를 통해 컨테이너 개수를 출력하자.
- M,N을 Y,X로 수정해서 쓰자.
*/
#include <bits/stdc++.h>
using namespace std;
int _T = 0;
int _dy[] = {-1, 0, 1, 0};
int _dx[] = {0, 1, 0, -1};

void dfs(pair<int,int> here, vector<vector<int>>& bc_arr, vector<vector<int>>& v_arr, vector<pair<int,int>>& c)
{

    v_arr[here.first][here.second] = 1;
    c.push_back(here);
    for(int d_cnt = 0; d_cnt < 4; d_cnt++)
    {
        int y = here.first + _dy[d_cnt];
        int x = here.second + _dx[d_cnt];
        if(y < 0 || x < 0 || y >= bc_arr.size() || x >= bc_arr[y].size())
            continue;
        if(bc_arr[y][x] == 1 && v_arr[y][x] == 0)
            dfs({y,x}, bc_arr, v_arr, c);
    }
}

int main(void)
{
    // T 입력받기
    cin >> _T;

    // T별 M, N 받고 지도 그리기
    for(int tc = 0; tc < _T; tc++)
    {
        int Y ,X, K; // M, N, 배추개수
        cin >> Y >> X >> K;
        // Init 배추밭, visited
        vector<vector<int>> bc_array(Y, vector<int>(X,0));
        vector<vector<int>> visited(bc_array);
        vector<vector<pair<int,int>>> containers;
        for(int bc_n = 0; bc_n < K; bc_n++)
        {
            int y, x;
            cin >> y >> x;
            bc_array[y][x] = 1;
        }
        for(int y = 0; y < Y; y++)
        {
            for(int x = 0; x < X; x++)
            {
                if(bc_array[y][x] == 1 && visited[y][x] == 0)
                {
                    vector<pair<int, int>> container;
                    dfs({y,x}, bc_array, visited, container);
                    if(container.size() != 0)
                        containers.push_back(container);
                }
            }
        }
        cout << containers.size() << "\n";
    }
}
