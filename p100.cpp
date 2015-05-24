#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int DIGITS_NUM = 10;

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
	BigNum operator*(const BigNum &n) const
	{
		BigNum res;
		res.data_.resize(n.data_.size() + data_.size());
		for(size_t i = 0; i < data_.size(); ++i) {
			for(int j = 0, carry = 0; j<(int)n.data_.size() || carry; ++j) {
				long long cur = res.data_[i+j] + data_[i] * 1ll * (j < (int)n.data_.size() ? n.data_[j] : 0) + carry;
				res.data_[i+j] = int (cur % base_);
				carry = int (cur / base_);
			}
		}
		while (res.data_.size() > 1 && res.data_.back() == 0)
			res.data_.pop_back();
		return res;
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
	int n;
	scanf("%d", &n);
	int tsize = (n / 2) * 9 + 1;
	tsize = max(tsize, 10);
	vector <BigNum> curd(tsize);
	for(int i = 0; i <= 9; ++i) {
		curd[i] = 1;
	}
	vector <BigNum> nextd(tsize);
	for(int i = 1; i < (n / 2); ++i) {
		for(int i = 0; i < nextd.size(); ++i) {
			nextd[i] = 0;
		}
		for(int j = 0; j < nextd.size(); ++j) {
			for(int k = 0; k <= min(j, 9); ++k) {
				nextd[j] += curd[j - k];
			}
		}
		for(int i = 0; i < curd.size(); ++i) {
			curd[i] = nextd[i];
		}
	}
	BigNum ans = 0;
	for(int i = 0; i < curd.size(); ++i) {
		ans += curd[i] * curd[i];
	}
	if(n & 1) {
		ans = ans * 10;
	}
	ans.print();
	putchar('\n');
	return 0;
}
