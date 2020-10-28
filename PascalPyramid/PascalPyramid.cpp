#include <iostream>
const int size = 30;
int main() {
	int n;
	std::cin >> n;
	int a[size][size];
	for (int i = 0; i < n; i++) {
		a[i][0] = 1;
		a[i][i] = 1;
		for (int j = 1; j < i; j++) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << a[i][j]<<" ";
		}
		std::cout << "\n";
	}
}