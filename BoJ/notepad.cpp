#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g_array;
int g_N, g_M, g_input;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    g_array.resize(g_N,vector<int>(g_M,0));
    for(int loopCnt = 0; loopCnt < 2; loopCnt++)
    {
        for(int y = 0; y < g_N; y++)
        {
            for(int x = 0; x < g_M; x++)
            {
                cin >> g_input;
                g_array[y][x] += g_input;
            }
        }
    }

    for(auto yArray: g_array)
    {
        for(auto value: yArray)
            cout << value << " ";
        cout << "\n";
    }

    return 0;
}