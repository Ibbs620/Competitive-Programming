#include <iostream>

using namespace std;

int main(){
    cout.precision(2);
    cout<<fixed;
    long double h, w;
    cin >> h >> w;
    cout << (h * w) / 4 << endl;
}