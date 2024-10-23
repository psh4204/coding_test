/* https://www.acmicpc.net/problem/7469
7469번째수

현정이는 새로운 자료구조를 만듦.
a[1..n]... 중에 Q(i,j,k) = i~j 오름차순 정렬 후 k번째 수 (1부터시작)

입력
- 배열크기n Q호출수m (n 1~100k, m 1~5k)
- 배열리스트
-  Q의 i j k

출력
- 각Q()의 출력

풀이
- 각 값을 받은 후, Q연산
- Q로 i부터 j까지 값을 받아온 후 k번째수를 받아온다.
- 1차. 무식하게 ㄱㄱ (시간초과)
- copy + sort가 제일 문제로 보임
- ... 진짜 어렵다 진짜로.. (프로그래머스문제랑 난이도가 아예다르네)
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _M;
vector<int> _nums;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N >> _M;
    _nums.resize(_N);
    for(int n_idx = 0; n_idx < _N; n_idx++)
    {
        cin >> _nums[n_idx];
    }
    for(int q_idx = 0; q_idx < _M; q_idx++)
    {
        int i, j, k;
        cin >> i >> j >> k;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int n_idx = i-1; n_idx < j; n_idx++)
            pq.push(_nums[n_idx]);
        for(int q_cnt = 0; q_cnt < k-1; q_cnt++)
            pq.pop();
        cout << pq.top() << "\n";
    }
    return 0;
}