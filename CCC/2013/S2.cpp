#include <iostream>

using namespace std;

int main(){
    int w, n;
    cin >> w >> n;
    int cars[n];
    int total = 0;
    bool a = false;
    for(int i = 0; i < n; i++){
        cin >> cars[i];
        total += cars[i];
        if(i > 3) total -= cars[i-4];
        if(total > w && !a) {
            cout << i;
            a = true;
        }
    }
    if(!a) cout << n;
}