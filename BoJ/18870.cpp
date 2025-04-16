/* 좌표 압축
https://www.acmicpc.net/problem/18870

수직선위 N개 좌표, X1~XN 이 있고 압축하고싶음
압축결과
- Xi 를 압축한 Xi' 는 Xi>Xj 를 만족하는 서로다른 좌표 Xj의 개수와 같아야함
- 뭔소리냐면,
    - Xi보다 작은값의 개수를 구하는게 좌표압축

풀이
- hash써서 카운트 하면 되지않을까? 시간초과
- vector와 hash 적절히 써서 시간단축했음

*/
#include <bits/stdc++.h>
using namespace std;
int g_N;
vector<int> g_nums; // 답 체크용
vector<int> g_sortNums; // sort할 애들
unordered_map<int,int> g_map; // 중복체크 및 답 저장용

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    for(int nIdx = 0; nIdx < g_N; nIdx++)
    {
        int input;
        cin >> input;
        g_nums.push_back(input);
        auto it = g_map.find(input);
        if(it == g_map.end())
        {
            g_sortNums.push_back(input);
            g_map.insert({input, 0});
        }
    }
    // 압축
    sort(g_sortNums.begin(), g_sortNums.end(), greater<int>());
    for(int nIdx = 0; nIdx < g_sortNums.size(); nIdx++)
    {
        g_map[g_sortNums[nIdx]] = g_sortNums.size() - nIdx -1;
    }

    // 출력
    for(int nIdx = 0; nIdx < g_N; nIdx++)
    {
        cout << g_map[g_nums[nIdx]] << " ";
    }
}