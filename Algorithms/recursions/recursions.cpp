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

int fibIterative(int n)
{
    int n_minus_2;
    int n_minus_1 = 0;
    int n_current = 1;

    for (int i = 1; i < n + 1; i++) 
    {
        n_minus_2 = n_minus_1;
        n_minus_1 = n_current;
        n_current = n_minus_2 + n_minus_1;
    }
    return n_current;
}

//A(0,n) = n + 1
//A(m, 0) = A(m - 1, 1)
//A(m, n) = A(m - 1, A(m, n - 1))
int ackermann(int m, int n) 
{
    if (m < 0 || n < 0)
        return 0;

    if (m == 0) 
        return n + 1;

    if (n == 0)
        return ackermann(m - 1, 1);

    else
        return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
    cout << "Ackermann(2,2): " << ackermann(2, 2) << endl;
    int x;
    cout << "Please give an integer for fibonacci calculation: ";
    cin >> x;
    cout << "Recursive: " << fibRecursive(x) << endl;
    cout << "Iterative: " << fibIterative(x) << endl;
    
}