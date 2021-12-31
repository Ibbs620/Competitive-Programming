#include <iostream>

using namespace std;

int main(){
    int n, p, r;
    cin >> p >> n >> r;
    int days = 0;
    int current = n;
    while(current <= p){
        n *= r;
        current += n;
        days++;
    }
    cout << days;
}