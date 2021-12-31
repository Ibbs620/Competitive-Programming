#include <iostream>

int main(){
    int n;
    std::cin >> n;
    char correct[n];
    char answer[n];
    int mark = 0;
    for(int i = 0; i < n; i++){
        std::cin >> correct[i];
    }
    for(int i = 0; i < n; i++){
        std::cin >> answer[i];
        if(answer[i] == correct[i]){
            mark++;
        }
    }
    std::cout << mark;
}
