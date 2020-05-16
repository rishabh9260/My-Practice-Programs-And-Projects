#include <iostream>

int fibonacci_sum(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < (n - 1) % 60; ++i)    //Pisano period of 10 is 60
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current + 1) % 10;    //Sum of fibbonacci is Fn-1 + Fn +1
    }

    return current;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
