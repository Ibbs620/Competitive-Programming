#include <iostream>

using namespace std;

int prime(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return i;
    }
    return x;
}


int main(){
    int n;
    cin >> n;
    int c = 0;
    while(n > 1){
        int f = prime(n);
        n -= n / f;
        c += f - 1;
    }
    cout << c;
}
