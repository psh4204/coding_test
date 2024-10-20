/* https://www.acmicpc.net/problem/2240
자두나무

매 초마다 두개의 나무 중 하나의 나무에서 자두가 떨어짐.
- 한칸씩 움직여서 자두를 받을 수 있다. (떨어지는 시간 1~1000, 자두체력 1~30)
자두가 떨어지는 정보가 주어졌을때 자두를 받을 수 있는 개수 구하기.

입력
- T W (T 각나무당떨어지는시간, W 자두체력)
- T개의 줄에 자두가 떨어지는 나무버호가 주어짐

출력
- 자두를 받을 수 있는 최대개수 출력

도전1
- T, W 받은 후, W를 사용할 수있는 경우의수 = 2^30
- 해당 경우에서 나온 값을 최적해를 구한 후 dp에 메모.
    - 특정 Tn W0 cntn 의 경우를 전부 안할 수 있음 (최적화)
- 최적해 고우고우
*/
#include <bits/stdc++.h>
using namespace std;
#define TRASH -1e9
#define MAX_T 1004
#define MAX_W 34
vector<vector<vector<int>>> _dp(MAX_T,vector<vector<int>>(MAX_W,vector<int>(2,-1)));
vector<int> _jadoos(MAX_T,-1);
int _T, _W;

inline int get_jadoo(int here, int hp, int move)
{
    // 기저
    if(hp < 0)  return TRASH;
    if(here > _T)  return 0;

    // 메모
    int &ret = _dp[here][hp][move]; 
    if(~ret)    return ret;
    
    // 로직
    ret = max(get_jadoo(here+1, hp, move), get_jadoo(here+1, hp-1, move^1)) + (_jadoos[here] == move);
    
    // // [[TEST]]
    // cout<< here << " " << move << " " << ret << "\n";
    return ret;
}

int main()
{
    cin >> _T >> _W;
    for(int j_idx = 1; j_idx <= _T; j_idx++)
    {
        int jadoo = 0;
        cin >> jadoo;
        _jadoos[j_idx] = jadoo -1;
    }
    // 초기화
    cout << get_jadoo(0,_W,0);

    return 0;
}
