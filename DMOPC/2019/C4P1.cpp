#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string c[n];
    int bracket[2] = {0, 0};
    getline(cin, c[0]);
    for(int i = 0; i < n; i++){
        getline(cin, c[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < c[i].length(); j++){
            if(!(c[i][j] == '0' || c[i][j] == '1' || c[i][j] == '2' || c[i][j] == '3' || c[i][j] == '4' || c[i][j] == '5' || c[i][j] == '6' || c[i][j] == '7' || c[i][j] == '8' || c[i][j] == '9' || c[i][j] == '(' || c[i][j] == ')')){
                cout << "NO";
                goto no;
            } else if(c[i][j] == '('){
                bracket[0]++;
            } else if(c[i][j] == ')'){
                bracket[1]++;
            }
            if(bracket[1] > bracket[0]){
                cout << "NO";
                goto no;
            }
        }
        if(c[i].empty()){
            cout << "YES";
        } else if(bracket[0] == bracket[1]){
            cout << "YES";
        } else {
            cout << "NO";
        }
        no:
        bracket[0] = 0;
        bracket[1] = 0;
        if(i != n - 1){
            cout << endl;
        }
    }
}