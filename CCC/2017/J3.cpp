#include <iostream>

int main(){
    int s[2],e[2],c;
    std::cin >> s[0] >> s[1] >> e[0] >> e[1] >> c;
    int d = std::abs(s[0] - e[0]) + std::abs(s[1] - e[1]);
    c -= d;
    if(c < 0 || c % 2 == 1){
        std::cout << "N";
    } else {
        std::cout << "Y";
    }
}