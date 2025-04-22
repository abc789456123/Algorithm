#include <iostream>
#include <string>

using namespace std;

int main()
{
	int sco=0;
	int len;
	string q;
	
	cin >> len;
	int* total = new int[len]();

	for (int i = 0; i < len;i++) {
		cin >> q;
		for (int j = 0; j < q.size(); j++) {
			if (q[j] == 'O') {
				sco++;
				total[i] = total[i] + sco;
			}
			else {
				sco = 0;
			}
		}
		sco = 0;
	}

	for (int i = 0;i < len;i++) {
		cout << total[i] << endl;
	}

	delete[] total;
}
