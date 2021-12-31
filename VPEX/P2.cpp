#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n];
    int total = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        total += p[i];
    }
    int x = total / n;
    int m = 0;
    for(int i = 0; i < n; i++){
        if(p[i] != x) m++;
    }
    cout << m;
}
