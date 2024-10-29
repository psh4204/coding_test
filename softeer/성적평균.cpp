/* 성적평균
N명의 학생들의 성적이 학번 순서대로 주어짐.
학번 [A,B]구간의 성정평균 구하기

입력
- 학생수 N, 구간수 K
- 학생성적 리스트(N개 만큼)
- 구간 A B .. (K개 만큼)

출력
- 구간별 평균

풀이
- 입력 배열 초기화
- K 수만큼 구간별 평균 체크
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> _inputs;
int _N, _K;

int main(int argc, char** argv)
{
    cin >> _N >> _K;
    _inputs.resize(_N,0);
    
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
        cin >> _inputs[n_cnt];
    
    for(int k_cnt = 0; k_cnt < _K; k_cnt++)
    {
        int A, B, high, low;
        double avg, sum = 0;
        cin >> A >> B;
        // SUM
        for(int a_cnt = A-1; a_cnt < B; a_cnt++)
        {
            sum +=_inputs[a_cnt];
        }
        // 평균구하기
        avg = sum/(B+1-A);
        // 소수점 셋째자리 반올림하기
        avg = round(avg *100) / 100;
        // 정답
        printf("%.2f\n",avg);
    }
    
    return 0;
}