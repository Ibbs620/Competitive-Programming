#include <iostream>

using namespace std;

int main()
{
    int spaces;
    string yes;
    string today;
    int occ = 0;
    cin >> spaces >> yes >> today;
    for(int i = 0; i < spaces; i++){
        if(today[i] == 'C' && yes[i] == 'C'){
            occ++;
        }
    }
    cout << occ;
}