#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool abs_cmp(const int a, const int b)
{
	return std::abs(a) < std::abs(b);
}

// 함수 객체 + inline
struct AbsCmp
{
	inline bool operator()(int a, int b)const
	{
		return std::abs(a) < std::abs(b);
	}
};

class Person
{
public:
	string name;
	int age;

	bool operator<(const Person& a)const
	{
		return this->age < a.age; // < 오버라이딩
	}

	void print() const
	{
		cout << name << ", " << age << endl;
	}

};


int main(void)
{
	// C언어 스럽게
	int arr[] = {3,2,1,5,4,9};
	sort(arr, arr+5);

	for(auto a : arr)
		cout<< a << ",";
	cout << endl;

	// C++ 스럽게
	sort(begin(arr), end(arr));
	vector<string> vec = {"A", "C", "K", "N"};

	// 오름차순
	sort(vec.begin(), vec.end()); // ,less<>() // C++14

	for(auto a : vec)
		cout<< a << ",";
	cout << endl;

	// 내림차순
	sort(vec.begin(), vec.end(), greater<>()); // C++14
	
	for(auto a : vec)
		cout<< a << ",";
	cout << endl;

	vector<int> nums = {10, 2, -3, 5, 7};
	sort(nums.begin(), nums.end(), abs_cmp); // 절대값 체크. (bool abs_cmp)

	nums = {10, 2, -3, 5, 7};
	sort(nums.begin(), nums.end(), AbsCmp()); // 절대값 체크. 함수객체 사용하기.

	nums = {10, 2, -3, 5, 7};
	sort(nums.begin(), nums.end(), [](int a, int b){return std::abs(a) < std::abs(b);}); // 절대값 체크. 함수객체 사용하기.

	for(auto a : nums)
		cout<< a << ",";
	cout << endl;

	vector<Person> v;
	v.push_back({"Billy", 28});
	v.push_back({"Ang", 21});
	v.push_back({"AreUG", 38});
	v.push_back({"Sexy", 44});
	v.push_back({"ABDSX", 267});
	v.push_back({"BZwsss", 23});

	sort(v.begin(), v.end());
	for(auto p: v)
		p.print();
	cout<< endl;

    return 0;
}



