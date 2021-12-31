#include <iostream>

int main(){
    int a[3];
    int b[3];
    int totalA = 0;
    int totalB = 0;
    std::cin >> a[0];
    std::cin >> a[1];
    std::cin >> a[2];
    totalA = a[2] + (2 * a[1]) + (a[0] * 3);
    std::cin >> b[0];
    std::cin >> b[1];
    std::cin >> b[2];
    totalB = b[2] + (2 * b[1]) + (b[0] * 3);
    if(totalA > totalB){
        std::cout << "A";
    } else if(totalA < totalB){
        std::cout << "B";
    } else {
        std::cout << "T";
    }
}