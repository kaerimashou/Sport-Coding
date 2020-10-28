#include <iostream>
using namespace std;
static int a;
static int n;
int amount(int n) {
	if (n == 1) {
		return 0;
	}
	else {
		if (n % 3 == 0) {
			return amount(n / 3) + 1;
		}
		else {
			if (n % 2 == 0 && amount(n - 1) > amount(n / 2)) {
				return amount(n / 2) + 1;
			}
			else {
				return amount(n - 1) + 1;
			}
		}
	}
}
int main() {
	cin >> n;
	cout << endl << amount(n);
}
