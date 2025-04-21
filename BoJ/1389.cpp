/* 케빈 베이컨의 6단계 법칙
https://www.acmicpc.net/problem/1389

6단계 법칙으로 지구상의 모든 사람이 연결될수 있다는 법칙이있다
- 케빈베이컨게임: 임의의 두사람이 최소 몇단계만에 이어질수 있는지 계산하는 게임

(양방향)
1- 3,4
2- 3
3- 4
4- 5
...

친구관계가 주어졌을때, 케빈베이컨의 총합이 가장 최소인 사람을 구하라

입력
- N (사람수.2~100) M (친구관계수.1~5,000)
- 친구관계

출력
- 케빈베이컨의 총합이 최소인 사람

풀이
- 양방향 그래프로 인접리스트를 만든 후, 탐색하면 됨
- '최소'를 찾는 것이니 여기서 만큼은 BFS를 써야함
- visited는 startIdx로 표시
- 케빈베이컨 배열도 함께 사용 -> 이미 구한 케빈베이컨은 안구할 수 있게

후기
- "과도한 시간 최적화는 메모리 초과를 부른다."
- BFS는 병렬로 최단거리를 찾는 알고리즘
    - 최단거리를 찾는 점과 찾았을때 visted 올리는 것을 함께 했다면, 훨씬 쉽게 풀렸음
    - 나의 문제. 값 하나하나 찾았었다는점. 
        그리고 visted 겸 거리를 찾는식으로 해야했는데, visited 따로-최단거리 따로 이런식으로 해서 
        좀더 느렸음. (12배 ㅋㅋ)
- BFS 특성을 잘 활용해보자 (visited 동시에 최단거리는 새롭게 다가온다..)

*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g_relationsList; // 인접 리스트
vector<pair<int, int>> g_kevinSums; // {사람 번호, 케빈 베이컨 합}
int g_N, g_M;
bool customCmp(const pair<int,int> &left, const pair<int,int> &right)
{
    if(left.second < right.second)
        return true;
    else if(left.second == right.second && left.first < right.first)
        return true;
    return false;
}

// start 노드로부터 모든 노드까지의 거리 합을 계산하는 함수
void CalculateTotalKevinSum(int start) {
    queue<pair<int, int>> q; // {현재 노드, 거리}
    vector<int> dist(g_N + 1, -1); // 거리 배열 (-1은 방문 안 함을 의미)
    int total_distance_sum = 0;

    q.push({start, 0});
    dist[start] = 0;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        int current_node = now.first;
        int current_dist = now.second;

        // 현재 노드까지의 거리를 총합에 더함
        total_distance_sum += current_dist;

        for (int neighbor : g_relationsList[current_node]) {
            if (dist[neighbor] == -1) { // 아직 방문하지 않은 이웃이라면
                dist[neighbor] = current_dist + 1;
                q.push({neighbor, current_dist + 1});
            }
        }
    }
    g_kevinSums[start].second = total_distance_sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;

    g_relationsList.resize(g_N + 1);
    g_kevinSums.resize(g_N + 1);
    g_kevinSums[0] = {INT_MAX, INT_MAX}; // 정렬을 위한 더미 값

    for (int i = 0; i < g_M; ++i) {
        int u, v;
        cin >> u >> v;
        g_relationsList[u].push_back(v);
        g_relationsList[v].push_back(u);
    }

    for (int start = 1; start <= g_N; ++start) {
        g_kevinSums[start].first = start;
        // start 노드에서 시작하는 BFS를 한 번만 호출하여 모든 노드까지의 거리 합 계산
        CalculateTotalKevinSum(start);
    }

    sort(g_kevinSums.begin() + 1, g_kevinSums.end(), customCmp); // 0번 인덱스 제외하고 정렬

    cout << g_kevinSums[1].first; // 정렬 후 가장 작은 값을 가진 사람 (1번 인덱스부터 유효)

    return 0;
}