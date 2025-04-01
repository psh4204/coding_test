/* 좌표 정렬하기2
https://www.acmicpc.net/problem/11651

좌표 x, y 받았을때
y가 오름차순으로 정렬하기
y가 같으면, x가 큰값으로 정렬하기

풀이
- compare 문 만들면 풀림
*/
#include <bits/stdc++.h>
using namespace std;
struct Pointer_t{
    int x;
    int y;
};
vector<Pointer_t> g_pointers;
int g_N; 

bool Compare(const Pointer_t & first, const Pointer_t & second)
{
    if(first.y < second.y)
    {
        return true;
    }
    else if(first.y == second.y)
    {
        if(first.x < second.x)
            return true;
    }
    return false;
}

int main()
{
    cin >> g_N;
    while(g_N--)
    {
        Pointer_t input;
        cin >> input.x >> input.y;
        g_pointers.push_back(input);
    }
    sort(g_pointers.begin(), g_pointers.end(), Compare);
    for(auto point: g_pointers)
        cout << point.x << " " << point.y << "\n";
    return 0;
}