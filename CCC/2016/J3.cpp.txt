#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int m = 1;
    for(int i = s.length(); i > 0; i--){
        for(int j = 0; j <= s.length() - i; j++){
            string n = s.substr(j, i);
            m = i;
            bool found = true;
            for(int k = 0; k <= n.length() / 2; k++){
                if(n[k] != n[n.length() - k - 1]){
                    found = false;
                    break;
                }
            }
            if(found){
                goto done;
            }

        }
    }
    done:
    cout << m;
}
