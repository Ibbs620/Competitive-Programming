#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int x = 0; x < n; x++){
        string ans = "";
        string name;
        cin >> name;
        for(auto i : name){
            if(i == 'A' || i == 'a') ans += "Hi! ";
            else if(i == 'E' || i == 'e') ans += "Bye! ";
            else if(i == 'I' || i == 'i') ans += "How are you? ";
            else if(i == 'O' || i == 'o') ans += "Follow me! ";
            else if(i == 'U' || i == 'u') ans += "Help! ";
            else if(i == '1' || i == '2' || i == '3' || i == '4' || i == '5' || i == '6' || i == '7' || i == '8' || i == '9' || i == '0') ans += "Yes! ";
        }

        ans += '\n';
        cout << ans;
    }
}