#include <iostream>
#include <bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    int tide[n];
    for(int i = 0; i < n; i++){
        std::cin >> tide[i];
    }
    std::sort(tide, tide + n);
    for(int i = 0; i < n / 2; i++){
        if(n % 2 == 0){
            std::cout << tide[n / 2 - i - 1] << " " << tide[i + n / 2] << " ";
        } else {
            std::cout << tide[n / 2 - i] << " " << tide[i + n / 2 + 1] << " ";
        }
    }
    if(n % 2 == 1){
            std::cout << tide[0];
    }
}