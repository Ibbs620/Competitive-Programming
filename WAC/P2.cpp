#include <iostream>

using namespace std;

int main(){
    int n;
    long long h;
    cin >> n;
    long long int d;
    for(int i = 0; i < n; i++){
        cin >> h;
        if(h % 3 == 0) d = (h / 3) * (h / 3) * (h / 3);
        else if(h % 3 == 1) d = (h / 3) * (h / 3) * (h / 3 + 1);
        else d = (h / 3 + 1) * (h / 3 + 1) * (h / 3);
        cout << d << "\n";
    }
}