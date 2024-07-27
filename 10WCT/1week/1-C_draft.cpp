/*
2979: 트럭주차
트럭 3대, 트럭주차비용 계산.
- 트럭주차 수에 따라 요금할인.
- 1대할때 1분에 A원, 2대 1분에 B원, 3대 1분에 C원.
- A,B,C 와 minute 주어지면 요금 계산하기

input
- A B C = 1~100
- 차1번 도착시간 떠난시간 = 1~100
- 차2번 도착시간 떠난시간 = 1~100
- 차3번 도착시간 떠난시간 = 1~100

해석
- vector에 A, B, C 입력. 도착시간입력
- output으로 (key * value) 를 더하면 끝
*/

#include <bits/stdc++.h>
using namespace std;

int _abc_money[4] = {0,};

string input_t_p()
{
    // "A B C" 
    // + " " + "A시작 끝"
    // + " " + "B시작 끝"
    // + " " + "C시작 끝" 
    string input;
    string save;
    getline(cin, input);
    save += input + " ";
    getline(cin, input);
    save += input + " ";
    getline(cin, input);
    save += input + " ";
    getline(cin, input);
    save += input;
    return save;
}

void slice_string_and_init_mp(string &words, vector<vector<int>> &parking_datas, string delimeter)
{
    queue<int> input_numbers;
    long long pos =0;
    while((pos = words.find(delimeter)) != string::npos)
    {
        string str_num = words.substr(0,pos);
        words.erase(0, pos+delimeter.length());
        input_numbers.push(stoi(str_num));
    }
    input_numbers.push(stoi(words));

    // init abc_money
    for(int abc_cnt =1; abc_cnt <4; abc_cnt++)
    {
        // insert A,B,C
        _abc_money[abc_cnt] = input_numbers.front();
        input_numbers.pop();
    }
    // init parking time
    for(int abc_cnt =0; abc_cnt <3; abc_cnt++)
    {
        parking_datas.push_back({});
        parking_datas[abc_cnt].push_back(input_numbers.front()); // 파킹 시작 (이상)
        input_numbers.pop();
        parking_datas[abc_cnt].push_back(input_numbers.front()-1); // 떠나는 시간 (미만)
        input_numbers.pop();
    }
}

void calc_and_print(vector<vector<int>> & t_ps)
{
    int result = 0;
    int park_num = 0;
    for(int run_time = 1; run_time <= 100; run_time++)
    {
        park_num = 0;
        // runtime이 파킹_시작타임과 같은지 체크
        for(auto& park_time: t_ps)
        {
            if(park_time[0] == run_time)
            {
                park_num++;
                // - 파킹_시작타임 계산후 +1 씩 해준다. 단 파킹_끝타임과 같아지면 안한다.
                if(park_time[0] < park_time[1])
                    park_time[0]++;
            }
        }
        // 몇개의 파킹타임이 얼마나 같은지 확인 후 돈 더하기
        result += _abc_money[park_num]*park_num;
    }
    cout << result;
}

int main()
{
    // 변수 초기화
    string input;
    vector<vector<int>> t_ps; // 트럭-파킹타임s
    
    // 입력받기
    input = input_t_p();
    
    // String 후처리 후 map init
    slice_string_and_init_mp(input, t_ps, " ");

    // 계산 후 출력하기
    calc_and_print(t_ps);

    return 0;
}