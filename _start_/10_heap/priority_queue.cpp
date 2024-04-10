#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
void print_queue(T q)
{
    while(!q.empty())
    {
        cout << q.top() << ", ";
        q.pop();
    }
    cout << endl;
}

class Student
{
public:
    string name;
    int score;

    // 부동호 연산자 < 오버라이딩 (필수. 오름차순)
    bool operator < (const Student& st) const
    {
        return score < st.score;
    }

    // 부동호 연산자 > 오버라이딩 (내림차순)
    bool operator > (const Student& st) const
    {
        return score > st.score;
    }
};

int main(void)
{
    vector<int> vec {4,3,1,2,4,5};
    priority_queue<int> pq1;
    for(auto n: vec)
        pq1.push(n);
    print_queue(pq1);
    
    // 내림차순 + begin,end 으로 한번에 vector값 넣기
    priority_queue<int, vector<int>, greater<int>> pq2(vec.begin(),vec.end());
    print_queue(pq2);
    
    // priority_queue<Student> students;
    priority_queue<Student, vector<Student>, greater<Student>> students;
    students.push({"AAA", 80});
    students.push({"CCC", 29});
    students.push({"FFF", 55});
    students.push({"xXx", 11});
    students.push({"ZzZ", 34});
    while(!students.empty())
    {
        auto& s = students.top();
        cout<<s.name <<" (" << s.score <<")" <<endl;
        students.pop();
    }

    return 0;
}