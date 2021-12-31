#include <iostream>

int main(){
    int n,m,it,s;
    std::cin >> n;
    int f[n];
    for(int i = 0; i < n; i++){
        f[i] = i + 1;
    }
    std::cin >> m;
    int r[m];
    for(int i = 0; i < m; i++){
        std::cin >> r[i];
    }
    for(int i = 0; i < m; i++){
        it = 0;
        for(int j = 0; j < n; j++){
            if(f[j] == 0) continue;
            it++;
            if(it == r[i]){
                s = j;
                it = r[i];
                break;
            }

        }
        for(int j = s; j <= n; j++){
            if(f[j] == 0){
                continue;
            } else if(it == r[i]){
                f[j] = 0;
                it = 1;
                continue;
            }
            it++;
        }
    }
    for(int j = 0; j < n; j++){
        if(f[j] != 0) std::cout << f[j] << std::endl;
    }
}