#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int res = 0;
	int flag = 0;//단어가 없다면 
	getline(cin, str);
	if (str.size() > 2) {
		for (int i = 1;i < str.size() - 1;i++) {
			if (str[i - 1] != ' ' && str[i] == ' ' && str[i + 1] != ' ') {
				res++;
			}
			if (str[i - 1] != ' ' || str[i] != ' ' || str[i + 1] != ' ') {
				flag = 1; //단어가 존재한다면 flag=1
			}
		}
		if (flag == 1) {
			res++;
		}
	}
	else {
		for (int i = 0; i < str.size();i++) {
			if (str[i] != ' ') {
				res = 1;
			}
		}
	}
	
	cout << res;
}
