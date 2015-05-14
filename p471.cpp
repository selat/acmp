#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int CELLS_NUM = 10;

int conv[CELLS_NUM][3] = {
	{4, 6, 10},
	{6, 8, 10},
	{7, 9, 10},
	{4, 8, 10},
	{0, 3, 9},
	{10, 10, 10},
	{0, 1, 7},
	{2, 6, 10},
	{1, 3, 10},
	{2, 4, 10}
};

class BigNum
{
public:
	BigNum(int a)
	{
		data_.push_back(a);
	}
	BigNum()
	{
		data_.push_back(0);
	}
	BigNum& operator=(int a)
	{
		data_.clear();
		data_.push_back(a);
	}
	BigNum& operator+=(const BigNum &n)
	{
		int carry = 0;
		for(int i = 0; (i < n.data_.size()) || carry; ++i) {
			if(i == data_.size()) {
				data_.push_back(0);
			}
			data_[i] += carry + ((i < n.data_.size())?n.data_[i]:0);
			carry = data_[i] / base_;
			data_[i] %= base_;
		}
	}
	void print()
	{
		printf("%d", data_.back());
		for(int i = static_cast<int>(data_.size()) - 2; i >= 0; --i) {
			printf("%03d", data_[i]);
		}
	}
private:
	static const int base_ = 1000;
	vector <int> data_;
};

const int BigNum::base_;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	BigNum curd[CELLS_NUM + 1] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1};
	BigNum nextd[CELLS_NUM + 1];
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		// Clear nextd
		for(int i = 0; i <= CELLS_NUM; ++i) {
			nextd[i] = 0;
		}
		for(int i = 0; i < CELLS_NUM; ++i) {
			nextd[conv[i][0]] += curd[i];
			nextd[conv[i][1]] += curd[i];
			nextd[conv[i][2]] += curd[i];
		}
		for(int i = 0; i < CELLS_NUM; ++i) {
			curd[i] = nextd[i];
		}
	}
	BigNum ans = 0;
	for(int i = 0; i < CELLS_NUM; ++i) {
		ans += curd[i];
	}
	ans.print();
	putchar('\n');
	return 0;
}
