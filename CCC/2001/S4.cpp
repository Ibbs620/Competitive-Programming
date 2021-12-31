//NOTE: This solution is incomplete. Only 20/50 points were achieved.

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int chips[n][2];
    float radius;
    double len;
    vector<float> dist;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            cin >> chips[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        len = round(100 * sqrt(chips[i][0] * chips[i][0] + chips[i][1] * chips[i][1])) / 100 + 0.00000001;
        dist.push_back(len);
    }
    sort(dist.begin(), dist.end());
    radius = abs(dist.back() - dist.front());
    cout << radius;
}