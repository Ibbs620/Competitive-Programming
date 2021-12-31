#include <iostream>

using namespace std;

int main(){
    int l,n,s,t;
    cin >> l >> n;
    int r[l + 1];
    int m = 0;
    int m2 = 0;
    for(int i = 0; i < l + 1; i++){
        r[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cin >> s >> t;
        for(int j = s; j < t; j++){
            r[j] = 1;
        }
    }
    for(int i = 0; i < l + 1; i++){
        if(r[i] == 0){
            m2++;
            if(m2 > m){
                m = m2;
            }
        } else {
            m2 = 0;
        }
    }
    cout << m;
}
