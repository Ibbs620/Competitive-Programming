#include <iostream>
#include <bits/stdc++.h>

int main(){
    int q,n;
    std::cin >> q;
    std::cin >> n;
    int d[n], p[n];
    int m = 0;
    for(int i = 0; i < n; i++){
        std::cin >> d[i];
    }
    for(int i = 0; i < n; i++){
        std::cin >> p[i];
    }
    std::sort(d, d + n);
    std::sort(p, p + n);
    for(int i = 0; i < n; i++){
        if(q == 1){
            m += std::max(d[i],p[i]);
        } else {
            m += std::max(d[i],p[n - i - 1]);
        }
    }
   std::cout << m;
}