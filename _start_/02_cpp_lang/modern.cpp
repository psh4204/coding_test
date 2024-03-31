#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// using (typdef)
using uchar = unsigned char;
using pis   = pair<int,string>;
using da10  = double[10];
using func_int  = void (*)(int); 

template <typename T>
using matrix1d = vector<T>;

void my_function(int n)
{
    cout << "my_function() is called!!!" << endl;
}

vector<int> odds()
{
    return {6, 9, 7, 4};
}

struct Person
{
    string name;
    int age;
};

int main(void)
{
    // auto (var)
    auto start = chrono::system_clock::now();
    auto a1 = 10;
    auto a2 = 3.14f;
    auto a3 = "oh..Hell..No..."; // const char*
    auto a4 = "yeah"s; //string
    auto a5 = sqrt(2.0);
    auto labda = [](auto x) {return x * 2;};
    
    // using
    da10 arr {};
    matrix1d<float> vec(3);
    func_int fp = &my_function;

    //vector
    vector<Person> students;
    students.push_back({"Kim", 20});
    students.push_back({"Dong", 22});
    students.push_back({"GO", 21});

    sort(students.begin(), students.end(), [](const Person& p1, const Person& p2){
        return p1.name < p2.name;
    });

    for(auto& ref_person : students)
    {
        cout << ref_person.name << " : " << ref_person.age << endl;
    }

    auto end = chrono::system_clock::now();
    auto msec = chrono::duration<double>(end - start).count() * 1000;
    cout<< "Elapsed Time: " << msec << "ms." << endl;

    return 0;
}