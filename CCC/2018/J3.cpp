#include <iostream>

int main(){
    int dis[4];
    int cit[5] = {0,0,0,0,0};
    int t = 0;
    for(int i = 0; i < 4; i++){
        std::cin >> dis[i];
        t += dis[i];
        cit[i + 1] = t;
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            std::cout << std::abs(cit[j] - cit[i]) << " ";
        }
        std::cout << std::endl;
    }
}