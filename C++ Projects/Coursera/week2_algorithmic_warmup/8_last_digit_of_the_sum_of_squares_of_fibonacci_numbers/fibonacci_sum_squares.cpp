#include <iostream>
long long get_fibonacci_last_digit(long long a)
{
    if(a<=1)
        return a;
    long long previous = 0;
    long long current = 1;

    for(int i=0;i<(a-1)%60;i++)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }

    return current;
}

long long fibonacci_sum_squares(long long a)
{
    long long sum = get_fibonacci_last_digit(a)*get_fibonacci_last_digit(a+1);
    return sum%10;
}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}
