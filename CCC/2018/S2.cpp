#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int t[n][n];
    int c[2] = {0,0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> t[i][j];
        }
    }
    for(int i = 0; i < n; i = i + n - 1){
        for(int j = 0; j < n; j = j + n - 1){
            if(t[i][j] < t[c[0]][c[1]]){
                c[0] = i;
                c[1] = j;
            }
        }
    }
    if(c[0] > 0 && c[1] > 0){
        for(int i = c[0]; i >= 0; i--){
            for(int j = c[1]; j >= 0; j--){
                std::cout << t[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else if(c[0] > 0) {
        for(int i = 0; i < n; i++){
            for(int j = c[0]; j >= 0; j--){
                std::cout << t[j][i] << " ";
            }
            std::cout << std::endl;
        }
    } else if(c[1] > 0) {
        for(int i = c[1]; i >= 0; i--){
            for(int j = 0; j < n; j++){
                std::cout << t[j][i] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        for(int i = c[0]; i < n; i++){
            for(int j = c[1]; j < n; j++){
                std::cout << t[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}