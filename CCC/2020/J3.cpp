#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string points[n];
    int x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> points[i];
        x[i] = stoi(points[i].substr(0, points[i].find(',')));
        y[i] = stoi(points[i].substr(points[i].find(',') + 1,10000));
    }
    sort(x, x+n);
    sort(y, y+n);
    cout << x[0] - 1 << "," << y[0] - 1 << endl << x[n - 1] + 1 << "," << y[n - 1] + 1;
}