/* 연탄크기
난로는 모두 원통형, 난로의 반지름 길이가 연탄의 반지름길의 배수여야 연탄사용가능.

n개의 난로들의의 반지름길이가 주어지면, 
연탄의 반지름길이를 처음에 잘 설정해서 가장 많은 집에 연탄을 주고싶음.

입력
- n (1~100)
- 난로반지름 배열(크기 2~100)
출력
- 연탄사용 가능한 최대집의 개수

풀이
- 하나하나 계산 후 카운트 해서 가장 큰 카운트수 구하기.
- (주의). 난로구멍들의 호환성을 보지말고, Only 연탄크기로만 승부를 봐야함.
*/

#include<bits/stdc++.h>
using namespace std;
int _N, _max_cnt = 0;
vector<int> _nanros;

int main(int argc, char** argv)
{
    cin>>_N;
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
    {
        int nanro;
        cin >> nanro;
        _nanros.push_back(nanro);
    }
    sort(_nanros.begin(), _nanros.end());
    
    // cout << "[TEST] ";
    // for(auto n: _nanros)
    //     cout << n << " ";
    // cout << "\n";
    
    for(int size_cnt = 2; size_cnt <= 100; size_cnt++)
    {
        int able_cnt =0;
        for(int sub_cnt = 0; sub_cnt < _N; sub_cnt++)
        {
            if(_nanros[sub_cnt] % size_cnt == 0)
                able_cnt++;
        }
        _max_cnt = max(_max_cnt, able_cnt);
    }
    cout << _max_cnt << "\n";
    return 0;
}