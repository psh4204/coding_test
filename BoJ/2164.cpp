/* 카드 2
https://www.acmicpc.net/problem/2164

1~N까지 순서대로 쌓인 카드 중에 다음의 규칙 루프를 돌려 
마지막에 남는카드가 먼지 알아보자 (참고 1이 가장 위이다) 
- 가장 위의 카드는 버린다
- 그다음에 가장위카드를 가장 아래에 둔다

풀이
- 덱 문제 (C++은 그냥 큐쓰면됨)
*/
#include <bits/stdc++.h>
using namespace std;
int g_N;
queue<int> g_cards;

int main()
{
    cin >> g_N;
    for(int num = 1; num <= g_N; num++)
        g_cards.push(num);
    
    while(g_cards.size() >= 2)
    {
        int top = 0;
        g_cards.pop();
        top = g_cards.front();
        g_cards.pop();
        g_cards.push(top);
    }
    cout << g_cards.front();
    return 0;
}
