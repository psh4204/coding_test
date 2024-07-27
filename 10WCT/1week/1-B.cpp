/*
10808: 알파벳 개수
URL: https://www.acmicpc.net/problem/10808

알파벳 소문자로만 이루어진 단어에서 각 알파벳이 몇개 포함되어있는지 구하기.
input:  baekjoon
output: 1 1 0 0 1 0 0 0 0 1 1 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0

해석
- 단어의 문자를 하나하나 확인. 단순히 지역변수에 저장 후 출력
- 컨테이너: map으로 해서, char_키, int_카운트
- 함수: Split 구현
*/

#include <bits/stdc++.h>
using namespace std;

void init_alphabets(map<char,int> & in)
{
    // in['a'];
    // in['b'];
    // in['c'];
    // in['d'];
    // in['e'];
    // in['f'];
    // in['g'];
    // in['h'];
    // in['i'];
    // in['j'];
    // in['k'];
    // in['l'];
    // in['m'];
    // in['n'];
    // in['o'];
    // in['p'];
    // in['q'];
    // in['r'];
    // in['s'];
    // in['t'];
    // in['u'];
    // in['v'];
    // in['w'];
    // in['x'];
    // in['y'];
    // in['z'];
    for(int alpah_cnt = 0; alpah_cnt < 26; alpah_cnt++)
        in[97+alpah_cnt];
}

void print_data(map<char, int> & mp)
{
    for(auto key: mp)
    {
        cout << key.second << " ";
    }
}

void split_and_count(string words, map<char,int> &mp)
{
    for(auto alpha: words)
    {
        mp[alpha] += 1;
    }
}

int main()
{
    string input;
    map<char,int> alphabets;

    cin >> input; // 입력

    init_alphabets(alphabets);
    split_and_count(input, alphabets);
    print_data(alphabets);

    return 0;
}