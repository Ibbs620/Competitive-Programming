#include <iostream>

using namespace std;

int main(){
    string yes;
    getline(cin, yes);
    string ans = "YES";
    bool pass;
    char ac[7] = {'I','O','S','H','Z','X','N'};
    for(int i = 0; i < yes.length(); i++){
        pass = false;
        for(int j = 0; j < 7; j++){
            if(yes[i] == ac[j]){
                pass = true;
                break;
            }
        }
        if(!pass) {
            ans = "NO";
            break;
        }
    }
    cout << ans;
}