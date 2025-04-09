/* 파도반 수열
https://www.acmicpc.net/problem/9461

N이 주어졌을때 문제에 그려진 삼각형처럼 N번째 삼각형 변의 길이를 구하라

풀이
- 피보나치수열 비슷한 느낌
- 1 1 1 2 2 3 4 5 7 9 12 16 21
- 1 1 1 2 2 까지만 입력한 후에 구하면 될듯
- 3 부터는 i-4 번째 칸 수와 합해짐

*/
#include <bits/stdc++.h>
using namespace std;
int g_TC, g_input;
vector<long long> g_triangles(101);

void SetTriangles(int tIdx)
{
    if(tIdx == 101)
        return;
    g_triangles[tIdx] = g_triangles[tIdx -1] + g_triangles[tIdx-5];
    // cout << g_triangles[tIdx] << " [" << tIdx <<"]\n";
    SetTriangles(tIdx+1);
}

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    g_triangles[1] = 1; g_triangles[2] = 1; g_triangles[3] = 1;
    g_triangles[4] = 2; g_triangles[5] = 2;
    cin >> g_TC;
    SetTriangles(6);
    while(g_TC--)
    {
        cin >> g_input;
        cout << g_triangles[g_input] << "\n";
    }
    return 0;
}