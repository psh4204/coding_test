/* 거짓말
https://www.acmicpc.net/problem/1043

파티마다 거짓말을 치는 친구가 있다
매번 거짓말을 치면 이미지가 나빠지기때문에 
매파티마다 거짓말을 칠 순 없다
왜냐하면 진실을 아는사람은 분명히 있기 때문이다

사람수와 진실을 아는사람수, 그리고 파티에 오는 사람들 번호가 주어짐.
친구는 매번파티를 참가해야한다
거짓말쟁이로 안남으면서, 거짓말을 가장많이 칠수있는 파티개수를 구하라

입력
- N M (사람수, 파티수... 50이하 자연수)
- T (진실을 아는사람수 ... 0 ~ 50) 진실을 아는 사람 번호들 ...
- P (파티에 오는사람 수) 파티에 오는사람 번호들
- ...

출력
- 최대 거짓말 가능파티개수

풀이
- 처음 풀어보는 문제네
- 거짓말 가능한 파티수까지 구해야함
    - 각 파티에 진실을 몰라도 거짓말을 치면 안되는경우까지 생각해야함.
    - 이야 참신한 문제네
- 비트연산 문제같은데 (최대 50이랬으니)
    - 진실을 아는사람들을 비트연산으로 채움
    - 파티에 참석하는 사람들도 따로 비트로 각각채움
    - 만약 진실만 말하는 파티에 참석하는 인원이 있다면,
        그 인원도 진실을 안다는 비트체크를 해야함 <-- TODO: 이런식의 방법론 고민 후 문제풀자

4 3
1 4
2 2 3
1 2 
3 1 3 4

ans: 1 << 원래 생각했던답.
ans: 0 << 이게 실제 답일듯

4 3
1 4
1 1
1 2
4 1 2 3 4

[NOTE]
- 비트연산자는 우리가 평소에 쓰는 연산자, 비교연산자 보다 우선순위가 낮기때문에
    사용할때 괄호가 필수이다.

--- 비트 연산을 통한 풀이는 오답 ---
2트 풀이
- 탐색으로 풀어보자
- 노드는 각 사람들을 뜻하고, 사람들에겐 참석할 파티들이 주어짐 (양방향)
- 
- 거짓말 친사람을 체크하고, 그들을 통하는 모든 파티를 탐색한다
    - 진아모: 사람 노드들 <- 이걸 통해서 진입
    - 사람: 파티 노드들
    - 파티: 사람 노드들
    - visited: y:파티 x: 사람 
        - 해당 파티에 해당사람에 접근했는지 체크
        - 아. 이걸 비트연산으로 체크하면 되겠다 (visted[0] |= 1<<사람)
    - 거짓말 가능체크: visited 비트 중에 0인애들 카운트

[NOTE]
- LONG LONG 타입일때 비트연산하게되면, '숫자LL 꼭 붙이자'
- 여태 이거때메 틀렸음
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g_N, g_M, g_T, g_ans;
ll g_trueManCheck = 0;
vector<vector<int>> g_man; // 사람 {참여할 파티들}
vector<vector<int>> g_party; // 파티 {참여하신 사람들}
vector<ll> g_partyCheck(51);
queue<int> g_manQ;

int main()
{
    /* 초기화 */
    cin >> g_N >> g_M; // 사람, 파티 수
    g_man.resize(g_N+1);
    g_party.resize(g_M+1);

    cin >> g_T;  // 진실을 아는 사람 수
    for(int tIdx = 0; tIdx < g_T; tIdx++)
    {
        int tMan;
        cin >> tMan;
        g_manQ.push(tMan);
        g_trueManCheck |= (1LL<<tMan);
    }

    for(int partyIdx = 1; partyIdx <= g_M; partyIdx++)
    {
        int joinNum;
        cin >> joinNum;
        for(int jIdx = 0; jIdx < joinNum; jIdx++)
        {
            int joinManIdx;
            cin >> joinManIdx;
            g_man[joinManIdx].push_back(partyIdx);
            g_party[partyIdx].push_back(joinManIdx);
            g_partyCheck[partyIdx] |= 1LL<< joinManIdx;
        }
    }

    /* 탐색 */
    while(!g_manQ.empty())
    {
        int nowMan = g_manQ.front();
        g_manQ.pop();
        // 해당 인물이 갈 파티 체크
        for(auto party: g_man[nowMan])
        {
            // 해당 파티에 인원체크
            for(auto nextMan: g_party[party])
            {
                if((g_trueManCheck & 1LL<<nextMan) != 0)
                    continue;
                // cout << "nextMan: " << nextMan << " nextParty: " << nextParty << "\n"; // TEST <<<<<
                g_manQ.push(nextMan);
                g_trueManCheck |= (1LL<<nextMan);
            }
        }
    }

    /* 거짓말 가능한 파티 수 체크 */
    for(int partyIdx = 1; partyIdx <= g_M; partyIdx++)
    {
        if((g_partyCheck[partyIdx] & g_trueManCheck) == 0)
            g_ans++;
    }
    cout << g_ans;
    return 0;
}