#include <iostream>

using namespace std;

int main()
{
    string s1,s2;
    int diff = 0;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i]){
            diff++;
        }
    }
    if(diff == 1){
        cout << "LARRY IS SAVED!";
    } else {
        cout << "LARRY IS DEAD!";
    }
}