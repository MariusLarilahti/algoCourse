#include <iostream>
using namespace std;

//f(n) = f(n-1) + f(n-2),  n > 1 and f(0) = f(1) = 1

int fibRecursive(int n)
{
    if (n < 0)
        return 0;
    if (n == 1 || n == 0)
        return 1;
    else
        return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main()
{
    cout << fibRecursive(6);
}