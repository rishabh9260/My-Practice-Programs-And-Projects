#include <iostream>

long long get_fibonacci_huge(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long num;
    long long div = 1;
    int flag = 0;

    for (long long i = 0; i <n-1; ++i)
    {
        // std::cout<<current<<"\t";
        num = (previous + current)%m;
        previous = current;
        current = num;
        if(previous == 0 && current == 1)
        {
            flag = 1;
            div = i+1;
            // std:: cout<<std::endl<<div<<std::endl;
            break;
        }
    }
    if(flag == 0)
        return num;

    if (n%div <= 1)
        return n%div;

    previous = 0;
    current = 1;

    for (long long i = 0; i <n%div-1; ++i)
    {
        //std::cout<<current<<"\t";
        num = (previous + current)%m;
        previous = current;
        current = num;
    }
    return current;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
