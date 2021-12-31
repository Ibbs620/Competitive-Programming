#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long double sides[3];
        long double a, b, c;
        cin >> sides[0] >> sides[1] >> sides[2];
        sort(sides, sides+3);
        a = sides[0], b = sides[1], c = sides[2];
        if(a*a + b*b < c*c) cout << "O\n";
        else if(a*a + b*b == c*c) cout << "R\n";
        else cout << "A\n";
    }
}