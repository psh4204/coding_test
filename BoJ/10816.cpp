/* 숫자카드2
https://www.acmicpc.net/problem/10816

숫자카드 N개 중 찾고싶은 M개의 숫자가 몇장있는지 확인해보자

입력
- N (1~500,000)
- 숫자카드들 ( -10,000,000 ~ 10,000,000)
- M
- 찾으려는숫자들

출력
- M개의 숫자카드 가 각 몇장있는지 출력

풀이
- unordeded_Map으로 풀어야하는 문제
    - key: num
    - value: count
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> g_cards;
int g_N, g_M;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    while(g_N--)
    {
        int cardNum;
        cin >> cardNum;
        if(!g_cards.empty() && g_cards.find(cardNum) != g_cards.end())
        {
            g_cards[cardNum]++;
            continue;
        }
        g_cards.insert({cardNum, 1});
    }
    cin >> g_M;
    while(g_M--)
    {
        int cardNum;
        cin >>cardNum;
        if(g_cards.find(cardNum) == g_cards.end())
        {
            cout << 0 << " ";
            continue;
        }
        cout << g_cards[cardNum] << " ";
    }
}