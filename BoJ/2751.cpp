/* 수정렬하기2
https://www.acmicpc.net/problem/2751

진짜 sort 로 풀어도되는 문제같은데?
*/
#include <bits/stdc++.h>
using namespace std;
int g_N;
vector<int> g_nums;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    while(g_N--)
    {
        int input;
        cin >> input;
        g_nums.push_back(input);
    }
    sort(g_nums.begin(), g_nums.end());
    
    for(auto num: g_nums) cout << num <<"\n";
    return 0;
}