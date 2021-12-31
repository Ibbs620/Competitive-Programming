#include <iostream>

using namespace std;

int main(){
    int t, d, p, c = 0;
    cin >> t >> d >> p;
    if(t < -40) c++;
    if(d >= 15) c++;
    if(p > 50) c++;
    if(c >= 2) cout << "YES";
    else cout << "NO";
}