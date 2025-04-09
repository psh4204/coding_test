/* ATM
https://www.acmicpc.net/problem/11399

각 사람이 돈뽑는데 걸리는 시간의 최소합을 구하라
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_sum;
vector<int> g_mans;

int main()
{
    cin >> g_N;
    while(g_N--)
    {
        int input;
        cin >> input;
        g_mans.push_back(input);
    }
    sort(g_mans.begin(), g_mans.end());
    
    g_sum = g_mans[0];
    for(int manIdx = 0; manIdx < g_mans.size(); manIdx++)
    {
        if(manIdx == 0)
            continue;
        
        g_mans[manIdx] += g_mans[manIdx-1];
        g_sum += g_mans[manIdx];
    }
    cout << g_sum;
    return 0;
}