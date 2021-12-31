#include <iostream>

int main()
{
    int n,k;
    std::cin >> n >> k;
    int sum = n;
    for(int i = 0; i < k; i++){
        n *= 10;
        sum += n;
    }
    std::cout << sum;
}