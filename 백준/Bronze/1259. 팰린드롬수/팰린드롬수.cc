#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string str = "";
	vector<string> strIn;

	while (str != "0") {
		cin >> str;
		strIn.push_back(str);
	}

	int flag = 0;
	int len = 0;
	vector<string> ans;
	int leng = strIn.size();
	for (int i = 0; i < leng -1;i++) {
		str = strIn[i];
		len = str.size();
		for (int j = 0;j < len;j++) {
			if (str[j] != str[len - j - 1]) {
				flag = 1;
			}
		}
		if (flag == 1) {
			ans.push_back("no");
		}
		else{
			ans.push_back("yes");
		}
		flag = 0;
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

}
