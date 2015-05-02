#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int base = 1000;

class LongNum
{
public:
	LongNum()
	{
	}
	LongNum(int a)
	{
		d.push_back(a);
	}
	LongNum& operator=(int a)
	{
		d.clear();
		d.push_back(a);
		return *this;
	}
	LongNum& operator+=(const LongNum &a)
	{
		int carry = 0;
		for(int i = 0; (i < a.d.size()) || carry; ++i) {
			if(d.size() == i) {
				d.push_back(0);
			}
			d[i] += ((i < a.d.size())?a.d[i]:0) + carry;
			carry = d[i] / base;
			d[i] %= base;
		}
		return *this;
	}
	void print(ostream &out) const
	{
		out << d[d.size() - 1];
		for(int i = int(d.size()) - 2; i >= 0; --i) {
			cout << setw(3) << setfill('0') << d[i];
		}
	}
private:
	vector <int> d;
};

ostream& operator<<(ostream &out, const LongNum &l)
{
	l.print(out);
	return out;
}

bool canCombineDigits(char c1, char c2)
{
	int d1 = c1 - '0';
	int d2 = c2 - '0';
	if(d1 == 0) {
		return false;
	}
	if(d1 <= 2) {
		return true;
	}
	return ((d1 == 3) && (d2 <= 3));
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	vector <LongNum> d(s.size());
	d[0] = 1;
	if((s.length() >= 2) && canCombineDigits(s[0], s[1])) {
		d[1] = 2;
	} else if(s.length() >= 2) {
		d[1] = 1;
	}
	for(int i = 2; i < d.size(); ++i) {
		d[i] = d[i - 1];
		if(canCombineDigits(s[i - 1], s[i])) {
			d[i] += d[i - 2];
		}
	}
	cout << d[d.size() - 1] << endl;
	return 0;
}
