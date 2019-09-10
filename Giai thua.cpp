#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

class bigint {
	string num;
public:
	bigint(int n) {
		num = "";
		while (n) {
			num = (char)(n % 10 + 48) + num;
			n = n / 10;
		}
	}
	bigint(string n) {
		num = n;
	}
	bigint(const bigint& n) {
		num = n.num;
	}
	friend ostream& operator << (ostream& os, bigint n) {
		os << n.num;
		return os;
	}
	bigint operator=(const bigint& other) {
		num = other.num;
		return *this;
	}

	friend bigint operator*(const bigint& n1, int n2) {
		string s = n1.num;
		int n = s.length();
		int i;
		int mem = 0;
		for (i = n - 1; i >= 0; i--) {
			int tmp = (s[i] - 48) * n2 + mem;
			mem = tmp / 10;
			tmp = tmp % 10;
			s[i] = (char)(tmp + 48);
		}
		while (mem) {
			s = (char)(mem % 10 + 48) + s;
			mem = mem / 10;
		}
		bigint tmp(s);
		return tmp;
	}
};

bigint giaithua_dequy(int n) {
    if (n==1) return bigint(1);
    else return (giaithua_dequy(n-1)*n);
}
bigint giaithua_0dequy(int n) {
    bigint s(1);
    for (int i=n;i>=2;i--) s=s*i;
    return bigint(s);
}
int main() {
    cout << "Giai thua khong su dung de quy! \n";
    clock_t start=clock();
    cout << "Ket qua: " << giaithua_0dequy(50) << endl;
    clock_t finish=clock();
    cout << "Thoi gian chay: ";
    cout << fixed << setprecision(3) << (double)(start-finish) << endl;
    cout << "----------------------------------\n";
    cout << "Giai thua su dung de quy!" << endl;
    start=clock();
    cout << "Ket qua: " << giaithua_dequy(50) << endl;
    clock_t finish=clock();
    cout << "Thoi gian chay: ";
    cout << fixed << setprecision(3) << (double)(start-finish);
	return 0;
}
