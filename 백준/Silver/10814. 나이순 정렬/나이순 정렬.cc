#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct User
{
	int age;
	string name;
	int num;
};

//비교 기준 함수
bool comp(const User &u1, const User& u2) {
	if (u1.age == u2.age) {
		return u1.num < u2.num;
	}
	else {
		return u1.age < u2.age;
	}
}

int main()
{
	int N;
	cin >> N;

	User u;
	vector<User> v;
	
	for (int i = 0;i < N;i++) {
		cin >> u.age >> u.name;
		u.num = i;
		v.push_back(u);
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0;i < N;i++) {
		cout << v.at(i).age << " " << v.at(i).name << "\n";
	}

}

