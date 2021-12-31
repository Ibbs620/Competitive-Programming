#include <iostream>

using namespace std;

bool isPrime(int num){
    if(num <= 1)  return false;
    if(num <= 3)  return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i = i + 6)
        if (num % i == 0 || num % (i + 2) == 0)
           return false;

    return true;
}
int main() {
    int t;
    cin >> t;
    int n;
    int a;
    int b;
    for(int i = 0; i < t; i++){
        cin >> n;
        n *= 2;
        for(int j = 2; j < n / 2; j++){
            a = j;
            b = n - j;
            if(isPrime(a) && isPrime(b)){
                cout << a << " " << b << endl;
                break;
            }
        }
    }
}
