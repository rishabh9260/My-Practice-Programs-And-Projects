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

int fibonacci_partial_sum(long long a, long long b)
{
    if(a==0)
        return fibonacci_sum(b);
    long long previous = 0;
    long long current = 1;

    for(int i=0;i<(a-1)%60;i++)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }

    if(a == b)
        return current;

    long long start = current + previous;
    long long from = a%60;
    long long to = b%60;
    if(to<from)
        to = from + to + 1;
    for (long long i = from; i < to + 2; ++i)    //Pisano period of 10 is 60
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;    //Sum of fibbonacci is Fn-1 + Fn + 1
    }

    return (current - start%10 + 10)%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_partial_sum(from, to) << '\n';
}
