#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    pair<long double,long double> d[n];
    long double a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        d[i] = make_pair(a, b);
    }
    long double speed = 0;
    sort(d, d + n);
    for(int i = 1; i < n; i++) speed = max(speed, abs(d[i].second - d[i - 1].second) / abs(d[i].first - d[i - 1].first));
    cout << setprecision(10) << fixed << speed;
}