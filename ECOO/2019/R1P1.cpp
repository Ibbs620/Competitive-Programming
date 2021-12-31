#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, d, it, clean, laundry;
    for(int x = 0; x < 10; x++){
        cin >> n >> m >> d;
        int events[m];
        for(int i = 0; i < m; i++) cin >> events[i];
        sort(events, events + m);
        laundry = 0;
        clean = n;
        for(int i = 1; i <= d; i++){
            if(clean == 0){
                laundry++;
                clean = n;
            }
            clean--;
            for(int j = 0 ; j < m; j++){
                if(i == events[j]){
                    n++;
                    clean++;
                }
            }
        }
        cout << laundry << endl;
    }
}