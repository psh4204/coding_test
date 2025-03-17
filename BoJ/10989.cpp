/* https://www.acmicpc.net/problem/10989
수 정렬하기3
*/
#include <bits/stdc++.h>
using namespace std;
vector<char> g_nums;
int g_N;

int main()
{
    cin >> g_N;
    while(g_N--)
    {
        char input;
        cin >> input;
        g_nums.push_back(input);
    }
    
    sort(g_nums.begin(), g_nums.end());
    
    for(auto n: g_nums)
        cout << n << "\n";
    
    return 0;
}