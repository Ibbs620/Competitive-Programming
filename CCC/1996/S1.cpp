#include <iostream>

using namespace std;

int factors(int m){
    int sum = 1;
    for(int i = 2 ; i * i <= m; i++){
        if(m % i == 0) {
            sum += i + (m / i);
            if(i * i == m) sum -= i;
        }
    }
    return sum;
}
int main(){
    int n;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    int fac;
    for(int i = 0; i < n; i++){
        fac = factors(num[i]);
        if(num[i] < fac){
            cout << num[i] <<" is an abundant number.\n";
        } else if(num[i] > fac){
            cout << num[i] <<" is a deficient number.\n";
        }else {
            cout << num[i] <<" is a perfect number.\n";
        }
    }
}