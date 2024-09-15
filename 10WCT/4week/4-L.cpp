/* https://www.acmicpc.net/problem/5430
AC

정수배열연산을 위한 언어로 AC를 만듦.
R,D(뒤집기, 버리기) 함수가 있음.
- 아무것도 없는데 D를 쓰면 에러남
함수는 조합해서사용가능
- RDD -> R한번 D 두번
배열 초기값과 수행할 함수를 받았을때 최종결과를 얻는 프로그램 작성하기

Input
- TC개수 T (0~100) . T만큼 반복
    - 수행할함수조합 (1~100,000)
    - 배열에 들어갈 수 개수 (0~100,000)
    - 정수배열 (수의크기는 1~100, 혹은 없을수도)

Output
- 입력으로 주어진 정수배열에 함수를 수행 결과. 에러발생시 error

Try1
- 수행할 함수조합이 .. 어마어마하다.
- 저거는 비트마스킹으로 해결하면 될것으로 판단됨.
- 함수받으면 비트마스킹.및 함수길이 받아오기.
    - 같은 함수가 몇번나오는지 체크하는 시퀀스도 필요할듯(최적화를 위함)
- 입력받은배열String을 배열로 만드는 함수 필요.

Try2
- error조건은 값이 없는데 delete를 시도했을때의 경우임.
- 이거 외에는 없음.

Try3
- 비트마스킹은 길어봤자 32... -> 경우의수가 32까지 밖에안됨.
- 비스마스킹이 아닌 다른거로 해보자.
4
D
1
[22]
R
2
[1,2]
DDDD
3
[1,2,3]
RRRRD
3
[1,2,3]

2
R
0
[]
R
0
[]

*/
#include <bits/stdc++.h>
using namespace std;
int _T;

struct func_t{
    string str;
    vector<int> op;
    int size = 0;
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _T;
    while (_T--)
    {
        bool is_error = false;
        func_t func;
        cin >> func.str;
        func.size = func.str.length();
        for(int f_cnt = 0; f_cnt < func.str.length(); f_cnt++)
        {
            if(func.str[f_cnt] == 'R')
                func.op.push_back(1);
            else 
                func.op.push_back(0);
        }
        deque<int> nums;
        char trash;
        int num;
        int num_cnt = 0;
        cin >> num_cnt;
        do
        {
            cin >> trash;
            if(num_cnt)
            {
                cin >> num;
                nums.push_back(num);
            }
            num_cnt--;
        }while(num_cnt>0);
        cin >> trash;
        
        // calculate
        int reverse_cnt = 0;
        for(int c_idx = 0; c_idx < func.size; c_idx++)
        {
            if(func.op[c_idx] == 0)   // 0:delete, 1:reverse
            {
                if(nums.size() > 0)
                {
                    if((reverse_cnt%2)==1)
                        nums.pop_back();
                    else
                        nums.pop_front();
                }
                else
                {
                    is_error = true;
                    break;
                }
            }
            else
                reverse_cnt++;
        }
        if(is_error)
        {
            cout << "error\n";
            continue;
        }
        if(nums.size() == 0)
        {
            cout << "[]\n";
            continue;
        }
        if((reverse_cnt%2)==1)
            reverse(nums.begin(), nums.end());
        cout << "[";
        for(int n_idx = 0; n_idx < nums.size(); n_idx++)
        {
            cout << nums[n_idx];
            if(n_idx < nums.size()-1)
                cout << ",";
        }
        cout << "]\n";
    };

    return 0;
}