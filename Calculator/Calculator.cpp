#include<iostream>
#include<cstring>
int N;
struct op {
    unsigned count_op;
    unsigned code_op;
    unsigned operand;
}x[1000001];
void print(int operand) {
    if (operand != 1) {
        print(x[operand].operand);
        std::cout << x[operand].code_op;
    }
}
int main()
{
    std::cin >> N;
    memset(x, 0xFF, (N + 1) * sizeof(op));
    x[1] = { 0 };
    for (int i = 1; i < N; ++i)
    {
        if (x[i + 1].count_op > x[i].count_op + 1)
        {
            x[i + 1].count_op = x[i].count_op + 1;
            x[i + 1].code_op = 1;
            x[i + 1].operand = i;
        }
        if (i * 2 <= N && x[i * 2].count_op > x[i].count_op + 1)
        {
            x[i * 2].count_op = x[i].count_op + 1;
            x[i * 2].code_op = 2;
            x[i * 2].operand = i;
        }
        if (i * 3 <= N && x[i * 3].count_op > x[i].count_op + 1)
        {
            x[i * 3].count_op = x[i].count_op + 1;
            x[i * 3].code_op = 3;
            x[i * 3].operand = i;
        }
    }
    print(N);
}