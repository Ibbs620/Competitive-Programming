#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int a, b, p;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> p;
        if(a * b == p) cout << "POSSIBLE DOUBLE SIGMA" << endl;
        else cout << "16 BIT S/W ONLY" << endl;
    }
}