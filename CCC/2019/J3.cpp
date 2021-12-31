#include <iostream>

int main(){
    int n,l;
    std::cin >> n;
    std::string s[n];
    for(int i = 0; i < n; i++){
        std::cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        l = 1;
        for(int j = 1; j <= s[i].length(); j++){
            if(s[i][j] == s[i][j - 1]){
                l++;
            } else {
                std::cout << l << " " << s[i][j - 1] << " ";
                l = 1;
            }
        }
        std::cout << std::endl;
    }
}