#include <iostream>

using namespace std;

int main(){
    int c,m,k;
    cin >> c >> m >> k;
    cout << max(k * c, k * m) << endl;
}
