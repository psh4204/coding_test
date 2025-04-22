/* 경로찾기
https://www.acmicpc.net/problem/11403

인접행렬이 주어짐 (1이면 연결. 0이면 비연결. i i 끼린 연결절대X)
- i에서 j로 가는 길이가 양수인 경로가 있는지 없는지 확인하는 프로그램 작성
- (양수로 가는 경로가 뭔소리냐?)
    - 아마 i에서 'j들'로 전부 단방향으로 들리냐 이거 물어보는건가?
    - 맞네
- 즉, 단방향 인접행렬을 인접리스트로 만드는데, 만들때 숫자를 기입하는게 아닌, 해당 j를 1로 만드는 것이네
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_input;
vector<vector<int>> g_adjArray;
vector<vector<int>> g_adjListArray;

void GotoTarget(const int start, int target)
{
    for(int nTarget = 0; nTarget < g_N; nTarget++)
    {
        if(g_adjArray[target][nTarget] == 1 && g_adjListArray[start][nTarget]==0)
        {
            g_adjListArray[start][nTarget] = 1;
            GotoTarget(start, nTarget);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    for(int inY = 0; inY < g_N; inY++)
    {
        g_adjArray.push_back({});
        g_adjListArray.push_back({});
        for(int inX = 0; inX < g_N; inX++)
        {
            cin >> g_input;
            g_adjArray[inY].push_back(g_input);
            g_adjListArray[inY].push_back(0);
        }
    }
    for(int start = 0; start < g_N; start++)
    {
        GotoTarget(start, start);
    }

    for(auto y: g_adjListArray)
    {
        for(auto x: y)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}