#include <bits/stdc++.h>

using namespace std;

int main(){
    int j, a, n, c = 0;
    cin >> j >> a;
    int jersies[j];
    pair<int,int> request[a];
    char r;
    for(int i = 0; i < j; i++){
        cin >> r;
        if(r == 'S') jersies[i] = 1;
        if(r == 'M') jersies[i] = 2;
        if(r == 'L') jersies[i] = 3;
    }
    for(int i = 0; i < a; i++){
        cin >> r >> n;
        if(r == 'S') request[i] = make_pair(1, n);
        if(r == 'M') request[i] = make_pair(2, n);
        if(r == 'L') request[i] = make_pair(3, n);
    }
    //sort(request, request+j);
    //for(auto i: jersies) cout << i << endl;
    //cout << endl;
    //for(auto i: request) cout << i.first << " " << i.second << endl;
    for(auto i : request){
        if(i.first <= jersies[i.second - 1] && i.second <= j){
            c++;
            jersies[i.second - 1] = 0;
        }
    }
    cout << c;
}