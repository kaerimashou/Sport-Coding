#include <iostream>
#include <algorithm>

const int sz = 20;
static int a[sz][sz];
static int b[sz][sz];
static int n;
static int m;

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	b[0][0] = a[0][0];
	for (int i = 1; i < n; i++) {
		b[i][0] = b[i - 1][0] + a[i][0];
	}
	for (int i = 1; i < m; i++) {
		b[0][i] = b[0][i-1] + a[0][i];
	}
	for (int i = 1; i < n; i++) {
		
		for (int j = 1; j < m; j++) {
			b[i][j] = std::min(b[i][j - 1], b[i - 1][j]) + a[i][j];
		}
	}
	std::cout << b[n-1][m-1];
}