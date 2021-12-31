#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int f = 0;
    int e = 0;
    std::string s;
    for(int i = 0; i <= n; i++){
        std::getline(std::cin, s);
        for(int j = 0; j < s.length(); j++){
            if(s[j] == 'S' || s[j] == 's'){
                f++;
            } else if(s[j] == 'T' || s[j] == 't'){
                e++;
            }
        }
    }
    if(f >= e){
        std::cout << "French";
    } else {
        std::cout << "English";
    }
}