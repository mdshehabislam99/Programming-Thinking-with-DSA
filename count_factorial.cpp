#include<bits/stdc++.h>
using namespace std;

void count_factorial(int n)
{
    int fact = 1;
    for(int i=1; i<=n; i++)
    {
        fact *= i;
    }
    cout << "Factorial of " << n << " is: " << fact << endl;
}

int main()
{
    int n;
    cin >> n;
    count_factorial(n);
    return 0;
}
