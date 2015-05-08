#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int p[1001];

int main()
{
	int a, b;
	char c;
	int integer_part;
	vector <int> frac;
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	cin >> a >> c >> b;
	integer_part = a / b;
	a %= b;
	int id = 1;
	while((a > 0) && (p[a] == 0)) {
		p[a] = id++;
		a *= 10;
		frac.push_back(a / b);
		a %= b;
	}
	cout << integer_part;
	if(!frac.empty()) {
		cout << ".";
		int last_id = p[a];
		if(a == 0) {
			last_id = frac.size() + 1;
		}
		for(int i = 0; i + 1 < last_id; ++i) {
			cout << frac[i];
		}
		if(a > 0) {
			cout << "(";
			for(int i = p[a] - 1; i + 1 < id; ++i) {
				cout << frac[i];
			}
			cout << ")" << endl;
		}
	}
	return 0;
}
