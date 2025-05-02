/* 플로이드
https://www.acmicpc.net/problem/11404

도시 n 2~100 개 있고,
버스 m 1~100,000 개가 있다
- 각 버스는 사용할때마다 비용이듦

모든 도시의 쌍 에서 필요한 비용의 최소값을 구하라

입력
- n
- m
- 출발도시 도착도시 필요비용
- ...

출력
- i to j로 이동최소비용 (2차원배열)

풀이
- 이건 다익스트라다.
- 각 도시로 가는 최소비용을 구한다.
- 단, 시작도시별로 각각 다 구한다.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Bus_t{
    int city;
    ll pay;
};
struct MinHeap{
    bool operator() (const Bus_t & left, const Bus_t & right) const
    {
        return !(left.pay < right.pay);
    }
};
vector<vector<ll>> g_pays(101,vector<ll>(101, LONG_LONG_MAX));
vector<vector<Bus_t>> g_adjList(101);
int g_N, g_M;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    for(int bIdx = 0; bIdx < g_M; bIdx++)
    {
        int start, dest, pay;
        cin >> start >> dest >> pay;
        g_adjList[start].push_back({dest,pay});
    }
    for(int cityIdx = 1; cityIdx <= g_N; cityIdx++)
    {
        priority_queue<Bus_t, vector<Bus_t>, MinHeap> pq;
        pq.push({cityIdx,0});
        g_pays[cityIdx][cityIdx] = 0;
        while(!pq.empty())
        {
            Bus_t now = pq.top();
            pq.pop();
            if(now.pay > g_pays[cityIdx][now.city])
                continue;
            for(auto next: g_adjList[now.city])
            {
                ll nextPaySum = now.pay + next.pay;
                if(nextPaySum > g_pays[cityIdx][next.city])
                    continue;
                g_pays[cityIdx][next.city] = nextPaySum;
                pq.push({next.city, nextPaySum});
            }
        }
    }

    for(int start = 1; start <=g_N; start++)
    {
        for(int target = 1; target <= g_N; target++)
        {
            if(g_pays[start][target] == LONG_LONG_MAX)
                cout << 0 << " ";
            else
                cout << g_pays[start][target] << " ";
        }
        cout << "\n";
    }

    return 0;
}