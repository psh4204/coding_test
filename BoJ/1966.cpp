/* https://www.acmicpc.net/problem/1966
프린터 큐

프린터소프트웨어 개발.
- 중요도가 들어간 큐로 개발
- 중요도는 내림차순

입력
- T(테스트케이스 수)
    - N M (문서개수.. 1~100 , 몇번째문서인지.. 0~N)
    - 중요도_리스트
    ...(테케 만큼반복)

출력
- 각 테케마다 M번째 문서가 몇번째(1~)로 출력됐는지

풀이
- 문서번호(1~N) 중요도(0~N-1)
- 아... 진짜 pq가 특이한 유사 pq를 만든거였음 (자신의 인쇄차례때 문서 중 중요도가 더 높은게 있으면, 자신은 가장 뒤로 물러섬)
    - pq 쓸필요 없고, 그냥 vector로 sort해서 우선순위배치하면 됨.
    - 책리스트는 deque으로 구현: 본인차례때 우선순위리스트의 값과 체크 후 본인이 낮으면 가장뒤로 밀려남.
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct{
    int pri; // 오름차순
    int num; // 순서상관X
}paper_t;
struct cmp{
    bool operator() (const paper_t& first, const paper_t& second)const{
        // pq는 반대로
        if(first.pri > second.pri)
            return false;
        else
            return true;
    }
};
int _T, _N, _M;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _T;
    for(int t_cnt = 0; t_cnt < _T; t_cnt++)
    {
        priority_queue<paper_t, vector<paper_t> ,cmp> pq; // PQ왜씀? 그냥. 만들었는데 지우기 아까워서
        deque<paper_t> papers;
        cin >> _N >> _M;
        for(int n_cnt = 0; n_cnt < _N; n_cnt++)
        {
            int priority;
            cin >> priority;
            pq.push({priority, n_cnt});
            papers.push_back({priority, n_cnt});
        }
        int paper_cnt = 1;
        while(papers.size())
        {
            // books 기준 print. 현재 문서의 우선순위가 낮으면 젤 뒤로 보냄.
            while(papers.front().pri < pq.top().pri)
            {
                papers.push_back(papers.front());
                papers.pop_front();
            }
            if(papers.front().num == _M)
            {
                cout << paper_cnt << "\n";
                break;
            }
            paper_cnt++;
            pq.pop();
            papers.pop_front();
        }
    }
    return 0;
}