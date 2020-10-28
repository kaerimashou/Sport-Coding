#include <iostream>

const int size = 50;
static int n;
static int m;
static int a[size][size];

void initialize(int n,int m,int a[size][size]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = -1;
		}
	}
	a[0][0] = 1;
}

bool good(int i, int j, int n, int m)
{
	return (i >= 0) && (j >= 0) && (i < n) && (j < m);
}

int solve(int i, int j,int n,int m,int a[size][size])
{
	if (good(i, j, n, m))
	{
		if (a[i][j] == -1)
			a[i][j] = solve(i - 2, j - 1,n,m,a) + solve(i - 2, j + 1,n,m,a) + solve(i - 1, j - 2,n,m,a) + solve(i + 1, j - 2,n,m,a);
	}
	else
		return 0;
	return a[i][j];
}
	
int main() {
	std::cin >> m >> n;
	initialize(n, m, a);
	std::cout << solve(n-1,m-1,n,m,a);
}