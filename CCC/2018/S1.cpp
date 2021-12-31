#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;
    double v[n];
    double a[n];
    a[0] = 999999999999;
    a[n - 1] = 999999999999;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v, v + n);
    for(int i = 1; i < n - 1; i++){
        a[i] = abs(v[i] - v[i - 1]) / 2 + abs(v[i + 1] - v[i]) / 2;
    }
    sort(a, a + n);
    cout << fixed << setprecision(1) << a[0];
}