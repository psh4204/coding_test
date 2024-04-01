#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/// @brief 20까지의 factorial 계산 코드
/// @param n 
/// @return 
long long factorial(int n) // 8Byte type
{
    if(n==0)
        return 1;
    return n*factorial(n-1);
}

/// @brief 
/// @param n n번째 항 (1 ~ n) 
/// @return 1~n번째 항까지의 피보나치 합. 
long long fibo(int n)
{
    if(n<1)
        return n;
    else
        return fibo(n-2)*fibo(n-1);
}

/// @brief 
/// @param n n번째 항 (1 ~ n) 
/// @return 1~n번째 항까지의 피보나치 합. 
long long fibo_light(int n)
{
    vector<long long> ch; //1,1,2,3,5 .. fibo(n)
    for(int i = 0; i< n ;i++)
    {
        if(i <= 1)
            ch.push_back(1);
        else if(ch.size() < n)
            ch.push_back(ch[i-2]+ch[i-1]);
    }
    return ch[n-1];
}

std::string reverse(const std::string& str)
{
    if(str.length() == 0) // size 써도 됨
        return "";
    else
        // .substr(pos,count). 
        // pos부터 count만큼 substr. count가 npos면 pos부터 끝까지 substr
        return reverse(str.substr(1))+str[0]; // "123" -> "23" + "1" -> "3" + "2" + "1" + "" 
}

/// @brief 유클리드 호재법을 통한 최대공약수 식.
/// @param a 
/// @param b 
/// @return a와 b의 최대 공약수
int gcd(int a, int b)
{
    if( b == 0 )
        return a;
    else
        return gcd(b, a%b);
}

/// @brief 최소공배수 식. a*b = gcd*lcm 이라는 걸 이용한 식.
/// @param a 
/// @param b 
/// @return a와 b의 최소 공배수
int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

void print_vector(vector<int>& vec)
{
    for(auto const v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}

/// @brief 벡터값의 k번째수부터 시작하는 순열 하여 print하는 함수.
/// @param vec 
/// @param k 
void permutation(vector<int>& vec, int k)
{
    // k가 벡터의 마지막 번지수를 찍고있다면 vector all print
    if(k == (vec.size()-1)) 
    {
        print_vector(vec);
        return;
    }

    for(int i = k; i<vec.size(); i++)
    {
        swap(vec[k], vec[i]);   // k번재와 k+n번째 swap
        permutation(vec, k+1);  // k+1번째로 순열 재귀. (앞자리가 바뀐대로 K+1번째 순열에 들어감.)
        swap(vec[k], vec[i]);   // 원상복구. k_i와 k_1번째 다시 swap. 그래야 설계한대로 앞자리수가 차례로 바뀜.
                                // k가 벡터 사이즈에 도달할때가지 반복
    }
}

/// @brief next_permutation 사용예제. 콜렉터의 시작과 끝을 알려주면 알아서 다음 수열값을 리턴해준다.
/// @param vec 
void next_permutation_example(vector<int>& vec)
{
    // next_permutation함수는 무조건 오름차순 sort 후 사용해야한다.
    sort(vec.begin(), vec.end()); // sort(시작iterator, 마지막iterator, 정렬함수). 기본값은 오름차순
    do
    {
        print_vector(vec);
    } while (next_permutation(vec.begin(),vec.end())); // 리턴 false면 마지막형태까지 도달했다는 뜻.
    
}

/// @brief 하노이탑 코드
/// @param n 탑의 갯수
/// @param from 시작 탑 번호
/// @param to 목표 탑 번호
/// @param by 잠깐 놔두는 탑 번호
void hanoi(int n, int from, int to, int by)
{
    if(n == 1) // 1개면 바로 to로.
        cout << from << "->" << to << endl;
    else
    {
        hanoi(n-1, from, by, to); // 큰원판을 제외하고, 나머지 원판을 from 설정 후 재귀.
        cout << from << "->" << to << endl; // 큰원판을 바로 to로.
        hanoi(n-1, by, to, from); // by에 있던 원판을 to로 이동 후 재귀.
    }
}


// https://school.programmers.co.kr/learn/courses/30/lessons/12946

/// @brief 프로그래머스 연습문제용 하노이탑
/// @param vec 
/// @param top 
/// @param from 
/// @param to 
/// @param by 
void hanoi_vector(vector<vector<int>>& vec, int top, int from, int to, int by )
{
    vector<int> ret {from, };
    if(top==1)
    {
        // from -> to
        ret.push_back(to);
        vec.push_back(ret);
    }
    else
    {
        // n-1, from, by, to
        hanoi_vector(vec, top-1, from, by, to);
        // from -> to
        ret.push_back(to);
        vec.push_back(ret);
        // n-1, by, to, from
        hanoi_vector(vec,top-1, by, to, from);
    }
}

/// @brief 프로그래머스 연습문제용 하노이탑 정답
/// @param n 
/// @return 
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi_vector(answer, n, 1, 3, 2);
    cout <<"[ ";
    for(auto& a: answer)
        cout << "[" << a[0]<< "," << a[1] << "]";
    cout <<" ]";
    return answer;
}

int main(void)
{ 
    // hanoi(2,1,3,2);
    hanoi(3,1,3,2);
    solution(3);
    
    return 0;
}
