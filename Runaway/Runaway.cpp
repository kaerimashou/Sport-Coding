#include <iostream>

const int size = 1000;
static long int a[size][size];
static long int b[size][size];
static int n;
static int m;
void initalize(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = -1;
		}
	}
	b[0][0] = 1;
}
bool av(int i, int j) {
	return(i >= 0) && (j >= 0) &&(i<n) && (j<m) && (a[i][j] != 0);
}
int move(int i, int j) {
	if (av(i, j)) {
		
		if (b[i][j] == -1) {
			b[i][j] = move(i - 1, j) + move(i, j - 1);
		}
	}
	else {
		return 0;
	}
	return b[i][j];
}
int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	initalize(n, m);
	int c = move(n - 1, m - 1);
	if (c == 0) {
		std::cout << "Impossible";
	}
	else {
		std::cout << c;
	}
}