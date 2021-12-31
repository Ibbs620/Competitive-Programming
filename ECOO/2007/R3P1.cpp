#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool prime(int num){
    if (num % 2 == 0) return false;
    for(int i = 3; i * i <= num; i+=2){
        if(num % i == 0) return false;
    }
    return true;
}

int main(){
    int n[5];
    for(int i = 0; i < 5; i++) cin >> n[i];
    int a, b, c;
    for(int i = 0; i < 5; i++){
        int nums[3];
        if(prime(n[i])){
            cout << n[i] << " = " << n[i] << endl;
            continue;
        } else if(n[i] % 2 == 0){
            a = n[i] / 2;
            b = a;
            while(!prime(a) || !prime(b)){
                a--;
                b++;
            }
            cout << n[i] << " = " << a << " + " << b << endl;
        } else {
            for(int j = n[i] / 3; j > 2; j--){
                if(!prime(j)) continue;
                a = (n[i] - j) / 2;
                b = a;
                while(!prime(a) || !prime(b)){
                    a--;
                    b++;
                }
                if(a < j) continue;
                cout << n[i] << " = " << j << " + " << a << " + " << b << endl;
                break;
            }
        }
    }
}