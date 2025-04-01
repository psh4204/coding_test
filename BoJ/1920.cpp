/* 수 찾기
https://www.acmicpc.net/problem/1920

숫자는 int형이고
숫자 리스트를 에서 X가 있으면 1 없으면 0 출력하기

입력
- N (숫자리스트개수, 1~100,000)
- 숫자리스트
- M (X개수)
- X1 X2 ... Xm

출력
- 각 X마다 존재여부 표시 후 엔터 (유 1, 무 0)
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M;
unordered_set<int> g_numList;
vector<int> g_xList;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    while(g_N--)
    {
        int input;
        cin >> input;
        g_numList.insert(input);
    }
    cin >> g_M;
    while(g_M--)
    {
        int input;
        cin >> input;
        g_xList.push_back(input);
    }
    for(auto x: g_xList)
    {
        if( g_numList.find(x) == g_numList.end())
            cout << 0 <<"\n";
        else
            cout << 1 <<"\n";
    }
    return 0;
}