/*https://www.acmicpc.net/problem/1978
소수찾기

주어진 수 N개중 소수가 몇개인지 찾아서 
출력하는 프로그램 작성하시오.

[입력]
숫자개수 N은 100 이하. 
1000이하의 자연수 들. 

[출력]
소수 개수

[풀이]
소수라면.. 1을 제외하고 안나눠떨어지는 수. 
1000 이하의 소수를 구한 후에, 개수 구하자. 
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _ret;
vector<int> _inputs;
vector<int> _sosus;

int main()
{
    cin >> _N;
    _inputs.resize(_N,0);
    for(int inCnt = 0; inCnt < _N; inCnt++)
        cin >> _inputs[inCnt];
    sort(_inputs.begin(), _inputs.end());
    
    // 소수 만들어두기
    _sosus.push_back(2);
    for(int num = 3; num <1000; num++)
    {
        int sosuCnt = 0;
        for(sosuCnt; sosuCnt < _sosus.size(); sosuCnt++)
        {
            if(num%_sosus[sosuCnt] == 0)
                break;
        }
        if(sosuCnt == _sosus.size())
            _sosus.push_back(num);
    }
    
    // 입력값과 소수값 비교 체크
    int sosuCnt = 0;
    for(auto num: _inputs)
    {
        for(sosuCnt; sosuCnt <_sosus.size(); sosuCnt++)
        {
            if(num == _sosus[sosuCnt])
            {
                _ret++;
                break;
            }
            else if(num < _sosus[sosuCnt])
                break;
        }
    }
    cout << _ret;
    return 0;
}