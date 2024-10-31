/* X marks the Stot
문자열 한쌍씩(S,T) 준다.(서로 길이는 같음)
S에서 발견한 x,X 의 위치를 파악하고, T에서 그위치의 문자를 출력한다.('무조건 대문자 출력')

풀이
- 문자열 받은 후 x, X 체크 후 해당 문자 대문자로 출력
*/    


#include<bits/stdc++.h>
using namespace std;
int _N;

int main(int argc, char** argv)
{
    cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
    {
        int x_idx = 0;
        string S, T;
        cin >> S >> T;
        for(x_idx ; x_idx <S.length() ;x_idx++)
        {
            if(S[x_idx] == 'x' || S[x_idx] == 'X')
                break;
        }
        if(T[x_idx] >= 'a' && T[x_idx] <= 'z')
            T[x_idx] = (T[x_idx]-'a')+'A';
        cout << T[x_idx];
    }
    return 0;
}