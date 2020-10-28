#include <iostream>
static int n;
static int m;
int find(int n,int m) {
	if (n == 0 || m == 0) {
		return 1;
	}
	else {
		return find(n, m - 1) + find(n - 1, m);
	}
}
int main() {
	std::cin >> n >> m;
	std::cout << find(n-1, m-1);
}