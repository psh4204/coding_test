#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec1 {1, 2, 3, 4};
    cout << vec1.capacity() << ":" << vec1.size() << endl; // 4:4

    vec1.push_back(5);
    cout << vec1.capacity() << ":" << vec1.size() << endl; // 8:5

    vec1.push_back(6);
    cout << vec1.capacity() << ":" << vec1.size() << endl; // 8:6

    vec1.insert(vec1.begin(), 0);
    cout << vec1.capacity() << ":" << vec1.size() << endl; // 8:7

    vec1.erase(vec1.begin()+1, vec1.begin() + 3);
    cout << vec1.capacity() << ":" << vec1.size() << endl; // 8:5

    return 0;
}