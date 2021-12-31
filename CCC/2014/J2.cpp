#include <iostream>

using namespace std;

int main()
{
    int v;
    int a = 0;
    int b = 0;
    cin >> v;

    char votes[v];
    for(int i = 0; i < v; i++){
        cin >> votes[i];
        if(votes[i] == 'A'){
            a++;
        } else {
            b++;
        }
    }
    if(a == b){
        cout << "Tie";
    } else if(b > a) {
        cout << "B";
    } else {
        cout << "A";
    }
}