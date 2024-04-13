#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main(void)
{
    // 데이터가 중복되는지 체크
    unordered_set<string> words;
    words.insert("0AA");
    words.insert("ABB");
    words.insert("BCC");
    words.insert("CDD");
    words.insert("DEE");
    words.insert("EFF");

    string word = "BCC";
    if(words.find(word) != words.end())
        cout << word << " is used!" << endl;
    else
        cout << word << " is not used!" << endl;

    // 중복된 데이터를 제외한 int 값 갯수 체크
    vector<int> numbers {1,2,4,6,2,1,5,6,32,4,6,67, 2}; // 벡터에 중복된 데이터들이 마구 들어가있다.
    unordered_set<int> num_set(numbers.begin(), numbers.end()); // unoredered_set은 중복값은 무시하며 init한다.
    cout << num_set.size() << endl;


    return 0;
}